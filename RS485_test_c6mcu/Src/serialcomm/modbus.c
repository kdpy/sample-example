
#include "modbus.h"

float par_val;
int8_t enter_setup = 0;
uint8_t save_cfg;
uint32_t original_value;

void modbus_init( uint8_t slvAddr )
{
	InitPetitModbus(slvAddr);
}

uint16_t modbus_getRegValue ( uint32_t regNum )
{
	uint32_t *ptrFlt;
	uint32_t fltVal;
	
	MFM_FMD_t* mfmd = meter_getFMDHandle();
	
	regNum += 40001;
							
				switch ( regNum )
				{	
									
								case MB_WREG_ADDR_CT_PRIMARY:
										fltVal = cfg.ratio_ct_primary;
								break;
								case MB_WREG_ADDR_CT_PRIMARY+1:
										fltVal = cfg.ratio_ct_primary;
								break;
									
								case MB_WREG_ADDR_CT_SECONDARY:
									fltVal = cfg.ratio_ct_secondary;
								break;
								case MB_WREG_ADDR_CT_SECONDARY+1:
									fltVal = cfg.ratio_ct_secondary;
								break;
									
								case MB_WREG_ADDR_PT_PRIMARY:
									fltVal = cfg.ratio_pt_primary;
								break;
								case MB_WREG_ADDR_PT_PRIMARY+1:
									fltVal = cfg.ratio_pt_primary;
								break;
									
								case MB_WREG_ADDR_PT_SECONDARY:
								fltVal = cfg.ratio_pt_secondary;
								break;
								case MB_WREG_ADDR_PT_SECONDARY+1:
									fltVal = cfg.ratio_pt_secondary;									
								break;
								
								case MB_WREG_ADDR_ADDRESS:
									fltVal = cfg.address;
								break;
								case MB_WREG_ADDR_ADDRESS+1:
									fltVal = cfg.address;
								break;
									
								case MB_WREG_ADDR_BAUD:
									fltVal = cfg.buad_rate;
								break;
								case MB_WREG_ADDR_BAUD+1:
										fltVal 	= cfg.buad_rate;
								break;
									
								case MB_WREG_ADDR_PARITY:
									fltVal = cfg.parity;
								break;
								case MB_WREG_ADDR_PARITY+1:
									fltVal=	cfg.parity;
								break;
								
								case MB_WREG_ADDR_PULSE_DUR:
									fltVal = cfg.io_pulseWidth;
								break;
								case MB_WREG_ADDR_PULSE_DUR+1:
										fltVal = cfg.io_pulseWidth;
								break;
								
								case MB_WREG_ADDR_PULSE_SELECT:
									fltVal = cfg.io_pulseOnDisplay;
								break;
								case MB_WREG_ADDR_PULSE_SELECT+1:
									fltVal = cfg.io_pulseOnDisplay;
								break;
								
								case MB_WREG_ADDR_IMPULSE:
									fltVal = cfg.impulse;	
								break;
								case MB_WREG_ADDR_IMPULSE+1:
									fltVal = cfg.impulse;	
								break;
						
						
		// Group 1: VAP (RMS Voltage/Amps, Power Factor)
		case MB_REG_ADDR_VRMS_LN_R:
		case (MB_REG_ADDR_VRMS_LN_R+1):
			fltVal = (uint32_t)mfmd->vap[VAP_IDX_VRMS_LN][PH_IDX_R];
			break;
		case MB_REG_ADDR_VRMS_LN_Y:
		case (MB_REG_ADDR_VRMS_LN_Y+1):
			fltVal = (uint32_t)(mfmd->vap[VAP_IDX_VRMS_LN][PH_IDX_Y]);
			break;
		case MB_REG_ADDR_VRMS_LN_B: 
		case (MB_REG_ADDR_VRMS_LN_B+1):
			fltVal = (uint32_t) (mfmd->vap[VAP_IDX_VRMS_LN][PH_IDX_B]);
			break;
		case MB_REG_ADDR_VRMS_LN_AVG:
		case (MB_REG_ADDR_VRMS_LN_AVG+1):
			fltVal = (uint32_t)(  (mfmd->vap_avg_total[VAP_IDX_VRMS_LN]));
			break; 
		case MB_REG_ADDR_VRMS_LL_R: 
		case (MB_REG_ADDR_VRMS_LL_R+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_VRMS_LL][PH_IDX_R]) );
			break;
		case MB_REG_ADDR_VRMS_LL_Y:
		case (MB_REG_ADDR_VRMS_LL_Y+1):
			fltVal = (uint32_t) ( (mfmd->vap[VAP_IDX_VRMS_LL][PH_IDX_Y]) );
			break;
		case MB_REG_ADDR_VRMS_LL_B:
		case (MB_REG_ADDR_VRMS_LL_B+1):
			fltVal = (uint32_t) ( (mfmd->vap[VAP_IDX_VRMS_LL][PH_IDX_B]));
			break;
		case MB_REG_ADDR_VRMS_LL_AVG: 
		case (MB_REG_ADDR_VRMS_LL_AVG+1):
			fltVal = (uint32_t)(  (mfmd->vap_avg_total[VAP_IDX_VRMS_LL]));
			break;  
		case MB_REG_ADDR_ARMS_R: 
		case (MB_REG_ADDR_ARMS_R+1):
			fltVal = (uint32_t) (mfmd->vap[VAP_IDX_ARMS][PH_IDX_R]);
			break;
		case MB_REG_ADDR_ARMS_Y: 
		case (MB_REG_ADDR_ARMS_Y+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_ARMS][PH_IDX_Y]));
			break;
		case MB_REG_ADDR_ARMS_B:
		case (MB_REG_ADDR_ARMS_B+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_ARMS][PH_IDX_B]));
			break;
		case MB_REG_ADDR_ARMS_TOTAL: 
		case (MB_REG_ADDR_ARMS_TOTAL+1):
			fltVal = (uint32_t) ( (mfmd->vap_avg_total[VAP_IDX_ARMS]) );
			break;
		case MB_REG_ADDR_PF_R: 
		case (MB_REG_ADDR_PF_R+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_PF][PH_IDX_R]));
			break;
		case MB_REG_ADDR_PF_Y: 
		case (MB_REG_ADDR_PF_Y+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_PF][PH_IDX_Y]));
			break;
		case MB_REG_ADDR_PF_B: 
		case (MB_REG_ADDR_PF_B+1):
			fltVal = (uint32_t)(  (mfmd->vap[VAP_IDX_PF][PH_IDX_B]) );
			break;			  
		case MB_REG_ADDR_PF_AVG: 
		case (MB_REG_ADDR_PF_AVG+1):
			fltVal = (uint32_t) ( (mfmd->vap_avg_total[VAP_IDX_PF]) );
			break;
		 
		
		// Group 3: Frequency
		case MB_REG_ADDR_FREQ: 
		case (MB_REG_ADDR_FREQ+1):
			fltVal = (uint32_t) ( (mfmd->frequency) );
			break; 
		
		// Group 4: Power (KW, KVAR,KVA, Total Power)
		case MB_REG_ADDR_POW_KW_R: 
		case (MB_REG_ADDR_POW_KW_R+1):
			fltVal = (  (mfmd->power[PE_IDX_W][PH_IDX_R])   );
			break;
		case MB_REG_ADDR_POW_KW_Y: 
		case (MB_REG_ADDR_POW_KW_Y+1):
			fltVal =( (mfmd->power[PE_IDX_W][PH_IDX_Y])   );
			break;
		case MB_REG_ADDR_POW_KW_B: 
		case (MB_REG_ADDR_POW_KW_B+1):
			fltVal = (  (mfmd->power[PE_IDX_W][PH_IDX_B])   );
			break;
		case MB_REG_ADDR_POW_KVAR_R:
		case (MB_REG_ADDR_POW_KVAR_R+1): 
			fltVal = ( (mfmd->power[PE_IDX_VAR][PH_IDX_R])   );
			break;
		case MB_REG_ADDR_POW_KVAR_Y: 
		case (MB_REG_ADDR_POW_KVAR_Y+1):
			fltVal = ( (mfmd->power[PE_IDX_VAR][PH_IDX_Y])  );
			break;
		case MB_REG_ADDR_POW_KVAR_B:
		case (MB_REG_ADDR_POW_KVAR_B+1):
			fltVal =   ( (mfmd->power[PE_IDX_VAR][PH_IDX_B])  );
			break;
		case MB_REG_ADDR_POW_KVA_R: 
		case (MB_REG_ADDR_POW_KVA_R+1):
			fltVal =  (  (mfmd->power[PE_IDX_VA][PH_IDX_R])  );
			break;
		case MB_REG_ADDR_POW_KVA_Y:
		case (MB_REG_ADDR_POW_KVA_Y+1):
			fltVal =  (  (mfmd->power[PE_IDX_VA][PH_IDX_Y])  );
			break;
		case MB_REG_ADDR_POW_KVA_B:
		case (MB_REG_ADDR_POW_KVA_B+1): 
			fltVal =   ( (mfmd->power[PE_IDX_VA][PH_IDX_B])  );
			break;
		case MB_REG_ADDR_POW_KW_TOTAL: 
		case (MB_REG_ADDR_POW_KW_TOTAL+1):
			fltVal =  (  (mfmd->power_total[PE_IDX_W])  );
			break;
		case MB_REG_ADDR_POW_KVAR_TOTAL: 
		case (MB_REG_ADDR_POW_KVAR_TOTAL+1):
			fltVal =  (  (mfmd->power_total[PE_IDX_VAR])  );
			break;
		case MB_REG_ADDR_POW_KVA_TOTAL: 
		case (MB_REG_ADDR_POW_KVA_TOTAL+1):
			fltVal =  ( (mfmd->power_total[PE_IDX_VA])  );
			break;
		
		
		// Group 5: Energy (KWh, KVARh,KVAh, Total Energy)
	case MB_REG_ADDR_DG_ENG_KWH_R: 
	case (MB_REG_ADDR_DG_ENG_KWH_R+1):
			fltVal = (uint32_t) ( _UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_W][PH_IDX_R])  );		
			break;
		case MB_REG_ADDR_DG_ENG_KWH_Y: 
		case (MB_REG_ADDR_DG_ENG_KWH_Y+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_W][PH_IDX_Y])  );
			break;
		case MB_REG_ADDR_DG_ENG_KWH_B: 
		case (MB_REG_ADDR_DG_ENG_KWH_B+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_W][PH_IDX_B])  );
			break;
		
		case (MB_REG_ADDR_DG_ENG_KWH_TOTAL):
		case (MB_REG_ADDR_DG_ENG_KWH_TOTAL + 1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->Ext_storage_EB_energy_total[PE_IDX_W])  );
			break;
		
		case MB_REG_ADDR_DG_ENG_KVARH_R:
		case (MB_REG_ADDR_DG_ENG_KVARH_R+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VAR][PH_IDX_R])  ); 
			break;
		case MB_REG_ADDR_DG_ENG_KVARH_Y: 
		case (MB_REG_ADDR_DG_ENG_KVARH_Y+1):
			fltVal =(uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VAR][PH_IDX_Y])  );
			break;
		case MB_REG_ADDR_DG_ENG_KVARH_B: 
		case (MB_REG_ADDR_DG_ENG_KVARH_B+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VAR][PH_IDX_B])  );
			break;
		
		case (MB_REG_ADDR_DG_ENG_KVARH_TOTAL):
		case (MB_REG_ADDR_DG_ENG_KVARH_TOTAL + 1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->Ext_storage_EB_energy_total[PE_IDX_VAR])  );
			break;
		
		case MB_REG_ADDR_DG_ENG_KVAH_R: 
		case (MB_REG_ADDR_DG_ENG_KVAH_R+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VA][PH_IDX_R])  ); 
			break;
		case MB_REG_ADDR_DG_ENG_KVAH_Y: 
		case (MB_REG_ADDR_DG_ENG_KVAH_Y+1):
			fltVal =(uint32_t)  (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VA][PH_IDX_Y])  );
			break;
		case MB_REG_ADDR_DG_ENG_KVAH_B: 
		case (MB_REG_ADDR_DG_ENG_KVAH_B+1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->energy[PE_IDX_VA][PH_IDX_B]) );
			break;
		
		case (MB_REG_ADDR_DG_ENG_KVAH_TOTAL):
		case (MB_REG_ADDR_DG_ENG_KVAH_TOTAL + 1):
			fltVal = (uint32_t) (_UnscaleAndConvertToKiloHour(mfmd->Ext_storage_EB_energy_total[PE_IDX_VA])  );
			break;
		
				
		// Group 6: Used hours
		case MB_REG_ADDR_EB_USED_HOURS:  case (MB_REG_ADDR_EB_USED_HOURS+1):
			fltVal = _ConvertSecToHour(ebdg_used_seconds(MFM_PS_EB));
			break;
		case MB_REG_ADDR_DG_USED_HOURS: case (MB_REG_ADDR_DG_USED_HOURS+1):
			fltVal = _ConvertSecToHour(ebdg_used_seconds(MFM_PS_DG));			
			break;			
		default:
			break;
}
			if(enter_setup < 1)
			{	
						if(regNum > MB_WREG_ADDR_IMPULSE + 2 && regNum < MB_REG_ADDR_VRMS_LN_R)
						{								
										fltVal = 0;						
						}
				}
	ptrFlt = (uint32_t *)&fltVal;
	
	
	if( regNum & 0x1 )	// Upper 16-bit first (Odd register number)
	{
		return (uint16_t)(( *ptrFlt & 0xffff0000)>>16 );
	}
	else	// Lower 16-bit first (Even register number)
	{
		return (uint16_t)( *ptrFlt & 0x0000ffff );
	}
	//return (uint16_t)fltVal;
		
}


void modbus_writeMultipleRegValue ( uint32_t regNum , uint16_t value)
{
	regNum += 40001;
								switch ( regNum )
								{
								case MB_WREG_ADDR_CT_PRIMARY:
									original_value = value;
								break;
								case MB_WREG_ADDR_CT_PRIMARY+1:
									original_value = (original_value * 10000) + value;
									if(original_value > 0 && original_value < 32769)
										cfg.ratio_ct_primary = original_value;
									else 
										cfg.ratio_ct_primary = DEFAULT_RATIO_CT_PRIMARY;
								break;
									
								case MB_WREG_ADDR_CT_SECONDARY:
									original_value = value;
								break;
								case MB_WREG_ADDR_CT_SECONDARY+1:
									original_value = (original_value * 10000) + value;
									if(original_value > 0 && original_value < 7)
										cfg.ratio_ct_secondary = original_value;
									else 
									cfg.ratio_ct_secondary = DEFAULT_RATIO_CT_PRIMARY;
								break;
									
								case MB_WREG_ADDR_PT_PRIMARY:
									original_value = value;
								break;
								case MB_WREG_ADDR_PT_PRIMARY+1:
									original_value = (original_value * 10000) + value;
								if(original_value > 0 && original_value < 1000000)
										cfg.ratio_pt_primary = original_value;
									else 
										cfg.ratio_pt_primary = DEFAULT_RATIO_CT_PRIMARY;
								break;
									
								case MB_WREG_ADDR_PT_SECONDARY:
								original_value = value;
								break;
								case MB_WREG_ADDR_PT_SECONDARY+1:
								original_value = (original_value * 10000) + value;
								if(original_value > 0 && original_value < 260)
										cfg.ratio_pt_secondary = original_value;
								else 
									cfg.ratio_pt_secondary = DEFAULT_RATIO_CT_PRIMARY;									
								break;
								
								case MB_WREG_ADDR_ADDRESS:
									original_value = value;
								break;
								case MB_WREG_ADDR_ADDRESS+1:
									original_value = (original_value * 10000) + value;
								if(original_value > 0 && original_value < 226)					
										cfg.address = original_value;
								else
									cfg.address = DEFAULT_MOD_ADRRES;
								break;
									
								case MB_WREG_ADDR_BAUD:
									original_value = value;
								break;
								case MB_WREG_ADDR_BAUD+1:
									original_value = (original_value * 10000) + value;
								if(original_value == 1200  || original_value == 2400 || original_value == 4800 || original_value == 9600 || original_value == 19200 || original_value == 38400)
										cfg.buad_rate 	= original_value;
									else
										cfg.buad_rate 	= DEFAULT_BUAD_RATE;
								break;
									
								case MB_WREG_ADDR_PARITY:
									original_value = value;
								break;
								case MB_WREG_ADDR_PARITY+1:
									original_value = (original_value * 10000) + value;
								if(original_value > 0 && original_value < 3)
										cfg.parity 	= original_value;
									else
										cfg.parity 	= DEFAULT_PARITY;
								break;
								
								case MB_WREG_ADDR_PULSE_DUR:
									original_value = value;
								break;
								case MB_WREG_ADDR_PULSE_DUR+1:
									original_value = (original_value * 10000) + value;
								if(original_value > 0 && original_value <= 100)
									cfg.io_pulseWidth 	= original_value;
									else
										cfg.io_pulseWidth 				= DEFAULT_IO_PULSEWIDTH;
								break;
								
								case MB_WREG_ADDR_PULSE_SELECT:
									original_value = value;
								break;
								case MB_WREG_ADDR_PULSE_SELECT+1:
									original_value = (original_value * 10000) + value;
								if(original_value)
									cfg.io_pulseOnDisplay 	= original_value;																	
									else
									cfg.io_pulseOnDisplay 		= DEFAULT_IO_PULSE_ON_SCREEN;		
								break;
									
								case MB_WREG_ADDR_IMPULSE:
									original_value = value;
								break;
								case MB_WREG_ADDR_IMPULSE+1:
									original_value = (original_value * 10000) + value;
								if(original_value >= 1000 && original_value <= 5000)
									cfg.impulse 	= original_value;																	
									else
									cfg.impulse		= DEFAULT_PULSE_ON_DISPLAY;		
								break;
								default:
									break;			
								}
}

	
/************************ (C) COPYRIGHT Nagoba Electronics *****END OF FILE****/




