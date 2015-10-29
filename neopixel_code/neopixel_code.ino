//include FastLED library
#include<FastLED.h>

//define the number of LEDs being used
#define NUM_LEDS 89

//declare an array of LEDs
CRGB leds[NUM_LEDS];

int hue = 0;
int startHue = 0;
int t = 10;

void setup() {
  delay(3000);
  //add the LEDs and set brightness
  LEDS.addLeds<WS2812B, 5, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(80);
}

void loop() {
  //go through the entire array and assign a color to each LED
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
  }

  //display the colors
  LEDS.show();
  delay(t);

  //update colors
  hue++;
  if (hue > 255) {
    hue = 0;
  }
}
