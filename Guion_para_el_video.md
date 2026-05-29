## Guion para el el video 2 ##

---

# 1.--Presentacion del equipo(30 seg)--

Los integrantes se presentaran uno a uno diciendo su nombre y rol.

-Samuel Cament(Desarrollador Principal)

-Benjamin Vargas(Desarrollador de interfaz)

-Francisco Condori(Gestor GitHub + Documentación)

-Cristóbal Oyarzún(Gestor Github + Video explicativo)

---

# 2.--Problematica y Objetivos(1 min)--

#Se debera presentar la presentar la problematica y los objetivos para dar a entender.


Problematica a resolver:

-Está demostrado que cada persona tiene una forma de aprender distinta los casos fisicos, por lo que se debe crear y aplicar un videojuego con distintas funciones, en donde se busca que el usuario aprenda conceptos fisicos.

Objetivo General:

-Desarrollar un simulador en C++ orientado a fines educativos con objetos que modele el lanzamiento de proyectiles en distintos planetas del sistema solar, calculando la trayectoria y presentando los resultados en la consola.

Objetivos Específicos:

-Simular el lanzamiento de un cohete o proyectil aplicando las ecuaciones de movimiento parabólico.

-Permitir a estudiantes experimentar cómo cambia la trayectoria de un proyectil al modificar la velocidad, el ángulo y la gravedad de distintos planetas.

-Permitir al usuario comparar cómo cambia el alcance, altura y tiempo de vuelo en distintos cuerpos celestes (Luna, Marte, Júpiter, etc.).

-Mostrar las comparaciones a través de una tabla comparativa de todos los planetas con el mismo lanzamiento, analizando y entendiendo cómo influye la gravedad.

---

# 3.--Avances desde el hito 1 (1,5 min)--

"En el Hito 1 entregamos el simulador en lenguaje C. Funcionaba correctamente, pero toda la lógica estaba en funciones sueltas y structs sin encapsulamiento."

"Para el Hito 2 migramos completamente a C++. Los cambios más importantes fueron los siguientes:"

"El catálogo de planetas pasó de ser un array estático global a un std::map, lo que permite buscar el planeta por nombre de forma directa"

"La validación de entradas pasó de bucles con scanf a diferencia con throw, que es el mecanismo de manejo de errores en C++."

---

# 4.--Diseño en C++: clases y relaciones (2 min)--

"El programa está organizado en diferentes clases principales."

"La clase Planeta representa un cuerpo con su nombre y gravedad. Contiene un método estático que entrega el catálogo completo de los planetas."

"La clase Proyectil donde se encapsula los parámetros de lanzamiento: el ángulo y la velocidad inicial. Calcula las componentes horizontal y vertical de la velocidad."

"La clase Trayectoria siendo la más importante del simulador. Usa una composición que contiene un Proyectil y un Planeta. A partir de ellos, calcula todos los puntos de la parábola y entrega la altura máxima y el tiempo de vuelo. También genera el gráfico ASCII."

"Y la clase Simulador es el controlador principal. Gestiona el menú, solicita los datos al usuario y lanza simulaciones. Cuando el programa termina"

---

# 5.--Pruebas Basicas(1 min)--

#A continuación ejecutamos algunas pruebas para validar las funcionalidades.

---

# 6.--Organización en GitHub(1,5 min)--

La organización del trabajo la gestionamos completamente a través de GitHub.

La distribución de las tareas fueron las siguientes:

[Samuel Cament] 
[Benjamin Vargas]	
[Francisco Condori] se encargo del Manejo del repositorio, control de versiones.
[Cristóbal Oyarzun]	README, guión y producción del video del proyecto.

"El código está en la carpeta (src/) con la separación correcta entre archivos (.h) de declaraciones y (.cpp) de implementaciones, tal como lo exige el hito."

"Creamos el Milestone Hito 2 con issues asociadas, cada una representando una tarea concreta: migrar cada clase, implementar el historial, documentar el README, completar las pruebas y el AI_USAGE.md."

---

# 7.--Proximos pasos(20 seg)--

"Para el Hito 3 tenemos planificados los siguientes avances:"



8.--Cierre(20 seg)--

"Eso es todo por el Hito 2. Migramos el simulador completo a C++ con diseño orientado a objetos, aplicando encapsulamiento, composición y las herramientas estándar del lenguaje."
