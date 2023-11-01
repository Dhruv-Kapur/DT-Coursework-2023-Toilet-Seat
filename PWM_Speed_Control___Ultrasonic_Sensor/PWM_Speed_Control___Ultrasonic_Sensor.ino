//Arduino PWM Speed Control with Ultrasonic Sensor：
int E1 = 5;
int M1 = 4;
int E2 = 6;                    
int M2 = 7;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
    pinMode(M1, OUTPUT);  
    pinMode(M2, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance >= 100) {
    int value;
    for(value = 0 ; value <= 255; value+=1)
    { 
      digitalWrite(M1,HIGH);  
      digitalWrite(M2,HIGH);      
      analogWrite(E1, value);   //PWM Speed Control
      analogWrite(E2, value);   //PWM Speed Control
      delay(30);
    }
  }
}
