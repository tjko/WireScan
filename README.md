# WireScan

**WireScan** is very small library for scanning I2C bus.
It can be used to display devices currently connected to the bus, which
can be helpful to do dugin **setup()**. 

License: GPL3


## Library Installation

1. Download the ZIP file (rename it to "WireScan.zip" if needed)
2. From the Arduino IDE select: Scketch -> Include Library... -> Add .ZIP Library...
3. Restart the IDE to see new library "WireScan" and examples for it

## Usage Examples

Typical usage for this library is to scan I2C bus when Arduino boots, to help diagnose
that everything is connected correctly, etc...


Usage with **Serial** library:

  #include <Wire.h>
  #include <WireScan.h>

  ...


  void setup(void)
  {
     Serial.begin(9600);
     Wire.begin();

     WireScan.scan(Serial);

  }

  ...


Usage with **SoftwareSerial** library:


   #include <SoftwareSerial.h>
   #include <Wire.h>
   #include <WireScan.h>



   void setup(void)
   {
      Serial.begin(9600);
      Wire.begin();

      WireScan.scan(Serial);

   }


This library has very small foot print and shouldnt really affect availablre memory for the scketch.



