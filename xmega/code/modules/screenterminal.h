/*
 * screenterminal.h
 *
 * Created: 2/25/2017 8:15:30 PM
 *  Author: elmar
 */


#ifndef SCREENTERMINAL_H_
#define SCREENTERMINAL_H_

void screenterminal_writes(char text);
void screenterminal_write(char * text, uint8_t len);
void (*screenterminal_sink(void))(void *, char );



#endif /* SCREENTERMINAL_H_ */