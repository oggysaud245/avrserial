# Avr Serial library 
## Serial Project

This project demonstrates how to use a serial library with an AVR microcontroller. The program reads a string from the serial port and prints it back. It waits until a string is received and then prints the received string back to the serial port.

## Message
Supports only 9600 baudrate in Normal speed for now.

## Author

- **Ramesh Saud aKa oggy**
- Email: [rajusaud245@gmail.com](mailto:rajusaud245@gmail.com)
- Website: [www.saudramesh.com.np](http://www.saudramesh.com.np)

## Requirements

- AVR microcontroller (e.g., ATmega328P)
- AVR-GCC toolchain
- AVRDUDE for programming the microcontroller
- Serial terminal software (e.g., PuTTY, minicom)
## Class
- Serial
## Fucntions
- void write() => to write byte
- bool available() => check if serial data is available
- uint8_t read() => to read byte
- void print() => write char to serial, integer and floating type
- void println() => write char(only char) to serial with newline and carriage return
- void readString() => to read data from serial to char buffer 
- void readStringUntil() => read data to char buffer until a terminatior ('\n', '\r') received

## Setup

1. Clone the repository:

```sh
git clone https://github.com/oggysaud245/avrserial
cd avrserial