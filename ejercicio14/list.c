#include "list.h"

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t)); //pido lo que sea de memoria para alojar a la lista
    //no hace falta conocer cual sera su size, pues solo tiene un puntero a un nodo
    l->type = t;
    l->size = 0;
    l->first = NULL;
    return l;     
}

void listAddFirst(list_t* l, void* data) {
    //debo crear un nodo nuevo
    node_t* n = malloc(sizeof(node_t));
    switch (l->type) { //el dato del nodo debe ser el mismo que el de la lista
        case TypeFAT32:
        n->data = copy_fat32((fat32_t*) data); //haceme caso que es un fat
        break;
        case TypeEXT4:
        n->data = copy_ext4((ext4_t*) data);
        break;
        case TypeNTFS:
        n->data = copy_ntfs((ntfs_t*) data);
        break;
    }
    n->next = l->first; //el que ahora es first pasa a ser mi next
    l->first = n;//el nuevo first es el n
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
    } else {
        node_t * n = l->first;
        for (int j=0; j<i-1; j++) {
            n = n->next;
        }
        node_to_remove = n->next;
        data = node_to_remove->data;
        n->next = node_to_remove->next;
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
        switch (l->type) {
            case TypeFAT32:
            rm_fat32((fat32_t*) node_to_remove->data);
            break;
            case TypeEXT4:
            rm_ext4((ext4_t*) node_to_remove->data);
            break;
            case TypeNTFS:
            rm_ntfs((ntfs_t*) node_to_remove->data);
            break;
        }
        free(node_to_remove);
    }
    free(l);
}

