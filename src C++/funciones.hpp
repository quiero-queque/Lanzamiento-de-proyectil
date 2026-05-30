#include <iostream>
#include <vector>
#include <string>
#include <cmath>
class PLANETAS{
    private:
    std::string nombre;
    float gravedad;
    public:
    PLANETAS(std::string n, float g);
    std::string getnombre();
    float getgravedad();
};
//los angulos se reciben en grados y se cambian a radianes
float calcular_radianes(float angulo);
//funciones fisicas
float calcular_altura(float velocidad, float angulo, float t, float g);
float calcular_alturamax(float velocidad, float angulo, float g);
float calcular_alcance(float velocidad, float angulo, float t);
float calcular_tiempo(float velocidad, float angulo, float g);
float calcular_alcancemax(float velocidad, float angulo, float g);

//juego con preguntas
void iniciar_juego();
//pruebas donde seleccionamos los planetas
void modolibre();
//solucion bug
float limpiarbuffer(std::string instruccion);
//para despejar el main
void instrucciones();