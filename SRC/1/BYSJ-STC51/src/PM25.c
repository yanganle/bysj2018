#include "PM25.h"
#include "io.h"

u8 flag_dust;
u8 flag_low;
u16 msCountLow;

void dustPolling(void){
  if(IO_DUST == 0x00) flag_low = 1;else flag_low = 0;
  if(msCount >= 1000) flag_dust = 1;
}
float getDust(void){
  float dust_concentration;
  if(flag_dust){
    //dust_concentration = (float)100*getQueueSum(queuePM)/30000/2;
    msCount = 0;
    msCountLow = 0;
    flag_dust = 0;
    return dust_concentration;
  }
  return -1;
}

