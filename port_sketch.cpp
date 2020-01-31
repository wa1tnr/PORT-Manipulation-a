#include <Arduino.h>

// https://forum.arduino.cc/index.php?topic=334073.0

#ifdef ARDUINO_ARCH_AVR
  #define REGTYPE uint8_t   // AVR uses 8-bit registers
#else
  #define REGTYPE uint32_t
#endif

REGTYPE pin13;
volatile REGTYPE *mode13;
volatile REGTYPE *out13;

void setup(void) {
    pin13 = digitalPinToBitMask(13);
    mode13 = portModeRegister(digitalPinToPort(13));
    out13 = portOutputRegister(digitalPinToPort(13));

    // set pin 13 port as output
    *mode13 |= pin13;

    Serial.begin(9600);
    while (!Serial);
    Serial.println("hoosgow. dcbe2");

    // test payload, old method:
    // for (int i = 3; i>0; i--) {
        // digitalWrite(13,1); delay(500); digitalWrite(13,0); delay(500);
    // }
}

void loop(void) { }
