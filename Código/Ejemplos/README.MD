# Introducción a C

En la carpeta src hay 3 carpetas con programas introductorios a C

## Compilar

En esta carpeta existe un archivo llamado Makefile. Este tiene todas las instrucciones para el computador de cómo compilar los programas. Puedes asumir que para todas las tareas y programas del curso va a haber un archivo Makefile.

Para compilar los códigos solo debes abrir la consola en esta carpeta y ejecutar el siguiente comando

```sh
make
```

Esto hará que se generen los archivos compilados para los 3 programas en la capeta src: hellofile, hellohuman y helloworld

Además se generará una carpeta obj. Esta contiene archivos compilados también pero con extensión .o

La carpeta obj sirve en general para programas con múltiples archivos, y permite compilar denuevo solo las partes que se editaron. Es especialmente útil para programas muy grandes que podrán demorar mucho en compilar.

## Ejecutar el código

Para ejecutar el código debes escribir en consola el nombre del archivo a ejecutar. Por ejemplo:

```sh
./helloworld
```

El ./ agregado al comienzo del nombre del archivo indica que el archivo se encuentra en la carpeta actual.

Es posible ejecutar programas desde otras carpeta indicando el path. Por ejemplo, si abrimos una consola en la carpeta principal del repositorio podemos ejecutar los archivos de esta carpeta con el siguiente comando:

```sh
./Codigo/Introduccion/helloworld
```

## Códigos en C

Ve a la carpeta src y ve cada uno de los archivos de los programas. Cada archivo muestra un ejemplo de cómo usar aspectos básicos de C. Además están altamente comentados para guiarte sobre el funcionamiento.

Si editas el código de alguno de los archivos tienes que volver a compilarlo antes de poder ejecutarlo. Para esto solo tienes que usar el comando make denuevo en la carpeta con la Makefile
