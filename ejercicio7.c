
//swapeo de dos ints x e y usando punteros
void swap(int *a, int *b) {
    int tmp = *a; //valor al que apunta el puntero a
    *a = *b; //el valor del lugar al que apunta a pasa a ser el valor que hay en el lugar donde apunta b
    *b = tmp; //el valor de donde apunta b pasa a serlo que habia en a
    }

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
}

//si tuviera void swap(int a, int b), no podría hacer el swap, porque lo que se pasaría
//por parámetro serían copias de los valores de a y b.
//tengo swap(&x, &y), estoy pasando las direcciones de memoria de x e y
//debería hacer algo como
/*

int *pa = a //a es &x
int *pb = b //b es &y

y hacer lo que ya está puesto

int tmp = *pa; /
*pa = *pb; 
*pb = tmp; 

*/