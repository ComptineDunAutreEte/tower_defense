
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float const width = glutGet(GLUT_WINDOW_WIDTH);
        float const height = glutGet(GLUT_WINDOW_HEIGHT);
        
        float x_ = (-(width/2)+x)/(width/2);
        float y_ = (-(height/2)+y)/(height/2);
        std::cout << x_ << "x y" << y_<<std::endl;
        
        if(x_ >= -0.3f && x_ <= 1.0f && y_ <= 0.63f && y_ >= -0.63f ){
            if(terrain != NULL && niveauVaisseau != 0){
                Case* c = terrain->getCasePosition(x, y);
                if(c != NULL){
                    terrain->addVaisseau(Factory::getInstance()->createVaisseau(*c->getCentre(), (float)(terrain->get_case_size()/4), niveauVaisseau));
                }
            }
        }

        else if(x_ >= -0.9f && x_ <= -0.5f && y_ >= 0.75f && y_ <= 0.85f ){
            if(!butCommencerClicked){
                terrain->isRunning = true;
                butCommencerClicked = true;
            }
            else{
                butCommencerClicked = false;
                terrain->isRunning = false;
            }
            
        }else if(x_ >= -0.9f && x_ <= -0.7f && y_ <= 0.2f && y_ >= 0.0f ){
            niveauVaisseau = 3;
        }else if(x_ >= -0.9f && x_ <= -0.7f && y_ <= -0.1f && y_ >= -0.3f ){
            niveauVaisseau = 2;
        }else if(x_ >= -0.9f && x_ <= -0.7f && y_ <= -0.4f && y_ >= -0.6f ){
            niveauVaisseau = 1;
        }
    }
}
