const int mq2Pin = A0;          // Analog pin for MQ2 sensor
const int ledPin = 13;          // Optional: Built-in LED to indicate smoke

int sensorValue = 0;            // Variable to store sensor value
int threshold = 300;            // Adjust this threshold based on testing

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(mq2Pin);  // Read MQ2 analog value

  Serial.print("MQ2 Sensor Value: ");
  Serial.println(sensorValue);

  // Check if smoke/gas is detected
  if (sensorValue > threshold) {
    Serial.println("⚠️ Smoke/Gas Detected!");
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  delay(1000); // Read every second
}
