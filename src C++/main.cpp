#include "funciones.hpp"
#include <stdlib.h>
int main(){
    char eleccion;
    do{
        std::cout<<"Bienvenido a lanzamiento de proyectil con gravedad variable\n";
        std::cout<<"Seleccione una opcion\n";
        std::cout<<"1-Jugar\n";
        std::cout<<"2-Modo libre\n";
        std::cout<<"3-Intrucciones\n";
        std::cout<<"4-Salir del juego\n";
        std::cin>>eleccion;
        switch(eleccion){
                case '1':
                iniciar_juego();
                break;
                case '2':
                std::cout<<"Entrando a modo libre\n";
                modolibre();
                break;
                case '3':
                instrucciones();
                break;
                case '4':
                std::cout<<"Saliendo del juego...\n";
                break;
                default:
                std::cout<<"Opcion invalida\n";
                break;
            }
    }while(eleccion != '4');
    return 0;
}
