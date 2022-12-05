#include<stdio.h>
#include<mpi.h>
int main(int argc, char** argv)
{
 int my_rank;
 int array[10] = {1,1,1,1};
 int rate[4] = {10,20,50,10};
 MPI_Status status;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 if (my_rank==0){
  MPI_Recv( &array, 4, MPI_INT, 1, 10, MPI_COMM_WORLD, &status);
  printf("The data received  from department 1 is\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 1, 10, MPI_COMM_WORLD);
  MPI_Recv( &array, 4, MPI_INT, 2, 20, MPI_COMM_WORLD, &status);
  printf("The data received from department 2 is\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 2, 20, MPI_COMM_WORLD);
  MPI_Recv( &array, 4, MPI_INT, 3, 30, MPI_COMM_WORLD, &status);
  printf("The data received from department 3 is\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  array[0] = array[0]*rate[0];
          array[1] = array[1]*rate[1];
          array[2] = array[2]*rate[2];
          array[3] = array[3]*rate[3];
          MPI_Send( &array, 4, MPI_INT, 3, 30, MPI_COMM_WORLD);
  
 }
 else if(my_rank == 1)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 84;
          array[1] = 290;
          array[2] = 212;
          array[3] = 321;
          printf("Item cost 1\n");
          for(int i = 0;i<4;i++)
   printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 10, MPI_COMM_WORLD);
  printf("Data is sent from %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
  printf("Data received at department number 1\n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
  
 }
 else if(my_rank == 2)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 223;
          array[1] = 231;
          array[2] = 42;
          array[3] = 421;
          printf("Item cost 2\n");
          for(int i = 0;i<4;i++)
   printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 20, MPI_COMM_WORLD);
  printf("Data is sent from %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 20, MPI_COMM_WORLD, &status);
  printf("Data received at department number 2 \n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
 }
 else if(my_rank == 3)
 {
  if (!array) // error checking
          {
            MPI_Abort (MPI_COMM_WORLD,1);
          }
          array[0] = 532;
          array[1] = 422;
          array[2] = 421;
          array[3] = 242;
          printf("Item cost 3\n");
          for(int i = 0;i<4;i++)
   printf("%d ",array[i]); 
  printf("\n");
  MPI_Send( &array, 4, MPI_INT, 0, 30, MPI_COMM_WORLD);
  printf("Data is sent from %d\n",my_rank);
  MPI_Recv( &array, 4, MPI_INT, 0, 30, MPI_COMM_WORLD, &status);
  printf("Data received at department number 3 \n");
  for(int i = 0;i<4;i++)
   printf("%d ",array[i]);
  printf("\n");
 }
 MPI_Finalize();
 return 0;
}