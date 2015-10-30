//include FastLED library
#include<FastLED.h>

//define the number of LEDs being used
#define NUM_LEDS 57

//declare an array of LEDs
CRGB leds[NUM_LEDS];

//dclare an array of hues and an array of bright
float hues[NUM_LEDS];
float bright[NUM_LEDS];
float change[NUM_LEDS];

int hue;

int waitTime = 10;

void setup() {
  delay(3000);
  //add the LEDs and set brightness
  LEDS.addLeds<WS2812B, 5, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(30);

  for (int i = 0; i < NUM_LEDS; i++) {
    hues[i] = map(i, 0, NUM_LEDS, 0, 255);
    bright[i] = 255;
    //    change[i] = random(-1,1);
  }
}

void loop() {
  //go through the entire array and assign a color to each LED
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hues[i], 255, bright[i]);
    //    bright[i] += change[i];
    //    if (bright[i] > 250 || bright[i] < 5) {
    //      change[i] *= -1;
    //    }
  }


  //display the colors
  LEDS.show();
  delay(waitTime);
}
