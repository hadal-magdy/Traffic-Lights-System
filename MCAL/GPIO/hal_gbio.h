/* 
 * File:   hal_gbio.h
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 24, 2025, 9:58 AM
 */

#ifndef HAL_GBIO_H
#define	HAL_GBIO_H

/*Section : Includes*/
#include"../device_config.h"
#include"../mcal_std_types.h"
#include "hal_gbio_config.h"
#include <pic18f4620.h>
/*Section : Macro Declarations*/
#define BIT_MASK    (uint8)1

/*Section : Macro Functions Declarations*/
#define HWREG8(_x) (*((volatile uint8 *)(_x)))

#define SET_BIT(REG,BIT)    (REG |= (BIT_MASK << BIT))
#define CLEAR_BIT(REG,BIT)  (REG &= ~(BIT_MASK << BIT))
#define TOGGLE_BIT(REG,BIT) (REG ^= (BIT_MASK << BIT))
#define READ_BIT(REG,BIT)   ((REG >> BIT) & BIT_MASK)

#define PIN_MAX_NUMBER      8
#define PORT_MAX_NUMBER     5

#define PORT_TOGGLE_MASK    0xFF

/*Section : Data Type Declarations*/
typedef enum {
    GPIO_LOW,
    GPIO_HIGH
} logic_t;

typedef enum {
    GPIO_OUTPUT,
    GPIO_INPUT
} direction_t;

typedef enum {
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
} pin_t;

typedef enum {
    GPIO_PORTA_INDEX,
    GPIO_PORTB_INDEX,
    GPIO_PORTC_INDEX,
    GPIO_PORTD_INDEX,
    GPIO_PORTE_INDEX,
} port_t;

typedef struct {
    uint8 pin : 3;          /*@ref pin_t*/
    uint8 port : 3;         /*@ref port_t*/
    uint8 logic : 1;        /*@ref logic_t*/
    uint8 direction : 1;    /*@ref direction_t*/    
} pin_config_t;
/*Section : Function Declarations*/
Std_ReturnType gbio_pin_init(const pin_config_t * pin_config);
Std_ReturnType gbio_pin_direction_init(const pin_config_t * pin_config);
Std_ReturnType gbio_pin_get_direction(const pin_config_t * pin_config, uint8 *direction);
Std_ReturnType gbio_pin_write_logic(const pin_config_t * pin_config,uint8 logic);
Std_ReturnType gbio_pin_toggle_logic(const pin_config_t * pin_config);
Std_ReturnType gbio_pin_read_logic(const pin_config_t * pin_config,uint8 *logic);

Std_ReturnType gbio_port_direction_init(port_t port, uint8 direction);
Std_ReturnType gbio_port_get_direction(port_t port, uint8 *direction);
Std_ReturnType gbio_port_write_logic(port_t port, uint8 logic);
Std_ReturnType gbio_port_toggle_logic(port_t port);
Std_ReturnType gbio_port_read_logic(port_t port, uint8 *logic);

#endif	/* HAL_GBIO_H */

