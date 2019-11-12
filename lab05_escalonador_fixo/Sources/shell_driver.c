#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "task.h"
#include "shell_driver.h"

char initialMenu[] = "\
InitialMenu\r\n\
Shell Commands \r\n\
\r\n\
1 - Pause \n\r\
2 - State \n\r\
3 - Resume \n\r\
";

void shell_routine(void) {
	char option = 0;
	do {
		debug_printf("%s", initialMenu);
		option = debug_getchar();
		switch (option) {
			case 1:
				debug_printf("Option 1");
				//vTaskSuspendAll();
				break;
			case 2:
				debug_printf("Option 2");

				break;
			case 3:
				debug_printf("Option 3");

				break;
			default:
				break;
		}

		break;
	} while (1);

	TaskStatus_t *pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime;

	/* Take a snapshot of the number of tasks in case it changes while this
		 function is executing. */
	uxArraySize = uxTaskGetNumberOfTasks();

	/* Allocate a TaskStatus_t structure for each task.  An array could be
		 allocated statically at compile time. */
	pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );

	if( pxTaskStatusArray != NULL )
	{
		/* Generate raw status information about each task. */
		uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, &ulTotalRunTime );

		/* For percentage calculations. */
		ulTotalRunTime /= 100UL;

		/* Avoid divide by zero errors. */
		if( ulTotalRunTime > 0 )
		{
			debug_printf( "TASK NAME     ID    PRIORITY     STATUS     TCOMP \n\r\n\r");
			/* For each populated position in the pxTaskStatusArray array,
					 format the raw data as human readable ASCII data. */
			for( x = 0; x < uxArraySize; x++ )
			{
				char* taskStatus = 0;

				switch(pxTaskStatusArray[ x ].eCurrentState) {
				case eRunning:
					taskStatus = "RUNNING";
					break;
				case eReady:
					taskStatus = "READY";
					break;
				case eBlocked:
					taskStatus = "BLOCKED";
					break;
				case eSuspended:
					taskStatus = "SUSPENDED";
					break;
				case eDeleted:
					taskStatus = "DELETED";
					break;
				default:
					taskStatus = "FAILED";
					break;
				}

				char* taskPriority;

				switch(pxTaskStatusArray[ x ].uxCurrentPriority) {
				case 1:
					taskPriority = "LOWEST";
					break;
				case 2:
					taskPriority = "LOW";
					break;
				case 3:
					taskPriority = "REGULAR";
					break;
				case 4:
					taskPriority = "MEDIUM";
					break;
				case 5:
					taskPriority = "HIGH";
				}

				debug_printf( "%s       %d        %s        %s        %d\n\r",
						pxTaskStatusArray[ x ].pcTaskName,
						pxTaskStatusArray[ x ].xTaskNumber,
						taskPriority,
						taskStatus,
						pxTaskStatusArray[ x ].ulRunTimeCounter );
			}
		}

		/* The array is no longer needed, free the memory it consumes. */
		vPortFree( pxTaskStatusArray );

	}


}
