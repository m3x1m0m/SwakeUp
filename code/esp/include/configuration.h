#ifndef INCLUDE_CONFIGURATION_H_
#define INCLUDE_CONFIGURATION_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>

const char THERM_CONFIG_FILE[] = ".therm.conf"; // leading point for security reasons :)

struct SwakeConfig {
	SwakeConfig() {
		StaEnable = 1; //Enable WIFI Client
	}

	String StaSSID;
	String StaPassword;
	uint8_t StaEnable;

// ThermControl settings

	String city;
	String country;
};

SwakeConfig loadConfig();
void saveConfig(SwakeConfig& cfg);

extern SwakeConfig ActiveConfig;

#endif /* INCLUDE_CONFIGURATION_H_ */
