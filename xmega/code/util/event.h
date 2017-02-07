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
#define SYSTEM_ADDRESS      uint8_t *
#define SYSTEM_ADDRESS_CAST (SYSTEM_ADDRESS)
#define EVENT_SUPPORTS_SLEEP

#define EVENT_MAX_LISTENERS 14
#define EVENT_MAX_BUFFER    16

static const uint8_t eventIndex = 0;

#ifndef __cplusplus
typedef struct Event Event;
#endif
struct Event {
    uint8_t eventId;
    uint8_t * data;
    const char * description;
    uint8_t descLen;
};

typedef void (*EventCallback) (Event *, uint8_t *);

#define EVENT_EXP(NAME) extern struct Event NAME

#ifndef __cplusplus
#define EVENT_REGISTER(eventName, desc)\
Event eventName = {.eventId = __COUNTER__, .data = 0, .description = desc, .descLen = sizeof(desc) }
#else
#define EVENT_REGISTER(eventName, desc)\
static Event eventName = {__COUNTER__, 0, desc }
#endif

#ifdef EVENT_SUPPORTS_SLEEP
void event_init(void (*enableSleep)(void), void (*disableSleep)(void));
#endif
void event_fire(Event * event, uint8_t * data);
uint8_t event_addListener(Event * event, EventCallback callback);
void event_removeListener(Event * event, EventCallback callback);
void event_process(void);
uint8_t event_wait(Event * event, uint8_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* EVENT_H_ */
