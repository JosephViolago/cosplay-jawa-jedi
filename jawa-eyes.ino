//fades all pixels subtly
//code by Tony Sherwood for Adafruit Industries

// https://learn.adafruit.com/mystical-led-halloween-hood?view=all
// https://github.com/adafruit/Adafruit_NeoPixel
// https://forums.adafruit.com/viewtopic.php?f=47&t=41143&sid=eef7fdae0160d3855b3d3557a698be1a&start=15#p257897

// https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all

#include <Adafruit_NeoPixel.h>

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    // Written by: Jason Yandell

    int   TOTAL_LEDS        = 14;
    float MaximumBrightness = 100;
    float SpeedFactor       = 0.007;
    float StepDelay         = 10; // ms for a step delay on the lights

    // Make the lights breathe
    for (int i = 0; i < 65535; i++) {
        // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
        float intensity = MaximumBrightness / 2.0 * (1.5 + sin(SpeedFactor * i));
        strip.setBrightness(intensity);

        // Now set every LED to that color
        for (int ledNumber = 0; ledNumber < TOTAL_LEDS; ledNumber++) {
            strip.setPixelColor(ledNumber, 100, 50, 0);
        }

        strip.show();
        // Wait a bit before continuing to breathe
        delay(StepDelay);
    }
}
