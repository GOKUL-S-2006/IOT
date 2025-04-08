int pirPin = 2;      // PIR sensor output pin
int ledPin = 13;     // Onboard LED or external LED pin
int pirState = LOW;  // To track PIR state
int val = 0;         // To store the PIR pin state

void setup() {
  pinMode(pirPin, INPUT);   // PIR as input
  pinMode(ledPin, OUTPUT);  // LED as output
  Serial.begin(9600);       // For debugging
}

void loop() {
  val = digitalRead(pirPin);  // Read PIR state

  if (val == HIGH) {          // If motion is detected
    digitalWrite(ledPin, HIGH); // Turn on LED

    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH; // Update state
    }

  } else {
    digitalWrite(ledPin, LOW); // Turn off LED

    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW; // Update state
    }
  }

  delay(100); // Small delay to avoid bouncing
}
