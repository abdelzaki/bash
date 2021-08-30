/*
Thread Creation
-----------------------------------------------------------------------------------------------------------------------------------------
*/
static void functionTobeExecuted (void const *arg);                         // declare the function which will run
static osThreadDef(functionTobeExecuted, osPriorityNormal, 1, 0);           // decide hiw many instance of the thread should run
static osThreadId ID;                                       				// thread id to check if the thread was created or not

static void functionTobeExecuted (void const *arg){							// define the function which you need to execute
	printf("created")
}
ID = osThreadCreate(osThread(functionTobeExecuted), NULL);					// start the thread 
 if (!ID) {																	// ID should be postive number in case no error hads happend
        return (-1);
    }
	
/*
Queue Creation 
-----------------------------------------------------------------------------------------------------------------------------------------
*/

osMailQId qeueID;                                                    										// Declare an ID for the message queue
osMailQDef(qeueID, MaximalSize, StructureDataType);           												// Define dataType and size to be sent and received
qeueID = osMailCreate(osMailQ(qeueID), NULL);   															// create msg queue
StructureDataType msg = (StructureDataType *) osMailCAlloc(StructureDataType, MAIL_ALLOC_TIMEOUT_MS);       // Allocate initialized memory
osMailPut(qeueID, msg);								// Put data in the queue data is end by reference other thread can change the data
osMailFree(qeueID, msg);																					// free data from the queue
osEvent evt = osMailGet(qeueID, osWaitForever); 															// get data from the queue
if (evt.status == osEventMail) {
   msg = evt.value.p;
}

/*
Message
-----------------------------------------------------------------------------------------------------------------------------------------
*/

osMessageQId id;   // Declare a message ID
osMessageQDef(id, MSG_UART_SIZE, uint32_t); // Define a message queue 
g_uartSndAppMsgQ = osMessageCreate(osMessageQ(id), NULL);   // create msg queue
/*
Signals
-----------------------------------------------------------------------------------------------------------------------------------------
*/
osSignalSet(msg->tid, msg->signal);	// which thread is waiting for the signal and which signal is he waiting for
osSignalWait(OS_SIGNAL_DFLASH_READ, READ_TIMEOUT_MS); // which signal is he waiting for and for how long should he wait for the signal
osSignalClear(tid, OS_SIGNAL_DFLASH_READ); // clear the signa which the thread is waiting for