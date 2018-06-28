/*
#include "PROGMEMread.h"
#include <FastLED.h>


#ifndef LEDdriver_h
#define LEDdriver_h
#define NUM_LEDS 65
#define DATA_PIN 3
//FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
// NOTE: LEDs are not orderd in RGB, they are acting as GRB
// Colour selection should be done in hex 0xGGRRBB


class LEDdriver{

  CRGB* leds[NUM_LEDS];
  int data_pin;
  
  public:
  
  LEDdriver(CRGB*, int);

  void show_red();  // leds 13-25
  void show_green(); //leds 0-12
  void show_blue();  //leds 39-51
  void show_yellow(); //leds 26-38
  void show_orange(); //leds 52-64
}


LEDdriver::LEDdriver(CRGB list[NUM_LEDS], DATA_PIN)
{
  for(int i=0;i<65;i++)
  {
    leds[i]=list[i];
  }
  data_pin=3;
}

void LEDdriver::show_red()
{
  //chain leds in red row
  for(int i=13;i<=25; i++)
  {
    if(i!=25)
    {
      leds[i]=0x00FF00; //set to red
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=25)
    {
      leds[i]=0x00FF00; //set to red
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}

void LEDdriver::show_green()
{
  //chain leds in red row
  for(int i=0;i<=12; i++)
  {
    if(i!=12)
    {
      leds[i]=0xFF0000; //set to green
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=12)
    {
      leds[i]=0xFF0000; //set to green
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}

void LEDdriver::show_blue()
{
  //chain leds in red row
  for(int i=39;i<=51; i++)
  {
    if(i!=51)
    {
      leds[i]=0x0000FF; //set to blue
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=51)
    {
      leds[i]=0x0000FF; //set to blue
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}

void LEDdriver::show_red()
{
  //chain leds in red row
  for(int i=13;i<=25; i++)
  {
    if(i!=25)
    {
      leds[i]=0x00FF00; //set to red
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=25)
    {
      leds[i]=0x00FF00; //set to red
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}

void LEDdriver::show_yellow()
{
  //chain leds in red row
  for(int i=26;i<=38; i++)
  {
    if(i!=38)
    {
      leds[i]=0xFFFF00; //set to yellow
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=38)
    {
      leds[i]=0xFFFF00; //set to yellow
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}

void LEDdriver::show_orange()
{
  //chain leds in red row
  for(int i=52;i<=64; i++)
  {
    if(i!=64)
    {
      leds[i]=0xA5FF00; //set to orange
      FASTled.show();
      delay(30);
      leds[i]=0x000000; //reset to black
    }
    if(i=64)
    {
      leds[i]=0xA5FF00; //set to orange
      FASTled.show();
      delay(60); //hold last for longer
      leds[i]=0x000000; //reset to black
    }
  }
}
#endif */
