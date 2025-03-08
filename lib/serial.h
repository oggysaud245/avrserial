#ifndef SERIAL_H
#define SERIAL_H
#include <avr/io.h>
#include <stdlib.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
// Simplified version of std::enable_if
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

// Simplified version of std::is_integral
template<typename T>
struct is_integral {
    static const bool value = false;
};

template<>
struct is_integral<bool> {
    static const bool value = true;
};

template<>
struct is_integral<char> {
    static const bool value = true;
};

template<>
struct is_integral<unsigned char> {
    static const bool value = true;
};

template<>
struct is_integral<short> {
    static const bool value = true;
};

template<>
struct is_integral<unsigned short> {
    static const bool value = true;
};

template<>
struct is_integral<int> {
    static const bool value = true;
};

template<>
struct is_integral<unsigned int> {
    static const bool value = true;
};

template<>
struct is_integral<long> {
    static const bool value = true;
};

template<>
struct is_integral<unsigned long> {
    static const bool value = true;
};
// Simplified version of std::is_floating_point
template<typename T>
struct is_floating_point {
    static const bool value = false;
};

template<>
struct is_floating_point<float> {
    static const bool value = true;
};

template<>
struct is_floating_point<double> {
    static const bool value = true;
};
class Serial {
public:
    Serial(const uint32_t baud);
    void write(uint8_t data);
    bool available();
    uint8_t read();
    template <typename T>
    typename enable_if<is_integral<T>::value, void>::type print(T data);
    template <typename T>
    typename enable_if<is_floating_point<T>::value, void>::type print(T data);
    void print(char* str);
    void println(char* str);
    void readString(char* buffer, uint8_t maxLength);
    void readStringUntil(char terminator, char* buffer, uint8_t maxLength);

private:
    void begin(const uint16_t baud);
    uint16_t ubrr;
};

#endif // SERIAL_H