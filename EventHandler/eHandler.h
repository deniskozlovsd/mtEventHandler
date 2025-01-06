#ifndef EHANDLER_H
#define EHANDLER_H


#include <iostream>
#include <cstdio>
#include <thread>
#include <vector>
#include <chrono>
#include <pthread.h>
#include <unistd.h>
//#include <mutex>

                                             
                        
class Events {
public:
    std::vector<int>* getContainer(void){return &m_eventContainer;};
//inline static std::mutex testMutex;

private:

std::vector<int> m_eventContainer {0};




};
extern pthread_mutex_t PMutex;
extern Events event;

void* eHandlerPush(void*);
void* eHandlerPop(void*);
#endif