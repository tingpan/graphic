//
//  lamp.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "lamp.hpp"

Lamp::Lamp(float h) : _height(h)
{
    _texLamp = Scene::GetTexture("./Textures/Environment/lamp.bmp");
    _texS1 = Scene::GetTexture("./Textures/Environment/lam_stone.bmp");
    _texS2 = Scene::GetTexture("./Textures/Environment/lam_stone2.bmp");
}

Lamp::~Lamp()
{

}

void Lamp::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    drawBrickT(3, 3, 1, _texS1, 1);
    glTranslatef(1, 1, -1);
    drawBrickT(1, 1, _height, _texS1, 1);
    glTranslatef(-0.5,_height, 0.5);
    drawBrickT(2, 2, 0.8, _texS2, 1);
    glTranslatef(0.25, 0.8, -0.25);
    drawBrickT(1.5, 1.5, 0.3, _texS2, 1);
    glTranslatef(0.25, 0.3, -0.25);
    drawBrickT(1, 0.8, 1, _texS2, 1);
    glTranslatef(-1, 0.8, 0);
    drawBrickT(1, 3, 1, _texS2, 1);
    
    glTranslatef(-3, 0, 1);
    DrawLamp();
    glTranslatef(6, 0, 0);
    DrawLamp();
    
    SetupLight();
    
    
    glPopAttrib();
    glPopMatrix();
}

void Lamp::DrawLamp()
{
    glPushMatrix();
    {
        drawBrickT(3, 3, 1, _texS2, 1);
        glTranslatef(0, 1, 0);
        glPushMatrix();
        {
            glScalef(3, 3, 3);
            drawBrickT(1, 1, 1, _texLamp, -1);
        }
        glPopMatrix();
        glTranslatef(0, 3, 0);
        drawBrickT(3, 3, 1, _texS2, 1);
    }
    glPopMatrix();
}

void Lamp::SetupLight()
{
    
}
