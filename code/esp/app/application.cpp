#include <user_config.h>
#include <SmingCore/SmingCore.h>
// #include "streams/StreamWebsocket.h"
#include "StreamXmega.h"
#include "swakeup.pb.h"
#include <application.h>
#include <configuration.h>
#include "MsgDelegator.h"

#ifndef WIFI_SSID
#define WIFI_SSID "Abcdeff" // Put you SSID and Password here
#define WIFI_PWD "ElmarElmar"
#endif

#ifndef WIFI_SSID
#define WIFI_SSID "U&L" // Put you SSID and Password here
#define WIFI_PWD "BESTunalejla123"
#endif

Timer blinkTimer;
Timer weatherTimer;
Timer timeTimer;
int helloCounter = 0;
bool state = true;

void blink() {
	digitalWrite(2, state);
	state = !state;
	counter++;
}

void requestTime() {
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_DATE_TIME;
	frame.which_pl = MsgFrame_dateAndTime_tag;
	msgCallback(&frame, (void*) &restStream);
}

unsigned long counter = 0;

int i = 0;

void requestWeather() {
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_WEATHER;
	frame.which_pl = MsgFrame_weather_tag;
	frame.pl.weather.temperature = ++i;
	frame.pl.weather.unit[0] = 'C';
	frame.pl.weather.sunrise = 123123;
	frame.pl.weather.sunset = 123123;
	memcpy(&frame.pl.weather.city.bytes, ActiveConfig.city.c_str(), ActiveConfig.city.length() - 1);
	frame.pl.weather.city.size = ActiveConfig.city.length() - 1;
	msgCallback(&frame, (void*) &restStream);
}

void periodTest() {
	//web.connect();
	//requestTime();
	requestWeather();
	blinkTimer.initializeMs(5 * 1000, blink).start(true); // every 20 seconds
	weatherTimer.initializeMs(5 * 1000, requestWeather).start(true); // every 20 seconds
	//timeTimer.initializeMs(300 * 1000, requestTime).start(true); // every 20 seconds
}

void STADisconnect(String ssid, uint8_t ssid_len, uint8_t bssid[6], uint8_t reason) {
	Serial.printf("DISCONNECT - SSID: %s, REASON: %d\n", ssid.c_str(), reason);

	if (!WifiAccessPoint.isEnabled()) {
		Serial.printf("Starting OWN AP");
		WifiStation.disconnect();
		WifiAccessPoint.enable(true);
		WifiStation.connect();
	}
}

void STAGotIP(IPAddress ip, IPAddress mask, IPAddress gateway) {
	Serial.printf("GOTIP - IP: %s, MASK: %s, GW: %s\n", ip.toString().c_str(), mask.toString().c_str(), gateway.toString().c_str());

	if (WifiAccessPoint.isEnabled()) {
		Serial.printf("Shutdown OWN AP");
		WifiAccessPoint.enable(false);
	}
	// Add commands to be executed after successfully connecting to AP and got IP from it
}

static void webTestInit(void) {
	spiffs_mount(); // Mount file system, in order to work with files
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(false);
	Serial.commandProcessing(false);

	//SET higher CPU freq & disable wifi sleep
	system_update_cpu_freq(SYS_CPU_160MHZ);
	wifi_set_sleep_type(NONE_SLEEP_T);

	ActiveConfig = loadConfig();

	// Attach Wifi events handlers
	WifiEvents.onStationDisconnect(STADisconnect);
	WifiEvents.onStationGotIP(STAGotIP);

	startWebServer();

	blinkTimer.initializeMs(1000, blink).start();
}

void init() {
	pinMode(2, OUTPUT);
	webTestInit();
	/*
	Serial.begin(SERIAL_BAUD_RATE);

	Serial.systemDebugOutput(false); // Debug output to serial

	// TODO this should not be required. Singleton?
	xmegaStream.init();

	// TODO this should be set from the web interface
	userSettings.city = city;
	userSettings.country = country;

	// TODO this should be moved out here, constructor?
	// Setting callback for receiving the messages
	restStream.setMsgCallback(&msgCallback);

	periodTest();
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.enable(true);
	WifiAccessPoint.enable(false);

	// Run our method when station was connected to AP (or not connected)
	//WifiStation.waitConnection(periodTest);
	 */
}
