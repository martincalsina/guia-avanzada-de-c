#include <stdio.h>

typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

monstruo_t evolution(monstruo_t monstruo);

int main() {

    monstruo_t m1 = {"Goku", 100, 260, 220};
    monstruo_t m2 = {"Vegeta", 100, 270, 210};

    monstruo_t monstruos[] = {m1, m2};

    int length = sizeof(monstruos) / sizeof(monstruo_t);

    for(int i=0; i <length; i++) {
        monstruo_t m = monstruos[i];
        printf("Monstruo %d \n", i+1);
        printf("Nombre: %s Vida: %d Ataque: %f Defensa: %f \n", m.nombre, m.vida, m.ataque, m.defensa);
        m = evolution(m);
        printf("Monstruo %d evolucionado \n", i+1);
        printf("Nombre: %s Vida: %d Ataque: %f Defensa: %f \n", m.nombre, m.vida, m.ataque, m.defensa);
    }

    return 0;

}

monstruo_t evolution(monstruo_t monstruo) {
    monstruo.ataque += 10;
    monstruo.defensa += 10;
    return monstruo;
}