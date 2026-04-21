#include <stdio.h>
#include <math.h>
#define PI 3.1416
//probar con la funcion  M_PI
int main(){
    int eleccion;
    do{
        printf("Bienvenido a lanzamiento de proyectil con gravedad variable\n");
        printf("Seleccione una opcion\n");
        printf("1-Jugar\n");
        printf("2- Intrucciones\n");
        printf("3-Salir del juego\n");
        scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
            printf("Iniciando juego...\n");
            break;
            case 2:
            printf("Intrucciones:\n");
            printf("Hay que ajustar la gravedad, velocidad y angulo de lanzamiento\n");
            printf("El numero PI esta aproximado a 3.1416\n");
            break;
            case 3:
            printf("Saliendo del juego...");
            break;
            default:
            printf("Opcion invalida\n");
            }
    }while(eleccion!=3);
    return 0;
}
