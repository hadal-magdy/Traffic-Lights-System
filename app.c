/* 
 * File:   app.c
 * Author: Hadal Magdy Ahmed
 * Created on May 24, 2025, 10:00 AM
 */

#include "app.h"
#include "MCAL/GPIO/hal_gbio.h"

led_t red_led = {
    .port = GPIO_PORTC_INDEX,
    .pin = GPIO_PIN0,
    .led_status = LED_OFF
};
led_t yellow_led = {
    .port = GPIO_PORTC_INDEX,
    .pin = GPIO_PIN1,
    .led_status = LED_OFF
};
led_t green_led = {
    .port = GPIO_PORTC_INDEX,
    .pin = GPIO_PIN2,
    .led_status = LED_OFF
};

pin_config_t enable_ssegment1 = {
    .port = GPIO_PORTA_INDEX,
    .pin = GPIO_PIN0,
    .logic = GPIO_LOW,
    .direction = GPIO_OUTPUT,
};

pin_config_t enable_ssegment2 = {
    .port = GPIO_PORTA_INDEX,
    .pin = GPIO_PIN1,
    .logic = GPIO_LOW,
    .direction = GPIO_OUTPUT,
};

seven_segment_t ssegment = {
    .pins[PIN0].port = GPIO_PORTD_INDEX,
    .pins[PIN0].pin = GPIO_PIN0,
    .pins[PIN0].logic = GPIO_LOW,
    .pins[PIN0].direction = GPIO_OUTPUT,
    .pins[PIN1].port = GPIO_PORTD_INDEX,
    .pins[PIN1].pin = GPIO_PIN1,
    .pins[PIN1].logic = GPIO_LOW,
    .pins[PIN1].direction = GPIO_OUTPUT,
    .pins[PIN2].port = GPIO_PORTD_INDEX,
    .pins[PIN2].pin = GPIO_PIN2,
    .pins[PIN2].logic = GPIO_LOW,
    .pins[PIN2].direction = GPIO_OUTPUT,
    .pins[PIN3].port = GPIO_PORTD_INDEX,
    .pins[PIN3].pin = GPIO_PIN3,
    .pins[PIN3].logic = GPIO_LOW,
    .pins[PIN3].direction = GPIO_OUTPUT,
    .seven_segment_type = COMMON_ANODE
};

Std_ReturnType ret = E_NOT_OK;

void init() {
    ret = seven_segment_init(&ssegment);
    ret = gbio_pin_init(&enable_ssegment1);
    ret = gbio_pin_init(&enable_ssegment2);
    ret = led_init(&red_led);
    ret = led_init(&yellow_led);
    ret = led_init(&green_led);
}

void counter(void) {
    uint8 number = 60;
    while (number > 0) {
        for (uint8 i = 100; i > 0; --i) {
            gbio_pin_write_logic(&enable_ssegment1, GPIO_LOW);
            gbio_pin_write_logic(&enable_ssegment2, GPIO_LOW);

            seven_segment_write_number(&ssegment, ((uint8) (number / 10)));
            gbio_pin_write_logic(&enable_ssegment1, GPIO_HIGH);
            __delay_ms(5);
            gbio_pin_write_logic(&enable_ssegment1, GPIO_LOW);

            seven_segment_write_number(&ssegment, ((uint8) (number % 10)));
            gbio_pin_write_logic(&enable_ssegment2, GPIO_HIGH);
            __delay_ms(5);
            gbio_pin_write_logic(&enable_ssegment2, GPIO_LOW);
        }
        --number;
    }
}

int main() {
    init();
    while (1) {
        /****************red********************/
        ret = led_on(&red_led);
        counter();
        ret = led_off(&red_led);
        /****************yellow********************/
        ret = led_on(&yellow_led);
        counter();
        ret = led_off(&yellow_led);
        /****************green********************/
        ret = led_on(&green_led);
        counter();
        ret = led_off(&green_led);
    }
    return (EXIT_SUCCESS);
}

