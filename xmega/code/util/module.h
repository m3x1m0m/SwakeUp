/*
 * module.h
 *
 *  Created on: Nov 11, 2016
 *      Author: elmar
 */

#ifndef MODULE_H_
#define MODULE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#define MOUDLE_MAX_DEPENDENCIES         5

typedef struct _module{
	uint8_t (*init)();
	uint8_t (*deinit)();
	uint8_t cnt;
	const char * name;
	struct _module * deps[MOUDLE_MAX_DEPENDENCIES];
} Module;

#ifndef __cplusplus

#define MODULE_DEFINE(VAR, NAME, INIT, DEINIT, ...)     \
    HIDef VAR = {                               \
        .init = INIT,                           \
        .deinit = DEINIT,                       \
        .cnt = 0,                               \
        .name = NAME,                           \
        .deps = { __VA_ARGS__ }                 \
    }
#else

#define MODULE_DEFINE(VAR, NAME, INIT, DEINIT, ...)\
    Module VAR = {INIT, DEINIT, 0, NAME,{ __VA_ARGS__ }}

#endif
#define MODULE_EXP(MODULE)     extern Module MODULE;

uint8_t module_deinit(Module * module);
uint8_t module_init(Module * module);

#ifdef __cplusplus
}
#endif

#endif /* MODULE_H_ */
