
#define heartratePin D0 
#include "DFRobot_Heartrate.h"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>   //including the library of SimpleTimer

DFRobot_Heartrate heartrate(DIGITAL_MODE); 

SimpleTimer timer;
char auth[] = " 33ab7b734aa249ee93d7c91a131db36b";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "3Engineer,s";    // Your WiFi credentials.
char pass[] = "1122334455";  // Set password to "" for open networks.

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000, sendUptime);

}

void sendUptime()
{
  
  uint8_t rateValue;
  heartrate.getValue(heartratePin); ///< A1 foot sampled values
  rateValue = heartrate.getRate(); ///< Get heart rate value 
  if(rateValue)  {
    Serial.println(rateValue);
    Blynk.virtualWrite(V0,rateValue);
  }
  delay(20);
  
}
void loop() {

  Blynk.run();
  timer.run();
 
}


