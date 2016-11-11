/*
 * event.c
 *
 * Created: 11/8/2016 1:24:13 AM
 *  Author: elmar
 */
#include "event.h"

typedef struct {
	uint8_t eventId;
	EventCallback callback;
} EventListener;

EventListener listeners[EVENT_MAX_LISTENERS];
Event eventBuffer[EVENT_MAX_BUFFER];

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

void event_fire(Event event, uint8_t * data) {
	event.data = data;
	eventBuffer[eventBufferHead] = event;
	eventBufferHead++;
	if (eventBufferHead > EVENT_MAX_BUFFER - 1) {
		eventBufferHead = 0;
	}
#ifdef EVENT_SUPPORTS_SLEEP
	if(_disableSleep!=0) {
		_disableSleep();
	} else {
		//TODO throw warning
	}
#endif
}

static Event getNext(void) {
	Event returnal = eventBuffer[eventBufferTail];
	eventBufferTail++;
	if (eventBufferTail > EVENT_MAX_BUFFER - 1) {
		eventBufferTail = 0;
	}
	return returnal;
}

void event_addListener(uint8_t eventId, EventCallback callback) {
	listeners[listenerIndex].eventId = eventId; // = {.eventId = eventId, .callback = callback};
	listeners[listenerIndex].callback = callback;
	listenerIndex++;
}

void event_removeListener(uint8_t eventId, EventCallback callback) {
	for (uint8_t i = 0; i < listenerIndex; i++) {
		if (listeners[i].eventId == eventId
				&& listeners[i].callback == callback) {
			for (uint8_t b = i; b < listenerIndex - 1; b++) {
				listeners[b] = listeners[b + 1];
			}
			listenerIndex--;
			return;
		}
	}
}

void event_process(void) {
	while (eventBufferHead != eventBufferTail) {
		Event event = getNext();
		for (uint8_t i = 0; i < listenerIndex; i++) {
			if (listeners[i].eventId == event.eventId)
				listeners[i].callback(&event);
		}
	}
#ifdef EVENT_SUPPORTS_SLEEP
	if(_enableSleep != 0) {
		_enableSleep();
	} else {
		//TODO throw warning
	}
#endif
}