/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef _MTK_MT6797_H_
#define _MTK_MT6797_H_

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

#define CONSYS_BT_WIFI_SHARE_V33        0
#define CONSYS_PMIC_CTRL_ENABLE         1
#define CONSYS_EMI_MPU_SETTING          1
#define CONSYS_AHB_CLK_MAGEMENT         0
#define CONSYS_USE_PLATFORM_WRITE       1
#define CONSYS_PWR_ON_OFF_API_AVAILABLE 1
#define CONSYS_CLOCK_BUF_CTRL           1
#define CONSYS_AFE_REG_SETTING          1

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/

/*tag start:new platform need to make sure these define */
#if defined(CONFIG_ARCH_MT6797)
#define PLATFORM_SOC_CHIP 0x6797
#endif
/*tag end*/

#ifdef CONFIG_OF
/*TOPCKGEN_BASE*/
#define CONSYS_TOP_CLKCG_CLR_OFFSET	0x00000084
#define CONSYS_TOP_CLKCG_SET_OFFSET	0x00000054
#define CONSYS_WD_SYS_RST_OFFSET	0x00000018
#define CONSYS_AP2CONN_OSC_EN_OFFSET	0x00001f00
#define CONSYS_EMI_MAPPING_OFFSET	0x00001340
/*AP_RGU_BASE*/
#define CONSYS_CPU_SW_RST_OFFSET	0x00000018
/*SPM_BASE*/
#define CONSYS_PWRON_CONFG_EN_OFFSET	0x00000000
#define CONSYS_TOP1_PWR_CTRL_OFFSET	0x0000032c
#define CONSYS_PWR_CONN_ACK_OFFSET	0x00000180
#define CONSYS_PWR_CONN_ACK_S_OFFSET	0x00000184
/*CONN_MCU_CONFIG_BASE*/
#define CONSYS_CHIP_ID_OFFSET		0x00000008
#define CONSYS_ROM_RAM_DELSEL_OFFSET	0x00000114
#define CONSYS_MCU_CFG_ACR_OFFSET	0x00000110
#define CONSYS_CPUPCR_OFFSET		0x00000160
/*AXI bus*/
#define CONSYS_TOPAXI_PROT_EN_OFFSET		0x1220
#define CONSYS_TOPAXI_PROT_STA1_OFFSET		0x1228
#define CONSYS_CONN2AP_SLEEP_MASK_OFFSET	0x1350
#endif

/*tag start: connsys register base address (hard code, no use) */
#define AP_RGU_BASE		0xF0007000
#define TOPCKGEN_BASE		0xF0000000
#define SPM_BASE		0xF0006000
#define CONN_MCU_CONFIG_BASE	0xF8070000
/*GIC Interrupt ID*/
#define MT_CONN2AP_BTIF_WAKEUP_IRQ_ID 259
/*tag end*/

/*connsys register offset define(hard code mode)*/
#if 1
	/*top clock gating control register */
#define CONSYS_TOP_CLKCG_CLR_REG	(TOPCKGEN_BASE + 0x00000084)
#define CONSYS_TOP_CLKCG_SET_REG	(TOPCKGEN_BASE + 0x00000054)
#define CONSYS_TOP_CLKCG_BIT		(0x1 << 26)

	/*SPM clock gating control register */
#define CONSYS_PWRON_CONFG_EN_REG	(SPM_BASE + 0x00000000)
#define CONSYS_PWRON_CONFG_EN_VALUE	(0x0b160001)
#define CONSYS_PWRON_CONFG_DIS_VALUE	(0x0b160000)
#endif

#define CONSYS_CPU_SW_RST_REG		(AP_RGU_BASE + 0x00000018)
#define CONSYS_TOP1_PWR_CTRL_REG	(SPM_BASE + 0x0000032c)
#define CONSYS_PWR_CONN_ACK_REG		(SPM_BASE + 0x00000180)
#define CONSYS_PWR_CONN_ACK_S_REG	(SPM_BASE + 0x00000184)

#define CONSYS_WD_SYS_RST_REG		(TOPCKGEN_BASE + 0x00000018)
#define CONSYS_CHIP_ID_REG		(CONN_MCU_CONFIG_BASE + 0x00000008)
#define CONSYS_ROM_RAM_DELSEL_REG	(CONN_MCU_CONFIG_BASE + 0x00000114)
#define CONSYS_MCU_CFG_ACR_REG		(CONN_MCU_CONFIG_BASE + 0x00000110)

#if CONSYS_AFE_REG_SETTING
#define CONSYS_AFE_REG_BASE					(0x180B6000)
#define CONSYS_AFE_REG_GPS_SINGLE_OFFSET	(0x00000014)
#define CONSYS_AFE_REG_WBG_RCK_01_OFFSET	(0x00000020)
#define CONSYS_AFE_REG_WBG_GPS_01_OFFSET	(0x00000050)
#define CONSYS_AFE_REG_WBG_GPS_02_OFFSET	(0x00000054)
#define CONSYS_AFE_REG_WBG_BT_RX_01_OFFSET	(0x00000060)
#define CONSYS_AFE_REG_WBG_BT_RX_02_OFFSET	(0x00000064)
#define CONSYS_AFE_REG_WBG_BT_TX_01_OFFSET	(0x00000068)
#define CONSYS_AFE_REG_WBG_BT_TX_02_OFFSET	(0x0000006C)
#define CONSYS_AFE_REG_WBG_BT_TX_03_OFFSET	(0x00000070)
#define CONSYS_AFE_REG_WBG_WF_RX_02_OFFSET	(0x00000084)
#define CONSYS_AFE_REG_WBG_WF_TX_01_OFFSET	(0x00000088)
#define CONSYS_AFE_REG_WBG_WF_TX_02_OFFSET	(0x0000008C)
#define CONSYS_AFE_REG_WBG_WF_TX_03_OFFSET	(0x00000090)
#define CONSYS_AFE_REG_DIG_RCK_01_VALUE		(0x180B0160)
#define CONSYS_AFE_REG_WBG_RX_01_VALUE		(0xB8925421)
#define CONSYS_AFE_REG_WBG_RX_02_VALUE		(0x00006401)
#define CONSYS_AFE_REG_WBG_TX_01_VALUE		(0x08400000)
#define CONSYS_AFE_REG_WBG_TX_02_VALUE		(0x0C110200)
#define CONSYS_AFE_REG_WBG_TX_03_VALUE		(0x012A020A)
#define CONSYS_AFE_REG_GPS_SINGLE_12_VALUE	(0x00001000)
#endif

#define CONSYS_TOPAXI_PROT_EN		(TOPCKGEN_BASE + 0x1220)
#define CONSYS_TOPAXI_PROT_STA1		(TOPCKGEN_BASE + 0x1228)
#define CONSYS_CONN2AP_SLEEP_MASK_BIT	(0x01<<8) /* bit8 */
#define CONSYS_PROT_MASK		((0x1<<18) | (0x1<<19))	/* bit18,19 */
/*CONSYS_CPU_SW_RST_REG*/
#define CONSYS_CPU_SW_RST_BIT		(0x1 << 12)
#define CONSYS_CPU_SW_RST_CTRL_KEY	(0x88 << 24)

/*CONSYS_TOP1_PWR_CTRL_REG*/
#define CONSYS_SPM_PWR_RST_BIT		(0x1 << 0)
#define CONSYS_SPM_PWR_ISO_S_BIT	(0x1 << 1)
#define CONSYS_SPM_PWR_ON_BIT		(0x1 << 2)
#define CONSYS_SPM_PWR_ON_S_BIT		(0x1 << 3)
#define CONSYS_CLK_CTRL_BIT		(0x1 << 4)
#define CONSYS_SRAM_CONN_PD_BIT		(0x1 << 8)

/*CONSYS_PWR_CONN_ACK_REG*/
#define CONSYS_PWR_ON_ACK_BIT		(0x1 << 1)

/*CONSYS_PWR_CONN_ACK_S_REG*/
#define CONSYS_PWR_CONN_ACK_S_BIT	(0x1 << 1)

/*CONSYS_WD_SYS_RST_REG*/
#define CONSYS_WD_SYS_RST_CTRL_KEY	(0x88 << 24)
#define CONSYS_WD_SYS_RST_BIT		(0x1 << 9)

/*CONSYS_MCU_CFG_ACR_REG*/
#define CONSYS_MCU_CFG_ACR_MBIST_BIT	(0x1 << 18)

/* EMI part mapping & ctrl*/
#define CONSYS_EMI_AP_PHY_OFFSET	(0x80000)
#define CONSYS_EMI_AP_PHY_BASE		(0x80080000)
#define CONSYS_EMI_FW_PHY_BASE		(0xf0080000)
#define CONSYS_EMI_PAGED_TRACE_OFFSET	(0x400)
#define CONSYS_EMI_PAGED_DUMP_OFFSET	(0x8400)
#define CONSYS_EMI_FULL_DUMP_OFFSET	(0x10400)

/*cpupcr*/
#define CONSYS_CPUPCR_REG		(CONN_MCU_CONFIG_BASE + 0x00000160)
/*emi mapping*/
#define CONSYS_EMI_MAPPING		(TOPCKGEN_BASE + CONSYS_EMI_MAPPING_OFFSET)

/*control app2cnn_osc_en*/
#define CONSYS_AP2CONN_OSC_EN_REG	(TOPCKGEN_BASE + 0x00001800)
#define CONSYS_AP2CONN_OSC_EN_BIT	(0x1 << 10)
#define CONSYS_AP2CONN_WAKEUP_BIT	(0x1 << 9)

/*paged dump address start*/
#define CONSYS_PAGED_DUMP_START_ADDR	(0xf0088400)

/*full dump address start*/
#define CONSYS_FULL_DUMP_START_ADDR	(0xf0090400)
#define CONSYS_FULL_DUMP_DLM_LEN	(0x1f000)
#define CONSYS_FULL_DUMP_SYSB2_START	(CONSYS_FULL_DUMP_START_ADDR + CONSYS_FULL_DUMP_DLM_LEN)
#define CONSYS_FULL_DUMP_SYSB2_LEN	(0x6800)
#define CONSYS_FULL_DUMP_SYSB3_START	(CONSYS_FULL_DUMP_SYSB2_START + CONSYS_FULL_DUMP_SYSB2_LEN)
#define CONSYS_FULL_DUMP_SYSB3_LEN	(0x16800)


/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

#if CONSYS_BT_WIFI_SHARE_V33
typedef struct _BT_WIFI_V33_STATUS_ {
	UINT32 counter;
	UINT32 flags;
	spinlock_t lock;
} BT_WIFI_V33_STATUS;

extern BT_WIFI_V33_STATUS gBtWifiV33;
#endif

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _MTK_MT6797_H_ */