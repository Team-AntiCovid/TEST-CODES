// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

int echopin[] = {1,2,3,4}; // note: in this initialization, pin numbers are not as per the diagram shared 
int trigpin[] = {5,6,7,8};
int vcc[] = {9,10,11,12};
int gnd[] = {13,14,15,16};
// defines variables
int lalala( int trigpin, int vcc, int gnd, int echopin)
{
  digitalWrite(trigpin, LOW);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
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
  for (int thisPin = 0; thisPin < 4; thisPin++) {
    pinMode(trigpin[thisPin], OUTPUT);
    pinMode(echopin[thisPin], INPUT);
    pinMode(vcc[thisPin], OUTPUT);
    pinMode(gnd[thisPin], OUTPUT);
  }
}
void loop() {
  // Clears the trigPin condition
  int sensors[] = {0,0,0,0};
  int sensor_master = 0;
  int duration[] = {0,0,0,0};
  long distance[] = {0,0,0,0};
  /// code banao jo last me duration return kare.. sensor_outputs vale me value daalo 0 or 1.. fir second sensor ke iye nikalo 
  sensors[0] = lalala(trigpin[0], vcc[0], gnd[0], echopin[0]); 
  sensors[1] = lalala(trigpin[1], vcc[1], gnd[1], echopin[1]); 
  sensors[2] = lalala(trigpin[2], vcc[2], gnd[2], echopin[2]); 
  sensors[3] = lalala(trigpin[3], vcc[3], gnd[3], echopin[3]); 
  
  if (sensors[0] == 1|| sensors[1] == 1|| sensors[2] ==1 || sensors[3] == 1)
  {
    sensor_master = 1;
  }
}
