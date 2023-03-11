#ifndef MESSAGE_H
#define MESSAGE_H

#include <db-utils/types.h>

#define MAX_LENGTH_BARCODE 13

typedef struct
{
    char barcode[MAX_LENGTH_BARCODE];
    float price;
} scanner_message_t;

typedef struct
{
    ip_address_t ip_address;
} led_message_t;

typedef union
{
    scanner_message_t scanner;
    led_message_t led;
} message_t;

typedef struct
{
    long mtype;
    message_t message;
} msq_msg_t;

#endif