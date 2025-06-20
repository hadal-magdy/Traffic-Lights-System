/* 
 * File:   mcal_std_types.h
 * Author: Hadal Magdy Ahmed
 *
 * Created on May 24, 2025, 10:04 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*Section : Includes*/
#include "compiler.h"
#include"mcal_std_libraries.h"

/*Section : Data Type Declarations*/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef unsigned char sint8;
typedef unsigned short sint16;
typedef unsigned int sint32;

typedef uint8 Std_ReturnType;

/*Section : Macro Declarations*/
#define STD_HIGH    0x01
#define STD_LOW     0x00

#define STD_ON      0x01
#define STD_OFF     0x00

#define CONFIG_ENABLE      0x01
#define CONFIG_DISABLE     0x00

#define STD_ACTIVE  0x01
#define STD_IDLE    0x00

#define E_OK        (Std_ReturnType)0x01
#define E_NOT_OK    (Std_ReturnType)0x00

/*Section : Macro Functions Declarations*/

/*Section : Function Declarations*/


#endif	/* MCAL_STD_TYPES_H */

