
/**
  ******************************************************************************
  * @file           : mfm_modbus.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the serial comm.
  ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MODBUS_H
#define __MODBUS_H

 #include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "libModbus.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Modbus Holding Registers (All floats, 2*16-bit)
*/
#define MB_REG_ADDR_VRMS_LN_R	(40101U)
#define MB_REG_ADDR_VRMS_LN_Y	(40103U)
#define MB_REG_ADDR_VRMS_LN_B	(40105U)
#define MB_REG_ADDR_VRMS_LN_AVG	(40107U)

#define MB_REG_ADDR_VRMS_LL_R	(40109U)
#define MB_REG_ADDR_VRMS_LL_Y	(40111U)
#define MB_REG_ADDR_VRMS_LL_B	(40113U)
#define MB_REG_ADDR_VRMS_LL_AVG	(40115U)

#define MB_REG_ADDR_ARMS_R	(40117U)
#define MB_REG_ADDR_ARMS_Y	(40119U)
#define MB_REG_ADDR_ARMS_B	(40121U)
#define MB_REG_ADDR_ARMS_TOTAL	(40123U)

#define MB_REG_ADDR_PF_R	(40125U)
#define MB_REG_ADDR_PF_Y	(40127U)
#define MB_REG_ADDR_PF_B	(40129U)
#define MB_REG_ADDR_PF_AVG	(40131U)

#define MB_REG_ADDR_FREQ	(40133U)

#define MB_REG_ADDR_POW_KW_R	(40135U)
#define MB_REG_ADDR_POW_KW_Y	(40137U)
#define MB_REG_ADDR_POW_KW_B	(40139U)
#define MB_REG_ADDR_POW_KW_TOTAL	(40141U)

#define MB_REG_ADDR_POW_KVAR_R	(40143U)
#define MB_REG_ADDR_POW_KVAR_Y	(40145U)
#define MB_REG_ADDR_POW_KVAR_B	(40147U)
#define MB_REG_ADDR_POW_KVAR_TOTAL	(40149U)

#define MB_REG_ADDR_POW_KVA_R	(40151U)
#define MB_REG_ADDR_POW_KVA_Y	(40153U)
#define MB_REG_ADDR_POW_KVA_B	(40155U)
#define MB_REG_ADDR_POW_KVA_TOTAL	(40157U)

#define MB_REG_ADDR_DG_ENG_KWH_R	(40159U)
#define MB_REG_ADDR_DG_ENG_KWH_Y	(40161U)
#define MB_REG_ADDR_DG_ENG_KWH_B	(40163U)
#define MB_REG_ADDR_DG_ENG_KWH_TOTAL	(40165U)

#define MB_REG_ADDR_DG_ENG_KVARH_R	(40167U)
#define MB_REG_ADDR_DG_ENG_KVARH_Y	(40169U)
#define MB_REG_ADDR_DG_ENG_KVARH_B	(40171U)
#define MB_REG_ADDR_DG_ENG_KVARH_TOTAL	(40173U)

#define MB_REG_ADDR_DG_ENG_KVAH_R	(40175U)
#define MB_REG_ADDR_DG_ENG_KVAH_Y	(40177U)
#define MB_REG_ADDR_DG_ENG_KVAH_B	(40179U)
#define MB_REG_ADDR_DG_ENG_KVAH_TOTAL	(40181U)

#define MB_REG_ADDR_EB_USED_HOURS	(40183U)
#define MB_REG_ADDR_DG_USED_HOURS	(40185U)


//Address for Write Registers
#define MB_WREG_ADDR_CT_PRIMARY	(40001U)
#define MB_WREG_ADDR_CT_SECONDARY	(40003U)
#define MB_WREG_ADDR_PT_PRIMARY	(40005U)
#define MB_WREG_ADDR_PT_SECONDARY	(40007U)
#define MB_WREG_ADDR_ADDRESS	(40009U)
#define MB_WREG_ADDR_BAUD	(40011U)
#define MB_WREG_ADDR_PARITY	(40013U)
#define MB_WREG_ADDR_PULSE_DUR	(40015U)
#define MB_WREG_ADDR_PULSE_SELECT	(40017U)
#define MB_WREG_ADDR_IMPULSE (40019U)

void modbus_init( uint8_t slvAddr );
uint16_t modbus_getRegValue ( uint32_t regNum );
void modbus_writeMultipleRegValue ( uint32_t regNum , uint16_t value);



#ifdef __cplusplus
}
#endif

#endif /* __MODBUS_H */

/************************ (C) COPYRIGHT Nagoba Electronics *****END OF FILE****/
