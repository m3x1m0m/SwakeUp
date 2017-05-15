/*
 * mail.c
 *
 * Created: 5/13/2017 4:22:39 PM
 *  Author: elmar
 */
/*
* status.c
*
* Created: 5/13/2017 4:23:01 PM
*  Author: elmar
*/
#include <string.h>
#include <stdio.h>
#include "mail.h"
#include "app.h"
#include "../defines.h"
#include "../modules/screen.h"
#include "../sprites.h"
#include "../drivers/host/timer.h" //TODO remove, just for testing purposes

#define MAIL_ENTRY_HEIGHT 24

typedef struct EmailEntry {
    const char name[5];
    const char subject[5];
} EmailEntry;

EmailEntry entries[4];
// EmailEntry * order[4]; //TODO
uint8_t mails = 0;

static void move(uint16_t x, uint16_t y) {
}

APP_CREATE("Mail", move);

static void drawMail(uint16_t x, uint16_t y, EmailEntry * entry) {
    screen_draw_begin(FILLED);
    screen_color(0);
    screen_rect(x + 24, y, 40, 24);
    screen_draw_end();
    screen_color(COLOR_TO656(255, 255, 255));
    screen_text(entry->name, 5, x + 24, y + 2);
    screen_color(COLOR_TO656(200, 200, 200));
    screen_text(entry->subject, 5, x + 24, y + 8 + 4);
    screen_sub_image(&sprite_icons, x, y, SPRITE_ICON_MAIL * SPRITE_ICON_WIDTH, 0, SPRITE_ICON_SIZE);
}

static void draw(void) {
    if (APP_ISENABLED) {
        uint8_t i;
        for (i = 0; i < mails; i++) {
            drawMail(0, MAIL_ENTRY_HEIGHT * i, &entries[i]);
        }
#ifdef BOUNDARY_BOX
        screen_draw_begin(LINE);
        screen_color(COLOR_TO656(30, 240, 30));
        screen_rect(APP_BOUNDS);
        screen_draw_end();
#endif
    }
}

uint8_t waiter = 0;
static const char * name = "Elmar";
static const char Subject[] = "test ";



void mail_add(const char * sender, const char * subject) {
    uint8_t i;
    if (mails < 4) {
        memcpy(entries[mails].name, sender, 5);
        memcpy(entries[mails].subject, subject, 5);
        mails++;
    } else {
        for(i = 0; i<3; i++) {
            memcpy(&entries[i], &entries[i + 1], sizeof(EmailEntry));
        }
        memcpy(entries[3].name, sender, 5);
        memcpy(entries[3].subject, subject, 5);
    }
    draw();
}

uint8_t asd = 0;
static void callback(Event * event, uint8_t * data) {
    if (++waiter >= 3) {
        waiter = 0;
        asd++;
        snprintf(Subject, 6, "tst%02d", asd);
        mail_add(name, Subject);
    }
}

void mail_init(uint16_t x, uint16_t y) {
    APP_SET_POS(x, y);
    APP_SET_BOUNDS(MAIL_WIDTH, MAIL_HEIGHT);
//   uint8_t i;
//     for (i = 0; i < 4; i++) {
//         order[i] = &entries[i];
//     } TODO
    APP_ENABLE(true);
    draw();
    event_addListener(&EVENT_TIMER_1_HZ, &callback);
}
void mail_deinit(void) {
    APP_ENABLE(false);
    mails = 0;
    event_removeListener(&EVENT_TIMER_1_HZ, &callback);
}