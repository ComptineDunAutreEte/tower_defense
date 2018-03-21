//
//  Factory.cpp
//  generical_libGraphProject
//
//  Created by Thanh Long Tran on 06/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//

#include "Factory.h"

Factory* Factory::m_i = NULL;

Factory* Factory::getInstance() {
    if (m_i == NULL) {
        m_i= new Factory();
    }
    return m_i;
}

Case* Factory::createCase(float x, float y, float size){
    Case* c = new Case(1.0f, 1.0f, 0.878f, x, y, size);
    return c;
}

Vaisseau* Factory::createVaisseau(MyPoint& point, float size, int niveau){
    MyColor* color;
    int frequence;// à combien de tick il doit tirer
    int compteur;//nbr de missiles...
    
    
    if(niveau == 1){
        color = FactoryForm::getInstance()->createColor(1.000, 0.498, 0.314);
        frequence = 50;
        compteur = 10;
    }else if(niveau == 2){
        color = FactoryForm::getInstance()->createColor(1.000, 0.388, 0.278);
        frequence = 100;
        compteur = 5;

    }else if(niveau == 3){
        color = FactoryForm::getInstance()->createColor(1.000, 0.271, 0.000);
        frequence = 150;
        compteur = 3;
    }else{
        color = FactoryForm::getInstance()->createColor(1.000, 0.498, 0.314);
        frequence = 50;
        compteur = 10;
    }
    
    Forme* t = FactoryForm::getInstance()->createTriangle(point, size, color);
    Vaisseau* v =new Vaisseau(t);
    v->setNiveau(niveau);
    v->setCompteur(compteur);
    v->setFrequence(frequence);
    return v;
}

Asteroid* Factory::createAsteroid(MyPoint& point, float size, int niveau){
    Forme* p = FactoryForm::getInstance()->createPolygone(point, size, niveau);
    int vie;
    bool seDedouble;
    float vitesse;
    if(niveau == 1){
        vie = 5;
        seDedouble = false;
        vitesse = 0.001f;
    }else if(niveau == 3){
        vie = 5;
        seDedouble = true;
        vitesse = 0.005f;
    }else if(niveau == 2){
        vie = 8;
        seDedouble = true;
        vitesse = 0.0005f;
    }else{
        vie = 5;
        seDedouble = false;
        vitesse = 0.001f;
    }
    p->setBound(-0.3f, 1.0f);
    Asteroid* a = new Asteroid(p);
    a->setVie(vie);
    a->setVitesse(vitesse);
    a->setDedouble(seDedouble);
    a->setNiveau(niveau);
    return a;
}

/*
Rectangle* Factory::createRectangle(MyColor* color){
    Rectangle* rectangle = new Rectangle(color);
    return rectangle;
}
MyColor* Factory::createColor(float r, float g, float b){
    return new MyColor(r, g, b);
}
Triangle* Factory::createTriangle(MyPoint& point, float size, MyColor* color){
    Triangle* triangle = new Triangle(color);
    triangle->p1 = new MyPoint(point.x+size, point.y);
    triangle->p2 = new MyPoint(point.x-size, point.y-size);
    triangle->p3 = new MyPoint(point.x-size, point.y+size);
    return triangle;
}*/




