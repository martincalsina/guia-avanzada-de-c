#include "list.h"
#include <stdio.h>




int main() {
    list_t* l = listNew(TypeFAT32);
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    listAddLast(l, f1);
    listAddFirst(l, f2);
    listDelete(l);
    //pero no elimino el dato de f2, el remove tampoco lo hace
    rm_fat32(f1);
    rm_fat32(f2);
    return 0;
}