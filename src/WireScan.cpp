/*
  WireScan.cpp - Library for scanning I2C/TWI bus
  Copyright (c) 2017 Timo Kokkonen <tjko@iki.fi>. 
  All Rights Reserved.
 
  This file is part of WireScan Library.

  WireScan is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Foobar is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
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

