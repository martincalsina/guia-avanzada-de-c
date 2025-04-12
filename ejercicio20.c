# define VIDEO_COLS 80
# define VIDEO_FILS 50
// Cada posicion de memoria tiene 2 bytes
typedef struct ca_s {
    uint8_t c; // caracter
    uint8_t a; // atributos
} ca;
void screen_draw_layout(void) {
    // VIDEO es un puntero a la dirección de memoria del buffer de video
    ca(*p)[VIDEO_COLS] = (ca(*)[VIDEO_COLS])VIDEO;
    uint32_t f,c;
    for (f = 0; f < VIDEO_FILS; f++) {
        for (c = 0; c < VIDEO_COLS; c++) {
            p[f][c].c = ' ';
            p[f][c].a = 0x10;
        }
    }
}

/*
Analicen el código anterior y respondan las siguientes preguntas:
¿Qué hace ca(*p)[VIDEO COLS] = (ca(*)[VIDEO COLS])VIDEO;?

//esta diciendole a p 'che, sos un puntero a arrays de VIDEO COLS elementos de tipo ca'

a VIDEo le estoy forzando a pensarse como un puntero a cosas de tantas columnas

¿Por qué funciona esto: p[f][c].c = ’ ’;?

p es un puntero a arreglos de VIDEO COLS elems, ¿A que arreglo voy?
Me muevo, soy un puntero, *(p+f) y accedo al elem del VIDEO COL *(p+f)[c] para luego,
como lo parsee como un ca, puedo acceder a su .c
*/