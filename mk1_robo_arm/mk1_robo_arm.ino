#include <Servo.h>
Servo gripservo;
Servo baseservo;
Servo updownservo;
Servo forwardservo;

int gripservo_value = 10;
int baseservo_value = 1;
int updownservo_value = 90;
int forwardservo_value = 90;
boolean is_grip_open = false;

int multiplierSpeed = 10;
int multiplierDifference = -2;

void setup() 
{
  gripservo.attach( A0 );
  baseservo.attach( A1 );
  forwardservo.attach( A2 );
  updownservo.attach( A3 );
  
  Serial.begin(9600);
}


void loop()
{

  int a4value = analogRead( A4 );
  int a5value = analogRead( A5 );
  int a6value = analogRead( A6 );
  int a7value = analogRead( A7 );

  Serial.print( " a4value= " );
  Serial.print( a4value );
  Serial.print( " a5value= " );
  Serial.print( a5value );
  Serial.print( " a6value= " );
  Serial.print( a6value );
  Serial.print( " a7value= " );
  Serial.println( a7value );

//  delay( 1000 );
  
  if ( Serial.available() > 0 ) {
    char keypressed = Serial.read();
    
    if ( keypressed == 'U' ) {
        updownservo_value += multiplierSpeed;
        
        if ( updownservo_value > 180 ) {
          updownservo_value = 160;
        }
    } else if ( keypressed == 'D' ) {
        updownservo_value -= multiplierSpeed;
        
        if ( updownservo_value < 50 ) {
          updownservo_value = 0;
        }
        
    } else if ( keypressed == 'L' ) {
        baseservo_value += multiplierSpeed;
        
        if ( baseservo_value > 180 ) {
          baseservo_value = 180;
        }
    } else if ( keypressed == 'R' ) {
        baseservo_value -= multiplierSpeed;
        
        if ( baseservo_value < 0 ) {
          baseservo_value = 0;
        }
    } else if ( keypressed == 'K' ) {
        forwardservo_value += multiplierSpeed;
        
        if ( forwardservo_value > 180 ) {
          forwardservo_value = 180;
        }
    } else if ( keypressed == 'H' ) {
        forwardservo_value -= multiplierSpeed;
        
        if ( forwardservo_value < 90 ) {
          forwardservo_value = 90;
        }
    } else if ( keypressed == 'S' ) {
      if ( is_grip_open ) {
        is_grip_open = false;
      } else {
        is_grip_open = true;
      }
    } else if ( keypressed == 'T' ) {
      multiplierSpeed += multiplierDifference;
      
      if ( multiplierSpeed < 0 ) {
        multiplierSpeed = 1;
        multiplierDifference = -multiplierDifference;
      }

      if ( multiplierSpeed > 10 ) {
        multiplierSpeed = 10;
        multiplierDifference = -multiplierDifference;
      }
    }
  }
//
//  Serial.print( "baseservo_value= " );
//  Serial.print( baseservo_value );
//  
//  Serial.print( " updownservo_value= " );
//  Serial.print(  updownservo_value );
//  
//  Serial.print( " forwardservo_value= " );
//  Serial.print( forwardservo_value );
//  
//  Serial.print( " multiplierSpeed= " );
//  Serial.print( multiplierSpeed );
//  
//  Serial.print( " multiplierDifference= " );
//  Serial.println( multiplierDifference );
  
  if ( is_grip_open ) {
    gripservo_value = 40;
  } else {
    gripservo_value = 10;
  }
  
  gripservo.write( gripservo_value );
  baseservo.write( baseservo_value );
  forwardservo.write( forwardservo_value );
  updownservo.write( updownservo_value );
  
  delay( 10 );
}
