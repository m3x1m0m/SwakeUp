/*
 * event.h
 *
 * Created: 11/7/2016 11:41:38 AM
 *  Author: elmar
 */


#ifndef EVENT_H_
#define EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// #define EVENT_SUPPORTS_SLEEP

#define EVENT_MAX_LISTENERS 12
#define EVENT_MAX_BUFFER	16

static const uint8_t eventIndex = 0;

#ifndef __cplusplus
typedef struct Event Event;
#endif
struct Event{
	uint8_t eventId;
	uint8_t * data;
	const char * description;
};

typedef void (*EventCallback) (Event *);

#ifndef __cplusplus
#define EVENT_REGISTER(eventName, desc)\
 static Event eventName = {.eventId = __COUNTER__, .data = 0, .description = desc }
#else
#define EVENT_REGISTER(eventName, desc)\
 Event eventName = {__COUNTER__, 0, desc }
#endif

#ifdef EVENT_SUPPORTS_SLEEP
void event_init(void (*enableSleep)(void), void (*disableSleep)(void));
#endif
void event_fire(Event event, uint8_t * data);
void event_addListener(uint8_t eventId, EventCallback callback);
void event_removeListener(uint8_t eventId, EventCallback callback);
void event_process(void);

#ifdef __cplusplus
}
#endif

#endif /* EVENT_H_ */
