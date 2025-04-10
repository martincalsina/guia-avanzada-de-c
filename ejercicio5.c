# include <stdio.h>
# include <stdint.h>
int main(){
    uint8_t *x = (uint8_t*) 0xF0;
    int8_t *y = (int8_t*) 0xF6;
    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
    //Devolverá:
    // Dir de x: 0xF0 Valor: 255
    // Dir de y: 0xF6 Valor: -128
}

//¿Por qué x e y tienen distintos tipos? ¿Qué representan?
/*
- x es el valor que hay en la dirección de memoria 0xf0 como unsigned int de 8 bits, o sea
que se representa lo que haya como un entero entre 0 y 255.
- y es el valor que hay en la dirección de memoria 0xf6 casteado como int de 8 bits, 
o sea algo entre -128 y 127.
Los tipos son distintos porque a lo que acceden tiene tipo distino (o bueno, lo estamos
casteando como tipos deistintos para forzar esto, "interpretá la tira de bits de esta manera")
*/