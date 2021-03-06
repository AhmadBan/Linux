/*
 * gsm.h
 *
 *  Created on: Jan 7, 2021
 *      Author: Ahmad
 */

#ifndef INC_GSM_H_
#define INC_GSM_H_

#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#include<stdio.h>   // Standard I/O Routines Library

#include<unistd.h>  // Unix Standard Library

#include<pthread.h> // POSIX Thread Creation Library


#include "commands/baseCommand.h"
#include "commands/getOperator.h"
#include "commands/smsTextMode.h"
#include "commands/disableSMSNotif.h"
#include "commands/disableCall.h"
#include "commands/readSMS.h"
#include "myQueue.h"
typedef struct {
	MyQueue_t mq;
	int port;
	int inputSMSPollingPeriod;
}GSM_t;

GSM_t* gsmSetup(char * portAddress,int polligInSMSPeriod);
void *gsmQueueExecution(void * gsm);
void *gsmPollingReadSMS(void *gsm);
#endif /* INC_GSM_H_ */
