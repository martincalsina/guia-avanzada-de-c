/*
Crear programas demostrativos que utilicen las funciones de strings provistas en la
librerı́a estándar de C (en string.h): strcpy, strcat, strlen, strcmp, etc. 
Para acceder a la documentación de cada función se puede usar la lı́nea de comando: 
man strcpy, man strlen, etc.
Side quest: investigar que significa restrict en la firma de la función strcpy
*/

#include <string.h>
#include <stdio.h>

int main() {
    char str[] = "Ahora estoy furioso, Freezer!";

    printf("String: %s Dirección: %p \n", str, &str); 

    int len = sizeof(str) / sizeof(char);

    char src[len];

    char* terminating = stpcpy(src, str); 
    //stpcpy copia en src lo que le doy en str y retorna un
    //puntero al byte nulo del final.
    //hay que asegurarse que desde src haya suficiente memoria para alojar la copia,
    //por eso declaré antes ul src[len]
    printf("String: %s Dirección: %p TerminatingDir: %p \n", src, &src, terminating); 
    
    //appendeo un string al final de otro
    char str2[80] = "¡¡¿Acaso Te refieres a Krillin?!! ";
    strcat(str2, str);
    printf("String: %s \n", str2); 

    int longitud = strlen(str2);

    printf("El anterior string tiene longitud %d \n", longitud);

    char str3[] = "abcdef";
    char str4[] = "abcgkl";

    int n = 6;

    int res = strcmp(str3, str4); //ve los primeros n chars y decide cual es más grande en ASCII
    
    if (res > 0) {
        printf("%s es más grande en ASCII que %s \n", str3, str4);
    } 

    if (res < 0) {
        printf("%s es más grande en ASCII que %s \n", str4, str3);
    }


}