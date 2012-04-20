/************************************************************************/
/*    						NXP Semiconductors							*/
/* 		FreeRTOS Hands-on lab for the LPCxpresso for LPC1114			*/
/************************************************************************/

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Header file include for LPC1114 */
#include "LPC11xx.h"
#include "lcd.h"

/* Demo includes. */
#include "debug.h"

/* Declare a variable of type xSemaphoreHandle.  This is used to reference the
semaphore that is used to synchronize a task with an interrupt. */
//--------- Lab edit begin ---------
xSemaphoreHandle ButtonSemaphore;

// This function is called whenever FreeRTOS detects a stack overflow.
void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed portCHAR *pcTaskName )
{
	debug_puts("Stack overflow in thread: ");
	debug_puts((char *)pcTaskName);
}

/*-----------------------------------------------------------*/


/********************************************/
/* Our hands-on lab tasks are defined below */
/********************************************/

void vTaskLEDBlinker1(void *pvParameters)
{
	while(1)
	{
		if( LPC_GPIO0->DATA & (1<<6) ) {	// Is LPCxpresso board LED on?
			LPC_GPIO0->DATA &= ~(1<<6);	// if yes...turn it off
		}
		else {
			LPC_GPIO0->DATA |= (1<<6);	// It's off...turn it on
		}
		vTaskDelay(configTICK_RATE_HZ / 2);	// This task runs 2 times a second
	}
}
/*-----------------------------------------------------------*/

void vTaskDebuggerHeartbeat(void *pvParameters)
{
	while(1)
	{
		debug_puts((char *)"Heartbeat");		// Print heart beat message on console
		vTaskDelay(configTICK_RATE_HZ * 5);		// This task runs once every 3 seconds
	}
}
/*-----------------------------------------------------------*/

 void vTaskLcdDisplay(void *pvParameters)
{
	int i=0;

//--------- Lab edit begin ---------
	xSemaphoreTake(ButtonSemaphore, 0);

	while(1)
	{
//--------- Lab edit begin ---------
		xSemaphoreTake(ButtonSemaphore, portMAX_DELAY);

        if ((i & 0x01) == 0) {
		   lcd_putstring(0, "  UST SEIS 740  ");
		   lcd_putstring(1, "----------------");
        }
        else {
        	lcd_putstring(0, "++++++++++++++++");
        	lcd_putstring(1, "  UST SEIS 740  ");
        }

        i++;
	}
}

void vApplicationIdleHook( void )
{
	__WFI();
}

void PIOINT0_IRQHandler(void) {
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;  // do not force immediate context switch

    /* 'Give' the semaphore to unblock the task. */
//--------- Lab edit begin ---------
	xSemaphoreGiveFromISR( ButtonSemaphore, &xHigherPriorityTaskWoken );

    LPC_GPIO0->IC |= (1<<7);   // clear interrupt on P0.7
    __NOP();
    __NOP();
	portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}


int main( void )
{
	LPC_IOCON->PIO0_7 = 0x30;	 // configure PIO0_7 as an input with hysteresis
	LPC_GPIO0->IS  &= ~(1<<7);   // edge trigger
	LPC_GPIO0->IBE &= ~(1<<7);   // control based on IEV register
	LPC_GPIO0->IEV &= ~(1<<7);   // falling edge
	LPC_GPIO0->IE  |= (1<<7);    // enable interrupt

	LPC_GPIO0->DIR |= (1<<6);	/* Set up P0.7 as output */
	LPC_GPIO0->DATA &= ~(1<<6);	/* Turn off LED2 on LPCXpresso board */

	init_lcd();

//--------- Lab edit begin ---------
	vSemaphoreCreateBinary(ButtonSemaphore);

	/* Create one of the three tasks. */
	xTaskCreate(	vTaskLEDBlinker1,	/* Pointer to the function that implements the task. */
				    (const signed portCHAR *)"Blinker 1",		/* Text name for the task.  This is to facilitate debugging only. */
				    configMINIMAL_STACK_SIZE,		/* Stack depth in words. */
					NULL,		/* We are not using the task parameter. */
					3,			/* This task will run at priority 3. */
					NULL );		/* We are not using the task handle. */

	/* Create the other tasks in exactly the same way. */
	xTaskCreate( vTaskDebuggerHeartbeat, (const signed portCHAR *)"Heartbeat", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	xTaskCreate( vTaskLcdDisplay, (const signed portCHAR *)"Display", configMINIMAL_STACK_SIZE, NULL, 3, NULL);

	NVIC_SetPriority( EINT0_IRQn, 0);
	NVIC_EnableIRQ( EINT0_IRQn );

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();

	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

/**************************************************************/


void vApplicationMallocFailedHook( void )
{
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}

