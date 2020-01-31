#include <Arduino.h>

void setup(void) {
    // PA22: D13
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
