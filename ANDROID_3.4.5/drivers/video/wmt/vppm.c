/*++
 * linux/drivers/video/wmt/vppm.c
 * WonderMedia video post processor (VPP) driver
 *
 * Copyright c 2013  WonderMedia  Technologies, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * WonderMedia Technologies, Inc.
 * 4F, 533, Chung-Cheng Road, Hsin-Tien, Taipei 231, R.O.C
--*/

#define VPPM_C
/* #define DEBUG */
/* #define DEBUG_DETAIL */

#include "vppm.h"
HW_REG struct vppm_base_regs *vppm_regs = (void *) VPP_BASE_ADDR;

void vppm_set_int_enable(vpp_flag_t enable, enum vpp_int_t int_bit)
{
#ifdef WMT_FTBLK_SCL
	if (int_bit & VPP_INT_SCL_VBIE)
		vppm_regs->int_en.b.scl_vbie = enable;
	if (int_bit & VPP_INT_SCL_VBIS)
		vppm_regs->int_en.b.scl_vbis = enable;
	if (int_bit & VPP_INT_SCL_PVBI)
		vppm_regs->int_en.b.scl_pvbi = enable;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_bit & VPP_INT_GOVRH_VBIE)
		vppm_regs->int_en.b.govrh_vbie = enable;
	if (int_bit & VPP_INT_GOVRH_VBIS)
		vppm_regs->int_en.b.govrh_vbis = enable;
	if (int_bit & VPP_INT_GOVRH_PVBI)
		vppm_regs->int_en.b.govrh_pvbi = enable;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_bit & VPP_INT_GOVRH2_VBIE)
		vppm_regs->int_en.b.govrh2_vbie = enable;
	if (int_bit & VPP_INT_GOVRH2_VBIS)
		vppm_regs->int_en.b.govrh2_vbis = enable;
	if (int_bit & VPP_INT_GOVRH2_PVBI)
		vppm_regs->int_en.b.govrh2_pvbi = enable;
#endif
}

int vppm_get_int_enable(enum vpp_int_t int_bit)
{
	int ret = 0;

#ifdef WMT_FTBLK_SCL
	if (int_bit & VPP_INT_SCL_VBIE)
		ret = vppm_regs->int_en.b.scl_vbie;
	if (int_bit & VPP_INT_SCL_VBIS)
		ret = vppm_regs->int_en.b.scl_vbis;
	if (int_bit & VPP_INT_SCL_PVBI)
		ret = vppm_regs->int_en.b.scl_pvbi;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_bit & VPP_INT_GOVRH_VBIE)
		ret = vppm_regs->int_en.b.govrh_vbie;
	if (int_bit & VPP_INT_GOVRH_VBIS)
		ret = vppm_regs->int_en.b.govrh_vbis;
	if (int_bit & VPP_INT_GOVRH_PVBI)
		ret = vppm_regs->int_en.b.govrh_pvbi;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_bit & VPP_INT_GOVRH2_VBIE)
		ret = vppm_regs->int_en.b.govrh2_vbie;
	if (int_bit & VPP_INT_GOVRH2_VBIS)
		ret = vppm_regs->int_en.b.govrh2_vbis;
	if (int_bit & VPP_INT_GOVRH2_PVBI)
		ret = vppm_regs->int_en.b.govrh2_pvbi;
#endif
	return ret;
}

enum vpp_int_t vppm_get_int_status(void)
{
	unsigned int int_enable_reg;
	unsigned int int_sts_reg;
	enum vpp_int_t int_sts = 0;

	int_enable_reg = vppm_regs->int_en.val;
	int_sts_reg = vppm_regs->int_sts.val;

#ifdef WMT_FTBLK_SCL
	if (vppm_regs->int_en.b.scl_vbie && vppm_regs->int_sts.b.scl_vbie)
		int_sts |= VPP_INT_SCL_VBIE;
	if (vppm_regs->int_en.b.scl_vbis && vppm_regs->int_sts.b.scl_vbis)
		int_sts |= VPP_INT_SCL_VBIS;
	if (vppm_regs->int_en.b.scl_pvbi && vppm_regs->int_sts.b.scl_pvbi)
		int_sts |= VPP_INT_SCL_PVBI;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (vppm_regs->int_en.b.govrh_pvbi && vppm_regs->int_sts.b.govrh_pvbi)
		int_sts |= VPP_INT_GOVRH_PVBI;
	if (vppm_regs->int_en.b.govrh_vbis && vppm_regs->int_sts.b.govrh_vbis)
		int_sts |= VPP_INT_GOVRH_VBIS;
	if (vppm_regs->int_en.b.govrh_vbie && vppm_regs->int_sts.b.govrh_vbie)
		int_sts |= VPP_INT_GOVRH_VBIE;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (vppm_regs->int_en.b.govrh2_pvbi && vppm_regs->int_sts.b.govrh2_pvbi)
		int_sts |= VPP_INT_GOVRH2_PVBI;
	if (vppm_regs->int_en.b.govrh2_vbis && vppm_regs->int_sts.b.govrh2_vbis)
		int_sts |= VPP_INT_GOVRH2_VBIS;
	if (vppm_regs->int_en.b.govrh2_vbie && vppm_regs->int_sts.b.govrh2_vbie)
		int_sts |= VPP_INT_GOVRH2_VBIE;
#endif
	return int_sts;
}

void vppm_clean_int_status(enum vpp_int_t int_sts)
{
#ifdef WMT_FTBLK_SCL
	if (int_sts & VPP_INT_SCL_VBIE)
		vppm_regs->int_sts.val = BIT18;
	if (int_sts & VPP_INT_SCL_VBIS)
		vppm_regs->int_sts.val = BIT17;
	if (int_sts & VPP_INT_SCL_PVBI)
		vppm_regs->int_sts.val = BIT16;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_sts & VPP_INT_GOVRH_VBIE)
		vppm_regs->int_sts.val = BIT10;
	if (int_sts & VPP_INT_GOVRH_VBIS)
		vppm_regs->int_sts.val = BIT9;
	if (int_sts & VPP_INT_GOVRH_PVBI)
		vppm_regs->int_sts.val = BIT8;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (int_sts & VPP_INT_GOVRH2_VBIE)
		vppm_regs->int_sts.val = BIT14;
	if (int_sts & VPP_INT_GOVRH2_VBIS)
		vppm_regs->int_sts.val = BIT13;
	if (int_sts & VPP_INT_GOVRH2_PVBI)
		vppm_regs->int_sts.val = BIT12;
#endif
}

void vppm_set_module_reset(vpp_mod_t mod)
{
	unsigned int value1 = 0x00, value2 = 0x00;
	unsigned int value3 = 0x00;

#ifdef WMT_FTBLK_SCL
	if (mod == VPP_MOD_SCL)
		value1 |= BIT0;
#endif
#ifdef WMT_FTBLK_GOVRH
	if (mod == VPP_MOD_GOVRH)
		value2 |= (BIT0 | BIT8 | BIT9);
#endif
	vppm_regs->sw_reset1.val = ~value1;
	vppm_regs->sw_reset1.val = 0x1010101;
	vppm_regs->sw_reset2.val = ~value2;
	vppm_regs->sw_reset2.val = 0x1011311;
	vppm_regs->sw_reset3.val = ~value3;
	vppm_regs->sw_reset3.val = 0x10101;
}

void vppm_reg_dump(void)
{
	unsigned int reg1, reg2;

	DPRINT("========== VPPM register dump ==========\n");
	vpp_reg_dump(REG_VPP_BEGIN, REG_VPP_END - REG_VPP_BEGIN);

	DPRINT("---------- VPP Interrupt ----------\n");
	reg1 = vppm_regs->int_sts.val;
	reg2 = vppm_regs->int_en.val;
	DPRINT("GOVRH PVBI(En %d,%d),VBIS(En %d,%d),VBIE(En %d,%d)\n",
		vppm_regs->int_en.b.govrh_pvbi,
		vppm_regs->int_sts.b.govrh_pvbi,
		vppm_regs->int_en.b.govrh_vbis,
		vppm_regs->int_sts.b.govrh_vbis,
		vppm_regs->int_en.b.govrh_vbie,
		vppm_regs->int_sts.b.govrh_vbie);

	DPRINT("GOVRH2 PVBI(En %d,%d),VBIS(En %d,%d),VBIE(En %d,%d)\n",
		vppm_regs->int_en.b.govrh2_pvbi,
		vppm_regs->int_sts.b.govrh2_pvbi,
		vppm_regs->int_en.b.govrh2_vbis,
		vppm_regs->int_sts.b.govrh2_vbis,
		vppm_regs->int_en.b.govrh2_vbie,
		vppm_regs->int_sts.b.govrh2_vbie);

	DPRINT("SCL PVBI(En %d,%d),VBIS(En %d,%d),VBIE(En %d,%d)\n",
		vppm_regs->int_en.b.scl_pvbi,
		vppm_regs->int_sts.b.scl_pvbi,
		vppm_regs->int_en.b.scl_vbis,
		vppm_regs->int_sts.b.scl_vbis,
		vppm_regs->int_en.b.scl_vbie,
		vppm_regs->int_sts.b.scl_vbie);
}

#ifdef CONFIG_PM
void vppm_suspend(int sts)
{
	switch (sts) {
	case 0:	/* disable module */
		break;
	case 1: /* disable tg */
		break;
	case 2:	/* backup register */
		p_vppm->reg_bk = vpp_backup_reg(REG_VPP_BEGIN,
			(REG_VPP_END - REG_VPP_BEGIN));
		break;
	default:
		break;
	}
}

void vppm_resume(int sts)
{
	switch (sts) {
	case 0:	/* restore register */
		vpp_restore_reg(REG_VPP_BEGIN, (REG_VPP_END - REG_VPP_BEGIN),
			p_vppm->reg_bk);
		p_vppm->reg_bk = 0;
		break;
	case 1:	/* enable module */
		break;
	case 2: /* enable tg */
		break;
	default:
		break;
	}
}
#else
#define vppm_suspend NULL
#define vppm_resume NULL
#endif

void vppm_init(void *base)
{
	struct vppm_mod_t *mod_p;

	mod_p = (struct vppm_mod_t *) base;

	vppm_set_module_reset(0);
	vppm_set_int_enable(VPP_FLAG_ENABLE, mod_p->int_catch);
	vppm_clean_int_status(~0);
}

int vppm_mod_init(void)
{
	struct vppm_mod_t *mod_p;

	mod_p = (struct vppm_mod_t *) vpp_mod_register(VPP_MOD_VPPM,
		sizeof(struct vppm_mod_t), 0);
	if (!mod_p) {
		DPRINT("*E* VPP module register fail\n");
		return -1;
	}

	/* module member variable */
	mod_p->int_catch = VPP_INT_NULL;

	/* module member function */
	mod_p->init = vppm_init;
	mod_p->dump_reg = vppm_reg_dump;
	mod_p->get_sts = vppm_get_int_status;
	mod_p->clr_sts = vppm_clean_int_status;
	mod_p->suspend = vppm_suspend;
	mod_p->resume = vppm_resume;

	p_vppm = mod_p;
	return 0;
}
module_init(vppm_mod_init);
