#ifndef __DIG_SENSOR_H__
#define __DIG_SENSOR_H__

#include <ioCC2530.h>
#include "OnBoard.h"
#include "SampleApp.h"

extern uint8 relay_one_value;//继电器一
extern uint8 relay_two_value;//继电器二
extern uint8 relay_hot;

extern uint8 GetLightData(void);
extern void InitDigSensor(void);

extern void CtrlRelyOne(uint8 state);
extern void CtrlRelyTwo(uint8 state);
extern void CtrlRelyHot(uint8 state); //加热器

#endif