/* 
 * File:   7_segment.c
 * Author: Hadal Magdy Ahmed
 * Created on May 29, 2025, 4:47 PM
 */
#include "seven_segment.h"

Std_ReturnType seven_segment_init(const seven_segment_t * ssegment) {
    Std_ReturnType ret = E_OK;
    if (NULL == ssegment) {
        ret = E_NOT_OK;
    } else {

        ret = gbio_pin_init(&ssegment->pins[PIN0]);
        ret |= gbio_pin_init(&ssegment->pins[PIN1]);
        ret |= gbio_pin_init(&ssegment->pins[PIN2]);
        ret |= gbio_pin_init(&ssegment->pins[PIN3]);

    }
    return ret;
}

Std_ReturnType seven_segment_write_number(const seven_segment_t * ssegment, uint8 number) {
    Std_ReturnType ret = E_OK;
    if (NULL == ssegment || number > 9) {
        ret = E_NOT_OK;
    } else {
        if (COMMON_CATHODE == ssegment->seven_segment_type) {
            number = ~(number);
        }
        ret = gbio_pin_write_logic(&ssegment->pins[PIN0], ((number >> PIN0) & 0x01));
        ret |= gbio_pin_write_logic(&ssegment->pins[PIN1], ((number >> PIN1) & 0x01));
        ret |= gbio_pin_write_logic(&ssegment->pins[PIN2], ((number >> PIN2) & 0x01));
        ret |= gbio_pin_write_logic(&ssegment->pins[PIN3], ((number >> PIN3) & 0x01));
    }
    return ret;
}