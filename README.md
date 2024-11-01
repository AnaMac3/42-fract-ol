# **Fract-ol**
Proyecto pipex del cursus 42.

### Introducción

El objetivo de este proyecto es crear un programa de exploración de fractales.

Hay que usar la librería gráfica miniLibx. Guía &rarr; [AQUÍ]([ibs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx))
  - Extraer archivo: tar -xvzf minilibx-linux.tgz
  - Compilar minilibx: make
  - Incluir la minilibx en tu proyecto:
      - añadirlo en el Makefile: -L$(MLX_DIR) -lmlxLinux -lXext -lX11
      - #include "mlx.h"
      - Cuando hago make en la minilibx se me crean 2 .a --> libmlx_Linux.a y libmxl.a ¿Cuál necesito para qué? Creo que necesito la Linux.a
  - Hay que inicializar la conexión entre tu programa y el display --> con la función mlx_init, sin parámetros. Si falla devuelve NULL, si no, devuelve un puntero no nulo como identificador de conexión.

        int	main(void)
        {
          void	*mlx;
    
          mlx = mlx_init();
        }
  - Descripción del resto de funciones en:
      - mlx_new_window: manage windows
      - mlx_pixel_put: draw inside window
      - mlx_new_image: manipulate images
      - mlx_loop: handle keyboard or mouse events
(ESTA INFOR ESTÁ EN minilibx-linux/man/man1/mlx.1 y el resto de docs en este directorio)

Alternativa: minilibx de Codam &rarr; [AQUÍ](https://github.com/42-Fundacion-Telefonica/MLX42)
  -  Seguir instrucciones para descarga y build de MLX42
  -  Se genera la librería libmlx42.a en la carpeta build de MLX42
  -  Falgs para linkear tu proyecto con la librería: -Iinclude -ldl -lglfw -pthread -lm
  -  Leer el README ...
      - no me deja instalar estas opciones: cmake -B build && cmake --build build --parallel --config (Debug|Release|RelWithDebInfo|MinSizeRel) --target install; dice que no tengo permisos de acceso a los directorios
      - cmake -DBUILD_TESTS=ON -B build && cmake --build build --parallel : tests para comprobar la integridad de la librería. Para usarlo --> ctest --output-on-failure --test-dir build

Cómo hacerte el Makefile: https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md

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




### Funciones de la minilibx

***FUNCIONES BÁSICAS***

| ***mlx_init()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Inicializa el entorno gráfico y crea una ventana |
| Prototipo         | mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)|
| Parámetros   | width: ancho <br> height: alto <br> title: título <br> resize: true o false, si la ventana cambia de tamaño o no|
| Return   | Devuelve un puntero a la estructura mlx_t inicializada. |

| ***mlx_new_image()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Crea una nueva imagen en memoria, configura sus propiedades básicasm prepara una textura OpenGL asociada y la registra en el sistema MLX|
| Prototipo         | mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> width: ancho de imagen <br> height: altura de imagen.|
| Return   | Devuelve un puntero a la nueva imagen creada.|

| ***mlx_loop()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Mantiene activa la ventana gráfica creada por mlx_init(), se encarga de actualizar su contenido de manera continua en un bucle renderizado, permitiendo que el programa dibuje y responda a eventos hasta que la ventana se cierre. <br>
MLX_NONNULL(mlx) -> asegura que mlx no sea NULL. <br> Control de bucle. <br> Control de tiempo: obtiene el tiempo actual en segundos desde que comenzó la ejecución del programa y calcula delta_time que representa el tiempo transcurrido entre iteraciones (útil para animaciones o cálculos dependientes del tiempo). <br> Limpieza del buffer de color y profundidad: establece color de fondo gris oscuro. <br> Actualización del tamaño de la ventana. Si la ventana tiene un tamaño significativo, mlx_update_matrix ajusta la matriz de transformación. <br> Ejecución de ganchos y renderizado: mlx_exec_loop_hooks(mlx) llama a las funciones de hook o enganche, que permiten al usuario ejecutar funciones personalizadas; mlx_render_images(mlx) dibuja las imágenes a mostrar ne la ventana; mlx_flush_batch(mlx->context) envía los comandos de dibujo acumulados a la GPU. <br> Intercambio de buffers y manejo de eventos.|
| Prototipo         |void mlx_loop(mlx_t* mlx)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init().|
| Return   | Nada.|

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

***FUNCIONES QUE GESTIONAN LA ENTRADA DEL TECLADO***

| ***mlx_key_hook()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Permite registrar una función de callback de teclado (hook) que se ejecutará cada vez que ocurra un evento de teclado en la ventana.|
| Prototipo         |void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> func: función de callback que se quiere registrar, que debe tener la firma compatible con mlx_keyfunc <br> param: parámetro adicional |
| Return   | Nada.|

| ***mlx_is_key_down()***   |                 |
|------------------|-----------------|
| ¿Qué hace?      | Permite verificar si una tecla específica está presionada en un momento dado.|
| Prototipo         |bool mlx_is_key_down(mlx_t* mlx, keys_t key)|
| Parámetros   |mlx: estructura mlx_t inicializada por mlx_init(). <br> key: código de la tecla que se quiere verificar |
| Return   | Devuelve true si la tecla está presionada, y false si no lo está.|

