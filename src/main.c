#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
//probar con la funcion  M_PI
int main(){
    
    char eleccion;
    do{
        system("clear");
        printf("Bienvenido a lanzamiento de proyectil con gravedad variable\n");
        printf("Seleccione una opcion\n");
        printf("1-Jugar\n");
        printf("2- Intrucciones\n");
        printf("3-Salir del juego\n");
        scanf(" %c", &eleccion);
        switch(eleccion){
            case '1':
            system("clear");
            printf("Iniciando juego...\n");

            double velocidad, angulo, gravedad;
            printf("Ingrese velocidad inicial (m/s): ");
            scanf("%lf", &velocidad);

            printf("Ingrese el angulo de lanzamiento (grados): ");
            scanf("%lf", &angulo);

            printf("Ingrese gravedad (ej: Tierra=9.81, Luna=1.62): ");
            scanf("%lf", &gravedad);



            //aca tenemos que calcular con las formulas
            break;
            case '2':
            system("clear");
            printf("Intrucciones:\n");
            printf("Hay que ajustar la gravedad, velocidad y angulo de lanzamiento\n");
            printf("El numero PI esta aproximado a 3.1416\n");
            break;
            case '3':
            system("clear");
            printf("Saliendo del juego...");
            break;
            default:
            printf("Opcion invalida\n");
            break;
            }
    }while(eleccion!=3);
    return 0;
}