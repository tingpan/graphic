//
//  CatBlock.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class creates the animated cat cube.

#include "CatBlock.hpp"

CatBlock::CatBlock() : time(0.0), runAnimate(true), spriteFrame(0), spriteWidth(8)
{
    // load textures
    _blockTex = Scene::GetTexture("./Textures/Environment/glass.bmp");
    _catTex = Scene::GetTexture("./Textures/Roles/cats.bmp");
}

CatBlock::~CatBlock()
{

}


void CatBlock::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(scale[0], scale[1], scale[2]);
        glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
        
        // set the base color with alpha channel
        glEnable(GL_COLOR_MATERIAL);
        glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
        
        // draw the bricks
        drawBrickT(10, 10, 10, _blockTex, 1);
        
        // draw the front cat texture
        glTranslatef(0, 0, 0.002);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _catTex);
        
        glPushMatrix();
        {
            glScalef(10, 10, 10);
            glColor3f(1.0f, 1.0f, 1.0f);
            
            glBegin(GL_QUADS);
            {
                glNormal3f(0.0f, 0.0f, 0.0f);
                
                glTexCoord2d(texCoords[0], texCoords[1]);
                glVertex3f(0, 1, 0.0f);
                
                glTexCoord2d(texCoords[2], texCoords[3]);
                glVertex3f(-0, 0.0f, 0.0f);
                
                glTexCoord2d(texCoords[4], texCoords[5]);
                glVertex3f(1, 0.0f, 0.0f);
                
                glTexCoord2d(texCoords[6], texCoords[7]);
                glVertex3f(1, 1, 0.0f);
            }
            glEnd();
        }
        glPopMatrix();
        glBindTexture(GL_TEXTURE_2D,
                      NULL); // Bind to the blank (null) buffer to stop ourselves accidentaly using the wrong texture in the next draw call
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_COLOR_MATERIAL);
    }

    glPopAttrib();
    glPopMatrix();

}

void CatBlock::Update(const double &deltaTime)
{
    float sCoord;
    time += deltaTime;

    // the animation is not paused
    if (runAnimate)
    {
        if (time > 0.1)
        {
            spriteFrame = spriteFrame > 8 ? 0 : spriteFrame + 1;
            time = 0.0; // reset frame counter
        }
    }

    // increase the coordinate by 1 frame every 0.1s
    sCoord = (float) spriteFrame / (float) spriteWidth;

    texCoords[0] = sCoord; // (s,t) texture coord at [0, 1]
    texCoords[1] = 1.0f;

    texCoords[2] = sCoord; // (s,t) texture coord at [0, 0]
    texCoords[3] = 0.0f;

    sCoord = (float) (spriteFrame + 1) / (float) spriteWidth;

    texCoords[4] = sCoord; // (s,t) texture coord at [1, 0]
    texCoords[5] = 0.0f;

    texCoords[6] = sCoord; // (s,t) texture coord at [1, 1]
    texCoords[7] = 1.0f;
}

void CatBlock::HandleKey(unsigned char key, int state, int x, int y)
{
    // pause the animation with 'r' key
    if (key == 'r' && state)
    {
        runAnimate = !runAnimate;
        if (!runAnimate) spriteFrame = 0;
    }
}

void CatBlock::HandleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON || button == GLUT_MIDDLE_BUTTON) // right or middle button press
    {
        if (state)
        {
            // when release the mouse, play the animation
            runAnimate = true;
            spriteFrame = 0;
        } else
        {
            // show a special frame when holding the mouse
            spriteFrame = 6;
            runAnimate = false;
        }
    }
}
