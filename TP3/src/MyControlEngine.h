#pragma once
#include "Engine.h"
#include "Terrain.h"
#include "Vaisseau.h"
class MyControlEngine:public ControlEngine {    
public:
    MyControlEngine(Terrain* terrain_){
        terrain = terrain_;
        butCommencerClicked = false;
        butRecommencerClicked =false;
        niveauVaisseau = 0;
    }
   
    virtual void MouseCallback(int button, int state, int x, int y) ;
private:
    Terrain* terrain;
    bool butCommencerClicked;
    bool butRecommencerClicked;
    int niveauVaisseau;
};
