/*
 * BitwiseOperation.h
 *
 * Created: 2/13/2019 11:38:06 AM
 *  Author: AVE-LAP-025
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_
#include "type.h"

#define Set_Bit(Register,Bit)		Register=(uint8)(Register)|(1<<Bit)
#define Clear_Bit(Register,Bit)		Register=(uint8)(Register)&~(1<<Bit)
#define Toggle_Bit(Register,Bit)	Register=(uint8)(Register)^(1<<Bit)
#define Get_Bit(Register,Bit)		((uint8)((Register)&(1<<Bit))>>Bit)



#endif /* BITWISEOPERATION_H_ */