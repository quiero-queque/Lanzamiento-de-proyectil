#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <QPointF>

class PLANETAS {
private:
    std::string nombre;
    float gravedad;
public:
    PLANETAS(std::string n, float g);
    std::string getnombre() const;
    float getgravedad() const;
};

extern PLANETAS lista_planeta[9];

float calcular_radianes   (float angulo);
float calcular_altura     (float velocidad, float angulo, float t, float g);
float calcular_alturamax  (float velocidad, float angulo, float g);
float calcular_alcance    (float velocidad, float angulo, float t);
float calcular_tiempo     (float velocidad, float angulo, float g);
float calcular_alcancemax (float velocidad, float angulo, float g);

// genera los puntos de la trayectoria para graficar
std::vector<QPointF> calcular_trayectoria(float velocidad, float angulo, float g);

struct DatosNivel {
    float velocidad;
    float angulo;
    int planeta;
    float esperado;
    std::string enunciado;
};

DatosNivel obtener_nivel(int i);
