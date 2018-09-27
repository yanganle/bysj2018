#include "OSAL.h"
#include "ZGlobals.h"
#include "AF.h"
#include "aps_groups.h"
#include "ZDApp.h"

#include "SampleApp.h"
#include "SampleAppHw.h"

#include "OnBoard.h"

/* HAL */
#include "hal_lcd.h"
#include "hal_led.h"
#include "hal_key.h"
#include "MT_UART.h"
#include "MT_APP.h"
#include "MT.h"
#include "DHT11.h"
#include "hal_adc.h"

#include "adc_sensor.h"
#include "dig_sensor.h"
#include "agreement.h"
//#include "Array_list.h"

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */
uint8 AppTitle[] = "ALD2530 DHT11"; //应用程序名称

// This list should be filled with Application specific Cluster IDs.
const cId_t SampleApp_ClusterList[SAMPLEAPP_MAX_CLUSTERS] =
{
  SAMPLEAPP_PERIODIC_CLUSTERID,
  SAMPLEAPP_FLASH_CLUSTERID,
  SAMPLEAPP_P2P_CLUSTERID,
  SAMPLEAPP_CMD_CLUSTERID
};

const SimpleDescriptionFormat_t SampleApp_SimpleDesc =
{
  SAMPLEAPP_ENDPOINT,              //  int Endpoint;
  SAMPLEAPP_PROFID,                //  uint16 AppProfId[2];
  SAMPLEAPP_DEVICEID,              //  uint16 AppDeviceId[2];
  SAMPLEAPP_DEVICE_VERSION,        //  int   AppDevVer:4;
  SAMPLEAPP_FLAGS,                 //  int   AppFlags:4;
  SAMPLEAPP_MAX_CLUSTERS,          //  uint8  AppNumInClusters;
  (cId_t *)SampleApp_ClusterList,  //  uint8 *pAppInClusterList;
  SAMPLEAPP_MAX_CLUSTERS,          //  uint8  AppNumInClusters;
  (cId_t *)SampleApp_ClusterList   //  uint8 *pAppInClusterList;
};

// This is the Endpoint/Interface description.  It is defined here, but
// filled-in in SampleApp_Init().  Another way to go would be to fill
// in the structure here and make it a "const" (in code space).  The
// way it's defined in this sample app it is define in RAM.
endPointDesc_t SampleApp_epDesc;

/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */
uint8 SampleApp_TaskID;   // Task ID for internal task/event processing
                          // This variable will be received when
                          // SampleApp_Init() is called.
devStates_t SampleApp_NwkState;

uint8 SampleApp_TransID;  // This is the unique message ID (counter)

afAddrType_t SampleApp_Periodic_DstAddr; //广播
afAddrType_t SampleApp_Flash_DstAddr;    //组播
afAddrType_t SampleApp_P2P_DstAddr;      //点播
afAddrType_t SampleApp_CMD_DstAddr;      //下发命令

aps_Group_t SampleApp_Group;

uint8 SampleAppPeriodicCounter = 0;
uint8 SampleAppFlashCounter = 0;
agreementData sensorValue = {DATA_HEADH,DATA_HEADL,NWK_ZIGBEE,0,0,0,0,0,0,SENSOR_DATA_LENGTH,0,0,0,0,0,0,0,DATA_END};
//uint8 test_buffer[18] = {0xEE, 0xCC, 0x01, 0x00, 0x00, 0xBB, 0x51, 0x0B, 0x01, 0x44, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

/*********************************************************************
 * LOCAL FUNCTIONS
 */
void SampleApp_HandleKeys( uint8 shift, uint8 keys );
void SampleApp_MessageMSGCB( afIncomingMSGPacket_t *pckt );
void SampleApp_SendPeriodicMessage(void);
void SampleApp_SendFlashMessage( uint16 flashTime );
void SampleApp_Send_P2P_Message(int8 _SensorStyle, int8 _SenserIndex, int8 _SenserPositon, uint8 *_pData);
void SampleApp_NwkP2PMsgProcessing(afIncomingMSGPacket_t * pkt);
void SampleApp_NwkCMDMsgProcessing(afIncomingMSGPacket_t * pkt);
//void Sensor_ProcessMTCB( uint8 *pckt);
void SampleApp_Send_CMD_Message(afIncomingMSGPacket_t *pckt);
/*********************************************************************
 * NETWORK LAYER CALLBACKS
 */

/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn      SampleApp_Init
 *
 * @brief   Initialization function for the Generic App Task.
 *          This is called during initialization and should contain
 *          any application specific initialization (ie. hardware
 *          initialization/setup, table initialization, power up
 *          notificaiton ... ).
 *
 * @param   task_id - the ID assigned by OSAL.  This ID should be
 *                    used to send messages and set timers.
 *
 * @return  none
 */
void SampleApp_Init( uint8 task_id )
{ 
  SampleApp_TaskID = task_id;
  SampleApp_NwkState = DEV_INIT;
  SampleApp_TransID = 0;
  
  //MT_UartInit();                  //串口初始化
  //MT_UartRegisterTaskID(task_id); //注册串口任务
  MT_UartRegisterTaskID(SampleApp_TaskID);
  
  //外设初始化
  InitDigSensor();
  //Array_init(&Galist,&Dev_BasicInf[0] , MAX_DEV_MANAGE_NUM ,Coor_Dev_manage.dev_num);//初始化设备列表
  
  // Device hardware initialization can be added here or in main() (Zmain.c).
  // If the hardware is application specific - add it here.
  // If the hardware is other parts of the device add it in main().

 #if defined ( BUILD_ALL_DEVICES )
  // The "Demo" target is setup to have BUILD_ALL_DEVICES and HOLD_AUTO_START
  // We are looking at a jumper (defined in SampleAppHw.c) to be jumpered
  // together - if they are - we will start up a coordinator. Otherwise,
  // the device will start as a router.
  if ( readCoordinatorJumper() )
    zgDeviceLogicalType = ZG_DEVICETYPE_COORDINATOR;
  else
    zgDeviceLogicalType = ZG_DEVICETYPE_ROUTER;
#endif // BUILD_ALL_DEVICES

#if defined ( HOLD_AUTO_START )
  // HOLD_AUTO_START is a compile option that will surpress ZDApp
  //  from starting the device and wait for the application to
  //  start the device.
  ZDOInitDevice(0);
#endif

  // Setup for the periodic message's destination address
  // Broadcast to everyone
  SampleApp_Periodic_DstAddr.addrMode = (afAddrMode_t)AddrBroadcast;
  SampleApp_Periodic_DstAddr.endPoint = SAMPLEAPP_ENDPOINT;
  SampleApp_Periodic_DstAddr.addr.shortAddr = 0xFFFF;

  // Setup for the flash command's destination address - Group 1
  SampleApp_Flash_DstAddr.addrMode = (afAddrMode_t)afAddrGroup;
  SampleApp_Flash_DstAddr.endPoint = SAMPLEAPP_ENDPOINT;
  SampleApp_Flash_DstAddr.addr.shortAddr = SAMPLEAPP_FLASH_GROUP;
  
  SampleApp_P2P_DstAddr.addrMode = (afAddrMode_t)Addr16Bit; //点播 
  SampleApp_P2P_DstAddr.endPoint = SAMPLEAPP_ENDPOINT; 
  SampleApp_P2P_DstAddr.addr.shortAddr = 0x0000;            //发给协调器

  // Fill out the endpoint description.
  SampleApp_epDesc.endPoint = SAMPLEAPP_ENDPOINT;
  SampleApp_epDesc.task_id = &SampleApp_TaskID;
  SampleApp_epDesc.simpleDesc
            = (SimpleDescriptionFormat_t *)&SampleApp_SimpleDesc;
  SampleApp_epDesc.latencyReq = noLatencyReqs;

  // Register the endpoint description with the AF
  afRegister( &SampleApp_epDesc );

  // Register for all key events - This app will handle all key events
  RegisterForKeys( SampleApp_TaskID );

  // By default, all devices start out in Group 1
  SampleApp_Group.ID = 0x0001;
  osal_memcpy( SampleApp_Group.name, "Group 1", 7 );
  aps_AddGroup( SAMPLEAPP_ENDPOINT, &SampleApp_Group );
  
#if defined ( LCD_SUPPORTED )
  HalLcdWriteString( "SampleApp", HAL_LCD_LINE_1 );
#endif
}

/*********************************************************************
 * @fn      SampleApp_ProcessEvent
 *
 * @brief   Generic Application Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id  - The OSAL assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  none
 */
uint16 SampleApp_ProcessEvent( uint8 task_id, uint16 events )
{
  afIncomingMSGPacket_t *MSGpkt;
  
  (void)task_id;  // Intentionally unreferenced parameter
  
  uint8 sdata[4] = {0};
  
  if ( events & SYS_EVENT_MSG )
  {
    MSGpkt = (afIncomingMSGPacket_t *)osal_msg_receive( SampleApp_TaskID );
    while ( MSGpkt )
    {
      switch ( MSGpkt->hdr.event )
      {
        // Received when a key is pressed
        case KEY_CHANGE:
          SampleApp_HandleKeys( ((keyChange_t *)MSGpkt)->state, ((keyChange_t *)MSGpkt)->keys );
          break;

        // Received when a messages is received (OTA) for this endpoint
        case AF_INCOMING_MSG_CMD:
          SampleApp_MessageMSGCB( MSGpkt );
          break;
	case CMD_SERIAL_MSG_0: 
          //HalUARTWrite(1, ((mtOSALSerialData_t *)MSGpkt)->msg, 18); 
          SampleApp_Send_CMD_Message(MSGpkt);
          break;
        case CMD_SERIAL_MSG_1:
          //HalUARTWrite(1, sdata, 4); 
          //Sensor_ProcessMTCB( (mtOSALSerialData_t*)MSGpkt );
          break;
        // Received whenever the device changes state in the network
        case ZDO_STATE_CHANGE:
          SampleApp_NwkState = (devStates_t)(MSGpkt->hdr.status);
          if ( //(SampleApp_NwkState == DEV_ZB_COORD) ||
                 (SampleApp_NwkState == DEV_ROUTER)
              || (SampleApp_NwkState == DEV_END_DEVICE) )
          {
            // Start sending the periodic message in a regular interval.
            osal_start_timerEx( SampleApp_TaskID,
                              SAMPLEAPP_SEND_PERIODIC_MSG_EVT,
                              SAMPLEAPP_SEND_PERIODIC_MSG_TIMEOUT );
          }
          else
          {
            // Device is no longer in the network
          }
          break;

        default:
          break;
      }

      // Release the memory
      osal_msg_deallocate( (uint8 *)MSGpkt );

      // Next - if one is available
      MSGpkt = (afIncomingMSGPacket_t *)osal_msg_receive( SampleApp_TaskID );
    }

    // return unprocessed events
    return (events ^ SYS_EVENT_MSG);
  }

  // Send a message out - This event is generated by a timer
  //  (setup in SampleApp_Init()).
  if ( events & SAMPLEAPP_SEND_PERIODIC_MSG_EVT )
  {
    // Send the periodic message
    //SampleApp_SendPeriodicMessage();
    
#ifdef DEVICE_LIGHT //光照传感器
  sdata[0] = 0;
  sdata[1] = 0;
  sdata[2] = 0;
  sdata[3] = GetLightData();
  SampleApp_Send_P2P_Message(DEVICE_LIGHT, 0, 0, sdata);
#endif
#ifdef DEVICE_GAS_MQ135 //污染传感器
  gasvalue = ReadGasData();
  sdata[0] = 0;
  sdata[1] = 0;
  sdata[2] = gasvalue>>8;//高位
  sdata[3] = gasvalue;//低位
  SampleApp_Send_P2P_Message(DEVICE_GAS_MQ135, 0, 0, sdata);
#endif
#ifdef DEVICE_HT11 //温湿度
  GetHt11Value();
  sdata[0] = temp>>8;
  sdata[1] = temp;
  sdata[2] = humi>>8;
  sdata[3] = humi;
  SampleApp_Send_P2P_Message(DEVICE_HT11, 0, 0, sdata);
#endif    
#ifdef DEVICE_RELAY_ONE //风扇
  sdata[0] = 0;
  sdata[1] = 0;
  sdata[2] = 0;
  sdata[3] = relay_one_value;
  SampleApp_Send_P2P_Message(DEVICE_RELAY_ONE, 0, 0, sdata);
#endif    
#ifdef DEVICE_RELAY_TWO //灯光
  sdata[0] = 0;
  sdata[1] = 0;
  sdata[2] = 0;
  sdata[3] = relay_two_value;
  SampleApp_Send_P2P_Message(DEVICE_RELAY_TWO, 0, 0, sdata);
#endif    
 
    // Setup to send message again in normal period (+ a little jitter)
    osal_start_timerEx( SampleApp_TaskID, SAMPLEAPP_SEND_PERIODIC_MSG_EVT,
        (SAMPLEAPP_SEND_PERIODIC_MSG_TIMEOUT + (osal_rand() & 0x00FF)) );

    // return unprocessed events
    return (events ^ SAMPLEAPP_SEND_PERIODIC_MSG_EVT);
  }
  
  if(events & SAMPLEAPP_TEST_EVT)
  {
    //SampleApp_Send_CMD_Message(test_buffer);
    osal_start_timerEx( SampleApp_TaskID, SAMPLEAPP_TEST_EVT,
    (3000 + (osal_rand() & 0x00FF)) );

    // return unprocessed events
    return (events ^ SAMPLEAPP_TEST_EVT);
  }

  // Discard unknown events
  return 0;
}

/*********************************************************************
 * Event Generation Functions
 */
/*********************************************************************
 * @fn      SampleApp_HandleKeys
 *
 * @brief   Handles all key events for this device.
 *
 * @param   shift - true if in shift/alt.
 * @param   keys - bit field for key events. Valid entries:
 *                 HAL_KEY_SW_2
 *                 HAL_KEY_SW_1
 *
 * @return  none
 */
void SampleApp_HandleKeys( uint8 shift, uint8 keys )
{
  (void)shift;  // Intentionally unreferenced parameter
  
  if ( keys & HAL_KEY_SW_1 )
  {
    /* This key sends the Flash Command is sent to Group 1.
     * This device will not receive the Flash Command from this
     * device (even if it belongs to group 1).
     */
    SampleApp_SendFlashMessage( SAMPLEAPP_FLASH_DURATION );
  }

  if ( keys & HAL_KEY_SW_2 )
  {
    /* The Flashr Command is sent to Group 1.
     * This key toggles this device in and out of group 1.
     * If this device doesn't belong to group 1, this application
     * will not receive the Flash command sent to group 1.
     */
    aps_Group_t *grp;
    grp = aps_FindGroup( SAMPLEAPP_ENDPOINT, SAMPLEAPP_FLASH_GROUP );
    if ( grp )
    {
      // Remove from the group
      aps_RemoveGroup( SAMPLEAPP_ENDPOINT, SAMPLEAPP_FLASH_GROUP );
    }
    else
    {
      // Add to the flash group
      aps_AddGroup( SAMPLEAPP_ENDPOINT, &SampleApp_Group );
    }
  }
}

/*********************************************************************
 * LOCAL FUNCTIONS
 */

/*********************************************************************
 * @fn      SampleApp_MessageMSGCB
 *
 * @brief   Data message processor callback.  This function processes
 *          any incoming data - probably from other devices.  So, based
 *          on cluster ID, perform the intended action.
 *
 * @param   none
 *
 * @return  none
 */
void SampleApp_MessageMSGCB( afIncomingMSGPacket_t *pkt )
{
  uint16 flashTime;

  switch ( pkt->clusterId )
  {
    case SAMPLEAPP_P2P_CLUSTERID: //传感器数据上报
      SampleApp_NwkP2PMsgProcessing(pkt);
      break;    
    case  SAMPLEAPP_PERIODIC_CLUSTERID: 
      break;    
    case  SAMPLEAPP_CMD_CLUSTERID: //协调器命令下发
      SampleApp_NwkCMDMsgProcessing(pkt);
      break;
    case SAMPLEAPP_FLASH_CLUSTERID:
      flashTime = BUILD_UINT16(pkt->cmd.Data[1], pkt->cmd.Data[2] );
      HalLedBlink( HAL_LED_4, 4, 50, (flashTime / 4) );
      break;
  }
}

/*********************************************************************
 * @fn      SampleApp_SendPeriodicMessage
 *
 * @brief   Send the periodic message.
 *
 * @param   none
 *
 * @return  none
 */
void SampleApp_SendPeriodicMessage( void )
{
  if ( AF_DataRequest( &SampleApp_Periodic_DstAddr, &SampleApp_epDesc,
                       SAMPLEAPP_PERIODIC_CLUSTERID,
                       1,
                       (uint8*)&SampleAppPeriodicCounter,
                       &SampleApp_TransID,
                       AF_DISCV_ROUTE,
                       AF_DEFAULT_RADIUS ) == afStatus_SUCCESS )
  {
  }
  else
  {
    // Error occurred in request to send.
  }
}

/*********************************************************************
 * @fn      SampleApp_SendFlashMessage
 *
 * @brief   Send the flash message to group 1.
 *
 * @param   flashTime - in milliseconds
 *
 * @return  none
 */
void SampleApp_SendFlashMessage( uint16 flashTime )
{
  uint8 buffer[3];
  buffer[0] = (uint8)(SampleAppFlashCounter++);
  buffer[1] = LO_UINT16( flashTime );
  buffer[2] = HI_UINT16( flashTime );

  if ( AF_DataRequest( &SampleApp_Flash_DstAddr, &SampleApp_epDesc,
                       SAMPLEAPP_FLASH_CLUSTERID,
                       3,
                       buffer,
                       &SampleApp_TransID,
                       AF_DISCV_ROUTE,
                       AF_DEFAULT_RADIUS ) == afStatus_SUCCESS )
  {
  }
  else
  {
    // Error occurred in request to send.
  }
}

/*********************************************************************
 * @fn      SampleApp_Send_P2P_Message
 *
 * @brief   point to point.
 *
 * @param   none
 *
 * @return  none
 */
/*
*终端打包传感器数据并发送到协调器处理函数
*/
void SampleApp_Send_P2P_Message(int8 _SensorStyle, int8 _SenserIndex, int8 _SenserPositon, uint8 *_pData)
{
  //MT_BuildAndSendZToolResponse(((uint8)MT_RPC_CMD_SRSP | (uint8)MT_RPC_SYS_CBT2530_APP), 0, 0, 0);
  uint8 sMsg[10];  
  uint8 sMsgLen = 0x0A;
  uint16 nwkAddr;

  nwkAddr = NLME_GetShortAddr();

  sMsg[0] = HI_UINT16(nwkAddr);
  sMsg[1] = LO_UINT16(nwkAddr);
  sMsg[2] = _SensorStyle;
  sMsg[3] = _SenserIndex;
  sMsg[4] = _SenserPositon;

  sMsg[5] = _pData[0];
  sMsg[6] = _pData[1];
  sMsg[7] = _pData[2];
  sMsg[8] = _pData[3];
  
  sMsg[9] = 0x00;//_pData[4];// REV DATA BIT
  if ( AF_DataRequest( &SampleApp_P2P_DstAddr, &SampleApp_epDesc,
                       SAMPLEAPP_P2P_CLUSTERID,
                       sMsgLen,
                       sMsg,
                       &SampleApp_TransID,
                       AF_DISCV_ROUTE,
                       AF_DEFAULT_RADIUS ) == afStatus_SUCCESS )
  {
    
  }else
  {
    // Error occurred in request to send.
  }
}

/*
*协调器收到上位机串口数据处理函数
*/
void SampleApp_Send_CMD_Message(afIncomingMSGPacket_t *pckt)
{
  uint8 data_buf[18];
  uint8 len = 18;
 
  osal_memcpy(data_buf, (uint8 *)pckt+2, 18);
  //HalUARTWrite(1, data_buf, 18); 
  if((data_buf[0]==0xee) && (data_buf[1]==0xcc) && (data_buf[17]==0xff) && (len==18))
  {
    SampleApp_P2P_DstAddr.addrMode = (afAddrMode_t)afAddr16Bit;
    SampleApp_P2P_DstAddr.endPoint = SAMPLEAPP_ENDPOINT;
    SampleApp_P2P_DstAddr.addr.shortAddr = BUILD_UINT16(data_buf[6], data_buf[5]);
  
    if ( AF_DataRequest( &SampleApp_P2P_DstAddr, &SampleApp_epDesc,
                         SAMPLEAPP_CMD_CLUSTERID,
                         len,
                         data_buf,
                         &SampleApp_TransID,
                         AF_DISCV_ROUTE,
                         AF_DEFAULT_RADIUS ) == afStatus_SUCCESS )
    {    
      asm("NOP");
    }
    else
    {
      //HalLedBlink( HAL_LED_1, 2, 50, (1000 / 4) );
      //Error occurred in request to send.
    }
  }
}

/*
*协调器收到终端发送的周期数据处理函数
*/
void SampleApp_NwkP2PMsgProcessing(afIncomingMSGPacket_t * pkt)
{
  sensorValue.dataDetail.nodeAddr[2] = *pkt->cmd.Data;
  sensorValue.dataDetail.nodeAddr[3] = *(pkt->cmd.Data+1);
  sensorValue.dataDetail.nodeChannel = _NIB.nwkLogicalChannel;
  sensorValue.dataDetail.nodePort    = 0x01;
  sensorValue.dataDetail.data.sensorType = *(pkt->cmd.Data+2);
  sensorValue.dataDetail.data.sensorID   = *(pkt->cmd.Data+3);
  sensorValue.dataDetail.data.sensorPostion = *(pkt->cmd.Data+4);
  osal_memcpy(sensorValue.dataDetail.data.SensorData, pkt->cmd.Data+5, 4);
  
  HalUARTWrite(0, sensorValue.dataArry,DATA_AGREEMENT_LENGTH);
}

/*
*终端接受无线控制命令处理函数
*/
void SampleApp_NwkCMDMsgProcessing(afIncomingMSGPacket_t * pkt)
{
  uint8 *buf = pkt->cmd.Data;
  
  if(buf[0] == 0xEE && buf[1] == 0xCC && buf[17] == 0xFF)
  {
    switch(buf[10])
    {
#ifdef DEVICE_RELAY_ONE
      case DEVICE_RELAY_ONE:
        CtrlRelyOne(buf[16]);
        break;
#endif
#ifdef DEVICE_RELAY_TWO
      case DEVICE_RELAY_TWO:
        CtrlRelyTwo(buf[16]);
        break;
#endif
      default:
        break;
    }
  }
}
/*********************************************************************
*********************************************************************/
