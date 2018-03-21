#pragma once

#include "Engine.h"
#include "Terrain.h"
class MyGameEngine:public GameEngine {
    //std::vector<Papillon * > *paps;
public:
    
    MyGameEngine(Terrain* terrain_){
        terrain = terrain_;
    }
    
    virtual void idle();
private:
    Terrain* terrain;
    
};
