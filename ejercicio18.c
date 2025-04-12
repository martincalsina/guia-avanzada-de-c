#include <stdlib.h>
#include <stdio.h>

void allocateArray(int *arr, int size, int value) {
    arr = (int*)malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
                arr[i] = value;
        }
    }
}
// Uso

int main() {
    int *vector = NULL;
    allocateArray(vector,5,45);
    for(int i = 0; i < 5; i++) {
        printf("%d\n", vector[i]);
    }
    free(vector);
}

/*Se supone que intento crear un arreglo manualmente pidiendo un puntero, valores
iniciales y un size con el que usar un malloc para reservar memria y rellenarlo,
pero tira segmentation fault

Lo que sucede es que no se está modificando a vector sino al puntero interno del array
arr. */
