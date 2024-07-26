#include <Adafruit_NeoPixel.h>

// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN 10

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 16

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip


int lines = 0;
unsigned long lastSent = 0;
int incomingByte = 0;

void setup() {
  Serial.begin(57600);
  strip.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();   // Turn OFF all pixels ASAP
  strip.setBrightness(50);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print(incomingByte);

        //strip.setPixelColor(incomingByte, strip.Color(0, 0, 127));  //  Set pixel's color (in RAM)
        //strip.show();                                        //  Update strip to match
        //delay(50);
    
        //strip.clear();
      
      //  Pause for a moment

      // lines++;
    
  }

  unsigned long now = millis();
  if (now - lastSent > 2000) {
    Serial.print("Hello! I heard you ");
    Serial.print(lines);
    Serial.println(" times");
    lastSent = now;
  }
}