//
//  MyColor.h
//  TP3
//
//  Created by Tran Thanh Long on 20/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#pragma once
class MyColor{
public:
    float r;
    float g;
    float b;
    MyColor(float r_, float g_, float b_): r(r_), g(g_), b(b_){};
    MyColor(MyColor const& color): r(color.r), g(color.g), b(color.b){};
    ~MyColor(){};
};
/* MyColor_h */
