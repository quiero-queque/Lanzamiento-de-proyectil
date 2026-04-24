#include "funciones.h"
float calcular_radianes(float angulo){
    float radianes= (angulo*PI)/180;
    return radianes;
}
float calcular_altura(float velocidad, float angulo, float t, float g){
    float altura= velocidad* t* sin(calcular_radianes(angulo))- (g*t*t)/2;
    return altura;
}
float calcular_alturamax(float velocidad, float angulo, float g){
    float alturamax= (velocidad*velocidad)*(sin(calcular_radianes(angulo))*sin(calcular_radianes(angulo))/(2*g));
    return alturamax;
}
float calcular_alcance(float velocidad, float angulo, float t){
    float alcance = velocidad*cos(calcular_radianes(angulo))*t;
    return alcance;
}
float calcular_tiempo(float velocidad, float angulo, float g){
    float tiempo= 2*velocidad*sin(calcular_radianes(angulo))/(2*g);
    return tiempo;
}
float calcular_alcancemax(float velocidad, float angulo, float g) {
    return (velocidad * velocidad * sin(2 * calcular_radianes(angulo))) / g;
}
void juego(){
    float planeta[9]= {TIERRA, LUNA, MERCURIO, MARTE, URANO, VENUS, SATURNO, NEPTUNO, JUPITER};
    char *nombre[9]={"TIERRA", "LUNA", "MERCURIO", "MARTE", "URANO", "VENUS", "SATURNO", "NEPTUNO", "JUPITER"};
    for(int i = 1; i <= 9; i++){
        float resultado;
        printf("Nivel %d\n", i);
        printf("Te encuentras en %s\n Su gravedad es: %.2f\n", nombre[i-1], planeta[i-1]);
        if (i== 1){
            printf("Un jugador patea un balon a  15 m/s con un angulo de lanzamiento de 30°, de cuanto es su alcance?\n");
            scanf("%f", &resultado);
            if (resultado == calcular_alcancemax(15, 30, planeta[i-1])){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 2){
            printf("Un rover expulsa una muestra de roca con una velocidad inicial de 10 m/s con un angulo de lanzamiento de 45°\n");
            scanf("%f", &resultado);
            if (resultado == calcular_tiempo(10, 45, planeta[i-1])){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }
    }
