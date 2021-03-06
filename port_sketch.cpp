#include <Arduino.h>

#include "compatibility.h"

#ifdef HAS_DOTSTAR_LIB
extern void setup_dotstar(void); // dotstar.cpp
extern void set_dotStarColors(void);
#endif // #ifdef HAS_DOTSTAR_LIB

// https://forum.arduino.cc/index.php?topic=334073.0

#ifdef ARDUINO_ARCH_AVR
  #define REGTYPE uint8_t   // AVR uses 8-bit registers
#else
  #define REGTYPE uint32_t
#endif

REGTYPE pin13;
volatile REGTYPE *mode13;
volatile REGTYPE *out13;

void waitfor(void) {
    // blink pin 13
    *out13 |= pin13;
    delay(4);
    *out13 &= ~pin13;
    delay(3500);
}

void setup(void) {

    setup_dotstar(); set_dotStarColors();

    pin13 = digitalPinToBitMask(13);
    mode13 = portModeRegister(digitalPinToPort(13));
    out13 = portOutputRegister(digitalPinToPort(13));

    // set pin 13 port as output
    *mode13 |= pin13;

    Serial.begin(9600);
    while (!Serial) waitfor();
    delay(700); // a bit of relief
    Serial.println("Ready when you are.");
}

void loop(void) {
    *out13 |= pin13;
    delay(900);
    *out13 &= ~pin13;
    delay(1200);
}

/*
     This way you don't need to know the details of the
     underlying abstraction layer used to define pins.
*/
