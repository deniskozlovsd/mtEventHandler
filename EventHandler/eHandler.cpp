
#include "eHandler.h"

Events event;
std::vector<int>* temp;

void eHandlerBody(){
    temp = event.getContainer();
    int count = 0;
    while (count < 5000){
        temp->push_back(count);
        printf("pushing %d to vector\n", count);

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        count++;
    }

    printf("ehandlerThreadFinished\n");
}