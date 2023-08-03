# Ejemplo Taller C

Ejecutar ```./example```

# Para compilar
```
make
```
## Para recompilar

```shell
make clean && make
```

## Desbugeamos leacks con:

```shell
valgrind --leak-check=full --show-leak-kinds=all ./example
```

## Desbugeamos errores con:

```shell
valgrind --track-origins=yes ./example
```
