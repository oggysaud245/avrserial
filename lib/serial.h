#ifndef SERIAL_H
#define SERIAL_H

#include <avr/io.h>
#include <stdint.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
class Serial {
public:
    Serial(const uint32_t baud);
    void write(uint8_t data);
    bool available();
    uint8_t read();
    void print(char* str);
    void println(char* str);
    void readString(char* buffer, uint8_t maxLength);
    void readStringUntil(char terminator, char* buffer, uint8_t maxLength);

private:
    void begin(const uint16_t baud);
    uint16_t ubrr;
};

#endif // SERIAL_H