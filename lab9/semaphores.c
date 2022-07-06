#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;

sem_t semaphore;

void *counter_function(void *tid)
{
    int i;
    int return_value;

    printf("Thread %d will increase counter..\n", *(int *)tid);   

    for(i=0; i< 1000000; i++)
    {     
        //start critical section  
        return_value = sem_wait(&semaphore);
        if(return_value != 0)
        {
            perror("Error");
            pthread_exit(&return_value);
        }

        counter++;
        
        //end critical section
        return_value = sem_post(&semaphore);
        if(return_value != 0)
        {
            perror("Error");
            pthread_exit(&return_value);
        }
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
    

    return_value = sem_init(&semaphore, 0, 1);
    //check if semaphore initialized properly
    if(return_value != 0)
    {
        perror("Error");
        exit(1);
    }

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

	//"destroy" semaphore.
	return_value = sem_destroy(&semaphore);
	if (return_value != 0) {
   		perror("Error");
      	exit(1);
	}
   
    return 0;
}
