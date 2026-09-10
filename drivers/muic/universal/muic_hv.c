/*
 * muic_hv_afc.c
 *
 *  Copyright (C) 2012 Samsung Electronics
 *  Thomas Ryu <smilesr.ryu@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/workqueue.h>
#include <linux/delay.h>

/* MUIC header file */
#include <linux/muic/muic.h>
#include "muic-internal.h"
#include "muic_state.h"
#include "muic_i2c.h"
#include "muic_vps.h"
#include "muic_apis.h"
#include "muic_dt.h"
#include "muic_hv.h"
#include "muic_debug.h"

#if defined(CONFIG_MUIC_NOTIFIER)
#include <linux/muic/muic_notifier.h>
#endif /* CONFIG_MUIC_NOTIFIER */

#if defined(CONFIG_MUIC_SUPPORT_CCIC)
#include "muic_ccic.h"
#endif

extern struct muic_platform_data muic_pdata;

int muic_set_afc(bool enable)
{
	return muic_pdata.set_afc(enable);
}

void hv_afc_init(muic_data_t *pmuic)
{
}

void hv_afc_init_detect(muic_data_t *pmuic)
{
}

void hv_afc_irq_init(muic_data_t *pmuic)
{
}

void hv_afc_delay_check_state(muic_data_t *pmuic, int state)
{
}

void hv_afc_clear_hvcontrol(muic_data_t *pmuic)
{
}

void hv_afc_prepare_charger(muic_data_t *pmuic)
{
}

bool hv_afc_do_predetach(muic_data_t *pmuic, int mdev)
{
	bool ret = false;

	return ret;
}

void hv_afc_do_detach(muic_data_t *pmuic){
}

void hv_afc_remove(muic_data_t *pmuic)
{
}

muic_attached_dev_t hv_afc_check_id_err(muic_data_t *pmuic, muic_attached_dev_t new_dev)
{
	muic_attached_dev_t ret = 0;

	return ret;
}

void hv_update_status(struct hv_data *phv, int mdev)
{
	if (!phv) {
		pr_err("%s:%s: hv is not ready.\n", __func__, MUIC_HV_DEV_NAME);
		return;
	}
	MUIC_INFO_K("%s:%s mdev %d->%d\n", __func__, MUIC_HV_DEV_NAME, phv->attached_dev, mdev);
	phv->attached_dev = mdev;
}
