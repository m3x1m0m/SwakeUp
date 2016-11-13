/*
 * job.c
 *
 * Created: 11/13/2016 10:44:48 PM
 *  Author: elmar
 */ 

 #include "job.h"

uint8_t job_add(struct JobBuffer * buffer, char * job, uint8_t len, void (* callback)(struct Job *)){
	if(buffer->size == buffer->capacity){
		return 0;
	}
	buffer->size++;
	buffer->jobs[buffer->head].data = job;
	buffer->jobs[buffer->head].len = len;
	buffer->jobs[buffer->head].callback = callback;
	if(++buffer->head ==  buffer->capacity){
		buffer->head = 0;
	}
	return 1;
}


uint8_t job_get(struct JobBuffer * buffer, struct Job ** job){
	if(buffer->size == 0){
		return 0;
	}
	buffer->size--;
	*job = &buffer->jobs[buffer->tail];

	if (++buffer->tail == buffer->capacity) {
		buffer->tail = 0;
	}
	return 1;
}
