/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : lab04_message_queue
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-22, 16:15, # CodeGen: 2
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task2_task - void Task2_task(os_task_param_t task_init_data);
**         Task1_task - void Task1_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/         
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
extern msg_queue_handler_t msg_queue_handler;
//msg_queue_t queueHandler;
//extern msg_queue_handler_t queueHandler=MSG_QUEUE_DECLARE();
//extern xQueueHandle Global_Queue_Handle;

/*
** ===================================================================
**     Callback    : Task2_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task2_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	int cont_task2 = 0;
	osa_status_t status_task2;
	//char *messageToPut = "...";
	//struct MESSAGE messageToPut = '...';

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  ++cont_task2;
	  status_task2 = OSA_MsgQPut(msg_queue_handler, &cont_task2);
	  switch (status_task2) {
	  case kStatus_OSA_Success:
		  break;
	  case kStatus_OSA_Error:
		  break;
	  default:
		  break;
	  }
	  OSA_TimeDelay(1000);


               /* Example code (for task release) */
   
    
    
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/*
** ===================================================================
**     Callback    : Task1_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task1_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	int cont_task1 = 0;
	osa_status_t status_task1;
	int messageToGet = NULL;
	//struct MESSAGE messageToGet;
  

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  ++cont_task1;
	  status_task1 = OSA_MsgQGet(msg_queue_handler, &messageToGet, OSA_WAIT_FOREVER);
	  switch (status_task1) {
	  case kStatus_OSA_Success:
		  messageToGet;
		  break;
	  case kStatus_OSA_Error:
		  break;
	  default:
		  break;
	  }
	  OSA_TimeDelay(1000);


    
                  /* Example code (for task release) */
   
    
    
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
