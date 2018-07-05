#include "PROGMEMread.h"
#include <FastLED.h>
#include "LEDdriver.h"

//Define the number of leds in the strip, should be 5x13
#define NUM_LEDS 65
#define DATA_PIN 3

//guitar buttons
#define GREEN_BUT 2
#define RED_BUT 4
#define YELLOW_BUT 7
#define BLUE_BUT 8
#define ORANGE_BUT 12
#define STRUM 13
#define PUMP 11
#define SPEAKER 9

#define  c3    7634
#define  d3    6803
#define  e3    6061
#define  f3    5714
#define  g3    5102
#define  a3    4545
#define  b3    4049
#define  c4    3816    // 261 Hz 
#define  d4    3401    // 294 Hz 
#define  e4    3030    // 329 Hz 
#define  f4    2865    // 349 Hz 
#define  g4    2551    // 392 Hz 
#define  a4    2272    // 440 Hz 
#define  a4s   2146
#define  b4    2028    // 493 Hz 
#define  c5    1912    // 523 Hz
#define  d5    1706
#define  d5s   1608
#define  e5    1517    // 659 Hz
#define  f5    1433    // 698 Hz
#define  g5    1276
#define  a5    1136
#define  a5s   1073
#define  b5    1012
#define  c6    955
 
#define  R     0      // Rest

// Melody 1: Star Wars Theme
int melody1[] = {  f4,  f4, f4,  a4s,   f5,  d5s,  d5,  c5, a5s, f5, d5s,  d5,  c5, a5s, f5, d5s, d5, d5s, c5};
int beats1[]  = {  21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128}; 

long tempo = 10000; // Set overall tempo
int pause = 1000; // Set length of pause between notes
int rest_count = 50; // Loop variable to increase Rest length (BLETCHEROUS HACK; See NOTES)

// Define the array of leds
CRGB leds[NUM_LEDS];

//arrays to determine which row to light up
bool note_all[5]={true,true,true,true,true};
bool note_A[5]={true,false, false, false, false};
bool note_B[5]={false, true, false, false, false};
bool note_C[5]={false, false, true, false, false};
bool note_D[5]={false, false, false, true, false};
bool note_E[5]={false, false, false, false, true};

//colours in hex RED = 0x00FF00 BLUE = 0x0000FF GREEN = 0xFF0000 ORANGE = 0x35FF00 YELLOW = 0xA0FF00 BLACK = 0x000000


void setup() {

  //Initializing the LED strips
  // NOTE: LEDs are not orderd in RGB, they are acting as GRB
  // Colour selection should be done in hex 0xGGRRBB

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  pinMode(GREEN_BUT, INPUT);
  pinMode(RED_BUT, INPUT);
  pinMode(YELLOW_BUT, INPUT);
  pinMode(BLUE_BUT, INPUT);
  pinMode(ORANGE_BUT, INPUT);
  pinMode(STRUM, INPUT);
  pinMode(PUMP, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  playMelody();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  show_green();
  show_red();
  show_yellow();
  show_blue();
  show_orange();*/
 
  show_LED(note_all);
  show_LED(note_A);
  show_LED(note_C);
}

//lights up rows
void show_LED(bool arr[5])
{
  //check if rows grybo are expected on from bool array
  for(int i=0; i<13; i++)
  {
    if(arr[0]==true){
    leds[i]=0xFF0000; //assign 0-12 to green
  }
  if(arr[1]==true)
  {
    leds[i+13]=0x00FF00; //assign 13-25 to red
  }
  if(arr[2]==true)
  {
    leds[i+26]=0xA0FF00; //assign 26-38 to yellow
  }
  if(arr[3]==true)
  {
    leds[i+39]=0x0000FF; //assign 39-51 to blue
  }
  if(arr[4]==true)
  {
    leds[i+52]=0x35FF00; //assign 52-64 orange
  }
  FastLED.show(); //turn lights on
  
  delay(100);

   if(i=12)
  {
    //verify if guitar note was played
     drink(guitar_check(arr[5]);
  }
 
  //reset all to black
  for(int i=0; i<65; i++)
  {
    leds[i]=0x000000;
  }
  FastLED.show();
  }
}

//pump on
void drink(bool note_played)
{
  //1 ms to play note
  delay(100);

  //check if the argument is false, and if it is, drink up bitch
  if(!note_played)
    {
      digitalWrite(PUMP, HIGH);
    }
  delay(30);
  digitalWrite(PUMP, LOW);
}

//check if buttons pressed
bool guitar_check(bool note[5])
{
  bool temp[5];
  bool flag;
  temp[0]= button_check(GREEN_BUT);
  temp[1]= button_check(RED_BUT);
  temp[2]= button_check(YELLOW_BUT);
  temp[3]= button_check(BLUE_BUT);
  temp[4]= button_check(ORANGE_BUT);

  for(int i=0; i<5; i++)
  {
    if(temp[i]==note[i] && button_check(STRUM))
      flag = true;
    else flag = false;
  }
  return flag;
}


//button return
bool button_check(int button)
{
  if(button==HIGH)
    return true;
  else
    return false;
}

void show_red()
{
  //chain leds in red row
  for(int i=13;i<=25; i++)
  {
   
      leds[i]=0x00FF00; //set to red
      FastLED.show();
      delay(100);
      leds[i]=0x000000; //reset to black
      FastLED.show();
     
  }
}

void show_green()
{
  //chain leds in red row
  for(int i=0;i<=12; i++)
  {
    
      leds[i]=0xFF0000; //set to green
      FastLED.show();
      delay(100);
      leds[i]=0x000000; //reset to black
      FastLED.show();
   
  }
}

void show_blue()
{
  //chain leds in red row
  for(int i=39;i<=51; i++)
  {
    
      leds[i]=0x0000FF; //set to blue
      FastLED.show();
      delay(100);
      leds[i]=0x000000; //reset to black
      FastLED.show();  
  }
}

void show_yellow()
{
  //chain leds in red row
  for(int i=26;i<=38; i++)
  {
      leds[i]=0xA0FF00; //set to yellow
      FastLED.show();
      delay(100);
      leds[i]=0x000000; //reset to black
      FastLED.show(); 
  }
}

void show_orange()
{
  //chain leds in red row
  for(int i=52;i<=64; i++)
  {
    
      leds[i]=0x35FF00; //set to orange
      FastLED.show();
      delay(100);
      leds[i]=0x000000; //reset to black
      FastLED.show();
  
  }
}

void playTone(int toneM, int beat, long duration) {
  long elapsed_time = 0;
  if (toneM > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
 
      digitalWrite(SPEAKER,HIGH);
      delayMicroseconds(toneM / 2);
 
      // DOWN
      digitalWrite(SPEAKER, LOW);
      delayMicroseconds(toneM / 2);
 
      // Keep track of how long we pulsed
      elapsed_time += (toneM);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}

void playMelody() {
    for (int i=0; i<(sizeof(melody1)/sizeof(int)); i++) {
      int toneM = melody1[i];
      int beat = beats1[i];
 
      long duration = beat * tempo; // Set up timing
 
      playTone(toneM, beat, duration); // A pause between notes
      delayMicroseconds(pause);
    }
}

