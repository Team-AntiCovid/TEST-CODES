#include<Wire.h>
int x;
int echopin[] = {1,5,9,12};  
int trigpin[] = {2,6,10,13};
int vcc[] = {3,7,11};
int gnd[] = {0,4,8};
// defines variables
int SonarSensor( int trigpin, int vcc, int gnd, int echopin)
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  int Time = pulseIn(echopin, HIGH);
  int Distance = Time * 0.034 / 2;
  if (Distance < 60)
  return 1;
  else
  return 0;
  
}


void setup() {
  for (int thisPin = 0; thisPin < 4; thisPin++)
  {
    pinMode(trigpin[thisPin], OUTPUT);
    pinMode(echopin[thisPin], INPUT);
    pinMode(vcc[thisPin], OUTPUT);
    pinMode(gnd[thisPin], OUTPUT);
    digitalWrite(vcc[thisPin], HIGH);
    digitalWrite(gnd[thisPin], LOW);
  }
  Wire.begin(9);
  Wire.onRecieve(receiveEvent);
}
void receiveEvent(int bytes)
{
 x=Wire.read();
}
void loop() {
  // Clears the trigPin condition
  int sensors[] = {0,0,0,0};
  int sensor_slave = 0;
  int duration[] = {0,0,0,0};
  long distance[] = {0,0,0,0};
  
  sensors[0] = SonarSensor(trigpin[0], vcc[0], gnd[0], echopin[0]); 
  sensors[1] = SonarSensor(trigpin[1], vcc[1], gnd[1], echopin[1]); 
  sensors[2] = SonarSensor(trigpin[2], vcc[2], gnd[2], echopin[2]); 
  sensors[3] = SonarSensor(trigpin[3], vcc[3], gnd[3], echopin[3]); 
  
  if (sensors[0] == 1|| sensors[1] == 1|| sensors[2] ==1 || sensors[3] == 1)
  {
    sensor_slave = 1;
  }
  if (sensor_slave==1||x==1)
  {
  }
}
