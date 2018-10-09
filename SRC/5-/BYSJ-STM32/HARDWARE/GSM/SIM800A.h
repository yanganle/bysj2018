#ifndef __SAM800A_H__
#define __SAM800A_H__

#include <stdio.h>
#include "sys.h"

#define SIM_OK 0
#define SIM_COMMUNTION_ERR 0xff
#define SIM_CPIN_ERR 0xfe
#define SIM_CREG_FAIL 0xfd
#define SIM_MAKE_CALL_ERR 0Xfc
#define SIM_ATA_ERR       0xfb

#define SIM_SETECHO_ERR 0xf0

#define SIM_CMGF_ERR 0xfa
#define SIM_CSCS_ERR 0xf9
#define SIM_CSCA_ERR 0xf8
#define SIM_CSMP_ERR 0Xf7
#define SIM_CMGS_ERR       0xf6
#define SIM_CMGS_SEND_FAIL 0xf5

u8 sim800a_work_init(void);
u8 sim900a_send_cmd(u8 *cmd,u8 *ack,u16 waittime);
u8 sam800a_send_chmessage(u8 *number, u8 *content);

#endif
