/* 
 * File:   hal_gbio.c
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 24, 2025, 9:58 AM
 */
#include "hal_gbio.h"
volatile uint8 * port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 * tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 * lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};


#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_init(const pin_config_t * pin_config) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->pin > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        ret = gbio_pin_direction_init(pin_config);
        ret |= gbio_pin_write_logic(pin_config, pin_config->logic);
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_direction_init(const pin_config_t * pin_config) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->port > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        switch (pin_config->direction) {
            case GPIO_OUTPUT:
                CLEAR_BIT(*tris_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_INPUT:
                SET_BIT(*tris_registers[pin_config->port], pin_config->pin);
                break;
            default: ret = E_NOT_OK;
        }
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_get_direction(const pin_config_t * pin_config, uint8 *direction) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (direction == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->port > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        *direction = READ_BIT(*tris_registers[pin_config->port], pin_config->pin);
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_write_logic(const pin_config_t * pin_config, uint8 logic) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->port > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        switch (logic) {
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[pin_config->port], pin_config->pin);
                break;
            default: ret = E_NOT_OK;
        }
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_read_logic(const pin_config_t * pin_config, uint8 *logic) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (logic == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->pin > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        *logic = READ_BIT(*port_registers[pin_config->port], pin_config->pin);
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_pin_toggle_logic(const pin_config_t * pin_config) {
    Std_ReturnType ret = E_NOT_OK;
    if ((pin_config == NULL) || (pin_config->pin > (PIN_MAX_NUMBER - 1)) || (pin_config->pin > (PORT_MAX_NUMBER - 1))) {
        return ret;
    } else {
        TOGGLE_BIT(*lat_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif



#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_port_direction_init(port_t port, uint8 direction) {
    Std_ReturnType ret = E_NOT_OK;
    if (port > (PORT_MAX_NUMBER - 1)) {
        return ret;
    } else {
        *tris_registers[port] = direction;
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_port_get_direction(port_t port, uint8 *direction) {
    Std_ReturnType ret = E_NOT_OK;
    if ((direction == NULL) || port > (PORT_MAX_NUMBER - 1)) {
        return ret;
    } else {
        *direction = *tris_registers[port];
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_port_write_logic(port_t port, uint8 logic) {
    Std_ReturnType ret = E_NOT_OK;
    if (port > (PORT_MAX_NUMBER - 1)) {
        return ret;
    } else {
        *lat_registers[port] = logic;
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_port_toggle_logic(port_t port) {
    Std_ReturnType ret = E_NOT_OK;
    if (port > (PORT_MAX_NUMBER - 1)) {
        return ret;
    } else {
        *lat_registers[port] ^= PORT_TOGGLE_MASK;
        ret = E_OK;
    }
    return ret;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

Std_ReturnType gbio_port_read_logic(port_t port, uint8 *logic) {
    Std_ReturnType ret = E_NOT_OK;
    if (port > (PORT_MAX_NUMBER - 1) || ( NULL == logic)) {
        return ret;
    } else {
        *logic = *lat_registers[port];
        ret = E_OK;
    }
    return ret;
}
#endif
