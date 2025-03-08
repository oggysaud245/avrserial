#include "serial.h"

Serial::Serial(const uint32_t baud) {
    begin(baud);
}

void Serial::begin(const uint16_t baud) {
    ubrr =  (F_CPU/16/baud)-1;
    if(baud >= 115200) {
        ubrr = ( F_CPU / 8 / baud) - 1;   // 8 for double speed
        UCSR0A |= (1 << U2X0); // Enable double speed Mode
    }
    else {
        UCSR0A &= ~(1 << U2X0);  // Disable double speed Mode
    }
    // Set baud rate
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr & 0xFF;
    // Enable receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    // Set frame format: 8 data bits, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    
}

void Serial::write(uint8_t data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    // Put data into buffer, sends the data
    UDR0 = data;
}
bool Serial::available() {
    return (UCSR0A & (1 << RXC0));
}
uint8_t Serial::read() {
    // Wait for data to be received
    while (!available());
    // Get and return received data from buffer
    return UDR0;
}
void Serial::readString(char* buffer, uint8_t maxLength) {
    uint8_t index = 0;
    while (index < maxLength - 1) {
        // Wait for data to be received
        while (!available());
        char receivedChar = UDR0;
        // Check for end of line
        if (receivedChar == '\n' || receivedChar == '\r') {
            break;
        }
        buffer[index++] = receivedChar;
    }
    buffer[index] = '\0'; // Null-terminate the string
}
void Serial::readStringUntil(char terminator, char* buffer, uint8_t maxLength) {
    uint8_t index = 0;
    while (index < maxLength - 1) {
        // Wait for data to be received
        while (!available());
        char receivedChar = UDR0;
        // Check for terminator character
        if (receivedChar == terminator) {
            break;
        }
        buffer[index++] = receivedChar;
    }
    buffer[index] = '\0'; // Null-terminate the string
}
template <typename T>
typename enable_if<is_integral<T>::value, void>::type
Serial::print(T data) {
    char buffer[32]; // Increased buffer size to 32
    itoa(data, buffer, 10);
    print(buffer);
}

template <typename T>
typename enable_if<is_floating_point<T>::value, void>::type
Serial::print(T data) {
    char buffer[32];
    dtostrf(data, 6, 2, buffer); // Convert float/double to string
    print(buffer);
}
void Serial::print(char* str) {
    while (*str) {
        write((uint8_t)*str++);
    }
}
void Serial::println(char* str) {
    while (*str) {
        write((uint8_t)*str++);
    }
    write((uint8_t)'\n');
    write((uint8_t)'\r');
}
// Explicit template instantiations
template void Serial::print<int>(int);
template void Serial::print<unsigned int>(unsigned int);
template void Serial::print<long>(long);
template void Serial::print<unsigned long>(unsigned long);
template void Serial::print<float>(float);
template void Serial::print<double>(double);