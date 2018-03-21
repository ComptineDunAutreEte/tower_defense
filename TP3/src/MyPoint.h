//
//  MyPoint.h
//  TowerDefenseTTL
//
//  Created by Thanh Long Tran on 10/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#pragma once
#include <iostream>
//using namespace std;
class MyPoint{
public:
    MyPoint(float x_, float y_):x(x_), y(y_){}
    MyPoint(MyPoint const& point):x(point.x), y(point.y){
        std::cout<<"copy point: specX: "<<x<<" specY: "<<y<<std::endl;
    }
    ~MyPoint(){};
    float x;
    float y;
};/* MyPoint_h */
