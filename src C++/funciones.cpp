#include "funciones.hpp"
const float PI = 3.1416;
//funciones matematicas
float calcular_radianes(float angulo){ //los angulos se reciben en grados y se cambian a radianes
    float radianes= (angulo*PI)/180;
    return radianes;
}
float calcular_altura(float velocidad, float angulo, float t, float g){ //calcula la altura en un punto t
    float altura= velocidad* t* sin(calcular_radianes(angulo))- (g*t*t)/2;
    return altura;
}
float calcular_alturamax(float velocidad, float angulo, float g){ //calcula la altura maxima
    float alturamax= (velocidad*velocidad)*(sin(calcular_radianes(angulo))*sin(calcular_radianes(angulo))/(2*g));
    return alturamax;
}
float calcular_alcance(float velocidad, float angulo, float t){ //calcula alcance usando el tiempo
    float alcance = velocidad*cos(calcular_radianes(angulo))*t;
    return alcance;
}
float calcular_tiempo(float velocidad, float angulo, float g){ //calcula el tiempo
    float tiempo= 2*velocidad*sin(calcular_radianes(angulo))/(g);
    return tiempo;
}
float calcular_alcancemax(float velocidad, float angulo, float g){ //calcula el alcance sin el tiempo
    float alcancemax= (velocidad * velocidad * sin(2 * calcular_radianes(angulo))) / g;
    return alcancemax;
}
//arreglar bug
float limpiarbuffer(std::string instruccion){
    float valor;
    while (true){
        std::cout << instruccion;
        if (std::cin >> valor) {
            return valor;
        }
        std::cout << "Formato invalido\n";
        std::cin.clear();
        while (std::getchar() != '\n');
    }
}
//poner gravedades
PLANETAS::PLANETAS(std::string nom, float grav){
    nombre = nom;
    gravedad = grav;
}
std::string PLANETAS::getnombre(){
    return nombre;
}
float PLANETAS::getgravedad(){
    return gravedad;
}
PLANETAS lista_planeta[9]={
    PLANETAS("TIERRA", 9.81),
    PLANETAS("LUNA", 1.62),
    PLANETAS("MERCURIO", 3.70),
    PLANETAS("MARTE", 3.71),
    PLANETAS("URANO", 8.69),
    PLANETAS("VENUS", 8.87),
    PLANETAS("SATURNO", 10.44),
    PLANETAS("NEPTUNO", 11.15),
    PLANETAS("JUPITER", 24.79)
};
void instrucciones(){
    std::cout << "Intrucciones:\n";
    std::cout << "Hay que ajustar la gravedad, velocidad y angulo de lanzamiento\n";
    std::cout << "El numero PI esta aproximado a 3.1416\n";
    std::cout << "Selecciona cualquier tecla para volver \n";
    std::string eleccion;
    std::cin >> eleccion;
}
void iniciar_juego(){ //inicia el juego
    for(int i = 0; i < 9; i++){
        float g = lista_planeta[i].getgravedad();
        std::cout << "Nivel " << i+1 << "\n";
        std::cout << "Te encuentras en " << lista_planeta[i].getnombre() << "  Su gravedad es: " << g << "\n";
        float resultado;
        float esperado;
        if(i == 0){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 1: Tierra. Calibracion inicial del sistema. Lanzamos una sonda de prueba a 15 m/s con un angulo de 30. Calcule la distancia recorrida horizontalmente (alcance maximo):\n");
            esperado = calcular_alcancemax(15, 30, g);
        }else if(i == 1){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 2: Luna. Entorno de baja gravedad. Un rover expulsa una muestra de roca a 10 m/s con un angulo de 45. Calcule el tiempo que le toma tocar el suelo:\n");
            esperado = calcular_tiempo(10, 45, g);
        }else if(i == 2){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 3: Mercurio. Proximidad solar critica. Un geiser expulsa minerales a 20 m/s con angulo 60. Calcule la altura maxima que alcanzan los fragmentos:\n");
            esperado = calcular_alturamax(20, 60, g);
        }else if(i == 3){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 4: Marte. Navegando en tormentas de arena. Disparamos una bengala a 25 m/s con un angulo de 40. Calcule su alcance exacto a los 2 segundos de vuelo:\n");
            esperado = calcular_alcance(25, 40, 2);
        }else if(i == 4){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 5: Urano. Explorando el gigante de hielo. Un dron es impulsado a 30 m/s con angulo 50. A que altura se encontrara exactamente a los 3 segundos?\n");
            esperado = calcular_altura(30, 50, 3, g);
        }else if(i == 5){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 6: Venus. Presion extrema. Lanzamos un sensor a 50 m/s y 60. Calcule la ALTURA en el instante exacto de la MITAD de su tiempo total de vuelo:\n");
            esperado = calcular_altura(50, 60, calcular_tiempo(50, 60, g)/2.0, g);
        }else if(i == 6){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 7: Saturno. Evasion de anillos. Un dron es expulsado a 70 m/s con angulo 45. Calcule su ALCANCE HORIZONTAL evaluado con su TIEMPO TOTAL de vuelo:\n");
            esperado = calcular_alcance(70, 45, calcular_tiempo(70, 45, g));
        }else if(i == 7){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 8: Neptuno. Tormentas supersonicas. Un misil se lanza a 90 m/s con angulo 70. Calcule la ALTURA exactamente 2 segundos ANTES del tiempo total de vuelo:\n");
            esperado = calcular_altura(90, 70, calcular_tiempo(90, 70, g)-2, g);
        }else if(i==8){
            resultado = limpiarbuffer("Bitacora Estelar - Nivel 9: Jupiter. El coloso gravitatorio. Un modulo se lanza a 150 m/s con angulo 80. Calcule el ALCANCE HORIZONTAL en el momento de su ALTURA MAXIMA:\n");
            esperado = calcular_alcance(150, 80, calcular_tiempo(150, 80, g)/2.0);
        }
        if(fabs(resultado - esperado) < 0.05){
            std::cout << "Felicidades!!\n";
        }else{
            std::cout << "Te has equivocado, intentalo de nuevo\n";
            i--;
        }
    }
}
void modolibre(){ //abre un modo donde se puede probar distintas gravedades y movimientos parabolicos
    char condicion;
    do{
        float angulo = limpiarbuffer("Bienvenido al modo libre, ingrese angulo en decimales:\n");
        if(angulo >= 0 && angulo <= 180){
            float velocidad = limpiarbuffer("Ingrese una velocidad:\n");
            std::cout << "Elige un planeta:\n";
            for(int i = 0; i < 9; i++){
                std::cout << i+1 << "-" << lista_planeta[i].getnombre() << "\n";
            }
            int n;
            std::cin >> n;
            std::cin.ignore();
            if(n >= 1 && n <= 9){
                float g = lista_planeta[n-1].getgravedad();
                std::cout << "El tiempo de caida fue: " << calcular_tiempo(velocidad, angulo, g) << "\n";
                std::cout << "La distancia recorrida fue de: " << calcular_alcancemax(velocidad, angulo, g) << "\n";
                std::cout << "Su altura maxima fue: " << calcular_alturamax(velocidad, angulo, g) << "\n";
            }else{
                std::cout << "Planeta no valido\n";
            }
        }else{
            std::cout << "Angulo no valido, ingrese uno entre 0 y 180\n";
        }
        std::cout << "Quieres continuar? 1-si\n2-no\n";
        std::cin >> condicion;
    }while(condicion != '2');
}