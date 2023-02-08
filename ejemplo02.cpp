#include <iostream>
//#include <chrono>
#include <thread>
#include <ctime>
#include <mpi.h>

// para utilizar la sintaxis 2000ms
using namespace std::chrono_literals;

int main(int argc, char** argv) {
    int rank;
    int size;
    int data[100];


    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::srand( std::time(nullptr)*rank );
    int random_v = std::rand() % 7;

    std::printf( "Hola, soy el rank %d, de un total de %d procesos\n", rank, size );

    //sincronizar todos los procesos
    MPI_Barrier(MPI_COMM_WORLD);
    
    double start_time = MPI_Wtime();

    // trabajo
    //  tiempo aleatorio entre 1 y 30 segundos
    /**
    * RANK0: 1
    * RANK1: 2
    * RANK2: 3
    * RANK3: 4
    */
    double rank_time = (random_v);
    std::this_thread::sleep_for(1000ms*(random_v));

    std::printf("Time for RANK%d work is %lf seconds\n", rank, rank_time);

    // volver a sincronizar
    MPI_Barrier(MPI_COMM_WORLD);

    double main_time = MPI_Wtime() - start_time;

    if (rank == 0) 
        std::printf("Time for work is %lf seconds\n", main_time);

    MPI_Finalize();

    return 0;
}
