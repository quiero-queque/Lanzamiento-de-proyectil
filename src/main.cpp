#include "funciones.hpp"
#include <stdlib.h>
int main(){
    char eleccion;
    do{
        system("clear");
        std::cout<<"Bienvenido a lanzamiento de proyectil con gravedad variable\n";
        std::cout<<"Seleccione una opcion\n";
        std::cout<<"1-Jugar\n";
        std::cout<<"2-Intrucciones\n";
        std::cout<<"3-Salir del juego\n";
        std::cin>>eleccion;
        switch(eleccion){
                case '1':
                system("clear");
                std::cout<<"Iniciando juego...\n";
                system("clear");
                std::cout<<"¿Cuantas preguntas quieres hacer?\n";
                int Preguntas;
                std::cin>>Preguntas;
                system("clear");
                iniciar_juego(Preguntas);
                break;
                case '2':
                system("clear");
                instrucciones();
                break;
                case '3':
                system("clear");
                std::cout<<"Saliendo del juego...\n";
                break;
                default:
                system("clear");
                std::cout<<"Opcion invalida\n";
                break;
            }
    }while(eleccion != '3');
    return 0;
}

/*int main() {
    ResolverProblemas p1(an1, v1, 0, 9.81);
    float p_t = p1.calcular_tiempo(); // primero se calcula el tiempo y en base a eso lo demas se resuelve

    ResolverProblemas p2(an1, v1, p_t, 9.81);
    float pdos = p2.calcular_alturamax(); //probamos esta funcion solo en modo de prueba

    std::cout << GenerarProblema() << "\n";
    std::cout << pdos << " es la altura máxima\n";
  return 0; 
}*/