#include <Adafruit_NeoPixel.h>

#define PIN 8

#define NUMPIXELS 1

#define BUTTON_PIN 6

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

int lines = 0;
unsigned long lastSent = 0;

boolean oldState = HIGH;
int mode = 0;  // Currently-active animation mode, 0-9
               // This is where you're putting in place parameters for the Flora to start from
void setup() {
  Serial.begin(57600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pixels.begin();  // This initializes the NeoPixel library.
  pixels.setBrightness(5);
  pixels.show();
}

// This is where you're creating the looped command for the Flora
void loop() {
  boolean newState = digitalRead(BUTTON_PIN);
  // Check if state changed from high to low (button press).
  if ((newState == LOW) && (oldState == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {       // Yes, still low
      if (++mode > 3) mode = 0;  // Advance to next mode, wrap around after #8
      switch (mode) {
        case 0:
          // purple
          pixels.setPixelColor(0, pixels.Color(150, 0, 200));
          pixels.show();  // This sends the updated pixel color to the Flora.
          break;
        case 1:
          // greenish
          pixels.setPixelColor(0, pixels.Color(150, 200, 20));
          pixels.show();  // This sends the updated pixel color to the Flora.
          break;
        case 2:
          //blue green
          pixels.setPixelColor(0, pixels.Color(50, 60, 200));
          pixels.show();  // This sends the updated pixel color to the Flora.
          break;
        case 3:
          //
          pixels.setPixelColor(0, pixels.Color(0, 255, 255));
          pixels.clear();  // This sends the updated pixel color to the Flora.
          break;
      }
    }
  }
  oldState = newState;
  
}