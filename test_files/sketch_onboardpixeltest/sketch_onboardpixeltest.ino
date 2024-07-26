#include <Adafruit_NeoPixel.h>

#define PIN 8

#define NUMPIXELS 1

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN 12

// How many NeoPixels are attached to the Arduino?

// First, we need to tell the board to interact with the NeoPixel.
// Below we see Adafruit_NeoPixel() with three parameters inside the parenthesis
// Parameter 1 = number of pixels in strip, starting at 1.
// Parameter 2 = Arduino pin number, defined above (most are valid)
// Parameter 3 = pixel type indicators, added together as needed:
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products with WS2812 LEDs)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// This is where you're putting in place parameters for the Flora to start from
  void setup() {

      pixels.begin(); // This initializes the NeoPixel library.
      pixels.setBrightness(75);
      pixels.show();
}

// This is where you're creating the looped command for the Flora
    void loop() {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(0, pixels.Color(150,0,200)); 

      pixels.show(); // This sends the updated pixel color to the Flora.
}