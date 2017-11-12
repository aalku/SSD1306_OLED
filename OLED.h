/*
 * SSD1306xLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x64 displays
 *
 * @created: 2014-08-12
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/ssd1306xled
 *
 */
#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>
// #include <avr/pgmspace.h>
// #include <avr/interrupt.h>
#include <util/delay.h>

#ifndef OLED_H
#define OLED_H

#define FONT6X8		0
#define FONT8X8		1
#define FONT8X16	2

// ----------------------------------------------------------------------------

#ifndef SSD1306
#define SSD1306		0x3C	// Slave address
#endif

// ----------------------------------------------------------------------------

class SSD1306Device: public Print {

    public:
		SSD1306Device(void);
		int setup(void);
		int begin(void);
		void setFont(uint8_t font);
		int ssd1306_send_command(uint8_t command);
		void ssd1306_send_data_byte(uint8_t byte);
		void ssd1306_send_data_start(void);
		int ssd1306_send_data_stop(void);
		void setCursor(uint8_t x, uint8_t y);
		void fill(uint8_t fill);
		void clear(void);
		void bitmap(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t bitmap[]);
		void ssd1306_send_command_start(void);
		int ssd1306_send_command_stop(void);
		void ssd1306_char_f8x16(uint8_t x, uint8_t y, const char ch[]);
		virtual size_t write(byte c);
		int ping(void);
		void setContrast(uint8_t c);
		void screenOff();
		void screenOn();
  		using Print::write;
};


extern SSD1306Device oled;

// ----------------------------------------------------------------------------

#endif
