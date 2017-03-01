/*
 * command.h
 *
 * Created: 2/8/2017 11:29:04 PM
 *  Author: elmar
 */


#ifndef COMMAND_H_
#define COMMAND_H_

#include "../util/module.h"

uint8_t command_next_arg(uint8_t *data, uint8_t len);
uint8_t command_arguments(uint8_t *data, uint8_t len);
uint32_t command_next_int(uint8_t *data, uint8_t * index, uint8_t len);
uint8_t command_hook(char command, void (* callback)(uint8_t, uint8_t *));
uint8_t command_hook_description(char command, void (* callback)(uint8_t, uint8_t *), char * description);
uint8_t command_remove(char command, void (* callback)(uint8_t, uint8_t *));
void command_remove_force(char command);

MODULE_EXP(COMMAND);


#endif /* COMMAND_H_ */