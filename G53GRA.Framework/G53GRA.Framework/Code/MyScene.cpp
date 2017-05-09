#include "MyScene.h"
#include "MyFloor.hpp"
#include "MySunlight.hpp"
#include "MySkybox.hpp"
#include "TowerA.hpp"
#include "TowerB.hpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.44f, 0.72f, 1.0f);
    
   
    
    MyFloor *floor = new MyFloor();
    floor->size(8);
    floor->position(-1600, -50, 200);
    AddObjectToScene(floor);
    
    MySunlight *sl = new MySunlight();
    sl->direction(1.0f, 1.0f, 1.0f);
    AddObjectToScene(sl);
    
    GLuint tf = Scene::GetTexture("./Textures/Skybox/up.bmp");
    GLuint bf = Scene::GetTexture("./Textures/Skybox/down.bmp");
    GLuint lf = Scene::GetTexture("./Textures/Skybox/left.bmp");
    GLuint rf = Scene::GetTexture("./Textures/Skybox/right.bmp");
    GLuint nf = Scene::GetTexture("./Textures/Skybox/back.bmp");
    GLuint ff = Scene::GetTexture("./Textures/Skybox/front.bmp");
    
    MySkybox *skybox = new MySkybox(tf, bf, lf, rf, nf, ff);
    skybox->position(0.f, 0.f, 0.f);
    skybox->size(10000.0f, 10000.0f,10000.0f);
    AddObjectToScene(skybox);

    TowerA *towerA = new TowerA();
    towerA->size(8);
    towerA->position(-128, -50, -1050);
    AddObjectToScene(towerA);
    
    TowerB *towerB = new TowerB();
    towerB->size(8);
    towerB->position(-282, -50, -1050);
    AddObjectToScene(towerB);
    
    TowerB *towerB2 = new TowerB();
    towerB2->size(8);
    towerB2->position(128, -50, -1050);
    AddObjectToScene(towerB2);

    
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(40.0, aspect, 1.0, 20000.0);
}
