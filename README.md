# Msq-utils

## Purpose :

This repository provide a C library for using message queues in the connecktail project in order to communicate between the different modules witha the same functions and in the same way in every place it is needed.

## Build the library :

- clone the repository
- execute the following commands :

```bash
make
make install
```

The headers have been added to the /usr/include/msq-utils repository

In your code, you have just to include the dbutils.h header file :

```c
#include <msq-utils/msqutils.h>
```

In order to get the different types for the message queues, you have to include the msqtypes.h header file in your code :

```c
#include <msq-utils/msqtypes.h>
```

**Because the functions to recieve or send a message need the message queue id, you have to declare a global variable in your code :**

```c
int msqid;
```

Its value will be the result of the init_message_queue() function.

## Compilation :

If you want to use the static library, you have just to specify the path of the lib and its name :

```bash
gcc file.c -L path/to/libmsq-utils.a -lmsq-utils -o file
```

On the other hand, if you want to use the dynamic library, specify the name of the lib during the links edition :

```bash
gcc file.c -lmsq-utils -o file
```

## Data structures :

You will find the different data structures used to to send data through the message queues. Thoses data structures can be foundin the message.h header file
**Global struct which will be sent :**

```c
typedef struct
{
    long mtype;
    message_t message;
} msq_msg_t;

```

**Union message_t**

An union has been used to be able to use the same type "message_t" in the global struct not to make different gloabl struct for each type of message.

```c
typedef union
{
    scanner_message_t scanner;
    buzzer_message_t buzzer;
} message_t;
```

**Struct scanner_message_t**

```c
typedef struct
{
    char barcode[MAX_LENGTH_BARCODE]; //13
} scanner_message_t;
```

**Struct buzzer_message_t**

```c
typedef struct
{
    ip_address_t ip_address;
} buzzer_message_t;
```

## Functions :

### Utils

- Initialize the message queue :

```c
int init_message_queue()
```

- Receive a message from the message queue :

```c
void receive_message(msq_msg_t *message, long mtype)
```

- Send a message to the message queue :

```c
void send_message(msq_msg_t message)
```

## How to contribute

If you want to add a new message type to the message queue, please fill the msgtypes.h to define the type of your message. Then, you have to add the corresponding structure in the message.h file. Finally, you have to add the structure you have juste created in the message_t union.
