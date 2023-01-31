#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank;
    int size;
    int data[100];

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::printf( "Hola, soy el rank %d, de un total de %d procesos\n", rank, size );

    if( rank==0 ) {
        for(int i=0;i<100;i++) {
            data[i] = i;
        }
        std::printf("RANK0 enviando....\n");
        MPI_Send( &data[50],50, MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else if(rank==1){
        std::printf("RANK%d recibiendo....\n", rank);
        MPI_Recv(data,50,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        std::printf("RANK%d recibiendo....datos[99]=%d\n", rank, data[0]);
    }

    MPI_Finalize();

    return 0;
}
