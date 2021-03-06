#include <wire.h>
int slaveAddress=9;
int echopin[] = {0,3,7,11}; 
int trigpin[] = {1,4,8,12};
int vcc[] = {5,9,13};
int gnd[] = {2,6,10};

// defines variables
int SonarSensor( int trigpin, int vcc, int gnd, int echopin)
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  int Time = pulseIn(echopin, HIGH);
  // Calculating the distance
  int Distance = Time * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
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
  Wire.begin();
  
}
void loop() {
  // Clears the trigPin condition
  int sensors[] = {0,0,0,0};
  int sensor_master = 0;
  int duration[] = {0,0,0,0};
  long distance[] = {0,0,0,0};
  
  
  sensors[0] = SonarSensor(trigpin[0], vcc[0], gnd[0], echopin[0]); 
  sensors[1] = SonarSensor(trigpin[1], vcc[1], gnd[1], echopin[1]); 
  sensors[2] = SonarSensor(trigpin[2], vcc[2], gnd[2], echopin[2]); 
  sensors[3] = SonarSensor(trigpin[3], vcc[3], gnd[3], echopin[3]); 
  
  if (sensors[0] == 1|| sensors[1] == 1|| sensors[2] ==1 || sensors[3] == 1)
  {
    sensor_master = 1;
  }
  
    if( sensor_master==1)
    {
    Wire.beginTransmission(9);
    Wire.write(1);
    Wire.endTransmission();
    }
else
{ 
  Wire.beginTransmission(9);
    Wire.write(0);
    Wire.endTransmission();
}
}
