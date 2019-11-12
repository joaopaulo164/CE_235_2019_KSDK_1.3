#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "task.h"
#include "shell_driver.h"

typedef enum {
	START,
	PAUSE,
	STATUS,
	RESUME
} options_t;

char initialMenu[] = "\
InitialMenu\r\n\
Shell Commands \r\n\
\r\n\
1 - Pause \n\r\
2 - Status \n\r\
3 - Resume \n\r\
";

options_t option = START;

void shell_routine(void) {
	char read_value = 0;
	do {
		debug_printf("%s", initialMenu);
		read_value = debug_getchar();

		if (read_value == '1') {
			option = PAUSE;
		} else if (read_value == '2') {
			option = STATUS;
		} else if (read_value == '3') {
			option = RESUME;
		} else {
			debug_printf("Wrong option!!! Options are 1, 2 and 3. \r\n");
			option = START;
		}

		switch (option) {
		case PAUSE:
			debug_printf("PAUSE Option! \r\n");
			//vTaskSuspendAll();
			option = START;
			break;
		case STATUS:
			debug_printf("STATUS Option! \r\n");

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
					debug_printf( "TASK NAME     ID    PRIORITY     STATUS     TCOMP \r\n");
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
					debug_printf("\n\r");
				}

				/* The array is no longer needed, free the memory it consumes. */
				vPortFree( pxTaskStatusArray );

			}

			option = START;
			break;
		case RESUME:
			debug_printf("RESUME Option! \r\n");
			//xTaskResumeAll();
			option = START;
			break;
		default:
			debug_printf("DEFAULT Option \r\n");
			option = START;
			break;
		}

		break;
	} while (1);




}
