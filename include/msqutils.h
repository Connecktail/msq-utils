#ifndef MSQUTILS_H
#define MSQUTILS_H

#include "message.h"

#define MSQ_ID 1234
#define MSQ_NAME "/etc/connecktail/msq"

extern int msqid;

/**
 * @brief Initialize the message queue
 * @return The message queue id
 */
int init_message_queue();

/**
 * @brief Receive a message from the message queue
 * @param message the buffer where the message will be sent
 * @param mtype The type of the message to receive
 */
void receive_message(msq_msg_t *message, long mtype);

/**
 * @brief Send a message to the message queue
 * @param message The message to send
 */
void send_message(msq_msg_t message);

#endif