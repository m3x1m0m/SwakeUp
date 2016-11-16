/*
 * event.c
 *
 * Created: 11/8/2016 1:24:13 AM
 *  Author: elmar
 */
#include "event.h"
#include "../modules/log.h"

typedef struct {
    Event * event;
    uint8_t * data;
} InternalEvent;

typedef struct {
    Event * event;
    EventCallback callback;
} EventListener;

EventListener listeners[EVENT_MAX_LISTENERS];
InternalEvent eventBuffer[EVENT_MAX_BUFFER];

static uint8_t eventBufferHead = 0;
static uint8_t eventBufferTail = 0;
static uint8_t listenerIndex = 0;

#ifdef EVENT_SUPPORTS_SLEEP
void (*_enableSleep)(void) = 0;
void (*_disableSleep)(void) = 0;

void event_init(void (*enableSleep)(void), void (*disableSleep)(void)) {
    _disableSleep = disableSleep;
    _enableSleep = enableSleep;
}
#endif

uint8_t warning = 0;

LOG_INIT("Event");

void event_fire(Event * event, uint8_t * data) {
    uint8_t tempHead = (eventBufferHead + 1 > EVENT_MAX_BUFFER - 1) ? 0 : eventBufferHead + 1;
    if (tempHead == eventBufferTail) {
        //Our buffer is full! For now we will fire an error, could maybe process all the events?
        LOG_DEBUG("Event capacity(%d) reached!", EVENT_MAX_BUFFER);
    }
    eventBuffer[eventBufferHead].data = data;
    eventBuffer[eventBufferHead].event = event;
    eventBufferHead = tempHead;
#ifdef EVENT_SUPPORTS_SLEEP
    if (!warning) {
        if (_enableSleep != 0 && _disableSleep != 0) {
            _disableSleep();
        } else {
            LOG_WARNING("_enableSleep == %d _disableSleep == %d", _enableSleep, _disableSleep);
            warning = 1;
        }
    }
#endif
}

static InternalEvent * getNext(void) {
    InternalEvent * returnal = &eventBuffer[eventBufferTail];
    eventBufferTail++;
    if (eventBufferTail > EVENT_MAX_BUFFER - 1) {
        eventBufferTail = 0;
    }
    return returnal;
}

uint8_t event_addListener(Event * event, EventCallback callback) {
    if (listenerIndex >= EVENT_MAX_LISTENERS) {
        LOG_WARNING("Cant register listener for: %s", event->description);
        return 0;
    }
    listeners[listenerIndex].event = event;
    listeners[listenerIndex].callback = callback;
    listenerIndex++;
    return 1;
}

void event_removeListener(Event * event, EventCallback callback) {
    for (uint8_t i = 0; i < listenerIndex; i++) {
        if (listeners[i].event == event
                && listeners[i].callback == callback) {
            for (uint8_t b = i; b < listenerIndex - 1; b++) {
                listeners[b] = listeners[b + 1];
            }
            listenerIndex--;
            return;
        }
    }
    LOG_WARNING("Can't find listener for: %s", event->description);
}



void event_process(void) {
    while (eventBufferHead != eventBufferTail) {
        InternalEvent * event = getNext();
        for (uint8_t i = 0; i < listenerIndex; i++) {
            if (listeners[i].event == event->event) {
                listeners[i].callback(event->event, event->data);
            }
        }
    }
#ifdef EVENT_SUPPORTS_SLEEP
    if (!warning) {
        if (_enableSleep != 0 && _disableSleep != 0) {
            if (eventBufferHead == eventBufferTail) _enableSleep(); //One more check if everything is really processed
        } else {
            LOG_WARNING("_enableSleep == %d _disableSleep == %d", _enableSleep, _disableSleep);
            warning = 1;
        }
    }
#endif
}