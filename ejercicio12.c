/*
Definir una función crearPersona que reciba un nombre y una edad, y devuelva un
puntero a una estructura persona t que contenga esos datos. La función debe reservar
memoria dinámica para la estructura y devolver el puntero. Luego, en la función main,
crear una persona y liberar la memoria reservada. El string que se pasa por parámetro
debe ser copiado a la estructura.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char* nombre;
    int edad;
} persona_t;

persona_t* crearPersona(char* nombre, int edad) {
    //necesito memoria para el nombre + la edad
    persona_t* persona = malloc(strlen(nombre) * sizeof(char) + sizeof(int));
    (*persona).nombre = nombre;
    (*persona).edad = edad;
    return persona;
}

int main() {
    char* nombre = "Freezer";
    int edad = 123;
    persona_t* freezer = crearPersona(nombre, edad);
    printf("Nombre: %s, Edad: %d \n", (*freezer).nombre, (*freezer).edad);
    free(freezer);
}