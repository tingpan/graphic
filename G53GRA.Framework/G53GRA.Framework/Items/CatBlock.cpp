//
//  CatBlock.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "CatBlock.hpp"

CatBlock::CatBlock(): width(10), height(10), time(0.0), runAnimate(true), dx(4.0f)
{
    _blockTex = Scene::GetTexture("./Textures/Environment/glass.bmp");
    _catTex = Scene::GetTexture("./Textures/Environment/cats.bmp");
    spriteFrame = 0;
    spriteWidth = 8;
}

CatBlock::~CatBlock()
{
    
}


void CatBlock::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    
//    glEnable(GL_COLOR_MATERIAL);
//    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    drawBrickT(10, 10, 10, _blockTex,1);
    
    glTranslatef(0, 0, 0.001);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _catTex);
//    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPushMatrix();
    {
        glScalef(10, 10, 10);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glNormal3f(0.0f, 0.0f, 0.0f);
        
        glTexCoord2d(texCoords[0], texCoords[1]); // Texture coordinate index into the top left sprite coord
        glVertex3f(0, 1, 0.0f);    // Vertex coordinate of the top left of the quad
        
        glTexCoord2d(texCoords[2], texCoords[3]); // Texture coordinate index into the bottom left sprite coord
        glVertex3f(-0, 0.0f, 0.0f);       // Vertex coordinate of the bottom left of the quad
        
        glTexCoord2d(texCoords[4], texCoords[5]); // Texture coordinate index into the bottom right sprite coord
        glVertex3f(1, 0.0f, 0.0f);        // Vertex coordinate of the bottom right of the quad
        
        glTexCoord2d(texCoords[6], texCoords[7]); // Texture coordinate index into the top right sprite coord
        glVertex3f(1, 1, 0.0f);     // Vertex coordinate of the top right of the quad
        glEnd();
    }
    
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, NULL); // Bind to the blank (null) buffer to stop ourselves accidentaly using the wrong texture in the next draw call
    
    glDisable(GL_TEXTURE_2D);
    
    glDisable(GL_COLOR_MATERIAL);
    
    glPopAttrib();
    glPopMatrix();
    
}

void CatBlock::Update(const double& deltaTime)
{
    float sCoord;
    time += deltaTime;
    
    if (runAnimate)
    {
        if (time > 0.1)
        {
            spriteFrame = spriteFrame > 6 ? 0 : spriteFrame + 1; // shift frame up by 1 (wrap at 7)
            time = 0.0; // reset frame counter
        }
    }
    
    if (dx > 0.0f) // if he is running right, from spriteFrame to spriteFrame+1
        sCoord = (float)spriteFrame / (float)spriteWidth;
    else // if he is running left FLIP the coords to avoid needing more sprite sheets
        sCoord = (float)(spriteFrame + 1) / (float)spriteWidth;
    
    texCoords[0] = sCoord; // (s,t) texture coord at [0, 1]
    texCoords[1] = 1.0f;
    
    texCoords[2] = sCoord; // (s,t) texture coord at [0, 0]
    texCoords[3] = 0.0f;
    
    if (dx > 0.0) // if he is running right, from spriteFrame to spriteFrame+1
        sCoord = (float)(spriteFrame + 1) / (float)spriteWidth;
    else // if he is running left FLIP the coords to avoid needing more sprite sheets
        sCoord = (float)spriteFrame / (float)spriteWidth;
    
    texCoords[4] = sCoord; // (s,t) texture coord at [1, 0]
    texCoords[5] = 0.0f;
    
    texCoords[6] = sCoord; // (s,t) texture coord at [1, 1]
    texCoords[7] = 1.0f;
    
}