#include <DS3231.h>


#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 13

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 13*11

#define ANDREIA_DAY    18
#define ANDREIA MONTH  10

#define MIGUEL_DAY     
#define MIGUEL_MONTH   

#define WEDDING_DAY    7
#define WEDDING_MONTH  7

// Define the array of leds
CRGB leds[NUM_LEDS];

DS3231  rtc(SDA, SCL);

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

  // Initialize the rtc object
  rtc.begin();

  // rtc.setTime(12, 00, 05);
  // rtc.setDate(13, 8, 2018);
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
}

void clear(void){
  // clear all LEDs
  
}

void x_to(unsigned int bef, unsigned int hour){
  // turn on ("FIVE", "TEN", "QUARTER", "TWENTY" or "TWENTY FIVE"), "MINUTES", "TO" and the hour
}

void x_past(unsigned int after, unsigned int hour){
  // turn on ("FIVE", "TEN", "QUARTER", "TWENTY" or "TWENTY FIVE"), "MINUTES", "PAST" and the hour
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);

    // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
}
