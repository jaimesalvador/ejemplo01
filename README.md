
# MPI

## Instalación MPI en Ubuntu

```
sudo apt-get update
sudo apt-get install libopenmpi-dev
```

Verificar la instalación:

```
mpiexec --version

mpiexec (OpenRTE) 4.1.2

Report bugs to http://www.open-mpi.org/community/help/
```

```
mpiexec --version

g++ (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Compilar

```
mpicxx main.cpp -o ejemplo01
```

## Ejecutar

```
mpiexec -n 4 ./ejemplo01
```


