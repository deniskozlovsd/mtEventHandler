
#include "eHandler.h"

using namespace std;

vector<int>* tempVec;

int main() {
    
    thread eventHandlerThread(eHandlerBody);
    int count = 0;
    while (count < 5000){
        tempVec = event.getContainer();
        if (tempVec->size()>0){
            int currentInt = tempVec->back();
            printf("current front of vector is %d\n", currentInt);
            printf("\nsize of vector is %d\n", int(tempVec->size()));
            tempVec->clear();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            count++;
        }
        
    }

    eventHandlerThread.join();
    printf("main is done\n");
    return 0;
}