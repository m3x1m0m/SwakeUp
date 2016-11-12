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

static uint8_t eventBufferSize = 0;
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

uint8_t event_fire(Event event, uint8_t * data) {
	if (eventBufferSize == EVENT_MAX_BUFFER){
		//Can't fire the event, log error? TODO
		return 0;
	}
	event.data = data;
	eventBuffer[eventBufferHead] = event; 
	eventBufferSize++;
	if (eventBufferHead++ > EVENT_MAX_BUFFER - 1) {
		eventBufferHead = 0;
	}
#ifdef EVENT_SUPPORTS_SLEEP
	if(_disableSleep!=0) {
		_disableSleep();
	} else {
		//TODO throw warning
	}
#endif
	return 1;
}

static Event getNext(void) {
	if (eventBufferSize == 0){
		//Trying to read from an empty buffer, log error? TODO!
	}
	eventBufferSize--;
	Event returnal = eventBuffer[eventBufferTail];
	if (eventBufferTail++ > EVENT_MAX_BUFFER - 1) {
		eventBufferTail = 0;
	}
	return returnal;
}

uint8_t event_addListener(uint8_t eventId, EventCallback callback) {
	if(listenerIndex == EVENT_MAX_LISTENERS){
		//TODO log: no more listener slots available :( 
		return 0;
	}
	listeners[listenerIndex].eventId = eventId; // = {.eventId = eventId, .callback = callback};
	listeners[listenerIndex].callback = callback;
	listenerIndex++;
	return 1;
}

void event_removeListener(uint8_t eventId, EventCallback callback) {
	for (uint8_t i = 0; i < listenerIndex; i++) {
		if (listeners[i].eventId == eventId	&& listeners[i].callback == callback) {
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
