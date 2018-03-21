#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
//#include "Papillon.h"
#include "Terrain.h"
#include "Vaisseau.h"
#include <string.h>
using namespace std;
class MyGraphicEngine:public GraphicEngine {    
    char* str;
public:
    
    MyGraphicEngine(Terrain* terrain_){
        terrain = terrain_;
        buildInterface();
     }
    ~MyGraphicEngine(){
        if(terrain != NULL){
            delete terrain;
            terrain = NULL;
        }
        formes.clear();
    }
    virtual void Draw();
    void drawPaneUnder();
    void drawPaneRight();
    void drawPaneUp();
    
private:
    std::vector<Forme*> formes;
    void buildInterface();
    char* stringToChar(string str);
    char* argentLabel(int argent);
    
    Terrain* terrain;
};
