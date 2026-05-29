#include "funciones.hpp" 
#include <iostream>

//USO DE IA PARA GENERAR NUMEROS ALEATORIOS
//--------------------------------------------------------------------------------------------
    float generar_random_angulo(float min, float max) {
    std::random_device rd;  //semilla para que numeros sean aleatorios
    std::mt19937 gen(rd()); // motor de generacion eficiente
    std::uniform_real_distribution<> dist(min, max); // define valor minimo y maximo
    return dist(gen); // devuelve un valor entre min y max
    }
    float generar_random_velocidad(float min, float max) {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
    }
//------------------------------------------------------------------------------------------
    float v1=generar_random_velocidad(1.00, 200.00); //Definimos limites de acuerdo a la logica fisica
    float an1=generar_random_angulo(1, 89);

std::string GenerarProblema(int n){ 
    std::string Planeta = "Tierra"; //de modo de prueba solo tenemos asignado el planeta tierra
    float Gravedad = 9.81;
    std::string problema = "\n Bitácora Estelar - Nivel " + std::to_string(n) + " \nEn el Planeta " + Planeta +
                " con gravedad " + std::to_string(Gravedad) +
                " se lanza un proyectil a " + std::to_string(v1) +
                " m/s a un ángulo de " + std::to_string(an1) + "°\n¿Cuál es la altura máxima que alcanza?";
    return problema;                   
}
//esta funcion permite que el juego se ejecute, lo hacemos de esta forma para que el main quede mas limpio
void iniciar_juego(int o){ 
    for(int i = 1; i <= o; i++){
     // float planeta[9]= {TIERRA, LUNA, MERCURIO, MARTE, URANO, VENUS, SATURNO, NEPTUNO, JUPITER};
     // char *nombre[9]={"TIERRA", "LUNA", "MERCURIO", "MARTE", "URANO", "VENUS", "SATURNO", "NEPTUNO", "JUPITER"};
        float v1=generar_random_velocidad(1.00, 200.00); //Definimos limites de acuerdo a la logica fisica
        float an1=generar_random_angulo(1, 89);
        float Resultado;
        ResolverProblemas p1(an1, v1, 0, 9.81);
        float tiempo = p1.calcular_tiempo(); // primero se calcula el tiempo y en base a eso lo demas se resuelve
        ResolverProblemas p2(an1, v1, tiempo, 9.81);
        float altura_max = p2.calcular_alturamax(); //probamos esta funcion solo en modo de prueba
        float alcance_t = p2.calcular_alcance();
        std::cout << GenerarProblema(i) << "\n";
        std::cout << altura_max << " es la altura máxima\n";
        std::cin >> Resultado;
        if((Resultado > (altura_max - 1)) && (Resultado < (altura_max + 1))){ //De momento se establece rango de respuesta valida
            std::cout << "Respuesta correcta\n";
            system("clear");
        } else{
            std::cout << "Respuesta incorrecta (Presione enter para continuar)";
        }
    }
}
void instrucciones(){
    std::cout << "Intrucciones:\n";
    std::cout << "Hay que ajustar la gravedad, velocidad y angulo de lanzamiento\n";
    std::cout << "El numero PI esta aproximado a 3.1416\n";
    std::cout << "Selecciona cualquier tecla para volver \n";
    std::string eleccion;
    std::cin >> eleccion;
}
 void modolibre(){
        float velocidad;
        char condicion;
        float angulo;
        float planetas[9]= {TIERRA, VENUS, MERCURIO, MARTE, JUPITER, SATURNO, URANO, NEPTUNO, LUNA};
        int n;
        do{
            std::cout<<"\nBienvenido al modo libre\nIngrese ángulo en decimales\n";
            std::cin >> angulo;
            std::cout<<"Ingrese velocidad en decimales\n";
            std::cin >> velocidad;
            std::cout << "Elige un planeta:\n1-TIERRA\n2-VENUS\n3-MERCURIO\n4-MARTE\n5-JUPITER\n6-SATURNO\n7-URANO\n8-NEPTUNO\n9-LUNA\n";
            std::cin >> n;
            ResolverProblemas p3(angulo, velocidad,0,planetas[n-1]);
            float tiempo = p3.calcular_tiempo();
            float altura_max = p3.calcular_alturamax();
            float alcance_t = p3.calcular_alcancemax();
                std::cout<<"El tiempo de caida fue: "<<tiempo<<"\n";
                std::cout<<"la distancia recorrida fue de: "<< alcance_t<<"\n";
                std::cout<<"Su altura maxima fue: "<< altura_max<<"\n";
                std::cout<<"Quieres continuar?\n1-si\n2-no\n";
            scanf(" %c", &condicion);
        }while(condicion!='2');
    }
