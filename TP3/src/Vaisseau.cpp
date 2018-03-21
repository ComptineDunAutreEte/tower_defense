//
//  Vaisseau.cpp
//  TP3
//
//  Created by Thanh Long Tran on 12/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#include "Vaisseau.h"

void Vaisseau::draw(){
    if(!est_destruite)
        forme->draw();
    for(int i = 0; i < missiles.size(); i++){
        missiles[i]->draw();
    }
}

void Vaisseau::tick(){
    if(frequenceTmp <= 0){
        frequenceTmp = frequence;
        if(compteur>0){
            missiles.push_back(FactoryForm::getInstance()->createMissile(forme->getSpecialPoint(), niveau));
            compteur--;
        }
    }
    if(missiles.empty()&& compteur <= 0){
        est_destruite = true;
    }else{
        for (std::vector< Missile* >::iterator it = missiles.begin() ; it != missiles.end(); ++it)
        {
            if((*it)->estDestruite() ){
                delete (*it);
                missiles.erase(it);
                break;
            }
        }
        
    }
    frequenceTmp--;
    for(int i = 0; i < missiles.size(); i++){
        missiles[i]->tick();
    }
}

