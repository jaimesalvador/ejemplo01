clear
echo "Compilando y ejecutando"
mpicxx prueba.cpp -o prueba
mpiexec -n 4 ./prueba
