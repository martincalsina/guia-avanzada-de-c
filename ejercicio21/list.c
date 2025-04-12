#include "list.h"

//devuelvo un puntero a una funcion que espera cierto type_t para copiarlo
funcCopy_t getCopyFunction(type_t t) {
    switch (t) {
    case TypeFAT32: return (funcCopy_t) copy_fat32; break;
    case TypeEXT4: return (funcCopy_t) copy_ext4; break;
    case TypeNTFS: return (funcCopy_t) copy_ntfs; break;
    default: return NULL; break;
    }
}

funcRm_t getRmFunction(type_t t) {
    switch (t) {
    case TypeFAT32: return (funcRm_t) rm_fat32; break;
    case TypeEXT4: return (funcRm_t) rm_ext4; break;
    case TypeNTFS: return (funcRm_t) rm_ntfs; break;
    default: return NULL; break;
    }
}

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t)); //pido lo que sea de memoria para alojar a la lista
    //no hace falta conocer cual sera su size, pues solo tiene un puntero a un nodo
    l->type = t;
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;     
}

void listAddFirst(list_t* l, void* data) {
    //debo crear un nodo nuevo
    node_t* n = malloc(sizeof(node_t));
    n->data = getCopyFunction(l->type)(data);
    if (l->size > 0) {
        l->first->previous = n;
    } else {
        l->last = n; //es un unico elem en la lista
    }

    n->next = l->first;
    n->previous = NULL;
    l->first = n;
    l->size++;

}

void listAddLast(list_t* l, void* data) {
    //debo crear un nodo nuevo
    node_t* n = malloc(sizeof(node_t));
    n->data = getCopyFunction(l->type)(data);

    if (l->size > 0) {
        l->last->next = n;
    } else {
        l->first = n; //es un unico elem en la lista
    }

    n->previous = l->last;
    n->next = NULL;
    l->last = n;
    l->size++;

}

//asumo indice valido
void* listGet(list_t* l, uint8_t i) {
    node_t* n = l->first;
    for (int j=0; j<i; j++) {
        n = n->next; //el puntero al siguiente
    }
    return n->data;
}

void* listRemove(list_t* l, uint8_t i) {
    node_t* node_to_remove = NULL;
    void* data = NULL;   
    if (i == 0) {
        node_to_remove = l->first;
        data = node_to_remove->data;
        l->first = node_to_remove->next;
        if (l->first != NULL) {
            l->first->previous = NULL;
        }
    } else if (i == l->size -1) {
        node_to_remove = l->last;
        data = node_to_remove->data;
        l->last = node_to_remove->previous;
        if (l->last != NULL) {
            l->last->next = NULL;
        }
    }
    else{
        node_t * n = l->first;
        for (int j=0; j<i-1; j++) {
            n = n->next;
        }
        node_to_remove = n->next;
        data = node_to_remove->data;
        n->next = node_to_remove->next;
        if (node_to_remove->next != NULL) {
            node_to_remove->next->previous = n;
        }
    }

    free(node_to_remove);
    l->size--;
    return data;
}

void listDelete(list_t* l) {
    node_t* n = l->first;
    while (n) {
        node_t* node_to_remove = n;
        n = n-> next;
        getRmFunction(l->type)(node_to_remove->data);
        free(node_to_remove);
    }
    free(l);
}

