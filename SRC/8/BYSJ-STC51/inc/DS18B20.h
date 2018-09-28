#ifndef __DS18B20_H__
#define __DS18B20_H__
#include <reg52.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <intrins.h>
#include "delay.h"

unsigned int ReadTemperature(u8 *tempstr);

#endif
