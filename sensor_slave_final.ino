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
  for (int thisPin = 4; thisPin < 8; thisPin++)
  {
    digitalWrite(vcc, HIGH);
    digitalWrite(gnd, LOW);
    pinMode(trigpin[thisPin], OUTPUT);
    pinMode(echopin[thisPin], INPUT);
    pinMode(vcc[thisPin], OUTPUT);
    pinMode(gnd[thisPin], OUTPUT);
  }
}
void loop() {
  // Clears the trigPin condition
  int sensors[] = {0,0,0,0};
  int sensor_slave = 0;
  int duration[] = {0,0,0,0};
  long distance[] = {0,0,0,0};
  
  sensors[4] = SonarSensor(trigpin[4], vcc[4], gnd[4], echopin[4]); 
  sensors[5] = SonarSensor(trigpin[5], vcc[5], gnd[5], echopin[5]); 
  sensors[6] = SonarSensor(trigpin[6], vcc[6], gnd[6], echopin[6]); 
  sensors[7] = SonarSensor(trigpin[7], vcc[7], gnd[7], echopin[7]); 
  
  if (sensors[4] == 1|| sensors[5] == 1|| sensors[6] ==1 || sensors[7] == 1)
  {
    sensor_slave = 1;
  }
}