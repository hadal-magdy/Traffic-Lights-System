/* 
 * File:   ecu_led.h
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 25, 2025, 2:49 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section : Includes*/
#include "../../MCAL/GPIO/hal_gbio.h"

/*Section : Macro Declarations*/
typedef enum {
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct {
    uint8 port : 3;
    uint8 pin : 3;
    uint8 led_status : 1;
} led_t;
/*Section : Macro Functions Declarations*/
Std_ReturnType led_init(const led_t * led);
Std_ReturnType led_on(const led_t * led);
Std_ReturnType led_off(const led_t * led);
Std_ReturnType led_toggle(const led_t * led);

/*Section : Data Type Declarations*/

/*Section : Function Declarations*/

#endif	/* ECU_LED_H */

