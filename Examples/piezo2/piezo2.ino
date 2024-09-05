//chatGPT assisted https://chatgpt.com/share/da75d7fa-9f01-4a59-93be-8c82aa7aac66

#include <Adafruit_NeoPixel.h>

const int ledPin = 6;        // LED connected to digital pin 6
const int knockSensor = 10;  // the piezo is connected to analog pin 10
const int threshold = 900;   // threshold value to decide when the detected sound is a knock or not

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, ledPin, NEO_GRB + NEO_KHZ800);

int sensorReading = 0;  // variable to store the value read from the sensor pin
int mode = 0;

void setup() {
  Serial.begin(9600);  // use the serial port
  strip.begin();       // This initializes the NeoPixel library.
  strip.setBrightness(75);
  strip.show();
}

void loop() {
  sensorReading = analogRead(knockSensor);

  Serial.println(sensorReading);

  if (sensorReading >= threshold) {
    if (++mode > 8) mode = 0;  // Advance to the next mode, wrap around after #8

    Serial.print("Mode changed to: ");
    Serial.println(mode);

    switch (mode) {
      case 0: colorWipe(strip.Color(0, 0, 0), 50); break;  // Black/off
      case 1: colorWipe(strip.Color(255, 0, 0), 50); break;  // Red
      case 2: colorWipe(strip.Color(0, 255, 0), 50); break;  // Green
      case 3: colorWipe(strip.Color(0, 0, 255), 50); break;  // Blue
      case 4: theaterChase(strip.Color(127, 127, 127), 50); break;  // White
      case 5: theaterChase(strip.Color(127, 0, 0), 50); break;  // Red
      case 6: theaterChase(strip.Color(0, 0, 127), 50); break;  // Blue
      case 7: rainbow(10); break;  // Rainbow
      case 8: theaterChaseRainbow(50); break;  // Rainbow chase
    }

    delay(300);  // Debounce to avoid multiple triggers from one knock
  }
}

// Fill strip pixels one after another with a color.
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

// Theater-marquee-style chasing lights.
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
    }
  }
}

// Rainbow cycle along whole strip.
void rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

// Rainbow-enhanced theater marquee.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;
  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        int hue = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue));
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
      firstPixelHue += 65536 / 90;
    }
  }
}