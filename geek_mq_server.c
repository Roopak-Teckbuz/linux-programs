// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 

    printf("server msgid:%d\n",msgid); 
    // msgrcv to receive message 
    int sm=msgrcv(msgid, &message, sizeof(message), 1, 0); 

	printf("*****complet data*****\n");
	printf("msgid of server:%d\n",msgid);
	printf("server message:%d\n",sm);
  
    // display the message 
    printf("Data Received is : %s \n",  
                    message.mesg_text); 
  
    // to destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 
  
    return 0; 
} 
