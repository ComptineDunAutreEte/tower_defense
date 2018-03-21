//
//  Missile.cpp
//  TP3
//
//  Created by Tran Thanh Long on 19/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#include <stdio.h>
#include "Missile.h"

void Missile::draw(){
    if(!est_destruite)
        forme->draw();
}
void Missile::tick(){
    if(!est_destruite){
        for(int i = 0; i < forme->x.size(); i++){
            if(!forme->colisionAvecMur(true)){
                forme->x[i]+=vitesse;
            }else{
                forme->x[i]+=vitesse;
                forme->draw();
                est_destruite = true;
            }
        }
        forme->getSpecialPoint().x+=vitesse;
    }
}
