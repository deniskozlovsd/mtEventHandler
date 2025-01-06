
#include "eHandler.h"

using namespace std;



int main() {

    pthread_t pthrd1, pthrd2;
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
    
    
    pthread_join(pthrd1, NULL);
    pthread_join(pthrd2, NULL);
    //eventHandlerThreadPush.join();
   // eventHandlerThreadPop.join();
    printf("main is done\n");
    pthread_mutex_destroy(&PMutex);

    return 0;
}