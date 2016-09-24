
#define THRESHOLD 200

void setup() 
{
  Serial.begin(38400);
}

void loop() 
{

  
  int sensorValue = analogRead(A7);
  
  if (sensorValue > THRESHOLD)
  {
     //Serial.println(sensorValue);
     //return;

     int velocity = sensorValue-THRESHOLD;

     velocity = velocity * 4;

     if (velocity < 60) 
     {
        velocity = 60;
     }

     if (velocity > 127)
     {
        velocity = 127;
     }
     
     sendMIDI(0x90, 60, velocity);
     delay(10);
     
     sendMIDI(0x80, 60, velocity);
     delay(100);
  }
}

void sendMIDI(byte cmd, byte data1, byte data2)
{
   Serial.write(cmd);
   Serial.write(data1);
   Serial.write(data2);
}

