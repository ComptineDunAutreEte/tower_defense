//
//  Factory.hpp
//  generical_libGraphProject
//
//  Created by Thanh Long Tran on 06/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#pragma once
#include <stdio.h>
#include "Case.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Missile.h"
#include "MyColor.h"
#include "FactoryForm.h"

class Factory{
public:
    static Factory* getInstance();
    Case* createCase(float x, float y, float size);
    Vaisseau* createVaisseau(MyPoint& point, float size, int niveau);
    Asteroid* createAsteroid(MyPoint& point, float size, int niveau);
    void kill(){
        delete m_i;
        m_i = NULL;
    }
private:
    ~Factory();
    Factory(){}
    static Factory* m_i;
    
};
