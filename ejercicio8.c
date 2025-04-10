int main(){
    char *str1 = "Hola";
    char str2[] = "Hola";
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}

/*Hay diferencia entre una definición y otra?

- con un puntero puedo representar a un array, por lo que en principio las diferencias
serían las mismas que con array.
str2 no puede ser redefinido (es el inicio en memoria del literal "Hola") pero
str1 sí y apuntar a otro lado.
Los literales además no se pueden modificar, por lo que no puedo hacer
str2[3]=e pero sí str1[3]=e y tener Hole*/