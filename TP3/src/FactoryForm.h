//
//  FactoryForm.hpp
//  TP3
//
//  Created by Tran Thanh Long on 20/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//
#pragma once
#include <stdio.h>
#include "Forme.h"
#include "Missile.h"
class FactoryForm{
public:
    static FactoryForm* getInstance();
    MyColor* createColor(float r, float g, float b);
    Forme* createTriangle(MyPoint& point, float size, MyColor* color);
    Forme* createRectangle(MyPoint& point, float height, float width, MyColor* color);
    Missile* createMissile(MyPoint& point, int niveau);
    Forme* createPolygone(MyPoint& point, float size, int niveau);
    Forme* createHeart(MyPoint& point, float size);
    
    void kill(){
        delete mf_i;
        mf_i = NULL;
    }
private:
    ~FactoryForm(){}
    FactoryForm(){}
    static FactoryForm* mf_i;
    
};
