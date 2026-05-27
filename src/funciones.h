#include <stdio.h>
#include <math.h>
#define PI 3.1416
#define TIERRA 9.81
#define VENUS 8.87
#define MERCURIO 3.70
#define MARTE 3.71
#define JUPITER 24.79
#define SATURNO 10.44
#define URANO 8.69
#define NEPTUNO 11.15
#define LUNA 1.62
//los angulos se reciben en grados y se cambian a radianes
float calcular_alcance(float velocidad, float angulo, float t);
float calcular_altura(float velocidad, float angulo, float t, float g);
float calcular_tiempo(float velocidad, float angulo, float g);
float calcular_radianes(float Angulo);
float calcular_alturamax(float velocidad, float angulo, float g);
void instrucciones(char eleccion);
void iniciar_juego();
//solucion bug
float limpiarbuffer(const char *mensaje)
