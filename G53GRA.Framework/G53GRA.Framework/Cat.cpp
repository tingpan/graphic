//
//  Cat.cpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Cat.hpp"
Cat::Cat(){
    Body = Scene::GetTexture("./Textures/Cats/cat1/Body.bmp");
    Face = Scene::GetTexture("./Textures/Cats/cat1/Face.bmp");
    Head = Scene::GetTexture("./Textures/Cats/cat1/Head.bmp");
    LeftHand = Scene::GetTexture("./Textures/Cats/cat1/LeftHand.bmp");
    LeftLeg = Scene::GetTexture("./Textures/Cats/cat1/LeftLeg.bmp");
    Leg = Scene::GetTexture("./Textures/Cats/cat1/Leg.bmp");
    RightHand = Scene::GetTexture("./Textures/Cats/cat1/RightHand.bmp");
    RightLeg = Scene::GetTexture("./Textures/Cats/cat1/RightLeg.bmp");
    Back = Scene::GetTexture("./Textures/Cats/cat1/Back.bmp");
    Hand = Scene::GetTexture("./Textures/Cats/cat1/Hand.bmp");
}

void Cat::Display() {
    glPushMatrix();
    {
        setWallColor(255, 255, 255, 20);
        drawBrickRT(16, 16, 48, Leg);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 16, 48, LeftLeg);
        glTranslatef(16, 0, -1);
        drawBrickRT(16, 16, 48, Leg);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 16, 48, RightLeg);
        glTranslatef(-16, 48, -1);
        drawBrickRT(16, 32, 48, Back);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 32, 48, Body);
        glTranslatef(-16, 0, -1);
        drawBrickRT(16, 16, 48, Hand);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 16, 48, LeftHand);
        glTranslatef(48, 0, -1);
        drawBrickRT(16, 16, 48, Hand);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 16, 48, RightHand);
        glTranslatef(-32, 48, -1);
        drawBrickRT(16, 32, 32, Head);
        glTranslatef(0, 0, 1);
        drawBrickRT(1, 32, 32, Face);
    }
    glPopMatrix();

}
