#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;

pthread_mutex_t mutex;

void *counter_function(void *tid)
{
    int i;
	
	for(i=0; i<10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Thread %d has locked the mutex\n", *(int *)tid);
        counter++;     
        sleep(20);              
        pthread_mutex_unlock(&mutex);
    }
		
    
  
    pthread_exit(tid);
}

int main()
{
    pthread_t *tid;
    int i, ids[5], return_value;

    tid = malloc(5 * sizeof(pthread_t));
    //check malloc return value
    if(tid == NULL)
    {
        perror("Error");
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);
    

    for(i=0; i<5; i++)
    {
        ids[i] = i+1;
        printf("Main creating thread %d\n", ids[i]);
        return_value = pthread_create(&tid[i], NULL, counter_function, &ids[i]);

        //check if thread created properly
        if(return_value != 0)
        {
            perror("Error");
            exit(1);
        }
    }
    
    

    void *status;
    for(i=0; i<5; i++)
    {
        return_value = pthread_join(tid[i], &status);
        //check if thread finished properly
        if(return_value != 0)
        {
            perror("Error");
            exit(1);
        }
        printf("Thread terminated with and returned: %d\n", *(int *)status);
    }
    
    printf("Counter value after threads finished = %d.\n", counter);
    pthread_mutex_destroy(&mutex);
   
    return 0;
}
