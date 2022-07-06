#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 10

float calculate_line_mean(int id, int **nums);

int main(int argc, char* argv[]){
  int **nums, i, j;
  float *line_means, mean=0;

  srand(time(NULL));

  line_means = (float*)malloc(sizeof(float)*SIZE);
  nums = (int**)malloc(sizeof(int*)*SIZE);
  for(i=0; i<SIZE; i++){
    nums[i] = (int*)malloc(sizeof(int)*SIZE);
    for(j=0; j<SIZE; j++){
      nums[i][j] = 1 + rand()%10;
    }
  }

  #pragma omp parallel num_threads(SIZE)
  {
    int id = omp_get_thread_num();
    line_means[id] = calculate_line_mean(id, nums);
  }

  for(i=0; i<SIZE; i++){
    mean += line_means[i];
  }
  mean /= SIZE;

  printf("The mean value of the whole table is: %.2f\n", mean);

  return 0;
}

float calculate_line_mean(int id, int **nums){
  int i, sum=0;
  for(i=0; i<SIZE; i++){
    sum += nums[id][i];
  }
  return (float)sum/SIZE;
}
