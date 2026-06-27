#include "funciones.hpp"

const float PI = 3.1416f;

PLANETAS::PLANETAS(std::string nom, float grav) : nombre(nom), gravedad(grav) {}

std::string PLANETAS::getnombre() const  { return nombre;   }
float       PLANETAS::getgravedad() const { return gravedad; }

PLANETAS lista_planeta[9] = {
    PLANETAS("TIERRA",   9.81f),
    PLANETAS("LUNA",     1.62f),
    PLANETAS("MERCURIO", 3.70f),
    PLANETAS("MARTE",    3.72f),
    PLANETAS("URANO",    8.69f),
    PLANETAS("VENUS",    8.87f),
    PLANETAS("SATURNO", 10.44f),
    PLANETAS("NEPTUNO", 11.15f),
    PLANETAS("JUPITER", 24.79f)
};

float calcular_radianes(float angulo) {
    return (angulo * PI) / 180.0f;
}

float calcular_altura(float velocidad, float angulo, float t, float g) {
    return velocidad * t * sin(calcular_radianes(angulo)) - (g * t * t) / 2.0f;
}

float calcular_alturamax(float velocidad, float angulo, float g) {
    float s = sin(calcular_radianes(angulo));
    return (velocidad * velocidad * s * s) / (2.0f * g);
}

float calcular_alcance(float velocidad, float angulo, float t) {
    return velocidad * cos(calcular_radianes(angulo)) * t;
}

float calcular_tiempo(float velocidad, float angulo, float g) {
    return 2.0f * velocidad * sin(calcular_radianes(angulo)) / g;
}

float calcular_alcancemax(float velocidad, float angulo, float g) {
    return (velocidad * velocidad * sin(2.0f * calcular_radianes(angulo))) / g;
}

std::vector<QPointF> calcular_trayectoria(float velocidad, float angulo, float g) {
    std::vector<QPointF> puntos;
    float T = calcular_tiempo(velocidad, angulo, g);
    const int pasos = 120;
    for (int i = 0; i <= pasos; i++) {
        float t = T * static_cast<float>(i) / static_cast<float>(pasos);
        float x = calcular_alcance(velocidad, angulo, t);
        float y = calcular_altura(velocidad, angulo, t, g);
        if (y < 0.0f) y = 0.0f;
        puntos.emplace_back(x, y);
    }
    return puntos;
}

DatosNivel obtener_nivel(int i) {
    DatosNivel d;
    float g = lista_planeta[i].getgravedad();
    d.planeta = i;

    switch (i) {
    case 0:
        d.velocidad = 15; d.angulo = 30;
        d.esperado  = calcular_alcancemax(15, 30, g);
        d.enunciado = "Tierra - Lanzamos una sonda a 15 m/s con angulo 30.\n"
                      "Calcula la distancia horizontal maxima (alcance maximo).";
        break;
    case 1:
        d.velocidad = 10; d.angulo = 45;
        d.esperado  = calcular_tiempo(10, 45, g);
        d.enunciado = "Luna - Un rover expulsa una roca a 10 m/s con angulo 45.\n"
                      "Calcula el tiempo total de vuelo (en segundos).";
        break;
    case 2:
        d.velocidad = 20; d.angulo = 60;
        d.esperado  = calcular_alturamax(20, 60, g);
        d.enunciado = "Mercurio - Un geiser lanza minerales a 20 m/s con angulo 60.\n"
                      "Calcula la altura maxima alcanzada.";
        break;
    case 3:
        d.velocidad = 25; d.angulo = 40;
        d.esperado  = calcular_alcance(25, 40, 2.0f);
        d.enunciado = "Marte - Disparamos una bengala a 25 m/s con angulo 40.\n"
                      "Calcula el alcance horizontal exactamente a los 2 segundos.";
        break;
    case 4:
        d.velocidad = 30; d.angulo = 50;
        d.esperado  = calcular_altura(30, 50, 3.0f, g);
        d.enunciado = "Urano - Un dron a 30 m/s con angulo 50.\n"
                      "Calcula la altura a exactamente 3 segundos de vuelo.";
        break;
    case 5:
        d.velocidad = 50; d.angulo = 60;
        d.esperado  = calcular_altura(50, 60, calcular_tiempo(50, 60, g) / 2.0f, g);
        d.enunciado = "Venus - Sensor a 50 m/s con angulo 60.\n"
                      "Calcula la altura en la mitad exacta del tiempo de vuelo.";
        break;
    case 6:
        d.velocidad = 70; d.angulo = 45;
        d.esperado  = calcular_alcance(70, 45, calcular_tiempo(70, 45, g));
        d.enunciado = "Saturno - Dron a 70 m/s con angulo 45.\n"
                      "Calcula el alcance horizontal usando el tiempo total de vuelo.";
        break;
    case 7:
        d.velocidad = 90; d.angulo = 70;
        d.esperado  = calcular_altura(90, 70, calcular_tiempo(90, 70, g) - 2.0f, g);
        d.enunciado = "Neptuno - Misil a 90 m/s con angulo 70.\n"
                      "Calcula la altura exactamente 2 segundos antes del aterrizaje.";
        break;
    case 8:
        d.velocidad = 150; d.angulo = 80;
        d.esperado  = calcular_alcance(150, 80, calcular_tiempo(150, 80, g) / 2.0f);
        d.enunciado = "Jupiter - Modulo a 150 m/s con angulo 80.\n"
                      "Calcula el alcance horizontal en el momento de altura maxima.";
        break;
    default:
        d.velocidad = 0; d.angulo = 0; d.esperado = 0;
        break;
    }
    return d;
}
