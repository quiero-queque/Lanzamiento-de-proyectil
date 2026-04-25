#include "funciones.h"
const float PI= 3.1416;
const float TIERRA= 9.81;
const float VENUS= 8.87;
const float MERCURIO= 3.70;
const float MARTE = 3.71;
const float JUPITER = 24.79;
const float SATURNO =10.44;
const float URANO= 8.69;
const float NEPTUNO =11.15;
const float LUNA = 1.62;
float calcular_radianes(float angulo){
    float radianes= (angulo*PI)/180;
    return radianes;
}
//esta funcion permite cambiar los angulos a radianes
float calcular_altura(float velocidad, float angulo, float t, float g){
    float altura= velocidad* t* sin(calcular_radianes(angulo))- (g*t*t)/2;
    return altura;
}
//esta funcion permite calcular la altura en un instante de tiempo
float calcular_alturamax(float velocidad, float angulo, float g){
    float alturamax= (velocidad*velocidad)*(sin(calcular_radianes(angulo))*sin(calcular_radianes(angulo))/(2*g));
    return alturamax;
}
//esta funcion permite calcular la altura maxima agarrada por el proyectil
float calcular_alcance(float velocidad, float angulo, float t){
    float alcance = velocidad*cos(calcular_radianes(angulo))*t;
    return alcance;
}
//esta funcion calcula la distancia horizontal en un instante de tiempo
float calcular_tiempo(float velocidad, float angulo, float g){
    float tiempo= 2*velocidad*sin(calcular_radianes(angulo))/(g);
    return tiempo;
}
//esta funcion calcula el tiempo que tarda el proyectil en chocar con el suelo
float calcular_alcancemax(float velocidad, float angulo, float g) {
    float alcancemax= (velocidad * velocidad * sin(2 * calcular_radianes(angulo))) / g;
    return alcancemax;
}
//esta funcion permite calcular la distancia horizontal cuando choca con el suelo, no depende del tiempo

//esta funcion permite que el juego se ejecute, lo hacemos de esta forma para que el main quede mas limpio
void iniciar_juego(){
    float planeta[9]= {TIERRA, LUNA, MERCURIO, MARTE, URANO, VENUS, SATURNO, NEPTUNO, JUPITER};
    char *nombre[9]={"TIERRA", "LUNA", "MERCURIO", "MARTE", "URANO", "VENUS", "SATURNO", "NEPTUNO", "JUPITER"};
    for(int i = 1; i <= 9; i++){
        float resultado;
        printf("Nivel %d\n", i);
        printf("Te encuentras en %s\n Su gravedad es: %.2f\n", nombre[i-1], planeta[i-1]);
        if (i== 1){
            printf("Bitácora Estelar - Nivel 1: Tierra. Calibración inicial del sistema. Lanzamos una sonda de prueba a 15 m/s con un ángulo de 30º. Calcule la distancia recorrida horizontalmente (alcance máximo):\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_alcancemax(15, 30, planeta[i-1])) < 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 2){
            printf("Bitácora Estelar - Nivel 2: Luna. Entorno de baja gravedad. Un rover expulsa una muestra de roca a 10 m/s con un ángulo de 45º. Calcule el tiempo que le toma tocar el suelo:\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_tiempo(10, 45, planeta[i-1]))< 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 3){
            printf("Bitácora Estelar - Nivel 3: Mercurio. Proximidad solar crítica. Un géiser expulsa minerales a 20 m/s con un angulo 60º. Calcule la altura máxima que alcanzan los fragmentos:\n");
            if (fabs(resultado - calcular_alturamax(20, 60, planeta[i-1]))< 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 4){
            printf("Bitácora Estelar - Nivel 4: Marte. Navegando en tormentas de arena. Disparamos una bengala a 25 m/s con un ángulo de 40º. Calcule su alcance exacto a los 2 segundos de vuelo:\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_alcance(25, 40, 2))< 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 5){
            printf("Bitácora Estelar - Nivel 5: Urano. Explorando el gigante de hielo. Un dron atmosférico es impulsado a 30 m/s con un angulo de 50º. ¿A qué altura se encontrará exactamente a los 3 segundos de su lanzamiento?\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_altura(30, 50, 3, planeta[i-1]))< 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 6){
            printf("Bitácora Estelar - Nivel 6: Venus. Presión extrema. Lanzamos un sensor a 50 m/s y 60º. Calcule la ALTURA del sensor en el instante exacto que corresponde a la MITAD de su tiempo total de vuelo:\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_altura(50, 60, calcular_tiempo(50, 60, planeta[i-1]) / 2.0, planeta[i-1])) < 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 7){
            printf("Bitácora Estelar - Nivel 7: Saturno. Evasión de anillos. Un dron es expulsado a 70 m/s con un ángulo de 45º. Calcule su ALCANCE HORIZONTAL evaluado exactamente utilizando su TIEMPO TOTAL de vuelo:\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_alcance(70, 45, calcular_tiempo(70, 45, planeta[i-1]))) < 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 8){
            printf("Bitácora Estelar - Nivel 8: Neptuno. Tormentas supersónicas. Un misil se lanza a 90 m/s con un angulo de inclinacion de 70º. Calcule la ALTURA del misil exactamente 2 segundos ANTES de que alcance su tiempo total de vuelo:\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_altura(90, 70, calcular_tiempo(90, 70, planeta[i-1])-2, planeta[i-1])) < 0.08){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }else if(i== 9){
            printf("Bitácora Estelar - Nivel 9: Júpiter. El coloso gravitatorio. Un módulo se lanza a 150 m/s con un angulo de inclinacion de 80º. Calcule el ALCANCE HORIZONTAL en el momento exacto en que el módulo alcanza su ALTURA MÁXIMA (es decir, a la mitad de su tiempo total de vuelo):\n");
            scanf("%f", &resultado);
            if (fabs(resultado - calcular_alcance(150, 80, calcular_tiempo(150, 80, planeta[i-1]) / 2.0)) < 0.05){
                printf("Felicidades!!\n");
            } else{
                printf("Te has equivocado, intentalo de nuevo\n");
                i= i-1;
            }
        }
    }
    return;
}
