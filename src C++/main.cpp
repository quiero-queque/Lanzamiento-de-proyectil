#include "funciones.hpp"
#include <stdlib.h>
int main(){
    char eleccion;
    do{
        system("clear");
        std::cout<<"Bienvenido a lanzamiento de proyectil con gravedad variable\n";
        std::cout<<"Seleccione una opcion\n";
        std::cout<<"1-Jugar\n";
        std::cout<<"2-Modo libre\n";
        std::cout<<"3-Intrucciones\n";
        std::cout<<"4-Salir del juego\n";
        std::cin>>eleccion;
        switch(eleccion){
                case '1':
                system("clear");
                std::cout<<"Iniciando juego...\n";
                system("clear");
                std::cout<<"Â¿Cuantas preguntas quieres hacer?\n";
                int Preguntas;
                std::cin>>Preguntas;
                system("clear");
                iniciar_juego(Preguntas);
                break;
                case '2':
                std::cout<<"Entrando a modo libre\n";
                modolibre();
                break;
                case '3':
                system("clear");
                system("clear");
                instrucciones();
                break;
                case '4':
                system("clear");
                std::cout<<"Saliendo del juego...\n";
                break;
                default:
                system("clear");
                std::cout<<"Opcion invalida\n";
                break;
            }
    }while(eleccion != '4');
    return 0;
}