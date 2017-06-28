#include <application.h>
#include <configuration.h>
bool serverStarted = false;
HttpServer server;

void onConsole(HttpRequest &request, HttpResponse &response) {
	if (request.getRequestMethod() == RequestMethod::POST) {
		StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(request.getBody());
		root.prettyPrintTo(Serial); //Uncomment it for debuging
	}
}

void onAlarm(HttpRequest &request, HttpResponse &response) {
	if (request.getRequestMethod() == RequestMethod::POST) {
		StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(request.getBody());
		Serial.print("Received on alarm!");
		root.prettyPrintTo(Serial); //Uncomment it for debuging

		if (root["StaAlarmTime"].success()) {
			ActiveConfig.alarmDays = ((uint8_t)root["StaAlarmMon"] << 1)
					| ((uint8_t)root["StaAlarmTue"] << 2) | ((uint8_t)root["StaAlarmWed"] << 3)
					| ((uint8_t)root["StaAlarmThu"] << 4) | ((uint8_t)root["StaAlarmFri"] << 5)
					| ((uint8_t)root["StaAlarmSat"] << 6) | ((uint8_t)root["StaAlarmSun"] << 7);
			ActiveConfig.alarmTime = String((const char *) root["StaAlarmTime"]);
		}
	}
}

void onIndex(HttpRequest &request, HttpResponse &response) {
	if (request.getRequestMethod() == RequestMethod::POST) {
		if (request.getBody() == NULL) {
			response.setCache(86400, true); // It's important to use cache for better performance.
			response.sendFile("index.html");
			return;
		}
		StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(request.getBody());
		root.prettyPrintTo(Serial); //Uncomment it for debuging

		if (root["StaCITY"].success()) {
			Serial.printf("Success\r\n");
			ActiveConfig.city = String((const char *) root["StaCITY"]);
			ActiveConfig.unit = String((const char *) root["StaUNIT"]);
		}
	} else {
		response.setCache(86400, true); // It's important to use cache for better performance.
		response.sendFile("index.html");
	}
}

void onConfiguration(HttpRequest &request, HttpResponse &response) {
	if (request.getRequestMethod() == RequestMethod::POST) {
		Serial.printf("Update config\n");
		// Update config
		if (request.getBody() == NULL) {
			Serial.printf("NULL bodyBuf\n");
			return;
		} else {
			StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
			JsonObject& root = jsonBuffer.parseObject(request.getBody());
			root.prettyPrintTo(Serial); //Uncomment it for debuging
			if (root["StaCITY"].success()) {
				ActiveConfig.city = String((const char *) root["StaCITY"]);
			} else if (root["StaSSID"].success()) {
				uint8_t PrevStaEnable = ActiveConfig.StaEnable;

				ActiveConfig.StaSSID = String((const char *) root["StaSSID"]);
				ActiveConfig.StaPassword = String(
						(const char *) root["StaPassword"]);
				ActiveConfig.StaEnable = root["StaEnable"];

				if (PrevStaEnable && ActiveConfig.StaEnable) {
					WifiStation.enable(true);
					WifiAccessPoint.enable(false);
					WifiStation.config(ActiveConfig.StaSSID,
							ActiveConfig.StaPassword);
				} else if (ActiveConfig.StaEnable) {
					WifiStation.enable(true, true);
					WifiAccessPoint.enable(false, true);
					WifiStation.config(ActiveConfig.StaSSID,
							ActiveConfig.StaPassword);
				} else {
					WifiStation.enable(false, true);
					WifiAccessPoint.enable(true, true);
					WifiAccessPoint.config("TyTherm", "ENTERYOURPASSWD",
							AUTH_WPA2_PSK);
				}
			}
		}
		saveConfig(ActiveConfig);
	} else {
		response.setCache(86400, true); // It's important to use cache for better performance.
		response.sendFile("config.html");
	}
}

void onConfiguration_json(HttpRequest &request, HttpResponse &response) {
	JsonObjectStream* stream = new JsonObjectStream();
	JsonObject& json = stream->getRoot();
	json["StaCITY"] = ActiveConfig.city;
	json["StaSSID"] = ActiveConfig.StaSSID;
	json["StaPassword"] = ActiveConfig.StaPassword;
	json["StaEnable"] = ActiveConfig.StaEnable;

	response.sendJsonObject(stream);
}
void onFile(HttpRequest &request, HttpResponse &response) {
	String file = request.getPath();
	if (file[0] == '/')
		file = file.substring(1);

	if (file[0] == '.')
		response.forbidden();
	else {
		response.setCache(86400, true); // It's important to use cache for better performance.
		response.sendFile(file);
	}
}

void onAJAXGetState(HttpRequest &request, HttpResponse &response) {
	JsonObjectStream* stream = new JsonObjectStream();
	JsonObject& json = stream->getRoot();
	json["counter"] = counter;
	json["weather"] = "23C";
	json["city"] = ActiveConfig.city;
	json["date"] = ActiveConfig.date;

	response.sendJsonObject(stream);
}

void startWebServer() {
	if (serverStarted)
		return;

	server.listen(80);
	server.addPath("/", onIndex);
	server.addPath("/config", onConfiguration);
	server.addPath("/config.json", onConfiguration_json);
	server.addPath("/state", onAJAXGetState);
	server.addPath("/console", onConsole);
	server.addPath("/alarm", onAlarm);
	server.setDefaultHandler(onFile);
	serverStarted = true;

	if (WifiStation.isEnabled()) {
		Serial.printf("STA: %s \n", WifiStation.getIP().toString().c_str());
	}
	if (WifiAccessPoint.isEnabled()) {
		Serial.printf("AP: %s \n", WifiAccessPoint.getIP().toString().c_str());
	}
}
