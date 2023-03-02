#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../include/msqutils.h"

int init_message_queue()
{
    int msgflg = IPC_CREAT | 0666;
    key_t key = ftok(MSQ_NAME, MSQ_ID);
    return msgget(key, msgflg);
}

void receive_message(msq_msg_t *message, long mtype)
{
    msgrcv(msqid, message, sizeof(message_t), mtype, 0);
}

void send_message(msq_msg_t message)
{
    msgsnd(msqid, &message, sizeof(message_t), 0);
}
