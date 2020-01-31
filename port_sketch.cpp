#include <Arduino.h>

void setup(void) {

    Serial.begin(9600);
    while (!Serial);
    Serial.println("hoosgow.");

    // PA22: D13
    pinMode(13, 1); // DDRD = B11111110;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
    digitalWrite(13,1); delay(500); digitalWrite(13,0); delay(500);
    digitalWrite(13,1); delay(500); digitalWrite(13,0); delay(500);
    digitalWrite(13,1); delay(500); digitalWrite(13,0); delay(500);
    digitalWrite(13,1); delay(500); digitalWrite(13,0); delay(500);

    // result: pending testing.
}

/* discussion:

  DDRD would be DDRA.
  PA22 would be 22 decimal or 21 decimal (zero-ref'd).
  That's a lot of bits.

  'ag DDRB' in avr shows pins_arduino.h defining.

  No hits in samd.

  Conclusion: not supported.

*/

void  loop(void) { }
