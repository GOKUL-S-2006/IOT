const int buzzerPin = 9;  // Connect buzzer to digital pin 9

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzerPin, HIGH); // Turn buzzer on
  delay(1000);                   // Wait 1 second
  digitalWrite(buzzerPin, LOW);  // Turn buzzer off
  delay(1000);                   // Wait 1 second
}
