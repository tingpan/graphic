//
//  Parterre.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "Parterre.hpp"

Parterre::Parterre(int w, int h, GLuint tex)
{
    _width = w;
    _height = h;
    _texFlower = tex;
    _texBrick = Scene::GetTexture("./Textures/Environment/brick2.bmp");
}
Parterre::~Parterre()
{
    
}

void Parterre::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    drawBrickT(1, _width, 1, _texBrick, 1);
    
    for (int i = 0; i < 3; i ++)
    {
        glTranslatef(-1, 0, -1);
        glPushMatrix();
        {
            drawBrickT(1, 1, 1, _texBrick, 1);
            glTranslatef(1, 0, 0);
            drawBrickT(1, _width + 2 * i, _height, _texFlower, 1);
            glTranslatef(_width + 2 * i, 0, 0);
            drawBrickT(1, 1, 1, _texBrick, 1);
        }
        glPopMatrix();
    }
    
    glTranslatef(-1, 0, 0);
    
    for (int i = 0; i < 3; i ++)
    {
        glTranslatef(1, 0, -1);
        glPushMatrix();
        {
            drawBrickT(1, 1, 1, _texBrick, 1);
            glTranslatef(1, 0, 0);
            drawBrickT(1, _width + 2 * (2 - i), _height, _texFlower, 1);
            glTranslatef(_width + 2 * (2 - i), 0, 0);
            drawBrickT(1, 1, 1, _texBrick, 1);
        }
        glPopMatrix();
    }
    
    glTranslatef(1, 0, -1);
    drawBrickT(1, _width, 1, _texBrick, 1);
    
    glPopAttrib();
    glPopMatrix();
    
}
