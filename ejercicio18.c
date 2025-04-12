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
arr. 

Lo correcto seria

void allocateArray(int **arr, int size, int value) { //recibo un puntero a un puntero
    *arr = (int*)malloc(size * sizeof(int)); //a ese puntero que recibi le hago ver esto
    if(*arr != NULL) { //si no ve a null
        for(int i=0; i<size; i++) {
            (*arr)[i] = value; //a lo que esta viendo accedo por indice
        }
    }
}

int *vector = NULL;
allocateArray(&vector,5,45); //le paso la direccion de mi puntero
for(int i = 0; i < 5; i++) {
    printf("%d\n", vector[i]);
}
free(vector);

*/
