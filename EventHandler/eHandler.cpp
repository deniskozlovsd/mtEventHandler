
#include "eHandler.h"

Events event;
pthread_mutex_t PMutex = PTHREAD_MUTEX_INITIALIZER;
std::vector<int>* temp;
std::vector<int>* tempVec;




void* eHandlerPush(void*){
    
    int count = 0;
    while (count < 50){
       // event.testMutex.lock();
        pthread_mutex_lock(&PMutex);
        temp = event.getContainer();
        temp->push_back(count);
        printf("pushing %d to vector\n", count);
       // event.testMutex.unlock();
        pthread_mutex_unlock(&PMutex);
        usleep(40000);
           // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        count++;
    }

    printf("Push Finished\n");
    pthread_exit(NULL);
}

void* eHandlerPop(void*){
  
    int count = 0;
    while (count < 50){
        
        tempVec = event.getContainer();
        if (!tempVec->empty()){
            //event.testMutex.lock();
           pthread_mutex_lock(&PMutex);
            int currentInt = tempVec->back();
            printf("current front of vector is %d\n", currentInt);
            printf("\nsize of vector is %d\n", int(tempVec->size()));
            tempVec->pop_back();
           // event.testMutex.unlock();
            pthread_mutex_unlock(&PMutex);
            //usleep(20000);
            //std::this_thread::sleep_for(std::chrono::milliseconds(25));
            count++;
        }

        
}

printf("Pop Finished\n");
pthread_exit(NULL);
        
}