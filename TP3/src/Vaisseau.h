//
//  Vaisseau.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 05/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#pragma once
#include "MyPoint.h"
#include "AbstractItem.h"
#include "Missile.h"
#include "FactoryForm.h"
class Vaisseau : public AbstractItem{
public:
    Vaisseau(Forme* triangle):AbstractItem(triangle){
    }
    virtual ~Vaisseau(){
        delete forme;
        forme = NULL;
        missiles.clear();
        std::cout<<"destructeur Vaisseau"<<std::endl;
    }
    
    
    virtual void draw();
    virtual void tick();
    std::vector<Missile* >& getMissiles(){
        return missiles;
    }
    void setFrequence(int f){
        frequence = f;
        frequenceTmp = f;
    }
    void setNiveau(int n){
        niveau = n;
    }
    int getNiveau(){
        return niveau;
    }
    void setCompteur(int c){
        compteur = c;
    }
private:
    std::vector<Missile* > missiles;
    int frequence;// à combien de tick il doit tirer
    int frequenceTmp;
    int niveau;//niveau du Vaisseau (existe 3)
    int compteur;//nbr de missiles...
    
};
/* Vaisseau_h */
