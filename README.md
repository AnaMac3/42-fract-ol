# **Fract-ol**
Proyecto fract-ol del cursus 42.

## Índice

- [Introducción](#introducción)
- [How to use](#how-to-use)
- [Algunas funciones de la MLX42](#algunas-funciones-de-la-mlx42)
- [La función para Mandelbrot y Julia](#la-función-para-mandelbrot-y-julia)
- [Bonus](#bonus)
- [Recursos](#recursos)

------------------------------

### Introducción

El objetivo de este proyecto es crear un programa de exploración de fractales, usando la librería gráfica miniLibX, o su alternativa MLX42 de Codam.

Un fractal es una forma geométrica en el se repite la misma estructura a diferentes escalas y con diferente orientación.

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/mandelbrot.png" alt="Mandelbrot" width="800"/> 


***Renderizado:***
  - El programa debe ofrecer los conjuntos de **Julia** y **Mandelbrot**
  - La rueda del ratón hace zoom in y zoom out y lo hace casi infinitamente (dentro de los límites del ordenador).
  - Se debe poder crear un conjunto de Julia diferente mediante parámetros del programa.
  - Se pasará un parámetro a través de la CLI para definir el tipo de fractal visualizado.
      - Se pueden usar más parámetros como opciones de renderizado.
      - Si no se introduce un parámetro o si este es inválido, el programa mostrará una lista de parámetros disponibls y terminará correctamente.
      - Se deben usar unos pocos colores para mostrar la profundidad de cada fractal.
    
***Representación gráfica:***
  - El programa tiene que mostrar la imagen en una ventana.
  - El manejo de la ventana debe ser fluido (cambio a otra ventana, minimización y demás).
  - ESC debe cerrar la ventana y alir del programa de manera limpia.
  - Hacer click en la cruz del marco de la ventana debe cerrarla y cerrar el programa de manera limpia.
  - El uso de images de la MiniLibx es obligatorio.

Alternativa a la minilix: MLX42 de Codam &rarr; [AQUÍ](https://github.com/42-Fundacion-Telefonica/MLX42)

### How to use

- Descargar [MLX42 de Codam](https://github.com/42-Fundacion-Telefonica/MLX42).
- Build:
  
      cd MLX42
      cmake -B build # build here refers to the outputfolder.
      cmake --build build -j4 # or do make -C build -j4

- Compilar fract-ol:

      cd ..
      make

- Ejecutar:

      ./fracto <fractal_type> <julia_pattern>

  - fractal_type:
    - "mandelbrot"
    - "julia"
    - "burning_ship"
  - julia_pattern (only if fractal_type == "julia")
    - 'pattern_f' for c = mouse position when click
    - 'pattern_1' for c = 0.279
    - 'pattern_2' for c = 0.8, 0.156i
    - 'pattern_3' for c = -0.70176, 0.6506i
    - 'pattern_4' for c = 0.285, 0.01i
    - 'pattern_5' for c = -0.70176, 0.3504i
    - 'pattern_6' for c = -0.4, 0.6i
    - 'pattern_7' for c = 0.355, 0.355i


### Algunas funciones de la MLX42

| ***mlx_init()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Inicializa el entorno gráfico y crea una ventana.|
| Prototipo         | mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)|
| Parámetros   | width: ancho <br> height: alto <br> title: título <br> resize: true o false, si la ventana cambia de tamaño o no|
| Return   | Devuelve un puntero a la estructura mlx_t inicializada. |

| ***mlx_loop()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Mantiene activa la ventana gráfica creada por mlx_init(), <br> actualiza su contenido de manera continua en un bucle renderizado, <br> permitiendo que el programa dibuje y responda a eventos hasta cerrar la ventana.|
| Prototipo         |void mlx_loop(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

| ***mlx_new_image()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Crea una nueva imagen dentro de una biblioteca gráfica.|
| Prototipo         |mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> width: ancho en píxeles <br> height: alto en píxeles |
| Return   | Devuelve un puntero a mlx_image_t, la nueva imagen creada.|

| ***mlx_terminate()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Libera recursos y cierra la ventana gráfica y su contexto.|
| Prototipo         |void mlx_terminate(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

| ***mlx_close_window()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Cierra la ventana en el siguiente ciclo de actualización de GLFW. <br> No cierra la ventana de inmediato, para permitir que el programa <br> termine de limpiar y guardar datos antes de salir |
| Prototipo         |void mlx_close_window(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

| ***mlx_key_hook()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Permite registrar una función de callback de teclado <br> que se ejecutará cada vez que ocurra un evento de teclado en la ventana.|
| Prototipo         |void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> func: función de callback que se quiere registrar, debe tener la firma <br> compatible con mlx_keyfunc <br> param: parámetro adicional |
| Return   | Nada.|

| ***mlx_scroll_hook()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Permite registrar una función de callback que se ejecutará <br> cuando se detecto un evento de desplazamiento (scroll)|
| Prototipo         |void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> func: función de callback que se quiere registrar, <br> que debe tener la firma compatible con mlx_scrollfunc <br> param: parámetro adicional |
| Return   | Nada.|

| ***mlx_get_mouse_pos()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Obtiene la posición actual del cursor dentro de la ventana gráfica. |
| Prototipo         |void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> x: posición en eje x <br> y: posición en eje y |
| Return   | Nada.|


### La función para Mandelbrot y Julia

Los conjuntos Julia y Mandelbrot se definen a partir de la iteración de la siguiente fórmula:

$$
z_{n+1} = z_{n}^2 + c
$$

Donde:
- $z_{n}$ es un número complejo que evoluciona con cada iteración.
- $c$ es un parámetro complejo, cuya forma de utilización varía entre los dos conjuntos.
- $z_{0}$ es el valor inicial, y es diferente en cada conjunto.

***Números complejos***

Las fractales se basan en números complejos, que son números que tienen una parte real y otra imaginaria. Un número complejo se representa como:

$$
z = a + b_{i}
$$

Donde:
- $a$ es la parte real.
- $b$ es la parte imaginaria.
- $i$ es la unidad imaginaria, con la propiedad $i² = -1$.

***Representación gráfica de números complejos***

- La parte real $a$ del número complejo se puede representar en el eje x.
- La parte imaginaria $b$ del número complejo se puede representar en el eje y.

Por ejemplo, las coordenadas $(3, 7)$ representarían el númer $z = 3 + 7_{i}$; se podría usar cada píxel de una ventana gráfica para representar ese número.


Los conjuntos de Julia y Mandelbrot se definen a partir de la misma fórmula iterativa, la diferencia entre ellos radica en el significado de los parámetros $z$ y $c$.

***Mandelbrot***

- Comienza con $z_{0} = 0$ y se aplica la fórmula iterativamente.
- El parámetro $c$ varía para cada punto del plano complejo (es decir, para cada píxel de la visualización).
- Si la secuencia de iteraciones de $z_{n}$ no tiende al infinito, entonces el número complejo $c$ pertenece al conjunto de Mandelbrot.
- Si la secuencia $z_{n}$ tiende al infinito, entonces $c$ no pertenece al conjunto.
- Visualización: los puntos $c$ que pertenecen al conjunto se colorean típicamente en negro. Los puntos fuera del conjunto, los que "escapan" al infinito, se colorean según la rapidez con la que divergen, es decir, en función del número de iteraciones necessarias para que $z_{n}$ salga de una región específica (normalmente un círculo de radio 2 en el plano complejo**).

**Círculo de radio 2 en el plano complejo: es la región en el plano complejo definida por todos los puntos cuya distancia al origen es menor o igual a 2. Es decir, es el conjunto de números complejos $z = x + iy$ (donde $x$ es la parte real e $y$ es la parte imaginaria) que cumplen esta condición:

$$
\sqrt{z_x^2 + z_y^2} > 2
$$

Que, trasladando la raíz cuadrada, queda en la condición:

$$
z_{x}² + z_{y}² > 4
$$

***Julia***

- El parámetro $c$ es un valor fijo (el mismo para todo el conjunto).
- El valor $z_{0}$ varía para cada punto del plano complejo (es decir, para cada píxel).
- Si la secuencia de iteraciones $z_{n}$ no tiende al infinito, el punto $z_{0}$ pertenece al conjunto de Julia para ese valor de $c$.
- Si la secuencia de iteraciones $z_{n}$ tiende al infinito, entonces $z_{0}$ no pertenece al conjunto.
- Visualización: los puntos que pertenecen al conjunto son generalmente coloreados en negro. Los puntos que no pertenecen al conjunto se colorean dependiendo de la rapidez con la que divergen.
- Existen diferentes conjuntos de Julia para cada valor de $c$.

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/funcion_generica.png" alt="Func_mandelbrot_julia" width="900" />



Para el conjunto Julia, podemos establecer diferentes valores de $c$.

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/julia_c_1.png" alt="Julia1" width="800"/>


También podemos hacer que el valor de $c$ dependea de la posición del cursor en la ventana gráfica, y hacerlo en modo interactivo.

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/julia_c_2.png" alt="Julia2" width="800"/>  


### Bonus

Se pueden conseguir puntos extra haciendo diferentes cosas:

- Un fractal diferente.
- Que el zoom siga la posición actual del ratón.
- Moverse con flechas en la ventana gráfica.
- Que cambie el rango de colores.

La fórmula para el conjunto Burning Ship es igual que la de Mandelbrot, pero con valores absolutos.

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/burning_ship.png" alt = "Burning_ship" width="400"/> 

### Recursos

Alternativa a la minilix: MLX42 de Codam &rarr; [AQUÍ](https://github.com/42-Fundacion-Telefonica/MLX42)




