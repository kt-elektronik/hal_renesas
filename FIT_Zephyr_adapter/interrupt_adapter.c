/*
 * The functions in this file replace (as far as required) the public interrupt
 * handling functions of the r_bsp FIT module interrupt handling (as declared
 * in FITModules\r_bsp\mcu\all\r_bsp_interrupts.h and
 * FITModules\r_bsp\mcu\rx64m\mcu_interrupts.h). To avoid interference between
 * FIT module based and Zephyr based interrupt handling.
 *
 * Copyright (c) 2021 KT-Elektronik, Klaucke und Partner GmbH
 * SPDX-License-Identifier: Apache-2.0
 */

#include "irq.h"
#include <drivers/interrupt_controller/rxv2_irq.h>
#include "mcu_interrupts.h"
#include "r_bsp_interrupts.h"

/* group interrupt callback structure for EINT0 */
static struct grp_intc_rx65n_callback eint0_callback;

void R_BSP_InterruptRequestEnable(uint32_t vector)
{
    /* not implemented for now*/
}

void R_BSP_InterruptRequestDisable(uint32_t vector)
{
    /* not implemented for now */
}

bsp_int_err_t R_BSP_InterruptWrite(bsp_int_src_t vector, bsp_int_cb_t callback)
{
	switch (vector) {
	case BSP_INT_SRC_AL1_EDMAC0_EINT0:
		eint0_callback.callback = (void (*)(const void *))callback;
		eint0_callback.param = NULL;
		eint0_callback.pin_mask = BIT(4);
		grp_intc_rx65n_manage_callback(device_get_binding("INT_AL1"), &eint0_callback, true);
	break;
	default:
	break;
	}

	return BSP_INT_SUCCESS;
}

bsp_int_err_t R_BSP_InterruptRead(bsp_int_src_t vector, bsp_int_cb_t *callback)
{
	return BSP_INT_SUCCESS;
}
bsp_int_err_t R_BSP_InterruptControl(bsp_int_src_t vector, bsp_int_cmd_t cmd, void *pdata)
{
	return BSP_INT_SUCCESS;
}

bsp_int_err_t bsp_interrupt_enable_disable(bsp_int_src_t vector, bool enable)
{
	return BSP_INT_SUCCESS;
}
