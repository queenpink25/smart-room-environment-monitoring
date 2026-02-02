# smart-room-environment-monitoring
Embedded system for monitoring temperature and light intensity using Arduino, with automatic alerts and serial output simulation in Tinkercad.

System Structure
Smart-Room-Monitoring/
│── smart_room.ino
│── circuit_screenshot.png
│── README.md

<img width="1536" height="606" alt="Cool Jaiks" src="https://github.com/user-attachments/assets/9011ae63-c440-4976-aa1d-6087b106b4de" />


# Smart Room Monitoring System

## What It Does
- Monitors room temperature and light
- Turns RED LED ON when temperature > 28°C
- Turns BLUE LED ON when room is dark
- Shows values on Serial Monitor

## Components Needed
1. Arduino Uno
2. LM35 Temperature Sensor
3. LDR (Light Sensor)
4. Red LED + Blue LED
5. 220Ω Resistors (2)
6. 10kΩ Resistor (1)
7. Breadboard + Wires

## How to Connect

### LM35 Sensor:
- Left pin → 5V
- Middle pin → A0
- Right pin → GND

### LDR Sensor:
- One leg → 5V
- Other leg → A1 AND to GND via 10kΩ resistor

### LEDs:
- Red LED: + → Pin 7 → 220Ω → GND
- Blue LED: + → Pin 8 → 220Ω → GND

### HOW TO TEST: 
Test 1: Normal Room
What to do: Nothing (just wait)
What happens:
• Serial shows: TEMP: 25.0C LIGHT: 300
• Both LEDs: OFF

Test 2: Hot Room
1. Click on LM35 sensor
2. Drag temperature slider ABOVE 28°C
3. See: Red LED turns ON
4. Serial shows: TEMP: 30.0C LIGHT: 300
   
Test 3: Dark Room  
1. Click on LDR/Photoresistor
2. Drag light slider to DARK side (moon icon)
3. When number goes above 400 → Blue LED turns ON
4. Serial shows: TEMP: 25.0C LIGHT: 450
   
Test 4: Hot & Dark Room 
1. Set temperature > 28°C
2. Set light > 400
3. See: Both LEDs ON
4. Serial shows: TEMP: 30.0C LIGHT: 500

## Arduino Code
```cpp
/* SMART ROOM SYSTEM */
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


}
