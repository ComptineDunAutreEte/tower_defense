//
//  AbstractItem.h
//  TP3
//
//  Created by Tran Thanh Long on 23/12/2017.
//  Copyright © 2017 Thanh Long Tran. All rights reserved.
//

#pragma once
#include "Forme.h"
class AbstractItem{
public:
    AbstractItem(Forme* forme_):forme(forme_){
        est_destruite = false;
        //forme = forme_;
    }
    virtual ~AbstractItem(){
        delete forme;
        std::cout<<"destructeur AbstractItem"<<std::endl;
    }
    bool estDestruite(){
        return est_destruite;
    }
    void setEstDestruite(bool b){
        est_destruite = b;
    }
    virtual void draw()=0;
    virtual void tick()=0;
    Forme& getForme(){
        return *forme;
    }
    void setForme(Forme* forme_){
        forme = forme_;
    }
    
protected:
    Forme* forme;
    bool est_destruite;
};

/* AbstractItem_h */
