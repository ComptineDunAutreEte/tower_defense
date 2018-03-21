//
//  Case.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 06/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//

#pragma once
#include "GraphicPrimitives.h"
#include "MyPoint.h"
class Case{
public:
    Case(float _r, float _g, float _b, float x_, float y_, float size_): r(_r), g(_g), b(_b), x(x_), y(y_), size(size_){
        createCenterPoint();
    };
    
    Case(Case const& c):r(c.r), g(c.g), b(c.b), x(c.x), y(c.y), size(c.size){
        createCenterPoint();
    }
    ~Case(){
        if(centre != NULL){
            delete centre;
            centre = NULL;
        }
        std::cout<<"delete case x: "<<x<<" y: "<< y <<std::endl;
    }
    void draw();
    MyPoint* getCentre();
private:
    float x;
    float y;
    float size;
    
    MyPoint *centre;
    
    float r;
    float g;
    float b;
    void createCenterPoint();
};
/* Case_h */
