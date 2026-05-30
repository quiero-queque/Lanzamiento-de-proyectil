#  Simulador de Lanzamiento Parabólico
---

##  Problematica a Solucionar

Está demostrado que cada persona tiene una forma de aprender distinta los casos fisicos, por lo que se debe crear y aplicar un videojuego con distintas funciones, en donde se busca que el usuario aprenda conceptos fisicos.

---

##  Objetivo General

Desarrollar un simulador en C++ orientado a fines educativos con objetos que modele el lanzamiento de proyectiles en distintos planetas del sistema solar, calculando la trayectoria y presentando los resultados en la consola.


---

##  Objetivos Específicos

- Simular el lanzamiento de un cohete o proyectil aplicando las ecuaciones de movimiento parabólico.
- Permitir a estudiantes experimentar cómo cambia la trayectoria de un proyectil al modificar la velocidad, el ángulo y la gravedad de distintos planetas.
- Permitir al usuario comparar cómo cambia el alcance, altura y tiempo de vuelo en distintos cuerpos celestes (Luna, Marte, Júpiter, etc.).
- Mostrar las comparaciones a través de una tabla comparativa de todos los planetas con el mismo lanzamiento, analizando y entendiendo cómo influye la gravedad.

---

##  Hoja de Ruta

| Hito | Tecnología | Estado | Descripción |
|------|-----------|--------|-------------|
| **Hito 1** | C |  Terminado | Prototipo básico en consola con física, menú y exportación |
| **Hito 2** | C++ + Gráficos |  En proceso | Reorganización en clases + visualización gráfica |
| **Hito 3** | C++ + Interfaz |  Pendiente | Interfaz desacoplada de la lógica + página web |

---

##  Equipo y Roles

###  Desarrollo de Código

| Integrante | Rol | Responsabilidades |
|-----------|-----|-------------------|
| [Samuel Cament] | Desarrollador principal | Lógica de física, funciones de cálculo, estructuras de datos |
| [Benjamin Vargas] | Desarrollador de interfaz | Menú interactivo, pantalla de bienvenida |

###  Gestión y Video 
| Integrante | Rol | Responsabilidades |
|-----------|-----|-------------------|
| [Cristobal Oyarzun] | Gestor GitHub + video exclicativo | Readme, Guión y producción del video del proyecto |
| [Francisco Condori] | Gestor GitHub + Documentación | Manejo del repositorio, commits, control de versiones |

---

## Física Aplicada

```
x(t)    =  v₀ · cos(θ) · t
y(t)    =  v₀ · sen(θ) · t  −  ½ · g · t²

Alcance  =  v₀² · sen(2θ) / g
H máx    =  (v₀ · sen(θ))² / (2g)
T vuelo  =  2 · v₀ · sen(θ) / g
```

---

##  Gravedades Disponibles

| Cuerpo celeste | g (m/s²) |
|----------------|----------|
| Luna           | 1.62     |
| Marte          | 3.72     |
| Mercurio       | 3.70     |
| Venus          | 8.87     |
| **Tierra**     | **9.81** |
| Saturno        | 10.44    |
| Urano          | 8.69     |
| Neptuno        | 11.15    |
| Júpiter        | 24.79    |
| Personalizado  | libre    |

---

##  Video Explicativo Hito 1

> https://www.youtube.com/watch?v=alypqZLJVk4

---

## Compilacion En C
- gcc -o simulador main.c funciones.c -lm
- ./simulador

--- 

## Migración de C a C++

|    | Hito 1 - C | Hito 2 - C++ | Razon |
|----|------------|--------------|--------|
| Organización | Funciones y estructs | Clases con encapsulamiento  | Diseño OOP |
| Validación de entradas | while con scanf | Excepciones std::invalid_argument | Manejo errores |
| Salida de texto | printf / scanf | std::cout / std::cin + iomanip | Estándar C++ |
| Separación de archivos | Un único .c | .h (declaraciones) + .cpp (implementaciones) | Modularidad |

---

## Funcionalidades implementadas

### Modo Juego (`iniciar_juego`):

El jugador avanza por 9 niveles, uno por planeta. Cada nivel presenta un problema físico
con contexto narrativo. El jugador debe ingresar el resultado correcto (tolerancia ±0.05).
Si se equivoca, el nivel se repite.

### Modo Libre (`modolibre`):

El usuario ingresa ángulo, velocidad y elige un planeta. El programa muestra el tiempo
de vuelo, alcance máximo y altura máxima.

### Validación de Entrada (`limpiarbuffer`):

Solicita un número flotante y repite si el formato es inválido, limpiando el buffer.
---
## Pruebas Realizadas

| Prueba | Entrada | Resultado Esperado | Resultado Obtenido |
|:-------|:--------|:-------------------|:-------------------|
| Alcance máximo Tierra | v=15, θ=30, g=9.81 | 19.86 m | ✅ Correcto |
| Tiempo de vuelo Luna | v=10, θ=45, g=1.62 | 8.73 s | ✅ Correcto |
| Altura máxima Mercurio | v=20, θ=60, g=3.70 | 40.54 m | ✅ Correcto |
| Entrada inválida (texto) | "a" | Solicita nuevo valor | ✅ Correcto |
| Ángulo fuera de rango | 200° | Mensaje de error | ✅ Correcto |
| Planeta fuera de rango | opción 10 | "Planeta no válido" | ✅ Correcto |

---

## Cambios respecto al Hito 1

- Se creo la función `instrucciones()` para mantener el main limpio.
- El catálogo de planetas migró de constantes globales (TIERRA, LUNA, etc.) 
  a un array de objetos de clase PLANETAS.
- Se creo la funcion `limpiarbuffer` para arreglar un bug de validacion de entrada
- Se mantiene el array global en lugar de std::map
  porque la funcionalidad es equivalente para el tamaño actual del catálogo.
  Se migrará en el Hito 3.

---

##  Video Explicativo Hito 2

> https://www.youtube.com/watch?v=alypqZLJVk4

---

## Compilacion En C++
- g++ main.cpp funciones.cpp -o juego -lm
- ./juego

---
## Hito 3

- Crearemos interfaz grafica para el juego

---

##  Distribución de Tareas

### [Samuel Cament] — Desarrollador principal
- [x] Implementar funciones de física (`calcular_alcance`, `calcular_altura_max`, etc.)
- [x] Diseñar las estructuras `Planeta` y `Resultado`
- [x] Verificar que las fórmulas físicas sean correctas
- [x] Arreglar bugs
- [x] Migrar lógica de física al Hito 2 en C++

### [Benjamin Vargas] — Desarrollador de interfaz
- [x] Implementar el menú interactivo con validación de entrada
- [x] Diseñar la pantalla de bienvenida con instrucciones
- [x] Crear el modo libre
- [ ] Diseñar la tabla de posiciones( Hito 3)


### [Francisco Condori] — Gestor GitHub + Documentación
- [x] Crear y configurar el repositorio en GitHub
- [x] Actualizar el `.gitignore` del proyecto
- [x] Hacer commits organizados con mensajes descriptivos
- [ ] Organizar las carpetas `hito1/`, `hito2/`, `hito3/`
- [ ] Documentar los cambios entre versiones

### [Cristobal Oyarzun] — Investigación + Video
- [x] Investigar las ecuaciones del movimiento parabólico
- [x] Buscar datos reales de gravedad de cada planeta
- [x] Redactar el marco teórico del proyecto
- [x] Mantener el README actualizado en el hito
- [x] Escribir el guión del video explicativo 2
- [ ] Grabar y editar el video demostrativo
- [ ] Subir el video y agregar el enlace al README

---
