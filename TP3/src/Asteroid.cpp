//
//  Asteroid.cpp
//  TP3
//
//  Created by Tran Thanh Long on 13/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//


#include "Asteroid.h"

void Asteroid::draw(){
    if(!est_destruite)
        forme->draw();
}
void Asteroid::moveUp(){
    for(int i = 0;  i<forme->y.size() ; i++){
        forme->y[i]+=0.13f;
    }
    forme->getSpecialPoint().y+=0.13f;
}
void Asteroid::moveDown(){
    for(int i = 0;  i<forme->y.size() ; i++){
        forme->y[i]-=0.13f;
    }
    forme->getSpecialPoint().y-=0.13f;
}
void Asteroid::moveLeft(){
    for(int i = 0;  i<forme->x.size() ; i++){
        forme->x[i]-=0.13f;
    }
    forme->getSpecialPoint().x-=0.13f;
}
void Asteroid::tick(){
    
    int i = 0;
    if(!est_destruite){
        if(vie <= 0){
            est_destruite = true;
        }
        for(i = 0;  i<forme->x.size() ; i++){
            forme->x[i]-=vitesse;
        }
        forme->getSpecialPoint().x-=vitesse;
        if(forme->colisionAvecMur(false)){
            est_destruite=true;
            coeur = -1;
        }
       
    }
}
