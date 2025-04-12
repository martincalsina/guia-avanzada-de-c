#include <stdint.h>
#include "type.h"

typedef struct node {
    void* data;
    struct node* next; //o struct node* tmb sirve
    struct node* previous;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    node_t* last;
} list_t;

list_t* listNew(type_t t);
void listAddFirst(list_t* l, void* data);
void listAddLast(list_t* l, void* data);
void* listGet(list_t* l, uint8_t i);
void* listRemove(list_t* l, uint8_t i);
void listDelete(list_t* l);
