#include <stdio.h>
#include <stdint.h>

uint16_t *secuencia(uint16_t n){
    uint16_t arr[n];
    for(uint16_t i = 0; i < n; i++)
    arr[i] = i;
    return arr;
}

/*Qué sucede acá?*/
int main(){
    uint16_t *arr = secuencia(10);
    printf("%d\n", arr[0]);
    return 0;
}

/*arr dentro de secuencia es una variable local que se almacena en memoria automática (no se
conoce al momento de compilación lo que valdrá n).
La memoria para ella se reserva y libera al ejecutar, haciendo que el arreglo ese
al que apunta arr en el return se muera (libere lo que ocupaba) al salir de la función, 
por lo que da segmentation fault, se está apuntando en arr[0] a 
una dirección desconocida

¿Cómo solucionarlo? 

podemos hacerlo todo en el main y liberar manualmente la memoria que ocupe arr luego
de printear

int main(){
    uint16_t *arr = secuencia(10);
    if (arr == NULL) {
    // Manejar el error de asignación de memoria
    return NULL;
    }
    for(uint16_t i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr); // Liberar la memoria reservada
    return 0;
}

*/