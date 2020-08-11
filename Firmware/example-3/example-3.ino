#include "FastLED.h"

// An hourglass contains 30 LEDs
#define NUM_LEDS 30

// Define the pin on your MCU board, which is connected to the "DIN" on the hourglass board
#define DATA_PIN 0

CRGB leds[NUM_LEDS];

void setJustOneLED(int ledIdx, CRGB colour)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB::Black;
    }
    leds[ledIdx] = colour;
    FastLED.show();
}

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    randomSeed(analogRead(0));
}

void loop()
{
    const int ledIdx = random(0, 30);
    const int red = random(0, 255);
    const int green = random(0, 255);
    const int blue = random(0, 255);
    const int delayMs = random(50, 200);
    setJustOneLED(ledIdx, CRGB(red, green, blue));
    delay(delayMs);
}
