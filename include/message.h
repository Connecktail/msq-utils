#ifndef MESSAGE_H
#define MESSAGE_H

#define MAX_LENGTH_BARCODE 13

typedef struct
{
    char barcode[MAX_LENGTH_BARCODE];
} scanner_message_t;

typedef union
{
    scanner_message_t scanner;
} message_t;

typedef struct
{
    long mtype;
    message_t message;
} msq_msg_t;

#endif