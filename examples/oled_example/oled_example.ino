#include <OLED.h>

void setup(void) {
  oled.begin();
  
  // This is optional. The supported clock speed depends on your hardware.
  // Wire.setClock(100000L); // Probably works but slow
  // Wire.setClock(400000L); // Should be ok
  // Wire.setClock(1000000L);
  // Wire.setClock(3400000L); // Works on very few harware
  
  oled.setContrast(255);
  // When doing a big change in screen you might want to have it off to avoid redrawing being noticed.
  oled.screenOff();
  printMainScreen();
  oled.screenOn();
}

void loop(void) {
  // To redraw the same screen do not clear it or turn it off to avoid flickering
  printMainScreen();
}

void printMainScreen(){
  unsigned long t0 = millis();
  oled.setCursor(0,0);
  
  // Fonts test
  oled.setFont(FONT8X16);
  oled.println("1234567890123456");
  oled.setFont(FONT8X8);
  oled.println("1234567890123456");
  oled.setFont(FONT6X8);
  oled.println("123456789012345678901");

  // Milliseconds that the drawing took
  oled.print(millis()-t0);
  // Some blank space to clean remaining digits for the case millis()-t0 is >= 100 in one cycle and < 100 on the next one.
  oled.print(" "); 
}
