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
#define PUMP 9
#define SPEAKER 11

#define NOTE_C4  262  
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

const int songSpeed = 1.5;

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

  playSong();
  while (true) ;
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
    // drink(guitar_check(arr[5]);
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

int duration[] = {         //duration of each note (in ms) Quarter Note is set to 250 ms
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  //Rpeat of First Part
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  //End of Repeat
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};

int notes[] = {       //Note of the song, 0 is a rest/pulse
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   //Repeat of first part
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //End of Repeat

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

void playSong() {
  for (int i=0;i<203;i++){              //203 is the total number of music notes in the song
    int wait = duration[i] * songSpeed;
    tone(SPEAKER,notes[i],wait);          //tone(pin,frequency,duration)
    delay(wait);
  } 
}

