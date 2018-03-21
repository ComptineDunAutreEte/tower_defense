//
//  FactoryForm.cpp
//  TP3
//
//  Created by Tran Thanh Long on 20/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#include "FactoryForm.h"
FactoryForm* FactoryForm::mf_i = NULL;

FactoryForm* FactoryForm::getInstance() {
    if (mf_i == NULL) {
        mf_i= new FactoryForm();
    }
    return mf_i;
}

Forme* FactoryForm::createRectangle(MyPoint& point, float height, float width, MyColor* color){
    Forme* rectangle = new Forme(color);
    
    float yDepart = point.y-(height/2.0f);
    
    rectangle->x.push_back(point.x);
    rectangle->y.push_back(yDepart);
    
    rectangle->x.push_back(point.x);
    rectangle->y.push_back(yDepart + height);
    
    rectangle->x.push_back(point.x + width);
    rectangle->y.push_back(yDepart);
    
    rectangle->x.push_back(point.x + width);
    rectangle->y.push_back(yDepart + height);
    
    MyPoint* specialPoint = new MyPoint(point.x + width, point.y );
    
    rectangle->setSpecialPoint(specialPoint);
    rectangle->setWidth(width);
    return rectangle;
}
MyColor* FactoryForm::createColor(float r, float g, float b){
    return new MyColor(r, g, b);
}
Forme* FactoryForm::createTriangle(MyPoint& point, float size, MyColor* color){
    Forme* triangle = new Forme(color);
    
    MyPoint* specialPoint = new MyPoint(point.x+size,point.y);
    
    triangle->x.push_back(specialPoint->x);
    triangle->y.push_back(specialPoint->y);
    
    
    triangle->x.push_back(point.x-size);
    triangle->y.push_back(point.y-size);
    
    
    triangle->x.push_back(point.x-size);
    triangle->y.push_back(point.y+size);
    
    triangle->setSpecialPoint(specialPoint);
    triangle->setWidth(2*size);
    /*
    triangle->p1 = new MyPoint(point.x+size, point.y);
    triangle->p2 = new MyPoint(point.x-size, point.y-size);
    triangle->p3 = new MyPoint(point.x-size, point.y+size);*/
    return triangle;
}

Forme* FactoryForm::createHeart(MyPoint& point, float size){
    float pas = size/6;
    float x = point.x;
    float y = point.y;
    Forme* heart = new Forme(createColor(1.000, 0.000, 0.000));
    
    x = point.x;
    y = point.y+pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    x -= pas;
    y +=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    y -=pas;
    x -= pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    y -=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    
    x += pas;
    y -=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    
    x += pas;
    y -=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    x += pas;
    y +=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    x += pas;
    y +=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    
    y +=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
    
    x -= pas;
    y +=pas;
    heart->x.push_back(x);
    heart->y.push_back(y);

    //*stop here
   
    
    x = point.x;
    y = point.y+pas;
    heart->x.push_back(x);
    heart->y.push_back(y);
  
    
    return heart;
}

Forme* FactoryForm::createPolygone(MyPoint& point, float size, int niveau){
    Forme* polygone;
    if(niveau == 1){
        polygone = new Forme(createColor(0.561, 0.737, 0.561));
    }else if(niveau == 2){
        polygone = new Forme(createColor(0.125, 0.698, 0.667));
    }else{
        polygone = new Forme(createColor(0.000, 0.545, 0.545));
    }
    
    float grid = size/3.0f;
    float innersquare = grid/2.0f;
    float outersquare = size/2.0f;
    //1
    polygone->x.push_back(point.x);
    polygone->y.push_back(point.y-outersquare);
    //2
    polygone->x.push_back(point.x+innersquare);
    polygone->y.push_back(point.y-innersquare);
    //3
    polygone->x.push_back(point.x+outersquare);
    polygone->y.push_back(point.y);
    //4
    polygone->x.push_back(point.x+innersquare);
    polygone->y.push_back(point.y+innersquare);
    //5
    polygone->x.push_back(point.x);
    polygone->y.push_back(point.y+outersquare);
    
    //6
    polygone->x.push_back(point.x-innersquare);
    polygone->y.push_back(point.y+innersquare);
    //7
    MyPoint* specialpoint = new MyPoint(point.x-outersquare, point.y);
    polygone->x.push_back(specialpoint->x);
    polygone->y.push_back(specialpoint->y);
    //8
    polygone->x.push_back(point.x-innersquare);
    polygone->y.push_back(point.y-innersquare);
    //std::cout<<polygone->x.size()<< "hello its me"<< polygone->y.size()<<std::endl;
    polygone->setSpecialPoint(specialpoint);
    polygone->setWidth(size);
    return polygone;
}
Missile* FactoryForm::createMissile(MyPoint& point, int niveau){
    MyColor* color = createColor(0.118, 0.565, 1.000);
    float height;
    float width;
    int puissance;
    float vitesse;
    if(niveau == 1){
        height = 0.01f;
        width = 0.02f;
        vitesse = 0.02f;
        puissance = 1;
    }else if (niveau == 2){
        height = 0.02f;
        width = 0.04f;
        vitesse = 0.002f;
        puissance = 3;
    }else if (niveau == 3){
        height = 0.03f;
        width = 0.04f;
        vitesse = 0.001f;
        puissance = 5;
    }else{
        height = 0.01f;
        width = 0.02f;
        vitesse = 0.01;
        puissance = 1;
    }
    
    
    
    Forme* rect = createRectangle(point, height, width, color);
    rect->setBound(-0.3f, 1.0f);
    Missile* m = new Missile(puissance, vitesse
                             ,rect);
    return m;
}




