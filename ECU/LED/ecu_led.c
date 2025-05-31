/* 
 * File:   ecu_led.c
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 25, 2025, 2:49 PM
 */

#include "ecu_led.h"

Std_ReturnType led_init(const led_t * led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_OUTPUT,
            .logic = led->led_status
        };
        ret = gbio_pin_init(&pin_obj);
    }
    return ret;
}

Std_ReturnType led_on(const led_t * led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_OUTPUT,
            .logic = led->led_status
        };
        ret = gbio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;
}
Std_ReturnType led_off(const led_t * led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_OUTPUT,
            .logic = led->led_status
        };
        ret = gbio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}

Std_ReturnType led_toggle(const led_t * led){
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    }
    else {
        pin_config_t pin_obj = {
            .port = led->port,
            .pin = led->pin,
            .direction = GPIO_OUTPUT,
            .logic = led->led_status
        };
        ret = gbio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}