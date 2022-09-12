

//Declare variables
int Motor1=8;
int Motor2=9;
int Motor3=10;
int Motor4=11;
//Declare string value for store input value
String data;
int S1=2;//S1 Mean sensor 1 and its a Right side sensor
int S2=3;//S2 Mean sensor 2 and its a Left side sensor
void setup() {
 //select pinmode output
 pinMode(Motor1,OUTPUT);
 pinMode(Motor2,OUTPUT);
 pinMode(Motor3,OUTPUT);
 pinMode(Motor4,OUTPUT);
 //serial start for serial communication
 Serial.begin(9600);
}

void loop() {
  Line();
  if (Serial.available())
   { 
    
    data=Serial.readString();
    data.toLowerCase();
    Serial.println(data);
    if (data == "forward")
    {
      Move_Forward();
      delay(4000);
      Stop();
      }
      
    else if (data =="backward")
    { 
      Move_Backward();
      delay(4000);
      Stop();      
      }
      
    else if (data =="right")
    {
      Trun_Right();
      delay(2000);
      Stop();      
      }
     else if (data =="left")
    {
      Trun_Left();
      delay(2000);
      Stop();      
      }
      else if (data =="stop")
    {
      Stop();
      }
}
}

void Move_Forward(){
      digitalWrite(Motor1,HIGH);
      digitalWrite(Motor2,LOW);
      digitalWrite(Motor3,LOW);
      digitalWrite(Motor4,HIGH);
      

}
void Move_Backward(){
      digitalWrite(Motor1,LOW);
      digitalWrite(Motor2,HIGH);
      digitalWrite(Motor3,HIGH);
      digitalWrite(Motor4,LOW);
      
}

void Trun_Right(){
      digitalWrite(Motor1,LOW);
      digitalWrite(Motor2,HIGH);
      digitalWrite(Motor3,LOW);
      digitalWrite(Motor4,HIGH);
   
}
void Trun_Left(){
      digitalWrite(Motor1,HIGH);
      digitalWrite(Motor2,LOW);
      digitalWrite(Motor3,HIGH);
      digitalWrite(Motor4,LOW);
 
}
void Stop(){
      digitalWrite(Motor1,LOW);
      digitalWrite(Motor2,LOW);
      digitalWrite(Motor3,LOW);
      digitalWrite(Motor4,LOW);
    
  
}
void Line(){
  if (S1 == 1 and S2 == 1)
    Move_Forward();
  else if (S1 == 0 and S2 == 1)
    Turn_Rght();
  else if (S1 == 1 and S2 == 0)
    Turn_Left();
  else if (S1 == 0 and S2 == 0)
    Stop();
     
  
}
