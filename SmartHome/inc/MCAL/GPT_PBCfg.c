/*
 * GPT_PBCfg.c
 *
 *  Created on: Apr 8, 2023
 *      Author: 20115
 */
#include <MCAL/GPT_interface.h>

Gpt_ConfigType Gpt_Configuration [3] = {
    /* Configuration for TIM0 */
    {
        GPT_MODE_NORMAL,
        GPT_COMP_OUT_MODE_DISCONNECTED
    },
    /* Configuration for TIM1 */
    {
        GPT_MODE_NORMAL,
        GPT_COMP_OUT_MODE_DISCONNECTED
    },
    /* Configuration for TIM2 */
    {
        GPT_MODE_CTC,
        GPT_COMP_OUT_MODE_DISCONNECTED
    }
};


