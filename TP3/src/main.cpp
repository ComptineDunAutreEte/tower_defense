
#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Factory.h"
#include "Terrain.h"


int main(int argc, char * argv[])
{

   Engine e(argc,argv);
   Terrain *terrain = new Terrain();
    terrain->build();
    //std::vector<Papillon *> paps;
    std::vector<Vaisseau * > vaisseaux;
    GraphicEngine * ge = new MyGraphicEngine(terrain);
    GameEngine * gme = new MyGameEngine(terrain);
    ControlEngine * ce = new MyControlEngine(terrain);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();

    return 0;
}
