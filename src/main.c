#include "funciones.h"
//probar con la funcion  M_PI(los include son locales de cada archivo)
int main(){
    char eleccion;
    do{
        printf("Bienvenido a lanzamiento de proyectil con gravedad variable\n");
        printf("Seleccione una opcion\n");
        printf("1-Intrucciones\n");
        printf("2-Jugar\n");
        printf("3-Modo libre\n");
        printf("4-Salir del juego\n");
        scanf(" %c", &eleccion);
        switch(eleccion){
            case '1':
            printf("Intrucciones:\n");
            printf("Hay que ajustar la gravedad, velocidad y angulo de lanzamiento\n");
            printf("El numero PI esta aproximado a 3.1416\n");
            break;
            case '2':
            printf("Iniciando juego...\n");
            iniciar_juego();
            break;
            case '3':
            printf("Entrando a modo libre");
            modolibre();
            break;
            case '4':
            printf("Saliendo del juego...");
            break;
            default:
            printf("Opcion invalida\n");
            }
    }while(eleccion!='4');
    return 0;
}
