#ifndef __SIMxxx_H__
#define __SIMxxx_H__

#include "hal_types.h"

#define SIM_OK 0
#define SIM_COMMUNTION_ERR 0xff
#define SIM_CPIN_ERR 0xfe
#define SIM_CREG_FAIL 0xfd
#define SIM_MAKE_CALL_ERR 0Xfc
#define SIM_ATA_ERR       0xfb

#define SIM_CMGF_ERR 0xfa
#define SIM_CSCS_ERR 0xf9
#define SIM_CSCA_ERR 0xf8
#define SIM_CSMP_ERR 0Xf7
#define SIM_CMGS_ERR       0xf6
#define SIM_CMGS_SEND_FAIL       0xf5

#define UART1 1

uint8 *sim900a_check_cmd(uint8 *str);
uint8 sim900a_send_cmd(uint8 *cmd,uint8 *ack,uint16 waittime);
extern uint8 sim900a_work_test(void);
extern uint8 sim900a_send_chmessage_shan(uint8 *number,uint8 *content);


#endif