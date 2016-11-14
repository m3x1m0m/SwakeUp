/*
 * job.h
 *
 * Created: 11/13/2016 9:18:41 PM
 *  Author: elmar
 */ 


#ifndef JOB_H_
#define JOB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct Job{
	uint8_t * data;
	uint8_t len;
	uint8_t i;
	void (* callback)(struct Job *);
};

struct JobBuffer{
	struct Job * jobs				;
	uint8_t capacity				;
	uint8_t head					;
	uint8_t tail					;
	uint8_t size					;
};

#ifdef __cplusplus
#define JOB_INIT(NAME, DATA) struct Job NAME = {DATA}
#define JOB_BUFFER_INIT(NAME, SIZE)	struct Job _##NAME[SIZE]; struct JobBuffer NAME = {_##NAME,SIZE,0,0,0}
#else
#define JOB_INIT(NAME, DATA) struct Job NAME = {.data = DATA}
#define JOB_BUFFER_INIT(NAME, SIZE)	struct Job _##NAME[SIZE]; struct JobBuffer NAME = {.jobs = _##NAME, .capacity = SIZE, .head = 0, .tail = 0, .size = 0}
#endif

uint8_t job_add(struct JobBuffer * buffer, uint8_t * job, uint8_t len, void (* callback)(struct Job *));
uint8_t job_get(struct JobBuffer * buffer, struct Job ** job);

#ifdef __cplusplus
}
#endif
   
#endif /* JOB_H_ */