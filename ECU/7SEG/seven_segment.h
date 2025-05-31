/* 
 * File:   7_segment.h
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 29, 2025, 4:47 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/*Section : Includes*/
#include "../../MCAL/GPIO/hal_gbio.h"

/*Section : Macro Declarations*/
typedef enum {
    COMMON_ANODE,
    COMMON_CATHODE
} seven_segment_type_t;
typedef enum{
    PIN0,PIN1,PIN2,PIN3
}bcd_pins_t;
/*Section : Macro Functions Declarations*/
typedef struct {
    pin_config_t pins[4];
    uint8 seven_segment_type;
} seven_segment_t;
/*Section : Data Type Declarations*/
uint8 bcd_codes[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
/*Section : Function Declarations*/
Std_ReturnType seven_segment_init(const seven_segment_t * ssegment);
Std_ReturnType seven_segment_write_number(const seven_segment_t * ssegment, uint8 number);

#endif	/* SEVEN_SEGMENT_H */

