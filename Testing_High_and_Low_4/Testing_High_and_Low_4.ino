#include "EncoderTM.h"
#include <Encoder.h>

#define CHN_A3 17 // Signal A (encoder A)
#define CHN_B3 18  // Signal B (encoder A)
#define Led 13  


int SamplingInterval=10; //Change this to determine the encoder sampling interval (ms)
float deg=0;
String degString;
float x_Value=0;
bool pinState ;  //Signal which tells if the reward value needs to be colected
                  //When Low the encoer ir read and the reward sum done
float cum_Sum=0;   //Reward acumulated value
int print_Flag=0;  //Once the pinSate goes to HIGH the acumulated value is printed

void setup() {

  pinMode(12, INPUT_PULLUP); 
  pinMode(11, INPUT); 
  pinMode(Led, OUTPUT); 
  
  Serial.begin(115200);
}

void loop() {
  //Serial.println("Hi");
/*deg = encoder3.read();  Serial.println(deg); */
  cum_Sum=0;
  pinState = digitalRead(12);  
  Encoder encoder3(CHN_A3, CHN_B3);

  while (pinState==LOW){
    digitalWrite(Led, HIGH);
    deg = encoder3.read();
    deg=Encoder_Lecture.Encoder_Lecture(deg); //Inside this function setup sign of deg depending on possitive treadmill direction
    //Serial.println(deg);   //Uncomment to print values being added while pin 12 is LOW
    cum_Sum=cum_Sum+deg;     //Current and all previus encoder values are addded (while pin 12 in LOW)
    delay(SamplingInterval); 
    pinState = digitalRead(12);
    //x_Value=pulseIn(11,HIGH);  //Uncomment to get values encoder spike esch 360° there is a spike (doing this takes a long time!)
    //Serial.println(x_Value);   //Uncomment to print values encoder spike esch 360° there is a spike (This will not be needed)
    print_Flag=1;   
  }
  if (print_Flag==1){
    digitalWrite(Led, LOW);
    //Serial.println(cum_Sum);//Uncomment this to see the cumulative reward value 
                            //(It should be enough with the value to which the leg move the treadmill)
    if (deg<0&&deg>-1000000)
  {
    deg=-deg;
    degString=String(deg);
    if (deg<10&&deg>0){degString="-00000"+degString;}
    if (deg<100&&deg>=10){degString="-0000"+degString;}
    if (deg<1000&&deg>=100){degString="-000"+degString;}
    if (deg<10000&&deg>=1000){degString="-00"+degString;}
    if (deg<100000&&deg>=10000){degString="-0"+degString;}    
    if (deg<1000000&&deg>=100000){degString="-"+degString;}
    Serial.println(degString);
    serial.flush()
    deg=-deg;
  }  

if (deg>=0&&deg<1000000) 
  {
    degString=String(deg);
    if (deg==0){degString="+00000"+degString;}
    if (deg<10&&deg>0){degString="+00000"+degString;}
    if (deg<100&&deg>=10){degString="+0000"+degString;}
    if (deg<1000&&deg>=100){degString="+000"+degString;}
    if (deg<10000&&deg>=1000){degString="+00"+degString;}
    if (deg<100000&&deg>=10000){degString="+0"+degString;}    
    if (deg<1000000&&deg>=100000){degString="+"+degString;}
    Serial.println(degString); 
    Serial.flush()
  }
    print_Flag=0;
  }
  
}

