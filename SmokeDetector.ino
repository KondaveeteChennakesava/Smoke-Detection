int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smoke = A5;int sensorThres = 100;

void setup() 
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int analogSensor = analogRead(smoke);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  //https://randomnerdtutorials.com/guide-for-mq-2-gas-smoke-sensor-with-arduino/
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}

