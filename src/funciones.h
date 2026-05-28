#include <stdio.h>
#include <math.h>
//los angulos se reciben en grados y se cambian a radianes
float calcular_alcance(float velocidad, float angulo, float t);
//funciones fisicas
float calcular_altura(float velocidad, float angulo, float t, float g);
float calcular_tiempo(float velocidad, float angulo, float g);
float calcular_radianes(float Angulo);
float calcular_alturamax(float velocidad, float angulo, float g);
float calcular_alcancemax(float velocidad, float angulo, float g);
//juego con preguntas
void iniciar_juego();
// pruebas donde se seleccionan los planetas
void modolibre();
//solucion bug
float limpiarbuffer(const char *instruccion);
