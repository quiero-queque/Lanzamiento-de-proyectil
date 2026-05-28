#include <iostream>
#include <stdio.h>
#include <stdlib.h> // para acceder a la funcion system()
#include <cmath> // para redondear los decimales
#include <random> // para generar los valores aleatorios a distintos problemas
#include <vector>
#include <string>


#define PI 3.1416
#define TIERRA 9.81
#define VENUS 8.87
#define MERCURIO 3.70
#define MARTE 3.71
#define JUPITER 24.79
#define SATURNO 10.44
#define URANO 8.69
#define NEPTUNO 11.15
#define LUNA 1.62
//los angulos se reciben en grados y se cambian a radianes
float calcular_alcance(float velocidad, float angulo, float t);
float calcular_altura(float velocidad, float angulo, float t, float g);
float calcular_tiempo(float velocidad, float angulo, float g);
float calcular_radianes(float Angulo);
float calcular_alturamax(float velocidad, float angulo, float g);
void instrucciones();
void iniciar_juego(int o);
std::string GenerarProblema(int n);

class jugador{
    private:
    std::string nombre;
    int puntaje;

    public:
    jugador(std::string nombre){
        this->nombre = nombre;
        this->puntaje = 0;
    }

    int subir_puntaje(){
        puntaje+=1;
        return puntaje;
    }
    void Mostrar_nombre(){
        std::cout<<"\n Nombre de usuario: "<<nombre;
    }
    
};

class ResolverProblemas{
    private:
    float angulo;
    float velocidad;
    float t;
    float g;

    public:
    ResolverProblemas(float angulo, float velocidad, float t, float g){
        this->angulo = angulo;
        this->velocidad = velocidad;
        this->t=t;
        this->g=g;
    }

    float calcular_radianes(){
        float radianes= (angulo*PI)/180;
        return radianes;
    }
    //esta funcion permite cambiar los angulos a radianes
    float calcular_altura(){
        float altura= velocidad* sin(calcular_radianes())*t- (g*t*t)/2;
        return altura;
    }
    //esta funcion permite calcular la altura en un instante de tiempo
    float calcular_alturamax(){
        float alturamax= (((velocidad*velocidad)*(sin(calcular_radianes())*sin(calcular_radianes())))/(2*g));
        return alturamax;
    }
    //esta funcion permite calcular la altura maxima agarrada por el proyectil
    float calcular_alcance(){
        float alcance = velocidad*cos(calcular_radianes())*t;
        return alcance;
    }
    //esta funcion calcula la distancia horizontal en un instante de tiempo
    float calcular_tiempo(){
       float tiempo= 2*velocidad*sin(calcular_radianes())/(g);
       return tiempo;
    }
    //esta funcion calcula el tiempo que tarda el proyectil en chocar con el suelo
    float calcular_alcancemax() {
        float alcancemax= (velocidad * velocidad * sin(2 * calcular_radianes())) / g;
        return alcancemax;
    }
};