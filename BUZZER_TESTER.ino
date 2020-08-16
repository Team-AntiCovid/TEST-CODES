
// ////////////////////////////////////////// CODE FOR TESTING PIEZO BUZZER USING IR SENSOR /////////////////////////////////

int buzzer=8;                       //POSITIVE PIN OF BUZZER IS CONNECTED TO PIN 8

int sign=2;                         //VARIABLE TO STORE STATE OF PIN

void setup() {
 
  pinMode(buzzer,OUTPUT);
  pinMode(sign,INPUT);

}

void loop() {
  int a=digitalRead(sign);
  if(a==0){
      tone(buzzer,2500,200);          //(PIN,FREQUENCY,TIME FOR WHICH BUZZER WILL SOUND)
      delay(400);                     //ACTUAL DELAY IS (400-200)=200ms, THIS PRODUCES A BEAT EFFECT
  }
  else
      digitalWrite(buzzer,LOW);
  

}
