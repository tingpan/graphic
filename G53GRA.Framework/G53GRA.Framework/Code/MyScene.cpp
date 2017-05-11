#include "MyScene.h"
#include "MyFloor.hpp"
#include "MySunlight.hpp"
#include "MySkybox.hpp"
#include "TowerA.hpp"
#include "TowerB.hpp"
#include "TowerC.hpp"
#include "TowerD.hpp"
#include "Tree.hpp"
#include "Cat.hpp"
#include "Parterre.hpp"
#include "CastleWall.hpp"
#include "Water.hpp"
#include "lamp.hpp"
#include "Spotlight.hpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.44f, 0.72f, 1.0f);
    
   
    
    MyFloor *floor = new MyFloor();
    floor->size(32);
    floor->position(-1600, -50, 200);
    AddObjectToScene(floor);
    
    MySunlight *ml = new MySunlight();
    ml->direction(-1.0f, 2.0f, -1.0f);
    AddObjectToScene(ml);
    
    Spotlight *sl = new Spotlight();
    AddObjectToScene(sl);
    
    GLuint tf = Scene::GetTexture("./Textures/Skybox/up.bmp");
    GLuint bf = Scene::GetTexture("./Textures/Skybox/down.bmp");
    GLuint lf = Scene::GetTexture("./Textures/Skybox/left.bmp");
    GLuint rf = Scene::GetTexture("./Textures/Skybox/right.bmp");
    GLuint nf = Scene::GetTexture("./Textures/Skybox/back.bmp");
    GLuint ff = Scene::GetTexture("./Textures/Skybox/front.bmp");
    
    MySkybox *skybox = new MySkybox(tf, bf, lf, rf, nf, ff);
    skybox->position(0.f, 0.f, -1400.f);
    skybox->size(1600.0f, 1600.0f,1600.0f);
    AddObjectToScene(skybox);


    DisplayCastle(8, -1070, -50, -2000);
    DisplayEnvorinment();
    Cat *cat = new Cat();
    cat->position(0, 0, 0);
    cat->size(8);
    AddObjectToScene(cat);
    

    
    Water *water = new Water();
    water->position(0,-50,-1000);
    water->size(32);
    AddObjectToScene(water);
}


void MyScene::DisplayEnvorinment()
{
    
    GLuint flower = Scene::GetTexture("./Textures/Environment/flower.bmp");
    GLuint grass = Scene::GetTexture("./Textures/Environment/grass.bmp");
    
    for (int i = 0; i < 5; i++) {
        GLuint tex = grass;
        float height = 1;
        
        if (i % 2 == 1)
        {
            tex = flower;
            height = 2;
        }
        
        Parterre *parterre = new Parterre(20, height, tex);
        parterre -> size(32);
        parterre -> position(500 + 50 * i, -50, -1390 + 320 * i);
        AddObjectToScene(parterre);
        
        Parterre *parterre2 = new Parterre(20, height, tex);
        parterre2 -> size(32);
        parterre2 -> position(-1140 - 50 * i, -50, -1390 + 320 * i);
        AddObjectToScene(parterre2);
        
        if (i % 2 == 0)
        {
            for (int j = 0; j < 5; j++) {
                Tree *tree = new Tree();
                tree->size(10 + i / 2);
                tree->position(-500 - j * 150 - 50 * i, -50, -1500 + 320 * i);
                AddObjectToScene(tree);
            }
            
            for (int j = 0; j < 5; j++) {
                Tree *tree = new Tree();
                tree->size(10 + i / 2);
                tree->position(500 + j * 150 + 50 * i, -50, -1500 + 320 * i);
                AddObjectToScene(tree);
            }
        }
        
        Lamp *lamp1 = new Lamp(20);
        lamp1 -> position(-500, -50, -1320 + 320 * i);
        lamp1 -> size(10);
        AddObjectToScene(lamp1);
        
        Lamp *lamp2 = new Lamp(20);
        lamp2 -> position(500, -50, -1320 + 320 * i);
        lamp2 -> size(10);
        AddObjectToScene(lamp2);
    }
    
    Lamp *lamp = new Lamp(20);
    lamp -> position(-300, -50, -1800);
    lamp -> size(10);
    AddObjectToScene(lamp);
    
    Lamp *lamp2 = new Lamp(20);
    lamp2 -> position(300, -50, -1800);
    lamp2 -> size(10);
    AddObjectToScene(lamp2);
}

void MyScene::DisplayCastle(float s, float x, float y, float z)
{
    
    CastleWall *wall2 = new CastleWall(50);
    wall2 ->size(s);
    wall2 ->position(x, y, z);
    AddObjectToScene(wall2);
    
    TowerD *towerD1 = new TowerD();
    towerD1 ->size(s);
    towerD1 ->position(x + 400, y, z);
    AddObjectToScene(towerD1);
    
    TowerC *towerC1 = new TowerC();
    towerC1->size(s);
    towerC1->position(x + 596, y, z);
    AddObjectToScene(towerC1);
    
    TowerB *towerB1 = new TowerB();
    towerB1->size(s);
    towerB1->position(x + 788, y, z);
    AddObjectToScene(towerB1);
    
    TowerA *towerA = new TowerA();
    towerA->size(s);
    towerA->position(x + 942, y, z);
    AddObjectToScene(towerA);
    
    TowerB *towerB2 = new TowerB();
    towerB2->size(s);
    towerB2->position(x + 1198, y, z);
    AddObjectToScene(towerB2);
    
    
    TowerC *towerC2 = new TowerC();
    towerC2->size(s);
    towerC2->position(x + 1352, y, z);
    AddObjectToScene(towerC2);
    
    
    TowerD *towerD2 = new TowerD();
    towerD2 ->size(s);
    towerD2 ->position(x + 1544, y, z);
    AddObjectToScene(towerD2);
    
    CastleWall *wall = new CastleWall(50);
    wall ->size(s);
    wall ->position(x + 1740, y, z);
    AddObjectToScene(wall);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(40.0, aspect, 1.0, 20000.0);
}
