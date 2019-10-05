/*	Author: adang018
 *      Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #2 Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    unsigned char pa0 = 0x00;
    unsigned char pa1 = 0x00;
    unsigned char pb0 = 0x00;

    while (1) {
      pa0 = PINA & 0x01;
      pa1 = PINA & 0x02;

      if(pa0 == 0x01 && pa1 == 0x00) {
	pb0 = (pb0 & 0xFE) | 0x01;
      } else {
	pb0 = (pb0 & 0xFE) | 0x00; 
      }

      PORTB = pb0;
    }
    return 0;
}
