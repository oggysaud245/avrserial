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
int main(void) {
    char message[BUFFER_SIZE];
    while (1) {
        if(serial.available()){
            serial.readString(message, BUFFER_SIZE);
            serial.println(message);
        }
 
    }

    return 0;
}