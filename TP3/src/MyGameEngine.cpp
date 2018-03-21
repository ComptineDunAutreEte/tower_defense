
#include "MyGameEngine.h"


void MyGameEngine::idle(){
    /*for (int i = 0; i < paps->size(); i++) {
        (*paps)[i]->tick();
    }*/
    if(terrain->isRunning)
        terrain->tick();
}
