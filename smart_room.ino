/* SMART ROOM SYSTEM */
/* SHOWS: TEMP: VALUE LIGHT: VALUE */

// PINS
int tempPin = A0;
int lightPin = A1;
int redLED = 7;
int blueLED = 8;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // READ TEMPERATURE
  int tempRead = analogRead(tempPin);
  float temp = tempRead * (500.0 / 1024.0);
  
  // READ LIGHT
  int light = analogRead(lightPin);
  
  // CONTROL RED LED (TEMP > 28)
  if(temp > 28.0) {
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);
  }
  
  // CONTROL BLUE LED (LIGHT > 400)
  if(light > 400) {
    digitalWrite(blueLED, HIGH);
  } else {
    digitalWrite(blueLED, LOW);
  }
  
  // DISPLAY VALUES
  Serial.print("TEMP: ");
  Serial.print(temp);
  Serial.print("C  LIGHT: ");
  Serial.println(light);
  
  delay(2000);
}
