
#include "eHandler.h"

Events event;
//static pthread_mutex_t PMutex = PTHREAD_MUTEX_INITIALIZER;
std::vector<int>* temp;
std::vector<int>* tempVec;




void* eHandlerPush(void*){
    int count = 0;
    while (count < 50){
           if (pthread_mutex_lock(&PMutex) != 0) {                                          
                perror("mutex_lock");                                                       
                exit(2);                                                                    
            }           
        temp = event.getContainer();
        temp->push_back(count);
        printf("pushing %d to vector\n", count);
        count++;
          if (pthread_mutex_unlock(&PMutex) != 0) {                                      
                perror("pthread_mutex_unlock() error");                                     
                exit(2);                                                                    
            }            
        usleep(1000); //delay between pushing frames, notification system can be implemented
   
    }

    printf("Push Finished\n");
    pthread_exit(NULL);
}

void* eHandlerPop(void*){
    int count = 0;
    while (count < 50){
        
        tempVec = event.getContainer();
        if (!tempVec->empty()){
            if (pthread_mutex_lock(&PMutex) != 0) {                                          
                perror("mutex_lock");                                                       
                exit(2);                                                                    
            }        
            int currentInt = tempVec->back();
            printf("current front of vector is %d\n", currentInt);
            printf("\nsize of vector is %d\n", int(tempVec->size()));
            tempVec->pop_back();
            count++;
            if (pthread_mutex_unlock(&PMutex) != 0) {                                      
                perror("pthread_mutex_unlock() error");                                     
                exit(2);                                                                    
            }    
 
        }

        
}

printf("Pop Finished\n");
pthread_exit(NULL);
        
}