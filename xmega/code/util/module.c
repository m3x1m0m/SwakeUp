/*
 * module.c
 *
 *  Created on: Nov 11, 2016
 *      Author: elmar
 */

#include "module.h"

static uint8_t _moduleInitDeps(Module * module) {
	uint8_t i;
	for (i = 0; i < MOUDLE_MAX_DEPENDENCIES; ++i) {
		if (module->deps[i] == 0)
			continue;
		if (!module_init(module->deps[i])) {
			while (i > 0)
				module_deinit(module->deps[--i]);
			return 0;
		}
	}
	return 1;
}

static uint8_t _moduleDeInitDeps(Module * module) {
	int i;
	uint8_t success = 1;
	for (i = 0; i < MOUDLE_MAX_DEPENDENCIES; ++i) {
		if (module->deps[i] == 0)
			continue;

		if (!module_deinit(module->deps[i]))
			success = 0;
	}
	return success;
}

uint8_t module_init(Module * module) {
	if (module->cnt == 0) {
		if (!_moduleInitDeps(module))
			return 0;
		if (!module->init()) {
			_moduleDeInitDeps(module);
			return 0;
		}
	}
	module->cnt++;
	return 1;
}

uint8_t module_deinit(Module * module) {
	module->cnt--;
	if (module->cnt > 0)
		return 1;
	if (module->deinit != 0 && !module->deinit()) {
		return 0;
	}
	return _moduleDeInitDeps(module);
}
