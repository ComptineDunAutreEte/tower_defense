//
//  Case.cpp
//  generical_libGraphProject
//
//  Created by Thanh Long Tran on 06/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//

#include "Case.h"
void Case::draw(){
    GraphicPrimitives::drawOutlinedRect2D(x,y,size,size,r,g,b, 0.3f);
}

void Case::createCenterPoint(){
    float x_ = x+(size/2);
    float y_ = y+(size/2);
    centre = new MyPoint(x_, y_);
}

MyPoint* Case:: getCentre(){
    return centre;
}

