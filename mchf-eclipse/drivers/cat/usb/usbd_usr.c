/**
  ******************************************************************************
  * @file    usbd_usr.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   This file includes the user application layer
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

// Optimization enable for this file
#pragma GCC optimize "O3"


// Common
#include "mchf_board.h"

/* Includes ------------------------------------------------------------------*/
#include "usbd_usr.h"
#include "usbd_ioreq.h"

#include <stdio.h>

USBD_Usr_cb_TypeDef USR_cb =
{
  USBD_USR_Init,
  USBD_USR_DeviceReset,
  USBD_USR_DeviceConfigured,
  USBD_USR_DeviceSuspended,
  USBD_USR_DeviceResumed,
  
  
  USBD_USR_DeviceConnected,
  USBD_USR_DeviceDisconnected,    
};

//
// call to here commented out
// in USBD_Init() in usbd_core.c
//
void USBD_USR_Init(void)
{
	//printf("USBD_USR_Init\n\r");
	//while(1);

  /* Initialize LEDs */
  //STM_EVAL_LEDInit(LED1);
  //STM_EVAL_LEDInit(LED2);
  //STM_EVAL_LEDInit(LED3);
  //STM_EVAL_LEDInit(LED4);
  
  //LCD_LOG_Init();
  
#ifdef USE_USB_OTG_HS 
  //LCD_LOG_SetHeader(" USB OTG HS VCP Device");
#else
  //LCD_LOG_SetHeader(" USB OTG FS VCP Device");
#endif
  //LCD_UsrLog("> USB device library started.\n");
  //LCD_LOG_SetFooter ("     USB Device Library v1.1.0" );
}

/**
* @brief  USBD_USR_DeviceReset 
*         Displays the message on LCD on device Reset Event
* @param  speed : device speed
* @retval None
*/
void USBD_USR_DeviceReset(uint8_t speed )
{
 switch (speed)
 {
   case USB_OTG_SPEED_HIGH: 
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [HS]" );
     break;

  case USB_OTG_SPEED_FULL: 
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [FS]" );
     break;
 //default:
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [??]" );
 }
}


/**
* @brief  USBD_USR_DeviceConfigured
*         Displays the message on LCD on device configuration Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConfigured (void)
{
  //LCD_UsrLog("> VCP Interface configured.\n");
}

/**
* @brief  USBD_USR_DeviceSuspended 
*         Displays the message on LCD on device suspend Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceSuspended(void)
{
  //LCD_UsrLog("> USB Device in Suspend Mode.\n");
  /* Users can do their application actions here for the USB-Reset */
}


/**
* @brief  USBD_USR_DeviceResumed 
*         Displays the message on LCD on device resume Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceResumed(void)
{
    //LCD_UsrLog("> USB Device in Idle Mode.\n");
  /* Users can do their application actions here for the USB-Reset */
}


/**
* @brief  USBD_USR_DeviceConnected
*         Displays the message on LCD on device connection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConnected (void)
{
  //LCD_UsrLog("> USB Device Connected.\n");

	//printf("USB Device Connected.\n\r");
}


/**
* @brief  USBD_USR_DeviceDisonnected
*         Displays the message on LCD on device disconnection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceDisconnected (void)
{
  //LCD_UsrLog("> USB Device Disconnected.\n");

	//printf("USB Device Disconnected.\n\r");
}

