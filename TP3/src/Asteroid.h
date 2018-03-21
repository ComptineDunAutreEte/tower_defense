//
//  Asteroid.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 05/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#pragma once
#include "GraphicPrimitives.h"
#include "AbstractItem.h"
class Asteroid : public AbstractItem{
public:
    Asteroid(Forme* polygone): AbstractItem(polygone){
        est_destruite = false;
        coeur = 0;
        //vie = 10;
    }
    
    Asteroid(Asteroid const& a): AbstractItem(a.forme), vie(a.vie), vitesse(a.vitesse), niveau(a.niveau){
        forme = new Forme(*a.forme);
        est_destruite = a.est_destruite;
        seDedouble = a.seDedouble;
        coeur = a.coeur;
        //vie = 10;
    }
    
    Asteroid& operator=(Asteroid const& a){
        forme = new Forme(*a.forme);
        vie = a.vie;
        vitesse = a.vitesse;
        est_destruite = a.est_destruite;
        niveau = a.niveau;
        seDedouble = a.seDedouble;
        coeur = a.coeur;
        return *this;
    }
    virtual ~Asteroid(){
        std::cout<<"Destructeur Asteroid niveau: "<<std::endl;
    }
    
    virtual void draw();
    virtual void tick();
    void setVie(int vie_){
        std::cout<<"vie: "<<vie<<std::endl;
        vie = vie_;
    }
    int getVie(){
        return vie;
    }
    void setDedouble(bool b){
        seDedouble = b;
    }
    bool isDedouble(){
        return seDedouble;
    }
    
    void setVitesse(float v){
        vitesse = v;
    }
    float getVitesse(){
        return vitesse;
    }
    void setNiveau(int n){
        niveau = n;
    }
    int getNiveau(){
        return niveau;
    }
    int getCoeur(){
        return coeur;
    }
    void setCoeur(int c){
        coeur = c;
    }
    void moveUp();
    void moveDown();
    void moveLeft();
private:
    int vie;
    int coeur;
    bool seDedouble;
    float vitesse;
    int niveau;
};/* Asteroid_h */
