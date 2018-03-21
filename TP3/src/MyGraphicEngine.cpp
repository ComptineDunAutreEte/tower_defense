
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    
    for(Forme *f : formes){
        f->draw();
    }
    terrain->draw();
    if(terrain->getGameOver()){
        GraphicPrimitives::drawText2D(stringToChar(string("GAME OVER!")),-0.8f,0.9f,1.0f,1.0f, 1.0f);
    }
    GraphicPrimitives::drawText2D(argentLabel(terrain->getArgent()),0.5f,0.9f,1.0f,1.0f, 1.0f);
    
    MyPoint* p = new MyPoint(-0.65f,0.48f);
    GraphicPrimitives::drawText2D(stringToChar(string("-5$")),p->x,p->y,1.0f,1.0f, 1.0f);
    p->y-=0.3f;
    GraphicPrimitives::drawText2D(stringToChar(string("-10$")),p->x,p->y,1.0f,1.0f, 1.0f);
    p->y-=0.3f;
    GraphicPrimitives::drawText2D(stringToChar(string("-15$")),p->x,p->y,1.0f,1.0f, 1.0f);
    p->y=0.7f;
    p->x=-0.9f;
    GraphicPrimitives::drawText2D(stringToChar(string("Choisissez un vaisseau!")),p->x,p->y,1.0f,1.0f, 1.0f);
    
    p->y=-0.82f;
    p->x=-0.8f;
    if(terrain->isRunning){
        GraphicPrimitives::drawText2D(stringToChar(string("Pause")),p->x,p->y,0,0,0);
    }
    else{
        GraphicPrimitives::drawText2D(stringToChar(string("Commencer")),p->x,p->y,0,0,0);
    }
    
    delete p;
}


char* MyGraphicEngine::argentLabel(int argent){
    string text ("Argent: ");
    text+=to_string(argent);
    text+=" $";
    char const *pchar = text.c_str();
    char* tmp = new char[strlen(pchar)+1];
    strcpy(tmp, text.c_str());
    return tmp;
}

char* MyGraphicEngine::stringToChar(string str){
    char const *pchar = str.c_str();
    char* tmp = new char[strlen(pchar)+1];
    strcpy(tmp, str.c_str());
    return tmp;
}


void MyGraphicEngine::buildInterface(){
    MyPoint *p = new MyPoint(-1.0f, 0.0f);
    Forme *leftPane = FactoryForm::getInstance()->createRectangle(*p,2.0f , 0.60f, new MyColor(0.133, 0.545, 0.133));
    
    
    p->x = -0.8f;
    p->y =0.5f;
    Forme *v1 = FactoryForm::getInstance()->createTriangle(*p, 0.1f, new MyColor(1.000, 0.498, 0.314f) );
    
    p->y-=0.3f;
    Forme *v2 = FactoryForm::getInstance()->createTriangle(*p, 0.1f, new MyColor(1.000, 0.388, 0.278f) );
    
    p->y-=0.3f;
    Forme *v3 = FactoryForm::getInstance()->createTriangle(*p, 0.1f, new MyColor(1.000, 0.271, 0.000) );
    
    p->x = -0.9f;
    p->y =-0.8f;
    Forme *buttonCommencer = FactoryForm::getInstance()->createRectangle(*p, 0.2f, 0.4f, new MyColor(1,1,1));
    
    formes.push_back(leftPane);
    formes.push_back(v1);
    formes.push_back(v2);
    formes.push_back(v3);
    formes.push_back(buttonCommencer);
}
void MyGraphicEngine::drawPaneUnder(){
    
}
void MyGraphicEngine::drawPaneRight(){
    
}
void MyGraphicEngine::drawPaneUp(){
    
}
