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

