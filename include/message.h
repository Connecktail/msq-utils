#ifndef MESSAGE_H
#define MESSAGE_H

#include <db-utils/types.h>

#define MAX_LENGTH_MESSAGE 600
#define MAX_LENGTH_BARCODE 13

typedef struct 
{
    long long int id_order;
    int cocktail;
    int total_cocktail;
    int step;
    int total_step;
    int bottle;
    int total_bottle;
    char message[MAX_LENGTH_MESSAGE];
} status_message_t;

typedef struct
{
    char barcode[MAX_LENGTH_BARCODE];
    float price;
} scanner_message_t;

typedef struct
{
    ip_address_t ip_address;
} led_message_t;

typedef struct
{
    ip_address_t ip_address;
} buzzer_message_t;

typedef union
{
    status_message_t order_status;
    scanner_message_t scanner;
    buzzer_message_t buzzer;
    led_message_t led;
} message_t;

typedef struct
{
    long mtype;
    message_t message;
} msq_msg_t;

#endif