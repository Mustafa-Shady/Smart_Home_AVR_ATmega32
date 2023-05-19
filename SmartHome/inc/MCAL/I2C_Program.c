/*
 * I2C_Program.c
 *
 *  Created on: Apr 23, 2023
 *      Author: DWEEBSTARK
 */
#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <MCAL/I2C_Config.h>
#include <MCAL/I2C_Interface.h>
#include <MCAL/I2C_Private.h>
#include <util/delay.h>

void I2C_voidMasterInit(){

	/*enable ACK bit  */

	CLR_BIT(TWCR,TWCR_TWEA_BIT);

	/*Set frequency to 400kbps*/
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,0);

	TWBR=2;

	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN_BIT);

}







I2C_ErrorStatus I2C_SendStartCondition(void){
	u8 ErrorStatus=NoError;

	/*Writing one to START Condition Bit */
	SET_BIT(TWCR,TWCR_TWSTA_BIT);
	/*Clearing the flag by Writing one to it, To start the operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);
	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	if((TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_START_DONE){
		ErrorStatus=StartConditionErr;
	}
	else{

	}

return ErrorStatus;
}

I2C_ErrorStatus I2C_SendRepeatedStart(void){
	u8 ErrorStatus=NoError;
	/*Set the start condition*/
	SET_BIT(TWCR,TWCR_TWSTA_BIT);

	/*Clear interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);

	/*Polling on the interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT_BIT))==0);

	/*check on the operation status ID*/
	if((TWSR&TWSR_PRE_SCALER_MASK) != TWSR_RE_START_DONE)
	{
		ErrorStatus= RepeatedStartError;
	}
	else
	{
		/*Do nothing*/
	}

	return ErrorStatus;
}

I2C_ErrorStatus I2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAdress){
	/*Before using the function,Please Check the return status of TWSR of
	the function I2C_SendStartCondition (START CONDITION RETURN)*/
	/*TWDR MUST BE SET BEFORE MANIPULATING TWCR VALUES */
	u8 ErrorStatus=NoError;
	/*Assigning the 7 bit address to TWDR*/
	TWDR=((Copy_u8SlaveAdress<<1));
	/*Sending the write command */
	CLR_BIT(TWDR,0);

	/*Clearing Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA_BIT);
	/*Clearing the flag by Writing one to it, To start the operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);
	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	if((TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_SLAVE_ADD_W_ACK && (TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_SLAVE_ADD_W_NO_ACK){
		ErrorStatus=SlaveAddressWithWriteErr;
	}
	else{

	}


	return ErrorStatus;
}

I2C_ErrorStatus I2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAdress){
	/*Before using the function,Please Check the return status of TWSR of
	the function I2C_SendStartCondition (START CONDITION RETURN)*/
	u8 ErrorStatus=NoError;
	/*Assigning the 7 bit address to TWDR*/
	TWDR=((Copy_u8SlaveAdress<<1));
	/*Sending the Reading command */
	SET_BIT(TWDR,0);
	//*Clearing Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA_BIT);


	/*Clearing the flag by Writing one to it, To start the operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);
	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	if((TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_SLAVE_ADD_R_ACK && (TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_SLAVE_ADD_R_NO_ACK){
		ErrorStatus=SlaveAddressWithReadErr;
	}
	else{

	}

	return ErrorStatus;
}

I2C_ErrorStatus I2C_MstrSendDataByte(u8 Copy_u8Data){
	/*Before using the function,Please Check the return status of TWSR of
	 * the function I2C_SendSlaveAddressWithWrite (Send address Write RETURN)*/
	u8 ErrorStatus=NoError;
	/*Assigning the Data TWDR*/
	TWDR=Copy_u8Data;

	/*Writing one to START Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA_BIT);
	/*Clearing the flag by Writing one to it, To start the operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);
	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	if((TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_DATA_W_ACK	 && (TWSR&TWSR_PRE_SCALER_MASK)!=TWSR_DATA_W_NO_ACK){
		ErrorStatus=MstrWriteByteErr;
	}
	else{

	}

	return ErrorStatus;
}

I2C_ErrorStatus I2C_MstrReadDataByte(pstring Copy_pu8Data){
	/*Before using the function,Please Check the return status of TWSR of
	  the function I2C_SendSlaveAddressWithRead (Send address Read RETURN)*/
	u8 ErrorStatus=NoError;

	/*Enable Acknowledge bit generation of master receiver*/
	SET_BIT(TWCR,TWCR_TWEA_BIT);


	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	ErrorStatus=(TWSR&TWSR_PRE_SCALER_MASK);
	if((TWSR&TWSR_PRE_SCALER_MASK)==TWSR_DATA_R_ACK){
		/*Assigning the Data TWDR*/
		*Copy_pu8Data=TWDR;
	}
	else{
		ErrorStatus=MstrReadByteWithAckErr;
	}

	return ErrorStatus;
}





I2C_ErrorStatus I2C_MstrReadDataByteNoAck(pstring Copy_pu8Data){
	/*Before using the function,Please Check the return status of TWSR of
	the function I2C_SendSlaveAddressWithRead (Send address Read RETURN)*/
	u8 ErrorStatus=NoError;


	/*Disable Acknowledge bit generation of master receiver*/
		CLR_BIT(TWCR,TWCR_TWEA_BIT);

	/*Wait for the transmission flag to be up*/
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0);

	ErrorStatus=(TWSR&TWSR_PRE_SCALER_MASK);
	if((TWSR&TWSR_PRE_SCALER_MASK)==TWSR_DATA_R_ACK){
		/*Assigning the Data TWDR*/
		*Copy_pu8Data=TWDR;

	}
	else{
		ErrorStatus=MstrReadByteWithAckErr;
	}

	return ErrorStatus;
}






void I2C_SendStopCondition(void){
	/*Writing one to STOP Condition Bit */
	SET_BIT(TWCR,TWCR_TWSTO_BIT);
	/*Clear interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT_BIT);
}





