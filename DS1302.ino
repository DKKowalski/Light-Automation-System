#include <virtuabotixRTC.h>


#define LEDPin 13
//creation of the Real Time Clock Object
virtuabotixRTC myRTC(6,7,8);
char Incoming_value = 0;                //Variable for storing Incoming_value

void setup() {
  // put your setup code here, o run once:
  Serial.begin(9600);

  pinMode(LEDPin,OUTPUT);
  myRTC.setDS1302Time(00, 59, 23, 3, 6, 9, 2021);
  

}

void loop() {

   bluetooth();
   delay(500);
 clockRTC();



 

}


void clockRTC(){
  
  
  myRTC.updateTime();
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);



  


  if (myRTC.seconds == 30 && myRTC.minutes == 59){
    digitalWrite(LEDPin, HIGH);
    }else if(myRTC.seconds == 00 && myRTC.minutes == 1)  {
      digitalWrite(LEDPin, LOW);
      }
  }

void bluetooth(){

if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
      digitalWrite(LEDPin, HIGH);  //If value is 1 then LED turns ON
    else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      digitalWrite(LEDPin, LOW);   //If value is 0 then LED turns OFF
  }                            
  
}

 
