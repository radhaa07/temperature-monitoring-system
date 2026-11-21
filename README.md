# temperature-monitoring-system
Temperature Monitoring System (Arduino, C/C++)

A sensor-based temperature monitoring and alert system built on an Arduino Uno and simulated in Wokwi. It reads temperature from a DHT22 sensor, logs values over serial, and turns on an LED and buzzer when the temperature goes above a set threshold.

Live simulation: [YOUR_WOKWI_PROJECT_LINK]

Circuit diagram

Features
  
-Reads temperature from a DHT22 sensor every 2 seconds

-Prints readings to the Serial Monitor (9600 baud)

-Turns on an LED and sounds a buzzer when the temperature exceeds 35 °C

-Turns the alert off automatically when the temperature drops back to normal

-Handles failed sensor reads without crashing (isnan() check)

Components
|Component	             |Quantity |	Purpose|
------------------------ |-------- |----------|
|Arduino Uno             |	1	     | Microcontroller
|DHT22 temperature sensor|	1	     |Measures temperature
|Red LED	               |1	       |Visual alert
|220 Ω resistor	         |1	       |Limits current through the LED
|Buzzer	                 |1        |	Audible alert

Pin connections

|From                     |To |
------------------------  |-------- |
|DHT22 VCC                |		Arduino 5V     
|DHT22 SDA            |	Arduino pin 2
|DHT22 GND	              |	Arduino GND	      
|Arduino pin 8	          |220 Ω resistor, then LED anode (+)      
|LED cathode (−)          |Arduino GND       |	
|Buzzer positive (+)      |Arduino pin 9|
|Buzzer negative (−)      |	Arduino GND|


How it works

1. setup() starts serial communication, sets the LED and buzzer pins as outputs, and starts the DHT22 sensor.
2. loop() reads the temperature. If the read fails, it prints an error message and tries again.
3. If the temperature is above the threshold (35 °C), the LED turns on and the buzzer plays a 1 kHz tone.
4. Otherwise, the LED and buzzer are switched off.
5. A 2-second delay keeps reads within the DHT22's sampling limit.

The threshold can be changed by editing the THRESHOLD value at the top of sketch.ino.

How to run
1. Open the Wokwi project link above.
2. Click the green play button.
3. Open the Serial Monitor to see temperature readings.
4. Click the DHT22 sensor and drag the temperature slider above 35 °C. The LED lights up and the buzzer sounds.

To run it in your own Wokwi project, create an Arduino Uno project, add the parts listed above, wire them as in the table, add the DHT sensor library (by Adafruit) in the Library Manager, and paste in sketch.ino.

Tech used

- C (Arduino)
- Arduino Uno
- DHT sensor library (Adafruit)
- Wokwi simulator

Future improvements

- Add a second threshold with a different alert pattern (for example, a blinking LED above 40 °C)
- Add an LCD display to show the live temperature
- Log readings over time
- Build and test on physical hardware

Note

This project was built and tested in the Wokwi simulator, not on physical hardware.
