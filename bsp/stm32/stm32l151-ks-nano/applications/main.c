/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-27     balanceTWK   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED0 pin: PC3 */
#define LED0_PIN    GET_PIN(C, 3)

int main(void)
{
    int count = 1;
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
		//GPIOC->MODER = GPIO_MODER_MODER3_0;


    while (count++)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
				//GPIOC->BSRR = GPIO_BSRR_BS_3;
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
				//GPIOC->BSRR = GPIO_BSRR_BR_3;
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
