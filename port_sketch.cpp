#include <Arduino.h>

// https://forum.arduino.cc/index.php?topic=334073.0

#ifdef ARDUINO_ARCH_AVR
  #define REGTYPE uint8_t   // AVR uses 8-bit registers
#else
  #define REGTYPE uint32_t
#endif

void setup(void) {

    Serial.begin(9600);
    while (!Serial);
    Serial.println("hoosgow. cfba9");
}

void loop(void) { }
