
#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

const int b1 = A6; // the piezo is connected to analog pin 9 (aka D9)
const int b2 = A7; // the piezo is connected to analog pin 7 (aka D6)
const int b3 = A10; // the piezo is connected to analog pin 10 (aka D10)

const int pins[] = {b1, b2, b3};

char Keys[] =   {'z','x','a'};

boolean currentPressed[] = {false, false, false};

const int ledPin = 6;        // LED connected to digital pin 6
const int knockSensor = 10;  // the piezo is connected to analog pin 10
const int threshold = 900;   // threshold value to decide when the detected sound is a knock or not

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, ledPin, NEO_GRB + NEO_KHZ800);

int sensorReading = 0;  // variable to store the value read from the sensor pin
int mode = 0;

void setup() {
  Serial.begin(9600);  // use the serial port
  strip.begin();       // This initializes the NeoPixel library.
  strip.setBrightness(25);
  strip.show();
  Keyboard.begin();
}

void loop() {
  for (int i=0;i<3;i++) {
    delay(1);
    long total1 = 0;
    long start = millis();
    long total =  analogRead(pins[i]);
    // check if we are sensing that a finger is touching
    // and that it wasnt already pressed
    if ((total > threshold) && (! currentPressed[i])) {
      Serial.print("Key pressed #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys[i]); Serial.println(")");
      currentPressed[i] = true;

      Keyboard.press(Keys[i]);
      rainbow(10);
      strip.show();
    } 
    else if ((total <= threshold) && (currentPressed[i])) {
      // key was released (no touch, and it was pressed before)
      Serial.print("Key released #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys[i]); Serial.println(")");
      currentPressed[i] = false;
      
      Keyboard.release(Keys[i]);
      strip.setPixelColor(0, strip.Color(0, 0, 0));
      strip.show();

    }
    
    delay(5);
  }
}

void rainbow(int wait) {
  // Hue of first pixel runs 3 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 3*65536. Adding 256 to firstPixelHue each time
  // means we'll make 3*65536/256 = 768 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
