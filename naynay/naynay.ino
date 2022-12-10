#include <Adafruit_NeoPixel.h>

#define PIN 11

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);


int sensorValue = A1;
int sensorValue2 = A2;
int sensorValue3 = A3;
int currentColourValue;
int currentColourValue2;
int currentColourValue3;
int manual = 10;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 pinMode(manual, INPUT);
 digitalWrite(manual, LOW);
}

void loop() {
 
 
 /*int beans = digitalRead(manual);
 if (beans == HIGH)
   {
 
 currentColourValue = (255 - map( analogRead(sensorValue), 0, 1024, 0, 255 ) );
 currentColourValue2 = (255 - map( analogRead(sensorValue2), 0, 1024, 0, 255 ) );
 currentColourValue3 = (255 - map( analogRead(sensorValue3), 0, 1024, 0, 255 ) );
 
 colorWipe(strip.Color(currentColourValue, currentColourValue2, currentColourValue3), 200);
 

 }
else{*/
  rainbow(50);
 }
 //}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(10);
  }
}
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
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
