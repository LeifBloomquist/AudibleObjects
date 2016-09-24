
void setup() 
{
  Serial.begin(38400);
}

void loop() 
{
  int sensorValueX = analogRead(A0);
  int sensorValueY = analogRead(A1);
  int sensorValueZ = analogRead(A2);

  /*
  Serial.print(sensorValueX);
  Serial.print("   ");
  Serial.print(sensorValueY);
  Serial.print("   ");
  Serial.print(sensorValueZ);
  Serial.print("   ");
  Serial.println();
  */

  float scaled = Scale(sensorValueZ, 400, 600);
  byte scaled_cc = scaled*127;

  sendMIDI(0xB1, 20, scaled_cc);
  delay(10);
}

void sendMIDI(byte cmd, byte data1, byte data2)
{
   Serial.write(cmd);
   Serial.write(data1);
   Serial.write(data2);
}

// Scale one of the inputs to between 0.0 and 1.0
float Scale(long in, long smin, long smax)
{
  // Bound
  if (in > smax) in=smax;
  if (in < smin) in=smin;
  
  // Change zero-offset
  in = in-smin;
  
  // Scale between 0.0 and 1.0    (0.5 would be halfway)
  float temp = (float)in/((float)smax-(float)smin);
  return temp;   
}

