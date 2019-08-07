/* D Moravek
Temp logger using arduinoUNO + AM2302-DHT22 +PiZeroW
-acquire temp data using AM2302-DHT22 + arduinoUNO
-print data from UNO to 16x2 LCD
-send serial data to PiZeroW for logging

adafruit libraries used
*/
#include <DHT.h>
//#include "DHT.humidity"
#include <LiquidCrystal.h>// include the library code


#define DHTPIN 2     // what digital pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

int tim = 250;  //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);


void setup() 
{
  
  Serial.begin(9600);
  Serial.println("test");
  
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 

  dht.begin();
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2500);

  // Reading temperature or humidity takes about 250 milliseconds
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tempCelsius = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float tempFahren = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(tempCelsius) || isnan(tempFahren)) 
  {
    Serial.println("failed to read from DHT");
    return;
  }

  // Serial.print("Humidity: ");
  // Serial.print(humidity);
  // Serial.print(" %\tempCelsius");
  // Serial.print("Temperature: ");
  // Serial.print(tempCelsius);
  // Serial.print(" *C ");
  // Serial.print(tempFahren);
  // Serial.print(" *tempFahren\n");
  Serial.println(String(tempFahren) + ',' + String(humidity));//example of serial: "80.96,50.20" 
  delay(1000); //maybe not needed
  Serial.flush(); //empty transmit buffer

  lcd.clear();

  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  
  lcd.print(tempFahren);
  lcd.print(" DEG F");
  
  lcd.setCursor(0,1);  // set the cursor to column 15, line 1

  lcd.print(humidity);
  lcd.print("% HUMIDITY");
}
