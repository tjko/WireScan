/*
 * WireScan.h - Library for scanning I2C/TWI bus
 * Copyright (c) 2017 Timo Kokkonen <tjko@iki.fi>. 
 * All Rights Reserved.
 *
 */

#ifndef WIRESCAN_H
#define WIRESCAN_H


class WireScanner
{
 public:
  WireScanner();
  static void scan(Stream *stream);
};

extern WireScanner WireScan;

#endif
