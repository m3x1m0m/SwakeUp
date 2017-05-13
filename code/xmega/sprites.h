/*
 * spritesheet.h
 *
 * Created: 5/13/2017 4:23:55 PM
 *  Author: elmar
 */

#include "util/image.h"

#define SPRITE_NUMBER_WIDTH     240
#define SPRITE_NUMBER_HEIGHT    60

#define SPRITE_WEATHER_WIDTH    192
#define SPRITE_WEATHER_HEIGHT   32


#define SPRITE_ICON_WIDTH       24
#define SPRITE_ICON_HEIGHT      24
#define SPRITE_ICON_SIZE        24, 24

#define SPRITE_ICON_FB          0
#define SPRITE_ICON_MAIL        1
#define SPRITE_ICON_WIFI_3      2
#define SPRITE_ICON_WIFI_2      3
#define SPRITE_ICON_WIFI_1      4
#define SPRITE_ICON_ALARM       5
#define SPRITE_ICON_LIGHT       6

#define SPRITE_MAIL_WIDTH       24
#define SPRITE_MAIL_HEIGHT      24
#define SPRITE_MAIL_SIZE        24, 24

#define SPRITE_WIFI_WIDTH       24
#define SPRITE_WIFI_HEIGHT      24
#define SPRITE_WIFI_SIZE        24, 24

#define SPRITE_ALARM_WIDTH      24
#define SPRITE_ALARM_HEIGHT     24
#define SPRITE_ALARM_SIZE        24, 24

extern const Image sprite_numbers;
extern const Image sprite_weather;
extern const Image sprite_icons;
/*
extern Image sprite_alarm;
extern Image sprite_wifi;
extern Image sprite_mail;
*/