#ifndef __LCD12864_H__
#define __LCD12864_H__

#include <reg52.h> 
#include <intrins.h>

void display_init(void);
void display_humiture(u8 *temp, u8 *humi);
void display_human(u8 *show);
void display_sound(u8 *show);

#endif
