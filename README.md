#  Simulador de Lanzamiento Parabólico
---

##  Problematica a Solucionar (resumido)

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
## Funcionalidades implementadas

-Selección de planeta:

El usuario elige entre los cuerpos celestes del sistema solar (más la Luna), cada uno con su gravedad en m/s².

-Configuración del lanzamiento:

Se ingresan el ángulo y la velocidad inicial. Ambos valores debe ser aceptados con manejo de excepciones; si no son aceptados, el programa los solicita nuevamente.

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

##  Video Explicativo

> https://www.youtube.com/watch?v=alypqZLJVk4

---

## Compilacion
- gcc -o simulador main.c funciones.c -lm
- ./simulador

---
##  Distribución de Tareas

### [Samuel Cament] — Desarrollador principal
- [x] Implementar funciones de física (`calcular_alcance`, `calcular_altura_max`, etc.)
- [x] Diseñar las estructuras `Planeta` y `Resultado`
- [x] Verificar que las fórmulas físicas sean correctas
- [x] Arreglar bugs
- [ ] Migrar lógica de física al Hito 2 en C++

### [Benjamin Vargas] — Desarrollador de interfaz
- [x] Implementar el menú interactivo con validación de entrada
- [x] Diseñar la pantalla de bienvenida con instrucciones
- [x] Crear el modo libre
- [ ] Diseñar la tabla de posiciones( Hito 3)


### [Francisco Condori] — Gestor GitHub + Documentación
- [x] Crear y configurar el repositorio en GitHub
- [x] Mantener el README actualizado en cada hito
- [x] Actualizar el `.gitignore` del proyecto
- [x] Hacer commits organizados con mensajes descriptivos
- [ ] Organizar las carpetas `hito1/`, `hito2/`, `hito3/`
- [ ] Documentar los cambios entre versiones

### [Cristobal Oyarzun] — Investigación + Video
- [x] Investigar las ecuaciones del movimiento parabólico
- [x] Buscar datos reales de gravedad de cada planeta
- [x] Redactar el marco teórico del proyecto
- [x] Escribir el guión del video explicativo 2
- [ ] Grabar y editar el video demostrativo
- [ ] Subir el video y agregar el enlace al README

---
