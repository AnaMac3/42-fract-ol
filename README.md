# **Fract-ol**
Proyecto pipex del cursus 42.

### Introducción

El objetivo de este proyecto es crear un programa de exploración de fractales.

Alternativa a la minilix: MLX42 de Codam &rarr; [AQUÍ](https://github.com/42-Fundacion-Telefonica/MLX42)

**Cosas que tiene que cumplir el programa:**

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

### Algunas funciones de la MLX42

| ***mlx_init()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Inicializa el entorno gráfico y crea una ventana |
| Prototipo         | mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)|
| Parámetros   | width: ancho <br> height: alto <br> title: título <br> resize: true o false, si la ventana cambia de tamaño o no|
| Return   | Devuelve un puntero a la estructura mlx_t inicializada. |

| ***mlx_loop()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Mantiene activa la ventana gráfica creada por mlx_init(), se encarga de actualizar su contenido de manera continua en un bucle renderizado, permitiendo que el programa dibuje y responda a eventos hasta que la ventana se cierre. <br>
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
| ¿Qué hace?      | Libera recursos y cierra adecuadamente la ventana gráfica y su contexto cuando ya no se necesita|
| Prototipo         |void mlx_terminate(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

| ***mlx_close_window()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Cierra la ventana en el siguiente ciclo de actualización de GLFW. No cierra la ventana de inmediato, para permitir que el programa termine de limpiar y guardar datos antes de salir |
| Prototipo         |void mlx_close_window(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

| ***mlx_key_hook()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Permite registrar una función de callback de teclado (hook) que se ejecutará cada vez que ocurra un evento de teclado en la ventana.|
| Prototipo         |void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> func: función de callback que se quiere registrar, que debe tener la firma compatible con mlx_keyfunc <br> param: parámetro adicional |
| Return   | Nada.|

| ***mlx_scroll_hook()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | GDSFGSFGGGG.|
| Prototipo         |void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> func: función de callback que se quiere registrar, que debe tener la firma compatible con mlx_scrollfunc <br> param: parámetro adicional |
| Return   | Nada.|

| ***mlx_get_mouse_pos()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | SDGSDFSDFH.|
| Prototipo         |void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> x: posición en eje x <br> y: posición en eje y |
| Return   | Nada.|


***OTRAS COSAS***

Estructura GLFWwindow de la biblioteca GLFW. Representa una ventana y su contexto de OpenGL asociado. GLFWwindow almacena datos relacionados con eventos como el teclado, el ratón y el cambio de tamaño de la ventana. El callback de cambio de tamaño es glfwSetWindowSizeCallback, y usa GLFWwindow para detectar cuando el usuario ajusta las dimensiones de la ventana.

### Explicación de la función para Mandelbrot y Julia

<img src="https://github.com/AnaMac3/42-fract-ol/blob/main/img/Untitled-2024-10-25-1038.png" alt="Mandelbrot" width="900" />







