int sensorPin = A0;     // Analog pin connected to sensor's A0
int ledPin = 13;        // LED pin for dry soil alert
int sensorValue = 0;    // To store analog value

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Read analog value from sensor

  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue);

  // Dry soil typically gives higher values (~700-1023)
  // Wet soil gives lower values (~300-600)

  if (sensorValue > 700) {  // Change threshold as needed
    digitalWrite(ledPin, HIGH);  // Soil is dry – turn on LED
    Serial.println("Soil is dry!");
  } else {
    digitalWrite(ledPin, LOW);   // Soil is moist – LED off
    Serial.println("Soil is moist.");
  }

  delay(1000); // Wait for 1 second before next reading
}
