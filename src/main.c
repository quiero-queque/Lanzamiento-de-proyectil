#include "funciones.h"
#include <stdlib.h>
int main(){
    char eleccion;
    do{
        system("clear");
        printf("Bienvenido a lanzamiento de proyectil con gravedad variable\n");
        printf("Seleccione una opcion\n");
        printf("1-Jugar\n");
        printf("2-Intrucciones\n");
        printf("3-Salir del juego\n");
        scanf("%c", &eleccion);
        switch(eleccion){
                case '1':
                system("clear");
                printf("Iniciando juego...\n");
                iniciar_juego();
                break;
                case '2':
                system("clear");
                instrucciones(eleccion);
                break;
                case '3':
                system("clear");
                printf("Saliendo del juego...\n");
                break;
                default:
                system("clear");
                printf("Opcion invalida\n");
                break;
            }
    }while(eleccion != '3');
    return 0;
}

