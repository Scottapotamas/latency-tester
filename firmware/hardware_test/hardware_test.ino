#include <Adafruit_DotStar.h>
#include <SPI.h>

#define PIN_BUTTON 2
#define PIN_PHOTOSENSE 0
#define PIN_STATUS 13

#define PIN_RGB_DATA   7
#define PIN_RGB_CLOCK  8
#define NUM_PIXELS 2

Adafruit_DotStar strip = Adafruit_DotStar( NUM_PIXELS, PIN_RGB_DATA, PIN_RGB_CLOCK, DOTSTAR_BRG );

void setup_pins()
{
  pinMode( PIN_BUTTON,      INPUT_PULLUP  );
  pinMode( PIN_PHOTOSENSE,  INPUT         );
  pinMode( PIN_STATUS,      OUTPUT        );

  //use the full capability of the ARM M0 ADC
  analogReadResolution(12); 
}

void setup()
{
  Serial.begin(115200);

  setup_pins();
  
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

uint8_t  hue = 0;

uint16_t light_adc = 0;
bool button_pressed = 0;

void loop()
{
  // Sample inputs
  light_adc       = analogRead( PIN_PHOTOSENSE );
  button_pressed  = !digitalRead( PIN_BUTTON );
  
  //turn the status led on when the button is pressed
  digitalWrite( PIN_STATUS, !button_pressed );
  
  if( button_pressed )
  {
    hue += 15; //abuse the fact that it rolls over
  }
  // run the two leds 180deg out of phase
  strip.setPixelColor(0, Wheel(hue));
  strip.setPixelColor(1, Wheel(hue));

  strip.show(); 
  delay(50);
}

// Hue transition on a 8-bit position value, returns RGB
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  
  if(WheelPos < 85) 
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  
  if(WheelPos < 170) 
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}