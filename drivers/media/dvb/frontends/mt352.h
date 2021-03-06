/*
 *  Driver for Zarlink DVB-T MT352 demodulator
 *
 *  Written by Holger Waechtler <holger@qanu.de>
 *	 and Daniel Mack <daniel@qanu.de>
 *
 *  AVerMedia AVerTV DVB-T 771 support by
 *       Wolfram Joost <dbox2@frokaschwei.de>
 *
 *  Support for Samsung TDTC9251DH01C(M) tuner
 *  Copyright (C) 2004 Antonio Mancuso <antonio.mancuso@digitaltelevision.it>
 *                     Amauri  Celani  <acelani@essegi.net>
 *
 *  DVICO FusionHDTV DVB-T1 and DVICO FusionHDTV DVB-T Lite support by
 *       Christopher Pascoe <c.pascoe@itee.uq.edu.au>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.=
 */

#ifndef MT352_H
#define MT352_H

#include <linux/dvb/frontend.h>

struct mt352_config
{
	
	u8 demod_address;

	
	int adc_clock;  
	int if2;        

	
	int no_tuner;

	
	int (*demod_init)(struct dvb_frontend* fe);
};

#if defined(CONFIG_DVB_MT352) || (defined(CONFIG_DVB_MT352_MODULE) && defined(MODULE))
extern struct dvb_frontend* mt352_attach(const struct mt352_config* config,
					 struct i2c_adapter* i2c);
#else
static inline struct dvb_frontend* mt352_attach(const struct mt352_config* config,
					 struct i2c_adapter* i2c)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif 

static inline int mt352_write(struct dvb_frontend *fe, const u8 buf[], int len) {
	int r = 0;
	if (fe->ops.write)
		r = fe->ops.write(fe, buf, len);
	return r;
}

#endif 
