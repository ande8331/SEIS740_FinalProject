/*****************************************************************************
 *   joystick.c:  Driver for the Joystick switch
 *
 *   Copyright(C) 2009, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************/

/*
 * NOTE: GPIOInit must have been called before using any functions in this
 * file.
 *
 */


/******************************************************************************
 * Includes
 *****************************************************************************/

#include "LPC11xx.h"
#include "joystick.h"

/******************************************************************************
 * Defines and typedefs
 *****************************************************************************/

/******************************************************************************
 * External global variables
 *****************************************************************************/

/******************************************************************************
 * Local variables
 *****************************************************************************/


/******************************************************************************
 * Local Functions
 *****************************************************************************/


/******************************************************************************
 * Public Functions
 *****************************************************************************/

/******************************************************************************
 *
 * Description:
 *    Initialize the Joystick Driver
 *
 *****************************************************************************/
void joystick_init (void)
{
    /* set the GPIOs as inputs */
//    GPIOSetDir( PORT2, 0, 0 );
//    GPIOSetDir( PORT2, 1, 0 );
 //   GPIOSetDir( PORT2, 2, 0 );
//    GPIOSetDir( PORT2, 3, 0 );
//    GPIOSetDir( PORT3, 4, 0 );
}

/******************************************************************************
 *
 * Description:
 *    Read the joystick status
 *
 * Returns:
 *   The joystick status. The returned value is a bit mask. More than one
 *   direction may be active at any given time (e.g. UP and RIGHT)
 *
 *****************************************************************************/
uint8_t joystick_read(void)
{
	uint8_t status = 0;
	uint32_t port2 = 0;
    uint32_t port3 = 0;

    port2 = LPC_GPIO2->DATA;
    port3 = LPC_GPIO3->DATA;

    if (!(port2 & 0x01)) {		/* PIO2_0 */
        status |= JOYSTICK_CENTER;
    }

    if (!(port2 & 0x02)) {		/* PIO2_1 */
        status |= JOYSTICK_LEFT;
    }

    if (!(port2 & 0x04)) {		/* PIO2_2 */
        status |= JOYSTICK_DOWN;
    }

    if (!(port2 & 0x08)) {		/* PIO2_3 */
        status |= JOYSTICK_RIGHT;
    }

    if (!(port3 & 0x10)) {	/* PIO3_4 */
        status |= JOYSTICK_UP;
    }

    return status;
}
