const int ALERT_LED_PIN = 8;    // Change this to your LED pin
const int ROOM_LED_PIN = 9;     // Change this to your LED pin
// ================================================

const int TEMP_PIN = A0;
const int LIGHT_PIN = A1;

void setup() {
  // Set LED pins - USE YOUR ACTUAL PINS HERE
  pinMode(ALERT_LED_PIN, OUTPUT);
  pinMode(ROOM_LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("System starting...");
  
  // Test LEDs
  Serial.print("Testing LED on pin ");
  Serial.println(ALERT_LED_PIN);
  digitalWrite(ALERT_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(ALERT_LED_PIN, LOW);
  
  Serial.print("Testing LED on pin ");
  Serial.println(ROOM_LED_PIN);
  digitalWrite(ROOM_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(ROOM_LED_PIN, LOW);
}

void loop() {
  // Read temperature
  int tempRaw = analogRead(TEMP_PIN);
  float voltage = tempRaw * (5.0 / 1024.0);
  float tempC = (voltage - 0.5) * 100.0;
  
  // Read light
  int lightVal = analogRead(LIGHT_PIN);
  
  // Control LEDs - USING YOUR PINS
  if (tempC > 28.0) {
    digitalWrite(ALERT_LED_PIN, HIGH);
  } else {
    digitalWrite(ALERT_LED_PIN, LOW);
  }
  
  if (lightVal < 500) {
    digitalWrite(ROOM_LED_PIN, HIGH);
  } else {
    digitalWrite(ROOM_LED_PIN, LOW);
  }
  
  // Display
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print("C | Light: ");
  Serial.print(lightVal);
  Serial.print(" | LED1: ");
  Serial.print(digitalRead(ALERT_LED_PIN));
  Serial.print(" | LED2: ");
  Serial.println(digitalRead(ROOM_LED_PIN));
  
  delay(2000);
}
