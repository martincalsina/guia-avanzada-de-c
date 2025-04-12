# include <stdio.h>
int main() {
    int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };
    // p apunta al int en la fila 0, columna 0
    int *p = &matrix[0][0];
    // ¿qué es reshape?
    int (*reshape)[2] = (int (*)[2]) p;
    /*Le dice a reshape que es un puntero que apunta a algo de dos columnas
    int (*)[2] fuerza a interpretar a p como una matriz de dos columnas*/
    printf("%d\n", p[3]); // Qué imprime esta lı́nea? si respecto de p me desplazo 3 veces, llego al 4, chill
    printf("%d\n", reshape[1][1]); // Qué imprime esta lı́nea? como reshape se piensa como matriz de dos columnas respecto de los elemes de p
    /*1 2 | 3 4 | 5 6 | 7 8 | 9 1 | 11 12 
    entonces irte a la fila 1 es la |3 4| y la col 1 es el 4*/
    return 0;
}

