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
}

void loop()
{
    for (int ledIdx = 0; ledIdx < NUM_LEDS; ledIdx++)
    {
        setJustOneLED(ledIdx, CRGB::Red);
        delay(50);
    
        setJustOneLED(ledIdx, CRGB::Green);
        delay(50);
    
        setJustOneLED(ledIdx, CRGB::Blue);
        delay(50);
    }

    for (int ledIdx = NUM_LEDS; ledIdx >= 0; ledIdx--)
    {
        setJustOneLED(ledIdx, CRGB::Red);
        delay(50);
    
        setJustOneLED(ledIdx, CRGB::Green);
        delay(50);
    
        setJustOneLED(ledIdx, CRGB::Blue);
        delay(50);
    }
}
