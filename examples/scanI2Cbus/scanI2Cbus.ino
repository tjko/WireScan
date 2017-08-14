// Example of WireScan usage

#include <Wire.h>
#include <WireScan.h>


void setup(void)
{
  Serial.begin(9600);
  while (!Serial) {
      delay(1);	
  }

  Serial.println("Booting...");
   
  Wire.begin();
  WireScan.scan(&Serial);
  
}



void loop(void)
{
  Serial.println("Doing something...");
  delay(5000);
}
