
   /**
     * SMART HOME AVR PROJECT
     * includes two modes:
     * 1- admin mode to control and adjust the IDs and passwords.
     * 2- user mode to control the house device
     *              Mustafa Shady
    */
#define INCLUDE  1
#if INCLUDE

#include <lib/STD_TYPES.h>
#include <lib/BIT_MATHS.h>
#include <MCAL/DIO_interface.h>
#include <MCAL/ADC_interface.h>
#include <MCAL/Extint_interface.h>
#include <MCAL/GIE_interface.h>
#include <MCAL/GPT_interface.h>
#include <MCAL/PWM_interface.h>
#include <HAL/servo.h>
#include <MCAL/UART_interface.h>
#include <HAL/EEPROM_Interface.h>
#include <MCAL/I2C_Interface.h>
#include <HAL/LCD_Interface.h>
#include <HAL/LED_interface.h>
#include "HAL/Buzzer.h"
#include <MCAL/DELAY.h>

#endif


#if 0 /*Eeprom first User name and password Configuration */
string ADMIN [5] = "ADMN";
string PASS [5] = "000";

string U1 [5] = "USR1";
string P1 [5] = "111";



void main(void)
{
    LCD_voidLCDInit();

    EEPROM_VoidInit();


    EEPROM_VoidSendBuffer(0,ADMIN,6);
    EEPROM_VoidSendBuffer(6,PASS,5);

    EEPROM_VoidSendBuffer(10,U1,5);
    EEPROM_VoidSendBuffer(15,P1,5);

    




}


#endif

#if 1 /*Run time code */

/**Global Variables 
 * 1- Admin ID and password
 * 2- 4 admin user names and passwords (USERx) 
 * 3- Define mode switcher
*/

string U1 [5]; 
string P1 [4]; 
string U2 [5];
string P2 [4]; 
string U3 [5];
string P3 [4]; 
string U4 [5]; 
string P4 [4]; 
string U5 [5]; 
string P5 [4]; 
u8 input ;
u8 op;
u8 index_user;
u8 address_ID;
u8 address_PASS;
u8 Light_Control;
u8 tries = 3;
volatile u16 data;
u8 I;
string CH_ID[5];
string CH_PASS[4];

/*3*/

#define ADMIN_MODE '1'
#define USER_MODE  '2'


u8 STR_u8length(u8 *str);
u8 STR_u8compare(u8 *str1,u8 *str2);
void AdminMode(void);
void UserMode(void);
void ADC_Handler(u16 data)
{   
    static  u32 counter = 0;

    if(counter>100)
    {



        data = (u32)(data*500)/1024;

        if(data>30)
        {
            LED_voidTurnOn(LED_5);
        }
        else
        {
            LED_voidTurnOff(LED_5);
        }
        counter = 0 ;
        
    }
    else 
    {
        counter++;
    }
    
    Gpt_Reset(GPT_CHANNEL_TIM0);   
    
    
                
}

void main(void)
{   
   
  
    Uart_Init();
    EEPROM_VoidInit();
    SERVO_init();
    Adc_Init(&Adc_Configuration);
    LED_voidInit(LED_1);
    LED_voidInit(LED_2);
    LED_voidInit(LED_3);
    LED_voidInit(LED_4);
    LED_voidInit(LED_5);
    LED_voidTurnOn(LED_4);
    Adc_SetCallback(ADC_Handler);
    

    

    Gie_Enable();
    
    
    

    while(tries)
    {
        /*Receive all data from EEPROM*/
            EEPROM_VoidReceiveBuffer (0,U1,5);
            EEPROM_VoidReceiveBuffer (5,P1,5);
            EEPROM_VoidReceiveBuffer(10,U2,5);
            EEPROM_VoidReceiveBuffer(15,P2,5);
            EEPROM_VoidReceiveBuffer(20,U3,5);
            EEPROM_VoidReceiveBuffer(25,P3,5);
            EEPROM_VoidReceiveBuffer(30,U4,5);
            EEPROM_VoidReceiveBuffer(35,P4,5);
            EEPROM_VoidReceiveBuffer(40,U5,5);
            EEPROM_VoidReceiveBuffer(45,P5,5);
            
            /**
             * 
                Uart_SendString("\n\rUSER1\n\r");
                Uart_SendString(U1);
                Uart_SendString(P1);
                Uart_SendString("\n\rUSER2\n\r");
                Uart_SendString(U2);
                Uart_SendString(P2);
                Uart_SendString("\n\rUSER3\n\r");
                Uart_SendString(U3);
                Uart_SendString(P3);
                Uart_SendString("\n\rUSER4\n\r");
                Uart_SendString(U4);
                Uart_SendString(P4);
                Uart_SendString("\n\rUSER5\n\r");
                Uart_SendString(U5);
                Uart_SendString(P5);
            */
            

        Uart_SendString("\n\rPlease Enter Your Mode '1' for Admin '2' For User\n\r");
        input = Uart_Receive();
        if(input == ADMIN_MODE)
        {   
            Uart_SendString("\n\rADMIN MODE\n\r");
            while (tries)
            {

                Uart_SendString("\n\rPlease enter ID ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                Uart_ReceiveWord(CH_ID);

                if(STR_u8compare(U1,CH_ID))
                {   
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P1,CH_PASS))
                    {   
                        AdminMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else if (STR_u8compare(U2,CH_ID))
                {

                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P1,CH_PASS))
                    {
                        AdminMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else if (STR_u8compare(U3,CH_ID))
                {
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P3,CH_PASS))
                    {
                        AdminMode();
                        break;

                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }


                }
                else if (STR_u8compare(U4,CH_ID))
                {
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P4,CH_PASS))
                    {
                        AdminMode();
                        break;

                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }


                }
                else if (STR_u8compare(U5,CH_ID))
                {

                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P5,CH_PASS))
                    {
                        AdminMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else 
                {

                    Uart_SendString("\n\rWRONG ID\n\r");
                    tries--;
                }
            }

        }
        else if(input == USER_MODE)
        {

            Uart_SendString("\n\rUSER MODE\n\r");
                
            while (tries)
            {

                Uart_SendString("\n\rPlease enter ID ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                Uart_ReceiveWord(CH_ID);

                if(STR_u8compare(U1,CH_ID))
                {   
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P1,CH_PASS))
                    {
                        UserMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else if (STR_u8compare(U2,CH_ID))
                {

                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P1,CH_PASS))
                    {
                        UserMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else if (STR_u8compare(U3,CH_ID))
                {
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P3,CH_PASS))
                    {
                        UserMode();
                        break;

                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }


                }
                else if (STR_u8compare(U4,CH_ID))
                {
                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P4,CH_PASS))
                    {
                        UserMode();
                        break;

                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }


                }
                else if (STR_u8compare(U5,CH_ID))
                {

                    tries = 3;
                    Uart_SendString("\n\rPlease enter password ending with '+'\n\rNOTE THAT YOU HAVE ONLY THREE(3) TRIES");
                    Uart_ReceiveWord(CH_PASS);
                    if(STR_u8compare(P5,CH_PASS))
                    {
                        UserMode();
                        break;
                    }
                    else 
                    {
                        Uart_SendString("\n\rWRONG PASSWORD\n\r");
                        tries--;
                    }

                }
                else 
                {

                    Uart_SendString("\n\rWRONG ID\n\r");
                    tries--;
                }
            }

        }
        else
        {    
            Uart_SendString("\n\rWRONG INPUT\n\r");
        }

    }

    //BUZZER
    BuzzerInit();
    BuzzerOn(3);
    BuzzerOff();
}


void UserMode(void)
{
    Gpt_Init(GPT_CHANNEL_TIM0,&Gpt_Configuration[0]);
    Gpt_Start(GPT_CHANNEL_TIM0,GPT_PRESCALER_1024);
    Adc_EnableNotification();             
    Adc_StartConversion(ADC_CHANNEL_ADC0);
    while (1)
            {
                

                
          
                Uart_SendString("\n\rYOUR ARE IN\n\r");
                Uart_SendString("\n\r(1) to Open the door \n\r(2) to Turn On/Off the lights\n\r(3) to Turn On/Off the TV \n\r(4) to EXIT");
                op = Uart_Receive();
                


                if(op == '1')
                {
                    _delay_ms(300);
		            SERVO_SetAngle(45);
		            _delay_ms(300);
		            SERVO_SetAngle(90);
		            _delay_ms(300);
		            SERVO_SetAngle(135);
		            _delay_ms(300);
		            SERVO_SetAngle(180);
		            _delay_ms(3000);
		            SERVO_SetAngle(135);
                    _delay_ms(300);
		            SERVO_SetAngle(90);
                    _delay_ms(300);
		            SERVO_SetAngle(45);
                    _delay_ms(300);
		            SERVO_SetAngle(0);

                }
                else if (op == '2')
                {
                    Uart_SendString("\n\r(1)ON \n\r(2)OFF ");
                    Light_Control = Uart_Receive();
                    if(Light_Control == '1')
                    {
                        LED_voidTurnOn(LED_1);
                        LED_voidTurnOn(LED_2);

                    }
                    else if (Light_Control == '2')
                    {
                        LED_voidTurnOff(LED_1);
                        LED_voidTurnOff(LED_2);

                    }
                    else
                    {
                        Uart_SendString("\n\rWrong Input\n\r");
                    }


                }
                else if (op == '3')
                {
                     Uart_SendString("\n\r(1)ON \n\r(2)OFF ");
                    Light_Control = Uart_Receive();
                    if(Light_Control == '1')
                    {
                        LED_voidTurnOn(LED_3);
                        LED_voidTurnOff(LED_4);

                    }
                    else if (Light_Control == '2')
                    {
                        LED_voidTurnOff(LED_3);
                        LED_voidTurnOn(LED_4);

                    }
                    else
                    {
                        Uart_SendString("\n\rWrong Input\n\r");
                    }

                }
                else if (op == '4')
                {
                    Uart_SendString("\n\rGOODBYE\n\r");
                    Adc_DisableNotification();
                    Gpt_Stop(GPT_CHANNEL_TIM0);
                    break;
                }
                else
                {
                    Uart_SendString("\n\rWRONG INPUT\n\r");
                }

            }
}

void AdminMode(void)
{
    while (1)
            {
                
            
                Uart_SendString("\n\rYOUR ARE IN\n\r");
                Uart_SendString("\n\r(1) to add user \n\r(2) to modify user \n\r(3) to EXIT");
                op = Uart_Receive();

                if(op == '1')
                {
                    Uart_SendString("\n\rADD USER\n\r");
                    Uart_SendString("\n\rNOTE:\n\r");
                    Uart_SendString("\n\rID must be 4 Litter/Num ending with '+' as 5th \n\r");
                    Uart_SendString("\n\rPassword must be 3 Litter/Num ending with '+' as 4th \n\r");
                    Uart_SendString("\n\rPlease Enter User index from (1-4)");
                    index_user = Uart_Receive();
                    address_ID   = (index_user-48)*10;
                    address_PASS = address_ID+5;

                    Uart_SendString("\n\rPlease enter ID ending with '+'");
                    Uart_ReceiveWord(CH_ID);
                    Uart_SendString("\n\rPlease enter Password ending with '+'");
                    Uart_ReceiveWord(CH_PASS);

                    EEPROM_VoidSendBuffer(address_ID,CH_ID,sizeof(CH_ID));
                    EEPROM_VoidSendBuffer(address_PASS,CH_PASS,sizeof(CH_PASS));

                    Uart_SendString("\n\r>>>>>>>>USER ADDED<<<<<<<<<<<<<<<<<\n\r");
                    

                    
  
    
                }
                else if (op == '2')
                {
                    Uart_SendString("\n\rMODIFY USER\n\r");
                     
                    Uart_SendString("\n\rNOTE:\n\r");
                    Uart_SendString("\n\rID must be 4 Litter/Num ending with '+' as 5th \n\r");
                    Uart_SendString("\n\rPassword must be 3 Litter/Num ending with '+' as 4th \n\r");
                    Uart_SendString("\n\rPlease Enter User index from (1-4)");
                    index_user = Uart_Receive();
                    address_ID   = (index_user-48)*10;
                    address_PASS = address_ID+5;

                    Uart_SendString("\n\rPlease enter ID ending with '+'");
                    Uart_ReceiveWord(CH_ID);
                    Uart_SendString("\n\rPlease enter Password ending with '+'");
                    Uart_ReceiveWord(CH_PASS);

                    EEPROM_VoidSendBuffer(address_ID,CH_ID,sizeof(CH_ID));
                    EEPROM_VoidSendBuffer(address_PASS,CH_PASS,sizeof(CH_PASS));

                    Uart_SendString("\n\r>>>>>>>>USER MODIFIED<<<<<<<<<<<<<<<<<\n\r");
                   

                }
                else if (op == '3')
                {
                    Uart_SendString("\n\rGOODBYE\n\r");
                    break;
                }
                else
                {
                    Uart_SendString("\n\rWRONG INPUT\n\r");
                }

            }
}

u8 STR_u8length(u8 *str)
{
	u8 i;
    for(i=0;str[i]!='\0';i++)
    {

    }
    return i;
}

u8 STR_u8compare(u8 *str1,u8 *str2)
{
	u8 i;
    if (STR_u8length(str1)!=STR_u8length(str2))
    {
        return 0;
    }
    else
    {
        for (i=0;str1[i]!='\0';i++)
        {
            if (str1[i]!=str2[i])
                return 0;
        }
        return 1;
    }
}
#endif 
