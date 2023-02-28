
# MPI

## Instalación MPI en Ubuntu

```
sudo apt-get update
sudo apt-get install libopenmpi-dev
```

Verificar la instalación:

```
mpiexec --version
```

## Compilar

```
mpicxx main.cpp -o ejemplo01
```

## Ejecutar

```
mpiexec -n 4 ./ejemplo01
```


