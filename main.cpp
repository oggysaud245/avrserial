/*
 * main.cpp
 *
 * Created on: 2018. 12. 12.
 * This is a simple example of how to use the serial library.
 * The program reads a string from the serial port and prints it back.
 * The program will wait until a string is received.
 * The program will print the received string back to the serial port.
 * Author: Ramesh Saud aKa oggy
 * email: rajusaud245@gmail.com
 * www.saudramesh.com.np
*/

#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include "./lib/serial.h"
#define     BUFFER_SIZE     64
Serial serial((uint16_t)9600);
char* mesage = (char*)"This is serial communication test";
int main(void) {
    char rxmessage[BUFFER_SIZE];
    serial.println(mesage);
    _delay_ms(2000);
    while (1) {
        if(serial.available()){
            serial.readString(rxmessage, BUFFER_SIZE);
            serial.println(rxmessage);
        }else{
        serial.print((char*) "This is char value");
        serial.println();
        serial.print((char*) "This is int value: ");
        serial.print(255);
        serial.println();
        serial.print((char*) "This is float value: ");  
        serial.print(100.50);
        serial.println();
        serial.print((char*) "This is a double value: ");
        serial.print(65268.50);
        serial.println();
        serial.print((char*) "---------------------------------");
        serial.println();
        _delay_ms(1000);
    }
 
    }

    return 0;
}