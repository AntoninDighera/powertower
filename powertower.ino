#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN     6              // Which pin on the Arduino is connected to the NeoPixels?
#define LED_COUNT  15              // How many NeoPixels are attached to the Arduino?
#define BRIGHTNESS 50              // NeoPixel brightness, 0 (min) to 255 (max)

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);  
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// the setup routine runs once when you press reset:
void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(9600);      // initialize serial communication at 9600 bits per second:
}

void loop() {
  // read the input on analog pin 0:
  //int sensorValue = analogRead(A0);
  
  graphSegTest(0, 10);
  graphSegTest(1, 50);
  graphSegTest(2, 100);
  graphSegTest(3, 150);
  graphSegTest(4, 200);
  graphSegTest(5, 250);
  graphSegTest(6, 300);
  graphSegTest(7, 350);
  graphSegTest(8, 400);
  graphSegTest(9, 450);
  graphSegTest(10, 500);
  graphSegTest(11, 550);
  graphSegTest(12, 600);
  graphSegTest(13, 650);
  graphSegTest(14, 700);
}

//Function for turning on and off *GREEN* LED bar meter segments(a=lowest value, i=LED #1, j=LED #2)
void graphSegTest(int i, int a)          
{
  int sensorValue = analogRead(A0);
  if(sensorValue > a)
  {
    strip.setPixelColor(i, 0, 255, 0);     //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
  }
  else
  {
    strip.setPixelColor(i, 0,0,0);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match 
  }
  Serial.println(sensorValue);
}
////Function for turning on and off *GREEN* LED bar meter segments(a=lowest value, b=highest value, i=LED #1, j=LED #2)
//void graphSegGrn(int i, int j, int a, int b)          
//{
//  if(sensorValue > i &&  <= j;)
//  {
//     strip.setPixelColor(i, 0, 255, 0);         //  Set pixel's color (in RAM)
//     strip.setPixelColor(j, 0, 255, 0);         //  Set pixel's color (in RAM)
//     strip.show();                          //  Update strip to match
//  }
//  else()
//  {
//   strip.setPixelColor(i, 0,0,0);         //  Set pixel's color (in RAM)
//   strip.setPixelColor(j, 0,0,0);         //  Set pixel's color (in RAM)
//   strip.show();                          //  Update strip to match 
//  }
  
