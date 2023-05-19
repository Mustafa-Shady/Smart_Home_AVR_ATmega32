/*
 * Extint_prog.c
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */
#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <MCAL/Extint_Cfg.h>
#include <MCAL/Extint_interface.h>
#include <MCAL/ExtInt_private.h>



/***********************************************************/
#if EXTINT_INT0

void (*Callback_Int0) (void) = NULL_PTR;

ISR(VECTOR_INT0)
{
	if (NULL_PTR != Callback_Int0) {
        Callback_Int0();
    }
}

void ExtInt0_SetTriggerEdge(u8 edge)
{
     switch (edge)
        {
        case EXTINT_TRG_LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
            break;
        case EXTINT_TRG_ON_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
            break;
        case EXTINT_TRG_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
            break;
        case EXTINT_TRG_RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
            break;
        default:
            break;
        }
}
void ExtInt0_EnableNotification(void)
{
    SET_BIT(GICR, GICR_INT0);

}
void ExtInt0_DisableNotification(void)
{
    CLR_BIT(GICR, GICR_INT0);

}
void ExtInt0_ClearFlag(void)
{
    SET_BIT(GIFR, GIFR_INTF0);
}
u8   ExtInt0_ReadFlag(void)
{
    u8 flag = 0;
    flag = GET_BIT(GIFR, GIFR_INTF0);
    return flag;
}
void ExInt0_SetCallback(void (*funcPtr) (void))
{
     Callback_Int0 = funcPtr;
}

#endif
/***********************************************************/
#if EXTINT_INT1

void (*Callback_Int1) (void) = NULL_PTR;

ISR(VECTOR_INT1)
{
	if (NULL_PTR != Callback_Int1) {
        Callback_Int1();
    }
} 

void ExtInt1_SetTriggerEdge(u8 edge)
{
    switch (edge)
        {
        case EXTINT_TRG_LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTINT_TRG_ON_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTINT_TRG_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTINT_TRG_RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
            break;
        default:
            break;
        }
}
void ExtInt1_EnableNotification(void)
{
    SET_BIT(GICR, GICR_INT1);
}
void ExtInt1_DisableNotification(void)
{
    CLR_BIT(GICR, GICR_INT1);
}
void ExtInt1_ClearFlag(void)
{
    SET_BIT(GIFR, GIFR_INTF1);
}
u8   ExtInt1_ReadFlag(void)
{
    u8 flag = 0;
    flag = GET_BIT(GIFR, GIFR_INTF1);
    return flag;
}
void ExInt1_SetCallback(void (*funcPtr) (void))
{
    Callback_Int1 = funcPtr;
}

#endif
/***********************************************************/
#if EXTINT_INT2

void (*Callback_Int2) (void) = NULL_PTR;

ISR(VECTOR_INT2)
{
	if (NULL_PTR != Callback_Int2) {
        Callback_Int2();
    }
}

void ExtInt2_SetTriggerEdge(u8 edge)
{
      switch (edge)
        {
        case EXTINT_TRG_FALLING_EDGE:
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        case EXTINT_TRG_RISING_EDGE:
            SET_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        default:
        
        SET_BIT(MCUCSR, MCUCSR_ISC2);

            break;
        }
}
void ExtInt2_EnableNotification(void)
{
    SET_BIT(GICR, GICR_INT2);
}
void ExtInt2_DisableNotification(void)
{
    CLR_BIT(GICR, GICR_INT2);
}
void ExtInt2_ClearFlag(void)
{
    SET_BIT(GIFR, GIFR_INTF2);
}
u8   ExtInt2_ReadFlag(void)
{
    u8 flag = 0;
    flag = GET_BIT(GIFR, GIFR_INTF2);
    return flag;
}
void ExInt2_SetCallback(void (*funcPtr) (void))
{
    Callback_Int2 = funcPtr;
}

#endif
/***********************************************************/