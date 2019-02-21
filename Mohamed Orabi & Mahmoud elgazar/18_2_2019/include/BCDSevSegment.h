/*
 * __BCDSevSegment.h
 *
 * Created: 2/18/2019 3:37:48 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef BCDSEVSEGMENT_H_
#define BCDSEVSEGMENT_H_

#include "type.h"
#include "timer.h"
#include "BCDSevSegment_config.h"


void BCDSevegments_init();
void BCDSevegments_enable(uint8 no_seg);
void BCDSevegments_disable (uint8 no_seg);
void BCDSevegments_displayNo(uint16 num1);



#endif /* “BCDSEVSEGMENT_H_ */