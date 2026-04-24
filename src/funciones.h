#include <stdio.h>
#include <math.h>
#include <string.h>
const float PI= 3.141592653589793;
const float TIERRA= 9.81;
const float VENUS= 8.87;
const float MERCURIO= 3.70;
const float MARTE = 3.71;
const float JUPITER = 24.79;
const float SATURNO =10.44;
const float URANO= 8.69;
const float NEPTUNO =11.15;
const float LUNA = 1.62;
//los angulos se reciben en grados y se cambian a radianes
float calcular_alcance(float velocidad, float angulo, float t);
float calcular_altura(float velocidad, float angulo, float t, float g);
float calcular_tiempo(float velocidad, float angulo, float g);
float calcular_radianes(float Angulo);
void iniciar_juego();