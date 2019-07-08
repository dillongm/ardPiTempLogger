/* D Moravek
Temp logger using arduinoUNO + AM2302-DHT22 +PiZeroW
-acquire temp data using AM2302-DHT22 + arduinoUNO
-print data from UNO to 16x2 LCD
-send data to PiZeroW for logging

adafruit libraries used
*/

#include "DHT.h"
#include <LiquidCrystal.h>// include the library code


#define DHTPIN 2     // what digital pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

char array1[]=" SunFounder               ";  //the string to print on the LCD
char array2[]="hello, world!             ";  //the string to print on the LCD
int tim = 250;  //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);


void setup() 
{
  
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 

  dht.begin();
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\n");

  lcd.clear();

  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  
  lcd.print(f);
  lcd.print(" DEG F");
  
  lcd.setCursor(0,1);  // set the cursor to column 15, line 1

  lcd.print(h);
  lcd.print("% HUMIDITY");
  
  //delay(2500);
  
 // lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
}
