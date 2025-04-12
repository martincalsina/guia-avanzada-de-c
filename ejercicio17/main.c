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
    //rm_fat32(f1);
    //rm_fat32(f2);
    return 0;
}

/*
Retorna lo siguiente el valgrind

==16878== Memcheck, a memory error detector
==16878== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==16878== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==16878== Command: ./ejercicio17/binario
==16878== 
==16878== 
==16878== HEAP SUMMARY:
==16878==     in use at exit: 8 bytes in 2 blocks
==16878==   total heap usage: 7 allocs, 5 frees, 88 bytes allocated
==16878== 
==16878== LEAK SUMMARY:
==16878==    definitely lost: 8 bytes in 2 blocks
==16878==    indirectly lost: 0 bytes in 0 blocks
==16878==      possibly lost: 0 bytes in 0 blocks
==16878==    still reachable: 0 bytes in 0 blocks
==16878==         suppressed: 0 bytes in 0 blocks
==16878== Rerun with --leak-check=full to see details of leaked memory
==16878== 
==16878== For lists of detected and suppressed errors, rerun with: -s
==16878== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Habían 8 bytes todavía en uso al finalizar el programa, son los dos fat32 que no removí 
*/