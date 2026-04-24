#include "funciones.h"
float calcular_radianes(float angulo){
    float radianes= (angulo*PI)/180;
    return radianes;
}
float calcular_altura(float velocidad, float angulo, float t, float planeta[]){
    float altura= velocidad* t* sin(calcular_radianes(angulo))- (planeta[]*t*t)/2;
    return altura;
}
float calcular_alcance(float velocidad, float angulo, float t){
    float alcance = velocidad*cos(calcular_radianes(angulo))*t;
    return alcance;
}
float calcular_tiempo(float velocidad, float angulo, float planeta[]){
    float tiempo= 2*velocidad*sin(calcular_radianes(angulo))/(2*planeta[]);
    return tiempo;
}
void juego(){
    float planeta[8]= {TIERRA, LUNA, MERCURIO, MARTE, URANO, VENUS, SATURNO, NEPTUNO, JUPITER};
    char *nombre[8]={"TIERRA", "LUNA", "MERCURIO", "MARTE", "URANO", "VENUS", "SATURNO", "NEPTUNO", "JUPITER"};
    for(int i = 0; i < 8; i++){
        printf("Nivel %d\n", i+1);
        printf("Te encuentras en %s\n Su gravedad es: %d\n", planeta[i], nombre[i]);
        if (i + 1 == 1){
            printf("Un jugador patea un balon ")
        }

    }
    }