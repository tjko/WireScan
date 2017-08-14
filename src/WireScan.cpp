/*
 * WireScan.cpp - Library for scanning I2C/TWI bus
 * Copyright (c) 2017 Timo Kokkonen <tjko@iki.fi>. 
 * All Rights Reserved.
 *
 */

#include <Arduino.h>
#include <Wire.h>
#include "WireScan.h"

#define MAX_WIRE_ADDR 127

WireScanner::WireScanner()
{

}

void WireScanner::scan(Stream *stream)
{
  byte addr = 1;
  byte count = 0;
  byte i, res;
  
  stream->print(F("Scanning I2C Bus: "));

  while (addr < MAX_WIRE_ADDR) {
    // test if we get response from this address...
    Wire.beginTransmission(addr);
    res = Wire.endTransmission();

    if (res == 0) {
      count++;
      stream->print(F("0x"));
      if (addr < 16) stream->print('0');
      stream->print(addr, HEX);
      stream->print(' ');
    }

    addr++;
  }
  
  stream->print(F(" ("));
  stream->print(count);
  stream->println(F(" device(s) found)"));
}

