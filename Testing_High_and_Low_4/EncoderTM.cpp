
#include "Arduino.h"
#include "EncoderTM.h"

Get_Encoder_Lecture_Class::Get_Encoder_Lecture_Class(){
  
}


void Get_Encoder_Lecture_Class::SETUP(){
  pinMode(12, INPUT_PULLUP);  
}

void Get_Encoder_Lecture_Class::Start_Encoder(){

}

float Get_Encoder_Lecture_Class::Encoder_Lecture(float deg){

  float raw_degree = deg * (360.0 / 8192.0);
  return -raw_degree; //The sign is adjusted depending on the positive direction of the treadmill

}

Get_Encoder_Lecture_Class EncoderTM = Get_Encoder_Lecture_Class(); 

