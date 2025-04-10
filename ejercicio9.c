/*
Definir una función que reciba un string y lo pase a mayúsculas. Pista: alcanza con sumar
la diferencia entre ’A’ y ’a’ a cada letra. Sólo aplicar la conversión si lo que llega es una
letra minúscula.
*/

#include <stdio.h>
#define UPCASESUM ('A' - 'a')

char getLetterUpperCase(char letter) {
    
    //https://www.w3schools.com/charsets/ref_html_ascii.asp
    if (letter < 97) {
        //si el codigo en ASCII del char es menor a 97, no es una letra o ya está en uppercase
        return letter;
    } else {
        return letter + UPCASESUM;
    }

}

char* getStringUpperCase(char* str) {

    char* head = str; 

    while (*str != '\0') {
        *str = getLetterUpperCase(*str);
        str += 1; //incrementar en uno a un puntero es sumarle una unidad del sizeof el tipo de dato al que apunta, en este caso 1 byte
    }

    return head;

}

int main() {
    char str[] = "Ahora estoy furioso, Freezer!";
    char* p = str; //hago un puntero aparte porque los literales no se pueden modificar
    printf("%s \n", p);
    printf("%s \n", getStringUpperCase(p));
    return 0;
}