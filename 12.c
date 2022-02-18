#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

long F(long a){
  return a*a;
}

void search(long limit, long num, int id){
    long start = (limit*id)/4;
    long end = (limit*(id+1))/4;
    for(long i=start;i<=end;i++){
    if(F(i)==num){
      printf("Process %d found!",id);
      break;
    }
  }
}

int main(){
  int rank,num_procs;
  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  search(100,729,rank);
  MPI_Finalize();
  return 0;
}