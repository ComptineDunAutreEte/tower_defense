//
//  Terrain.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 05/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//

#pragma once
#ifndef Terrain_h
#define Terrain_h
#include "Case.h"
#include "Factory.h"
#include "FactoryForm.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "AbstractItem.h"
#include "Missile.h"
#include "Engine.h"
#include <vector>
#include <cmath>
class Terrain{
public:
    Terrain(){
        isRunning = false;
        GamesOver = false;
        buildVies();
        argent = 50;
    };
    ~Terrain(){
        /*for (std::vector< Case* >::iterator it = cases.begin() ; it != cases.end(); ++it)
        {
            delete (*it);
        }*/
        cases.clear();
        vaisseaux.clear();
        asteroids.clear();
        vies.clear();
    }
    void draw();
    void tick();
    void build();
    Case* getCasePosition(float x, float y);
    Case* getCase(int i){
        return cases.at(i);
    }
    void buildVies();
    std::vector<Vaisseau*> getVaisseaux(){
        return vaisseaux;
    }
    
    void addVaisseau(Vaisseau* vaisseau);
    float get_case_size();
    int convert(float a, float b);
    bool getGameOver(){
        return GamesOver;
    }
    bool isRunning;
    bool GamesOver;
    int getArgent(){
        return argent;
    }
    void setArgent(int argent_){
        argent = argent_;
    }
private:
    void generateAsteroids();
    void menage();
    const int taille = 10;
    const float case_size = 0.13f;
    std::vector<Case*> cases;
    std::vector<Vaisseau*> vaisseaux;
    std::vector<Asteroid*> asteroids;
    std::vector<Missile*> missiles;
    std::vector<Forme*> vies;
    
    //std::map<int, Vaisseau*> vaisseaux;
    int argent;
};

#endif /* Terrain_h */
