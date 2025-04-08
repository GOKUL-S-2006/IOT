#define echoPin 2  // attach pin D2 Arduino to Echo of HC-SR04
#define trigPin 3  // attach pin D3 Arduino to Trig of HC-SR04

long duration;
int distance;      // distance in cm
float distanceInches; // distance in inches

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Distance measurement using Arduino Uno.");
  delay(500);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;
  distanceInches = distance / 2.54;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | ");
  Serial.print(distanceInches);
  Serial.println(" inches");

  delay(100);
}
