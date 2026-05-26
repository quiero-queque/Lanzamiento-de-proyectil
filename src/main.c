#include "funciones.hpp"
#include <stdlib.h>
/*int main(){
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
}*/

int main() {
    ResolverProblemas p1(an1, v1, 0, 9.81);
    float p_t = p1.calcular_tiempo(); // primero se calcula el tiempo y en base a eso lo demas se resuelve

    ResolverProblemas p2(an1, v1, p_t, 9.81);
    float pdos = p2.calcular_alturamax(); //probamos esta funcion solo en modo de prueba

    std::cout << GenerarProblema() << "\n";
    std::cout << pdos << " es la altura máxima\n";
  return 0; 
}