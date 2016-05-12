/*-
 * Copyright (c) 2007 Bruce M. Simpson.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * TODO: sprom
 * TODO: implement dma translation bits (if needed for system bus)
 */

#ifndef _SIBA_SIBAREG_H_
#define	_SIBA_SIBAREG_H_

#define	PCI_DEVICE_ID_BCM4401		0x4401
#define	PCI_DEVICE_ID_BCM4401B0		0x4402
#define	PCI_DEVICE_ID_BCM4401B1		0x170c
#define	SIBA_PCIR_BAR			PCIR_BAR(0)
#define	SIBA_CCID_BCM4710		0x4710
#define	SIBA_CCID_BCM4704		0x4704
#define	SIBA_CCID_SENTRY5		0x5365

/*
 * ChipCommon registers.
 */
#define	SIBA_CC_CHIPID			0x0000
#define	SIBA_CC_IDMASK			0x0000ffff
#define	SIBA_CC_ID(id)			(id & SIBA_CC_IDMASK)
#define	SIBA_CC_REVMASK			0x000f0000
#define	SIBA_CC_REVSHIFT		16
#define	SIBA_CC_REV(id)							\
	((id & SIBA_CC_REVMASK) >> SIBA_CC_REVSHIFT)
#define	SIBA_CC_PKGMASK			0x00F00000
#define	SIBA_CC_PKGSHIFT		20
#define	SIBA_CC_PKG(id)							\
	((id & SIBA_CC_PKGMASK) >> SIBA_CC_PKGSHIFT)
#define	SIBA_CC_NCORESMASK		0x0F000000
#define	SIBA_CC_NCORESSHIFT		24
#define	SIBA_CC_NCORES(id)						\
	((id & SIBA_CC_NCORESMASK) >> SIBA_CC_NCORESSHIFT)
#define	SIBA_CC_CAPS			0x0004
#define	SIBA_CC_CAPS_PWCTL		0x00040000
#define	SIBA_CC_CAPS_PMU		0x10000000	/* PMU (rev >= 20) */
#define	SIBA_CC_CHIPCTL			0x0028		/* rev >= 11 */
#define	SIBA_CC_CHIPSTAT		0x002C		/* rev >= 11 */
#define	SIBA_CC_BCAST_ADDR		0x0050		/* Broadcast Address */
#define	SIBA_CC_BCAST_DATA		0x0054		/* Broadcast Data */
#define	SIBA_CC_PLLONDELAY		0x00B0		/* Rev >= 4 only */
#define	SIBA_CC_FREFSELDELAY		0x00B4		/* Rev >= 4 only */
#define	SIBA_CC_CLKSLOW			0x00b8		/* 6 <= Rev <= 9 only */
#define	SIBA_CC_CLKSLOW_SRC		0x00000007
#define	SIBA_CC_CLKSLOW_SRC_CRYSTAL	0x00000001
#define	SIBA_CC_CLKSLOW_FSLOW		0x00000800
#define	SIBA_CC_CLKSLOW_IPLL		0x00001000
#define	SIBA_CC_CLKSLOW_ENXTAL		0x00002000
#define	SIBA_CC_CLKSYSCTL		0x00C0		/* Rev >= 3 only */
#define	SIBA_CC_CLKCTLSTATUS		0x01e0
#define	SIBA_CC_CLKCTLSTATUS_HT		0x00010000
#define	SIBA_CC_UART0			0x0300		/* offset of UART0 */
#define	SIBA_CC_UART1			0x0400		/* offset of UART1 */
#define	SIBA_CC_PMUCTL			0x0600		/* PMU control */
#define	SIBA_CC_PMUCTL_PLL_UPD		0x00000400
#define	SIBA_CC_PMUCTL_ILP		0xffff0000	/* mask */
#define	SIBA_CC_PMUCTL_NOILP		0x00000200
#define	SIBA_CC_PMUCTL_XF		0x0000007c	/* crystal freq */
#define	SIBA_CC_PMUCTL_XF_VAL(id)	((id & 0x0000007c) >> 2)
#define	SIBA_CC_PMUCAPS			0x0604
#define	SIBA_CC_PMUCAPS_REV		0x000000ff
#define	SIBA_CC_PMU_MINRES		0x0618
#define	SIBA_CC_PMU_MAXRES		0x061c
#define	SIBA_CC_PMU_TABSEL		0x0620
#define	SIBA_CC_PMU_DEPMSK		0x0624
#define	SIBA_CC_PMU_UPDNTM		0x0628
#define	SIBA_CC_CHIPCTL_ADDR		0x0650
#define	SIBA_CC_CHIPCTL_DATA		0x0654
#define	SIBA_CC_REGCTL_ADDR		0x0658
#define	SIBA_CC_REGCTL_DATA		0x065c
#define	SIBA_CC_PLLCTL_ADDR		0x0660
#define	SIBA_CC_PLLCTL_DATA		0x0664

#define	SIBA_CC_PMU0_PLL0		0
#define	SIBA_CC_PMU0_PLL0_PDIV_MSK	0x00000001
#define	SIBA_CC_PMU0_PLL0_PDIV_FREQ	25000
#define	SIBA_CC_PMU0_PLL1		1
#define	SIBA_CC_PMU0_PLL1_IMSK		0xf0000000
#define	SIBA_CC_PMU0_PLL1_FMSK		0x0fffff00
#define	SIBA_CC_PMU0_PLL1_STOPMOD	0x00000040
#define	SIBA_CC_PMU0_PLL2		2
#define	SIBA_CC_PMU0_PLL2_IMSKHI	0x0000000f
#define	SIBA_CC_PMU1_PLL0		0
#define	SIBA_CC_PMU1_PLL0_P1DIV		0x00f00000
#define	SIBA_CC_PMU1_PLL0_P2DIV		0x0f000000
#define	SIBA_CC_PMU1_PLL1		1
#define	SIBA_CC_PMU1_PLL2		2
#define	SIBA_CC_PMU1_PLL2_NDIVMODE	0x000e0000
#define	SIBA_CC_PMU1_PLL2_NDIVINT	0x1ff00000
#define	SIBA_CC_PMU1_PLL3		3
#define	SIBA_CC_PMU1_PLL3_NDIVFRAC	0x00ffffff
#define	SIBA_CC_PMU1_PLL4		4
#define	SIBA_CC_PMU1_PLL5		5
#define	SIBA_CC_PMU1_PLL5_CLKDRV	0xffffff00

#define	SIBA_CC_PMU0_DEFAULT_XTALFREQ	20000
#define	SIBA_CC_PMU1_DEFAULT_FREQ	15360

#define	SIBA_CC_PMU1_PLLTAB_ENTRY					\
{									\
	{ 12000,  1, 3, 22,  0x9, 0xffffef },				\
	{ 13000,  2, 1,  6,  0xb, 0x483483 },				\
	{ 14400,  3, 1, 10,  0xa, 0x1c71c7 },				\
	{ 15360,  4, 1,  5,  0xb, 0x755555 },				\
	{ 16200,  5, 1, 10,  0x5, 0x6e9e06 },				\
	{ 16800,  6, 1, 10,  0x5, 0x3cf3cf },				\
	{ 19200,  7, 1,  9,  0x5, 0x17b425 },				\
	{ 19800,  8, 1, 11,  0x4, 0xa57eb },				\
	{ 20000,  9, 1, 11,  0x4, 0 },					\
	{ 24000, 10, 3, 11,  0xa, 0 },					\
	{ 25000, 11, 5, 16,  0xb, 0 },					\
	{ 26000, 12, 1,  2, 0x10, 0xec4ec4 },				\
	{ 30000, 13, 3,  8,  0xb, 0 },					\
	{ 38400, 14, 1,  5,  0x4, 0x955555 },				\
	{ 40000, 15, 1,  2,  0xb, 0 }					\
}

#define	SIBA_CC_PMU0_PLLTAB_ENTRY					\
{									\
	{ 12000,  1, 73, 349525, }, { 13000,  2, 67, 725937, },		\
	{ 14400,  3, 61, 116508, }, { 15360,  4, 57, 305834, },		\
	{ 16200,  5, 54, 336579, }, { 16800,  6, 52, 399457, },		\
	{ 19200,  7, 45, 873813, }, { 19800,  8, 44, 466033, },		\
	{ 20000,  9, 44, 0,      }, { 25000, 10, 70, 419430, },		\
	{ 26000, 11, 67, 725937, }, { 30000, 12, 58, 699050, },		\
	{ 38400, 13, 45, 873813, }, { 40000, 14, 45, 0,      },		\
}

#define	SIBA_CC_PMU_4312_PA_REF		2
#define	SIBA_CC_PMU_4325_BURST		1
#define	SIBA_CC_PMU_4325_CLBURST	3
#define	SIBA_CC_PMU_4325_LN		10
#define	SIBA_CC_PMU_4325_CRYSTAL	13
#define	SIBA_CC_PMU_4325_RX_PWR		15
#define	SIBA_CC_PMU_4325_TX_PWR		16
#define	SIBA_CC_PMU_4325_LOGEN_PWR	18
#define	SIBA_CC_PMU_4325_AFE_PWR	19
#define	SIBA_CC_PMU_4325_BBPLL_PWR	20
#define	SIBA_CC_PMU_4325_HT		21
#define	SIBA_CC_PMU_4328_EXT_SWITCH_PWM	0
#define	SIBA_CC_PMU_4328_BB_SWITCH_PWM	1
#define	SIBA_CC_PMU_4328_BB_SWITCH_BURST	2
#define	SIBA_CC_PMU_4328_BB_EXT_SWITCH_BURST	3
#define	SIBA_CC_PMU_4328_ILP_REQUEST	4
#define	SIBA_CC_PMU_4328_RADSWITCH_PWM	5	/* radio switch */
#define	SIBA_CC_PMU_4328_RADSWITCH_BURST	6
#define	SIBA_CC_PMU_4328_ROM_SWITCH	7
#define	SIBA_CC_PMU_4328_PA_REF		8
#define	SIBA_CC_PMU_4328_RADIO		9
#define	SIBA_CC_PMU_4328_AFE		10
#define	SIBA_CC_PMU_4328_PLL		11
#define	SIBA_CC_PMU_4328_BG_FILTBYP	12
#define	SIBA_CC_PMU_4328_TX_FILTBYP	13
#define	SIBA_CC_PMU_4328_RX_FILTBYP	14
#define	SIBA_CC_PMU_4328_CRYSTAL_PU	15
#define	SIBA_CC_PMU_4328_CRYSTAL_EN	16
#define	SIBA_CC_PMU_4328_BB_PLL_FILTBYP	17
#define	SIBA_CC_PMU_4328_RF_PLL_FILTBYP	18
#define	SIBA_CC_PMU_4328_BB_PLL_PU	19
#define	SIBA_CC_PMU_5354_PA_REF		8
#define	SIBA_CC_PMU_5354_BB_PLL_PU	19

#define	SIBA_CC_PMU_4325_RES_UPDOWN					\
{									\
	{ SIBA_CC_PMU_4325_CRYSTAL, 0x1501 }				\
}

#define	SIBA_CC_PMU_4325_RES_DEPEND					\
{									\
	{ SIBA_CC_PMU_4325_HT, SIBA_CC_PMU_DEP_ADD,			\
	  ((1 << SIBA_CC_PMU_4325_RX_PWR) |				\
	   (1 << SIBA_CC_PMU_4325_TX_PWR) |				\
	   (1 << SIBA_CC_PMU_4325_LOGEN_PWR) |				\
	   (1 << SIBA_CC_PMU_4325_AFE_PWR)) }				\
}

#define	SIBA_CC_PMU_4328_RES_UPDOWN					\
{									\
	{ SIBA_CC_PMU_4328_EXT_SWITCH_PWM, 0x0101 },			\
	{ SIBA_CC_PMU_4328_BB_SWITCH_PWM, 0x1f01 },			\
	{ SIBA_CC_PMU_4328_BB_SWITCH_BURST, 0x010f },			\
	{ SIBA_CC_PMU_4328_BB_EXT_SWITCH_BURST, 0x0101 },		\
	{ SIBA_CC_PMU_4328_ILP_REQUEST, 0x0202 },			\
	{ SIBA_CC_PMU_4328_RADSWITCH_PWM, 0x0f01 },			\
	{ SIBA_CC_PMU_4328_RADSWITCH_BURST, 0x0f01 },			\
	{ SIBA_CC_PMU_4328_ROM_SWITCH, 0x0101 },			\
	{ SIBA_CC_PMU_4328_PA_REF, 0x0f01 },				\
	{ SIBA_CC_PMU_4328_RADIO, 0x0f01 },				\
	{ SIBA_CC_PMU_4328_AFE, 0x0f01 },				\
	{ SIBA_CC_PMU_4328_PLL, 0x0f01 },				\
	{ SIBA_CC_PMU_4328_BG_FILTBYP, 0x0101 },			\
	{ SIBA_CC_PMU_4328_TX_FILTBYP, 0x0101 },			\
	{ SIBA_CC_PMU_4328_RX_FILTBYP, 0x0101 },			\
	{ SIBA_CC_PMU_4328_CRYSTAL_PU, 0x0101 },			\
	{ SIBA_CC_PMU_4328_CRYSTAL_EN, 0xa001 },			\
	{ SIBA_CC_PMU_4328_BB_PLL_FILTBYP, 0x0101 },			\
	{ SIBA_CC_PMU_4328_RF_PLL_FILTBYP, 0x0101 },			\
	{ SIBA_CC_PMU_4328_BB_PLL_PU, 0x0701 },				\
}

#define	SIBA_CC_PMU_4328_RES_DEPEND					\
{									\
	{ SIBA_CC_PMU_4328_ILP_REQUEST, SIBA_CC_PMU_DEP_SET,		\
	  ((1 << SIBA_CC_PMU_4328_EXT_SWITCH_PWM) |			\
	   (1 << SIBA_CC_PMU_4328_BB_SWITCH_PWM)) },			\
}

#define	SIBA_CC_CHST_4325_PMUTOP_2B	0x00000200

#define	SIBA_BAR0			0x80
#define	SIBA_IRQMASK			0x94
#define	SIBA_GPIO_IN			0xb0
#define	SIBA_GPIO_OUT			0xb4
#define	SIBA_GPIO_OUT_EN		0xb8
#define	SIBA_GPIO_CRYSTAL		0x40
#define	SIBA_GPIO_PLL			0x80

#define	SIBA_REGWIN(x)							\
	(SIBA_ENUM_START + ((x) * SIBA_CORE_LEN))
#define	SIBA_CORE_LEN		0x00001000	/* Size of cfg per core */
#define	SIBA_CFG_END		0x00010000	/* Upper bound of cfg space */
#define	SIBA_MAX_CORES		(SIBA_CFG_END/SIBA_CORE_LEN)	/* #max cores */
#define	SIBA_ENUM_START			0x18000000U
#define	SIBA_ENUM_END			0x18010000U

#define	SIBA_DMA_TRANSLATION_MASK	0xc0000000

#define	SIBA_PCI_DMA			0x40000000U
#define	SIBA_TPS			0x0f18
#define	SIBA_TPS_BPFLAG			0x0000003f
#define	SIBA_IAS			0x0f90     /* Initiator Agent State */
#define	SIBA_IAS_INBAND_ERR		0x00020000
#define	SIBA_IAS_TIMEOUT		0x00040000
#define	SIBA_INTR_MASK			0x0f94
#define	SIBA_TGSLOW			0x0f98
#define	SIBA_TGSLOW_RESET		0x00000001	/* target state low */
#define	SIBA_TGSLOW_REJECT_22		0x00000002
#define	SIBA_TGSLOW_REJECT_23		0x00000004
#define	SIBA_TGSLOW_CLOCK		0x00010000
#define	SIBA_TGSLOW_FGC			0x00020000
#define	SIBA_TGSHIGH			0x0f9c
#define	SIBA_TGSHIGH_SERR		0x00000001
#define	SIBA_TGSHIGH_BUSY		0x00000004
#define	SIBA_TGSHIGH_DMA64		0x10000000
#define	SIBA_IMCFGLO			0x0fa8
#define	SIBA_IMCFGLO_SERTO		0x00000007
#define	SIBA_IMCFGLO_REQTO		0x00000070
#define	SIBA_IDLOW			0x0ff8
#define	SIBA_IDLOW_SSBREV		0xf0000000
#define	SIBA_IDLOW_SSBREV_22		0x00000000
#define	SIBA_IDLOW_SSBREV_23		0x10000000
#define	SIBA_IDLOW_SSBREV_24		0x40000000
#define	SIBA_IDLOW_SSBREV_25		0x50000000
#define	SIBA_IDLOW_SSBREV_26		0x60000000
#define	SIBA_IDLOW_SSBREV_27		0x70000000
#define	SIBA_IDHIGH			0x0ffc
#define	SIBA_IDHIGH_CORECODEMASK	0x00008FF0 /* Core Code */
#define	SIBA_IDHIGH_CORECODE_SHIFT	4
#define	SIBA_IDHIGH_CORECODE(id)					\
	((id & SIBA_IDHIGH_CORECODEMASK) >> SIBA_IDHIGH_CORECODE_SHIFT)
/* Revision Code (low part) */
#define	SIBA_IDHIGH_REVLO		0x0000000f
/* Revision Code (high part) */
#define	SIBA_IDHIGH_REVHI		0x00007000
#define	SIBA_IDHIGH_REVHI_SHIFT	8
#define	SIBA_IDHIGH_REV(id)						\
	((id & SIBA_IDHIGH_REVLO) | ((id & SIBA_IDHIGH_REVHI) >>	\
	  	 SIBA_IDHIGH_REVHI_SHIFT))
#define	SIBA_IDHIGH_VENDORMASK		0xFFFF0000 /* Vendor Code */
#define	SIBA_IDHIGH_VENDOR_SHIFT	16
#define	SIBA_IDHIGH_VENDOR(id)						\
	((id & SIBA_IDHIGH_VENDORMASK) >> SIBA_IDHIGH_VENDOR_SHIFT)

#define	SIBA_SPROMSIZE_R123		64
#define	SIBA_SPROMSIZE_R4		220
#define	SIBA_SPROM_BASE			0x1000
#define	SIBA_SPROM_REV_CRC		0xff00

#define	SIBA_SPROM1_MAC_80211BG		0x1048
#define	SIBA_SPROM1_MAC_ETH		0x104e
#define	SIBA_SPROM1_MAC_80211A		0x1054
#define	SIBA_SPROM1_ETHPHY		0x105a
#define	SIBA_SPROM1_ETHPHY_MII_ETH0	0x001f
#define	SIBA_SPROM1_ETHPHY_MII_ETH1	0x03e0
#define	SIBA_SPROM1_ETHPHY_MDIO_ETH0	(1 << 14)
#define	SIBA_SPROM1_ETHPHY_MDIO_ETH1	(1 << 15)
#define	SIBA_SPROM1_BOARDINFO		0x105c
#define	SIBA_SPROM1_BOARDINFO_BREV	0x00ff
#define	SIBA_SPROM1_BOARDINFO_CCODE	0x0f00
#define	SIBA_SPROM1_BOARDINFO_ANTBG	0x3000
#define	SIBA_SPROM1_BOARDINFO_ANTA	0xc000
#define	SIBA_SPROM1_PA0B0		0x105e
#define	SIBA_SPROM1_PA0B1		0x1060
#define	SIBA_SPROM1_PA0B2		0x1062
#define	SIBA_SPROM1_GPIOA		0x1064
#define	SIBA_SPROM1_GPIOA_P0		0x00ff
#define	SIBA_SPROM1_GPIOA_P1		0xff00
#define	SIBA_SPROM1_GPIOB		0x1066
#define	SIBA_SPROM1_GPIOB_P2		0x00ff
#define	SIBA_SPROM1_GPIOB_P3		0xff00
#define	SIBA_SPROM1_MAXPWR		0x1068
#define	SIBA_SPROM1_MAXPWR_BG		0x00ff
#define	SIBA_SPROM1_MAXPWR_A		0xff00
#define	SIBA_SPROM1_PA1B0		0x106a
#define	SIBA_SPROM1_PA1B1		0x106c
#define	SIBA_SPROM1_PA1B2		0x106e
#define	SIBA_SPROM1_TSSI		0x1070
#define	SIBA_SPROM1_TSSI_BG		0x00ff
#define	SIBA_SPROM1_TSSI_A		0xff00
#define	SIBA_SPROM1_BFLOW		0x1072
#define	SIBA_SPROM1_AGAIN		0x1074
#define	SIBA_SPROM1_AGAIN_BG		0x00ff
#define	SIBA_SPROM1_AGAIN_A		0xff00

#define	SIBA_SPROM2_BFHIGH		0x1038

#define	SIBA_SPROM3_MAC_80211BG		0x104a

#define	SIBA_SPROM4_MAC_80211BG		0x104c
#define	SIBA_SPROM4_ETHPHY		0x105a
#define	SIBA_SPROM4_ETHPHY_ET0A		0x001f
#define	SIBA_SPROM4_ETHPHY_ET1A		0x03e0
#define	SIBA_SPROM4_CCODE		0x1052
#define	SIBA_SPROM4_ANTAVAIL		0x105d
#define	SIBA_SPROM4_ANTAVAIL_A		0x00ff
#define	SIBA_SPROM4_ANTAVAIL_BG		0xff00
#define	SIBA_SPROM4_BFLOW		0x1044
#define	SIBA_SPROM4_AGAIN01		0x105e
#define	SIBA_SPROM4_AGAIN0		0x00ff
#define	SIBA_SPROM4_AGAIN1		0xff00
#define	SIBA_SPROM4_AGAIN23		0x1060
#define	SIBA_SPROM4_AGAIN2		0x00ff
#define	SIBA_SPROM4_AGAIN3		0xff00
#define	SIBA_SPROM4_TXPID2G01		0x0062
#define	 SIBA_SPROM4_TXPID2G0		0x00ff
#define	 SIBA_SPROM4_TXPID2G1		0xff00
#define	SIBA_SPROM4_TXPID2G23		0x0064
#define	 SIBA_SPROM4_TXPID2G2		0x00ff
#define	 SIBA_SPROM4_TXPID2G3		0xff00
#define	SIBA_SPROM4_TXPID5G01		0x0066
#define	 SIBA_SPROM4_TXPID5G0		0x00ff
#define	 SIBA_SPROM4_TXPID5G1		0xff00
#define	SIBA_SPROM4_TXPID5G23		0x0068
#define	 SIBA_SPROM4_TXPID5G2		0x00ff
#define	 SIBA_SPROM4_TXPID5G3		0xff00
#define	SIBA_SPROM4_TXPID5GL01		0x006a
#define	 SIBA_SPROM4_TXPID5GL0		0x00ff
#define	 SIBA_SPROM4_TXPID5GL1		0xff00
#define	SIBA_SPROM4_TXPID5GL23		0x006c
#define	 SIBA_SPROM4_TXPID5GL2		0x00ff
#define	 SIBA_SPROM4_TXPID5GL3		0xff00
#define	SIBA_SPROM4_TXPID5GH01		0x006e
#define	 SIBA_SPROM4_TXPID5GH0		0x00ff
#define	 SIBA_SPROM4_TXPID5GH1		0xff00
#define	SIBA_SPROM4_TXPID5GH23		0x0070
#define	 SIBA_SPROM4_TXPID5GH2		0x00ff
#define	 SIBA_SPROM4_TXPID5GH3		0xff00
#define	SIBA_SPROM4_BFHIGH		0x1046
#define	SIBA_SPROM4_MAXP_BG		0x1080
#define	SIBA_SPROM4_MAXP_BG_MASK	0x00ff
#define	SIBA_SPROM4_TSSI_BG		0xff00
#define	SIBA_SPROM4_MAXP_A		0x108a
#define	SIBA_SPROM4_MAXP_A_MASK		0x00ff
#define	SIBA_SPROM4_TSSI_A		0xff00
#define	SIBA_SPROM4_GPIOA		0x1056
#define	SIBA_SPROM4_GPIOA_P0		0x00ff
#define	SIBA_SPROM4_GPIOA_P1		0xff00
#define	SIBA_SPROM4_GPIOB		0x1058
#define	SIBA_SPROM4_GPIOB_P2		0x00ff
#define	SIBA_SPROM4_GPIOB_P3		0xff00

/* The following four blocks share the same structure */
#define	SIBA_SPROM4_PWR_INFO_CORE0	0x0080
#define	SIBA_SPROM4_PWR_INFO_CORE1	0x00AE
#define	SIBA_SPROM4_PWR_INFO_CORE2	0x00DC
#define	SIBA_SPROM4_PWR_INFO_CORE3	0x010A

#define	SIBA_SPROM4_2G_MAXP_ITSSI	0x00    /* 2 GHz ITSSI and 2 GHz Max Power */
#define	 SIBA_SPROM4_2G_MAXP		0x00FF
#define	 SIBA_SPROM4_2G_ITSSI		0xFF00
#define	 SIBA_SPROM4_2G_ITSSI_SHIFT	8
#define	SIBA_SPROM4_2G_PA_0		0x02    /* 2 GHz power amp */
#define	SIBA_SPROM4_2G_PA_1		0x04
#define	SIBA_SPROM4_2G_PA_2		0x06
#define	SIBA_SPROM4_2G_PA_3		0x08
#define	SIBA_SPROM4_5G_MAXP_ITSSI	0x0A    /* 5 GHz ITSSI and 5.3 GHz Max Power */
#define	 SIBA_SPROM4_5G_MAXP		0x00FF
#define	 SIBA_SPROM4_5G_ITSSI		0xFF00
#define	 SIBA_SPROM4_5G_ITSSI_SHIFT	8
#define	SIBA_SPROM4_5GHL_MAXP		0x0C    /* 5.2 GHz and 5.8 GHz Max Power */
#define	 SIBA_SPROM4_5GH_MAXP		0x00FF
#define	 SIBA_SPROM4_5GL_MAXP		0xFF00
#define	 SIBA_SPROM4_5GL_MAXP_SHIFT	8
#define	SIBA_SPROM4_5G_PA_0		0x0E    /* 5.3 GHz power amp */
#define	SIBA_SPROM4_5G_PA_1		0x10
#define	SIBA_SPROM4_5G_PA_2		0x12
#define	SIBA_SPROM4_5G_PA_3		0x14
#define	SIBA_SPROM4_5GL_PA_0		0x16    /* 5.2 GHz power amp */
#define	SIBA_SPROM4_5GL_PA_1		0x18
#define	SIBA_SPROM4_5GL_PA_2		0x1A
#define	SIBA_SPROM4_5GL_PA_3		0x1C
#define	SIBA_SPROM4_5GH_PA_0		0x1E    /* 5.8 GHz power amp */
#define	SIBA_SPROM4_5GH_PA_1		0x20
#define	SIBA_SPROM4_5GH_PA_2		0x22
#define	SIBA_SPROM4_5GH_PA_3		0x24

#define	SIBA_SPROM5_BFLOW		0x104a
#define	SIBA_SPROM5_BFHIGH		0x104c
#define	SIBA_SPROM5_MAC_80211BG		0x1052
#define	SIBA_SPROM5_CCODE		0x1044
#define	SIBA_SPROM5_GPIOA		0x1076
#define	SIBA_SPROM5_GPIOA_P0		0x00ff
#define	SIBA_SPROM5_GPIOA_P1		0xff00
#define	SIBA_SPROM5_GPIOB		0x1078
#define	SIBA_SPROM5_GPIOB_P2		0x00ff
#define	SIBA_SPROM5_GPIOB_P3		0xff00

#define	SIBA_SPROM8_BFLOW		0x1084
#define	SIBA_SPROM8_BFHIGH		0x1086
#define	SIBA_SPROM8_BFL2LO		0x1088
#define	SIBA_SPROM8_BFL2HI		0x108a
#define	SIBA_SPROM8_MAC_80211BG		0x108c
#define	SIBA_SPROM8_CCODE		0x1092
#define	SIBA_SPROM8_ANTAVAIL		0x109c
#define	SIBA_SPROM8_ANTAVAIL_A		0xff00
#define	SIBA_SPROM8_ANTAVAIL_BG		0x00ff
#define	SIBA_SPROM8_AGAIN01		0x109e
#define	SIBA_SPROM8_AGAIN0		0x00ff
#define	SIBA_SPROM8_AGAIN1		0xff00
#define	SIBA_SPROM8_GPIOA		0x1096
#define	SIBA_SPROM8_GPIOA_P0		0x00ff
#define	SIBA_SPROM8_GPIOA_P1		0xff00
#define	SIBA_SPROM8_GPIOB		0x1098
#define	SIBA_SPROM8_GPIOB_P2		0x00ff
#define	SIBA_SPROM8_GPIOB_P3		0xff00
#define	SIBA_SPROM8_AGAIN23		0x10a0
#define	SIBA_SPROM8_AGAIN2		0x00ff
#define	SIBA_SPROM8_AGAIN3		0xff00
#define	SIBA_SPROM8_RSSIPARM2G		0x10a4
#define	SIBA_SPROM8_RSSISMF2G		0x000f
#define	SIBA_SPROM8_RSSISMC2G		0x00f0
#define	SIBA_SPROM8_RSSISAV2G		0x0700	/* BITMASK */
#define	SIBA_SPROM8_BXA2G		0x1800	/* BITMASK */
#define	SIBA_SPROM8_RSSIPARM5G		0x10a6
#define	SIBA_SPROM8_RSSISMF5G		0x000f
#define	SIBA_SPROM8_RSSISMC5G		0x00f0
#define	SIBA_SPROM8_RSSISAV5G		0x0700	/* BITMASK */
#define	SIBA_SPROM8_BXA5G		0x1800	/* BITMASK */
#define	SIBA_SPROM8_TRI25G		0x10a8
#define	SIBA_SPROM8_TRI2G		0x00ff
#define	SIBA_SPROM8_TRI5G		0xff00
#define	SIBA_SPROM8_TRI5GHL		0x10aa
#define	SIBA_SPROM8_TRI5GL		0x00ff
#define	SIBA_SPROM8_TRI5GH		0xff00
#define	SIBA_SPROM8_RXPO		0x10ac
#define	SIBA_SPROM8_RXPO2G		0x00ff
#define	SIBA_SPROM8_RXPO5G		0xff00

/* The FEM blocks share the same structure */
#define	SIBA_SPROM8_FEM2G		0x00AE
#define	SIBA_SPROM8_FEM5G		0x00B0
#define	 SSB_SROM8_FEM_TSSIPOS		0x0001
#define	 SSB_SROM8_FEM_EXTPA_GAIN	0x0006
#define	 SSB_SROM8_FEM_PDET_RANGE	0x00F8
#define	 SSB_SROM8_FEM_TR_ISO		0x0700
#define	 SSB_SROM8_FEM_ANTSWLUT		0xF800

#define	SIBA_SPROM8_MAXP_BG		0x10c0
#define	SIBA_SPROM8_MAXP_BG_MASK	0x00ff
#define	SIBA_SPROM8_TSSI_BG		0xff00
#define	SIBA_SPROM8_PA0B0		0x10c2
#define	SIBA_SPROM8_PA0B1		0x10c4
#define	SIBA_SPROM8_PA0B2		0x10c6
#define	SIBA_SPROM8_MAXP_A		0x10c8
#define	SIBA_SPROM8_MAXP_A_MASK		0x00ff
#define	SIBA_SPROM8_TSSI_A		0xff00
#define	SIBA_SPROM8_MAXP_AHL		0x10ca
#define	SIBA_SPROM8_MAXP_AH_MASK	0x00ff
#define	SIBA_SPROM8_MAXP_AL_MASK	0xff00
#define	SIBA_SPROM8_PA1B0		0x10cc
#define	SIBA_SPROM8_PA1B1		0x10ce
#define	SIBA_SPROM8_PA1B2		0x10d0
#define	SIBA_SPROM8_PA1LOB0		0x10d2
#define	SIBA_SPROM8_PA1LOB1		0x10d4
#define	SIBA_SPROM8_PA1LOB2		0x10d6
#define	SIBA_SPROM8_PA1HIB0		0x10d8
#define	SIBA_SPROM8_PA1HIB1		0x10da
#define	SIBA_SPROM8_PA1HIB2		0x10dc
#define	SIBA_SPROM8_CCK2GPO		0x1140
#define	SIBA_SPROM8_OFDM2GPO		0x1142
#define	SIBA_SPROM8_OFDM5GPO		0x1146
#define	SIBA_SPROM8_OFDM5GLPO		0x114a
#define	SIBA_SPROM8_OFDM5GHPO		0x114e
#define	SIBA_SPROM8_CDDPO		0x0192
#define	SIBA_SPROM8_STBCPO		0x0194
#define	SIBA_SPROM8_BW40PO		0x0196
#define	SIBA_SPROM8_BWDUPPO		0x0198

/* There are 4 blocks with power info sharing the same layout */
#define	SIBA_SROM8_PWR_INFO_CORE0	0x00C0
#define	SIBA_SROM8_PWR_INFO_CORE1	0x00E0
#define	SIBA_SROM8_PWR_INFO_CORE2	0x0100
#define	SIBA_SROM8_PWR_INFO_CORE3	0x0120

#define	SIBA_SROM8_2G_MAXP_ITSSI	0x00
#define	 SIBA_SPROM8_2G_MAXP		0x00FF
#define	 SIBA_SPROM8_2G_ITSSI		0xFF00
#define	 SIBA_SPROM8_2G_ITSSI_SHIFT	8
#define	SIBA_SROM8_2G_PA_0		0x02    /* 2GHz power amp settings */
#define	SIBA_SROM8_2G_PA_1		0x04
#define	SIBA_SROM8_2G_PA_2		0x06
#define	SIBA_SROM8_5G_MAXP_ITSSI	0x08    /* 5GHz ITSSI and 5.3GHz Max Power */
#define	 SIBA_SPROM8_5G_MAXP		0x00FF
#define	 SIBA_SPROM8_5G_ITSSI		0xFF00
#define	 SIBA_SPROM8_5G_ITSSI_SHIFT	8
#define	SIBA_SPROM8_5GHL_MAXP		0x0A    /* 5.2GHz and 5.8GHz Max Power */
#define	 SIBA_SPROM8_5GH_MAXP		0x00FF
#define	 SIBA_SPROM8_5GL_MAXP		0xFF00
#define	 SIBA_SPROM8_5GL_MAXP_SHIFT	8
#define	SIBA_SROM8_5G_PA_0		0x0C    /* 5.3GHz power amp settings */
#define	SIBA_SROM8_5G_PA_1		0x0E
#define	SIBA_SROM8_5G_PA_2		0x10
#define	SIBA_SROM8_5GL_PA_0		0x12    /* 5.2GHz power amp settings */
#define	SIBA_SROM8_5GL_PA_1		0x14
#define	SIBA_SROM8_5GL_PA_2		0x16
#define	SIBA_SROM8_5GH_PA_0		0x18    /* 5.8GHz power amp settings */
#define	SIBA_SROM8_5GH_PA_1		0x1A
#define	SIBA_SROM8_5GH_PA_2		0x1C

#define	SIBA_BOARDVENDOR_DELL		0x1028
#define	SIBA_BOARDVENDOR_BCM		0x14e4
#define	SIBA_BOARD_BCM4309G		0x0421
#define	SIBA_BOARD_MP4318		0x044a
#define	SIBA_BOARD_BU4306		0x0416
#define	SIBA_BOARD_BU4309		0x040a
#define	SIBA_BOARD_BCM4321		0x046d

#define	SIBA_PCICORE_BCAST_ADDR		SIBA_CC_BCAST_ADDR
#define	SIBA_PCICORE_BCAST_DATA		SIBA_CC_BCAST_DATA
#define	SIBA_PCICORE_SBTOPCI0		0x0100
#define	SIBA_PCICORE_SBTOPCI1		0x0104
#define	SIBA_PCICORE_SBTOPCI2		0x0108
#define	SIBA_PCICORE_MDIO_CTL		0x0128
#define	SIBA_PCICORE_MDIO_DATA		0x012c
#define	SIBA_PCICORE_SBTOPCI_PREF	0x00000004
#define	SIBA_PCICORE_SBTOPCI_BURST	0x00000008
#define	SIBA_PCICORE_SBTOPCI_MRM	0x00000020

#define	SIBA_CHIPPACK_BCM4712S     1       /* Small 200pin 4712 */

#endif /* _SIBA_SIBAREG_H_ */
