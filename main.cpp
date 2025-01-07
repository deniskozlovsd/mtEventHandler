
#include "eHandler.h"

using namespace std;



int main() {

    pthread_t pthrd1, pthrd2;

    if (pthread_mutex_init(&PMutex, NULL) == -1) {                                  
        cerr << "mutex_init error\n";                                                 
        exit(2);                                                                    
    }         
    if (pthread_create(&pthrd1, NULL, eHandlerPush, NULL)!=0){
        cerr << "Failed to create Push thread\n";
        return 1;
    };
    if (pthread_create(&pthrd2, NULL, eHandlerPop, NULL)!=0){
        cerr << "Failed to create Pop thread\n";
        return 1;
    };
    //thread eventHandlerThreadPush(eHandlerPush);
    //thread eventHandlerThreadPop(eHandlerPop);
    
    
    if (pthread_join(pthrd1, NULL) != 0) {
    perror("pthread_create() error");
    exit(3);
  }
    if (pthread_join(pthrd2, NULL) != 0) {
    perror("pthread_create() error");
    exit(3);
  }
    //eventHandlerThreadPush.join();
   // eventHandlerThreadPop.join();
    printf("main is done\n");
    pthread_mutex_destroy(&PMutex);

    return 0;
}