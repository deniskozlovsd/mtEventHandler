#ifndef EHANDLER_H
#define EHANDLER_H


#include <iostream>
#include <cstdio>
#include <thread>
#include <vector>
#include <chrono>


class Events {
public:
    std::vector<int>* getContainer(void){return &m_eventContainer;};

private:

std::vector<int> m_eventContainer {0};

};

extern Events event;

void eHandlerBody();
#endif