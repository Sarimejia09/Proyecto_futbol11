# 🎮 Juegos de Fútbol en C++

Este proyecto es una colección de minijuegos en C++ basados en jugadores de fútbol. Incluye diferentes modos de juego donde el usuario debe adivinar jugadores utilizando pistas, letras o relaciones entre clubes y nacionalidades.

---

## 📌 Características

- ⚽ **Adivina el Jugador**: Adivina el jugador usando pistas como nacionalidad, posición y club.
- 🔤 **Worldle (modo palabras)**: Adivina el apellido del jugador letra por letra (similar a Wordle).
- 🧩 **Grid**: Completa una cuadrícula con jugadores que coincidan con combinaciones de clubes y países.
- 🎨 Interfaz en consola con colores y formato visual.
- 📂 Lectura de datos desde archivos `.csv`.

---

## 🗂️ Estructura del Proyecto

📁 Proyecto
│
├── Main.cpp # Menú principal
├── Juegos.cpp # Lógica de los juegos
├── Funciones.cpp # Funciones auxiliares
├── Funciones.h # Declaraciones de funciones
├── Juegos.h # Declaraciones de juegos
│
├── jugadores.csv # Base de datos para juegos 1 y 2
└── Jugadores_Grid.csv # Base de datos para el modo Grid


---

## ⚙️ Requisitos

- Compilador de C++ (g++ recomendado)
- Consola compatible con ANSI (para colores)
- Sistema operativo Windows (usa `cls` para limpiar pantalla)

---

## ▶️ Cómo ejecutar

1. Compila el proyecto:


g++ Main.cpp Juegos.cpp Funciones.cpp -o juego

./juego

🧠 Cómo funcionan los juegos
1. Adivina el Jugador
Se muestran pistas: nacionalidad, posición y club.
Debes escribir el nombre del jugador.
✔️ Correcto: +10 puntos
❌ Incorrecto: -5 puntos
2. Worldle
Adivina el apellido del jugador.
Recibes pistas por letras:
🟩 LC: letra correcta en posición correcta
🟨 LI: letra correcta en posición incorrecta
🟥 X: letra incorrecta
Tienes máximo 6 intentos.
3. Grid
Completa una cuadrícula 3x3.
Cada celda debe cumplir:
Un club (columna)
Un país (fila)
Debes ingresar un jugador que cumpla ambas condiciones.
📊 Datos

El proyecto usa archivos CSV para cargar jugadores:

jugadores.csv: contiene nombre, nacionalidad, posición y club.
Jugadores_Grid.csv: contiene nombre completo, nacionalidad y club.

🛠️ Funciones importantes
ObtenerDatos(): carga jugadores desde CSV.
ComprobarPalabra(): lógica del Wordle.
ImprimirTabla(): muestra la tabla con colores.
ImprimirGrid(): muestra la cuadrícula centrada.
IdJugador(): busca un jugador en la base de datos.
Ganar(): verifica si el usuario completó el juego.
