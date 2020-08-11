#include "FastLED.h"

// An hourglass contains 30 LEDs
#define NUM_LEDS 30

// Define the pin on your MCU board, which is connected to the "DIN" on the hourglass board
#define DATA_PIN 0

CRGB leds[NUM_LEDS];

void setAllLEDs(CRGB colour)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = colour;
    }
    FastLED.show();
}

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
    const int dimValue = 5;

    setAllLEDs(CRGB(dimValue, 0, 0)); // Dim red
    delay(1000);

    setAllLEDs(CRGB(0, dimValue, 0)); // Dim green
    delay(1000);

    setAllLEDs(CRGB(0, 0, dimValue)); // Dim blue
    delay(1000);
}
