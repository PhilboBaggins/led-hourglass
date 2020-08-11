#include "FastLED.h"

// An hourglass contains 30 LEDs
#define NUM_LEDS 30

// Define the pin on your MCU board, which is connected to the "DIN" on the hourglass board
#define DATA_PIN 0

CRGB leds[NUM_LEDS];

CRGB HOURGLASS_COLOUR(5, 0, 0); // Dim red

//const int COUNTDOWN_SECS = 15;
const int COUNTDOWN_SECS = 60;

const int SECONDS_PER_PIXEL = COUNTDOWN_SECS / (NUM_LEDS / 2);

void setHourglass(int seconds)
{
    // Colour top half of hourglass
    for (int i = 0; i < NUM_LEDS / 2; i++)
    {
        if (i < seconds / SECONDS_PER_PIXEL)
            leds[i] = CRGB::Black;
        else
            leds[i] = HOURGLASS_COLOUR;
    }

    // Colour bottom half of hourglass
    for (int i = 0; i < NUM_LEDS / 2; i++)
    {
        if (i <= seconds / SECONDS_PER_PIXEL)
            leds[NUM_LEDS - 1 - i] = HOURGLASS_COLOUR;
        else
            leds[NUM_LEDS - 1 - i] = CRGB::Black;
    }

    FastLED.show();
}

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
    setHourglass(millis() / 1000 % COUNTDOWN_SECS);
    delay(100);
}

