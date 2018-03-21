//
//  Forme.h
//  TP3
//
//  Created by Tran Thanh Long on 20/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#pragma once
#include "GraphicPrimitives.h"
#include "MyColor.h"
#include "MyPoint.h"
#include <math.h>
class Forme{
public:
    Forme(MyColor* color_){
        color = color_;
    }
    Forme(Forme const& forme){
        color = new MyColor(*forme.color);
        
        specialPoint = new MyPoint(*forme.specialPoint);
        
        boundXRight = forme.boundXRight;
        boundXLeft = forme.boundXLeft;
        x = forme.x;
        y = forme.y;
    }
    Forme& operator=(Forme const& forme){
        color = new MyColor(*forme.color);
        specialPoint = new MyPoint(*forme.specialPoint);
        boundXRight = forme.boundXRight;
        boundXLeft = forme.boundXLeft;
        return *this;
    }
    ~Forme(){
        std::cout<<"Destructeur de Forme"<<std::endl;
        delete color;
        color = NULL;
        x.clear();
        y.clear();
    }
    //virtual void translate(bool a_gauche, float pas)=0;
    //virtual void rotate()=0;
    void draw(){
        GraphicPrimitives::drawFillPolygone2D(x, y, color->r, color->g, color->b);
    }
    void setColor(MyColor* color_){
        color = color_;
    }
    void setSpecialPoint(MyPoint* p){
        specialPoint = new MyPoint(*p);
    }
    MyPoint& getSpecialPoint(){
        return *specialPoint;
    }
    void setBound(float xLeft, float xRight){
        boundXLeft = xLeft;
        boundXRight = xRight;
    }
    
    bool colisionAvecMur(bool right){
        if(right){
            return (boundXRight-specialPoint->x<= 0.001f);
        }
        return (specialPoint->x - boundXLeft <= 0.001f);
    }
    
    
    bool colision(Forme& forme){
            return (estSurLaMemeLigne(forme) && (specialPoint->x + forme.getWidth()) - forme.getSpecialPoint().x
                    <= forme.getWidth());
    }
    
    bool estSurLaMemeLigne(Forme& forme){
        if((forme.getSpecialPoint().y >= 0 && specialPoint->y >= 0)
           ||
           (forme.getSpecialPoint().y < 0 && specialPoint->y < 0))
        { //si c'est sur le meme y
            float res = abs(forme.getSpecialPoint().y - specialPoint->y);
            if(res >= 0 && res <= 0.1f)
            {
                return true;
            }
        }
        return false;
    }
    std::vector<float> x;
    std::vector<float> y;
    void setWidth(float w){
        width = w;
    }
    float getWidth(){
        return width;
    }
private:
    MyColor* color;
    MyPoint* specialPoint;
    float boundXRight;
    float boundXLeft;
    float width;
    
};
/* Forme_h */
