//
//  Missile.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 05/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#pragma once
#include "MyPoint.h"
#include "GraphicPrimitives.h"
#include "AbstractItem.h"
class Missile : public AbstractItem{
private:
    int puissance;
    float vitesse;
    
public:
    Missile(int p, float v, Forme* rect): AbstractItem(rect),puissance(p), vitesse(v){
        //std::cout<<rect->x.size()<<std::endl;
    }
    Missile(Missile const& m): AbstractItem(m.forme), puissance(m.puissance), vitesse(m.vitesse){
        est_destruite = m.est_destruite;
    }
    Missile& operator=(Missile const& m){
        forme = m.forme;
        puissance = m.puissance;
        vitesse = m.vitesse;
        est_destruite = m.est_destruite;
        return *this;
    }
    ~Missile(){
        if(forme!= NULL){
        delete forme;
        forme = NULL;
            std::cout<<"Destructeur de Missile"<<std::endl;
        }
        
    }
    int getPuissance(){
        return puissance;
    }
    
    float getVitesse(){
        return vitesse;
    }
    virtual void tick();
    virtual void draw();
    
};
/* Missile_h */
