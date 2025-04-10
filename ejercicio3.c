# include <stdio.h>

int main(){
    int x = 42;
    int *p = &x;
    printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
    printf("Valor de lo que apunta p: %d\n", *p);
}

//¿Cuál es la diferencia entre x y p? ¿Y entre x y &x? ¿Y entre p y *p?
/*
- x tiene el valor 42, p es igual a la dirección en memoria que tien x.
- x tiene el valor 42, &x es su dirección en memoria
- p tiene como valor la dirección en memoria de x, osea p = &x, mientras
que *p tiene el valor almacenado en esa dirección, osea *p = 42.
*/
//¿Qué valores creen que se van a imprimir por terminal?