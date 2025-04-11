/*
Definir una función eliminarPersona que reciba un puntero a una estructura persona t y
libere la memoria reservada para la estructura.
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

void eliminarPersona(persona_t* persona) {
    free(persona);
}

int main() {
    char* nombre = "Freezer";
    int edad = 123;
    persona_t* freezer = crearPersona(nombre, edad);
    printf("Nombre: %s, Edad: %d \n", (*freezer).nombre, (*freezer).edad);
    eliminarPersona(freezer);
}