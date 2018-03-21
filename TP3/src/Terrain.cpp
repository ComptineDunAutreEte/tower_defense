//
//  Terrain.cpp
//  generical_libGraphProject
//
//  Created by Thanh Long Tran on 06/12/2017.
//  Copyright © 2017 Tran Thanh Long. All rights reserved.
//
#include "Terrain.h"
void Terrain::build(){
    Factory* fact = Factory::getInstance();
    float x1 = -0.3f;
    float y1 = 0.5f;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            cases.push_back(fact->createCase(x1, y1, case_size));
            x1+=0.13f;
        }
        x1=-0.3f;
        y1-=0.13f;
    }
}

void Terrain::draw(){
    for (int i = 0; i < cases.size(); i++)  {
        cases[i]->draw();
    }
    for(int i = 0; i<vaisseaux.size(); i++){
        vaisseaux[i]->draw();
    }
    
    for(int i = 0; i<asteroids.size(); i++){
        asteroids[i]->draw();
    }
    for(int i = 0; i < missiles.size(); i++){
        missiles[i]->draw();
    }
    
    for(int i = 0; i < vies.size(); i++){
        vies[i]->draw();
    }
    
}

void Terrain::tick(){
    
    std::vector<Asteroid*> doubles;
    if(asteroids.empty()){
        generateAsteroids();
    }
    for(int i = 0; i < asteroids.size(); i++){
        asteroids[i]->tick();
        for(int j = 0; j < vaisseaux.size(); j++){
            if(asteroids[i]->getForme().colision(vaisseaux[j]->getForme())){
                asteroids[i]->setEstDestruite(true);
                asteroids[i]->setCoeur(1);
                vaisseaux[j]->setEstDestruite(true);
            }
        }
    }
    menage();
    for(int i = 0; i < vaisseaux.size(); i++){
        vaisseaux[i]->tick();
        for(Missile *m : vaisseaux[i]->getMissiles()){
            for(Asteroid *a:asteroids){
                if(a->getForme().colision(m->getForme())){
                    m->setEstDestruite(true);
                    std::cout<<"missile en colision avec asteroid"<<std::endl;
                    if(a->isDedouble()){
                        a->setDedouble(false);
                        if(a->getNiveau() == 2){
                            if((a->getForme().getSpecialPoint().y - 0.13f ) > (-0.63f)){
                                Asteroid *a_ = new Asteroid(*a);
                                a_->setDedouble(false);
                                a_->moveDown();
                                doubles.push_back(a_);
                            }else if((a->getForme().getSpecialPoint().y + 0.13) < (0.5f)){
                                Asteroid *a_ = new Asteroid(*a);
                                a_->moveUp();
                                doubles.push_back(a_);
                            }
                        }else if(a->getNiveau() == 3){
                            if((a->getForme().getSpecialPoint().x - 0.13f ) > (-1.0f)){
                                Asteroid *a_ = new Asteroid(*a);
                                a_->moveLeft();
                                doubles.push_back(a_);
                            }
                        }
                        
                    }else{
                        a->setVie(a->getVie() - m->getPuissance());
                    }
                }
            }
        }
        
    }
    while(!doubles.empty()){
        asteroids.push_back(doubles.at(0));
        doubles.erase(doubles.begin());
    }
    
    /*ménage des items lorsqu'ils sont destruits*/
    menage();
    if(vies.empty()){
        isRunning = false;
        GamesOver = true;
    }
}

void Terrain::menage(){
    for (std::vector< Vaisseau* >::iterator it = vaisseaux.begin() ; it != vaisseaux.end(); ++it)
    {
        if((*it)->estDestruite()){
            delete (*it);
            vaisseaux.erase(it);
            break;
        }
    }
    for (std::vector< Asteroid* >::iterator it = asteroids.begin() ; it != asteroids.end(); ++it)
    {
        if((*it)->estDestruite()){
            if((*it)->getCoeur() == -1){
                if(!vies.empty()){
                    vies.pop_back();
                }
            }else if((*it)->getCoeur() == 0){
                if((*it)->getNiveau() == 3){
                    argent += 15;
                }else if((*it)->getNiveau() == 2){
                    argent += 10;
                }else{
                    argent += 5;
                }
            }
            delete (*it);
            asteroids.erase(it);
            break;
        }
    }
}
Case* Terrain::getCasePosition(float x, float y){
    int indice = convert(x, y);
    Case* c = NULL;
    if(indice >= 0 && indice < cases.size()){
        c = cases.at(indice);
    }
    
    return c;
}

int Terrain::convert(float a, float b){
    float const width = glutGet(GLUT_WINDOW_WIDTH);
    float const height = glutGet(GLUT_WINDOW_HEIGHT);
    
    float real_size_caseW = (case_size*width/2.0f);
    float real_size_caseH = (case_size*(height/2.0f));
    
    float toLeft = width - (width*1.3f/2.0f);
    float toTop = height - (height*1.3f/1.6f);
    
    int indiceX = (int)((a-toLeft)/real_size_caseW);
    int indiceY = (int)((b-toTop)/real_size_caseH);
    return indiceY*taille+indiceX;
}

void Terrain::addVaisseau(Vaisseau* vaisseau){
    bool sur_la_meme_ligne = false;
    for(Vaisseau *v : vaisseaux){
        if(v->getForme().estSurLaMemeLigne(vaisseau->getForme())){
            sur_la_meme_ligne = true;
            break;
        }
    }
    if(!sur_la_meme_ligne && argent >0){
        if(vaisseau->getNiveau()==1){
            if(argent - 5 >= 0){
                vaisseaux.push_back(vaisseau);
                argent-=5;
            }
        }
        else if(vaisseau->getNiveau()==2){
            if(argent - 10 >= 0){
                vaisseaux.push_back(vaisseau);
                argent-=10;
            }
        }
        else{
            if(argent - 15 >= 0){
                vaisseaux.push_back(vaisseau);
                argent-=15;
            }
        }
    }
    
    
}

float Terrain::get_case_size(){
    return case_size;
}

void Terrain::generateAsteroids(){
    int nbr = 1+ rand()%5;
    std::vector<int> v;
    while(nbr>0){
        int niv = 1+rand()%3;
        int laCase;
        if(niv == 2){
            laCase = 1+rand()%8;
        }else{
            laCase = rand()%10;
        }
        bool existe = false;
        
        for(int i = 0; i < v.size(); i++){
            if(niv==2){
                if(v[i]==laCase-10 || v[i]==laCase+10 || v[i]==laCase){
                    existe = true;
                }
            }
            else if(v[i]==laCase)
                existe = true;
        }
        
        if(!existe){
            v.push_back(laCase);
            //std::cout<<"la case choisit"<<laCase*10+9<<std::endl;
            Asteroid * a= Factory::getInstance()->createAsteroid(*(cases[laCase*10+9]->getCentre()), (float)case_size/3, niv);
            asteroids.push_back(a);
            nbr--;
        }
    }
}
void Terrain::buildVies(){
    MyPoint *p = new MyPoint(0.9f, 0.8f);
    Forme *coeur = FactoryForm::getInstance()->createHeart(*p, 0.12f);
    
    p->x -= 0.12f;
    Forme *coeur1 = FactoryForm::getInstance()->createHeart(*p, 0.12f);
    
    
    p->x -= 0.12f;
    Forme *coeur2 = FactoryForm::getInstance()->createHeart(*p, 0.12f);
    
    
    p->x -= 0.12f;
    Forme *coeur3 = FactoryForm::getInstance()->createHeart(*p, 0.12f);
    
    p->x -= 0.12f;
    Forme *coeur4 = FactoryForm::getInstance()->createHeart(*p, 0.12f);
    
    
    vies.push_back(coeur);
    vies.push_back(coeur1);
    vies.push_back(coeur2);
    vies.push_back(coeur3);
    vies.push_back(coeur4);
}
