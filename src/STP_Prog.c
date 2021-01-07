/******************************************************************/
/*             >>DATE:6/1/2021                                    */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STP_INT.h"
#include "STP_Config.h"

#include "GPIO_INT.h"

#include "SYSTICK_INT.h"

void STP_VidSendSynchronus(u8 LOC_u8DataToSend)
{
	S8 LOC_Counter;
	u8 LOC_Bit;
	for(LOC_Counter=7;LOC_Counter>=0;LOC_Counter)
	{
	LOC_Bit=GET_BIT(LOC_u8DataToSend,LOC_Counter);	
	
	MGPIO_VidSetPinValue (STP_DATA_SERIAL,LOC_Bit);//DS-->Data Serial
	/**Rising Edge to Shift Clock**/
	MGPIO_VidSetPinValue (STP_SHIFT_CLOCK,HIGH);
	MSTK_VidSetBusyWait(1);
	MGPIO_VidSetPinValue (STP_SHIFT_CLOCK,LOW);
	MSTK_VidSetBusyWait(1);
	}
	/**Rising Edge to Storage Clock**/
	MGPIO_VidSetPinValue (STP_STORAGE_CLOCK,HIGH);
	MSTK_VidSetBusyWait(1);
	MGPIO_VidSetPinValue (STP_SHIFT_CLOCK,LOW);
	MSTK_VidSetBusyWait(1);
	
}

