#  Simulador de Lanzamiento Parabólico


---

##  Objetivo General

Crear un juego con fines educativos programado en C, para visualizar y analizar el movimiento parabólico haciendo visible la física detrás del lanzamiento.

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
| **Hito 1** | C |  Completado | Prototipo básico en consola con física, menú y exportación |
| **Hito 2** | C++ + Gráficos |  En progreso | Reorganización en clases + visualización gráfica |
| **Hito 3** | C++ + Interfaz |  Pendiente | Interfaz desacoplada de la lógica + página web |

---

##  Equipo y Roles

###  Desarrollo de Código

| Integrante | Rol | Responsabilidades |
|-----------|-----|-------------------|
| [Samuel Cament] | Desarrollador principal | Lógica de física, funciones de cálculo, estructuras de datos |
| [Benjamin Vargas] | Desarrollador de interfaz | Menú interactivo, visualización ASCII, pantalla de bienvenida |

###  Gestión e Investigación

| Integrante | Rol | Responsabilidades |
|-----------|-----|-------------------|
| [Cristobal Oyarzun] | Gestor GitHub + Documentación | Manejo del repositorio, README, commits, control de versiones |
| [Francisco Condori] | Investigación + Video explicativo | Búsqueda de información física, guión y producción del video del proyecto |

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

##  Estructura del Proyecto

```

simulador-parabolico/
│
├── README.md
├── .gitignore
│
├── hito1/
│   └── main.c                 ← Prototipo en C
│
├── hito2/
│   └── cohete_parabolico.cpp  ← Migración a C++ con clases
│
└── hito3/
    └── (en desarrollo)        ← Interfaz web
```

---

##  Video Explicativo

> [Enlace al video del proyecto](#) — *(próximamente)*


##  Distribución de Tareas

### [Samuel Cament] — Desarrollador principal
- [ ] Implementar funciones de física (`calcular_alcance`, `calcular_altura_max`, etc.)
- [ ] Diseñar las estructuras `Planeta` y `Resultado`
- [ ] Verificar que las fórmulas físicas sean correctas
- [ ] Agregar función de comparación entre planetas
- [ ] Migrar lógica de física al Hito 2 en C++

### [Benjamin Vargas] — Desarrollador de interfaz
- [ ] Implementar el menú interactivo con validación de entrada
- [ ] Diseñar la pantalla de bienvenida con instrucciones
- [ ] Crear el gráfico ASCII de la trayectoria
- [ ] Diseñar la tabla de posiciones formateada
- [ ] Mejorar la interfaz visual en el Hito 2

### [Cristobal Oyarzun] — Gestor GitHub + Documentación
- [ ] Crear y configurar el repositorio en GitHub
- [ ] Mantener el README actualizado en cada hito
- [ ] Crear el `.gitignore` del proyecto
- [ ] Hacer commits organizados con mensajes descriptivos
- [ ] Organizar las carpetas `hito1/`, `hito2/`, `hito3/`
- [ ] Documentar los cambios entre versiones

### [Francisco Condori] — Investigación + Video
- [ ] Investigar las ecuaciones del movimiento parabólico
- [ ] Buscar datos reales de gravedad de cada planeta
- [ ] Redactar el marco teórico del proyecto
- [ ] Escribir el guión del video explicativo
- [ ] Grabar y editar el video demostrativo
- [ ] Subir el video y agregar el enlace al README

---
