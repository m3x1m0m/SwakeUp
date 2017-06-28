#ifndef INCLUDE_CONFIGURATION_H_
#define INCLUDE_CONFIGURATION_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>

const char THERM_CONFIG_FILE[] = ".therm.conf"; // leading point for security reasons :)

#define DAYS_MONDAY          (1<<1)
#define DAYS_TUESDAY         (1<<2)
#define DAYS_WEDNESDAY       (1<<3)
#define DAYS_THURSDAY        (1<<4)
#define DAYS_FRIDAY          (1<<5)
#define DAYS_SATURDAY        (1<<6)
#define DAYS_SUNDAY          (1<<7)



struct SwakeConfig {
	SwakeConfig() {
		StaEnable = 1; //Enable WIFI Client
	}

	String StaSSID;
	String StaPassword;
	uint8_t StaEnable;

	// Alarm config
	uint8_t alarmDays = 0;
	String alarmTime;
	String unit;

	// Current state
	String date;
	String time;	//TODO
	String city;
	String country;
};

SwakeConfig loadConfig();
void saveConfig(SwakeConfig& cfg);

extern SwakeConfig ActiveConfig;

#endif /* INCLUDE_CONFIGURATION_H_ */
