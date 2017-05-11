//
//  Cat.cpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Cat.hpp"
#include "VectorMath.h"

Cat::Cat(): _time(0)
{
    
    _texBody = Scene::GetTexture("./Textures/Cats/cat1/Body.bmp");
    _texFace = Scene::GetTexture("./Textures/Cats/cat1/Face.bmp");
    _texFaceSide = Scene::GetTexture("./Textures/Cats/cat1/Head.bmp");
    _texLeftHand = Scene::GetTexture("./Textures/Cats/cat1/LeftHand.bmp");
    _texLeftLeg = Scene::GetTexture("./Textures/Cats/cat1/LeftLeg.bmp");
    _texLegSide = Scene::GetTexture("./Textures/Cats/cat1/Leg.bmp");
    _texRightHand = Scene::GetTexture("./Textures/Cats/cat1/RightHand.bmp");
    _texRightLeg = Scene::GetTexture("./Textures/Cats/cat1/RightLeg.bmp");
    _texBack = Scene::GetTexture("./Textures/Cats/cat1/Back.bmp");
    _texHandSide = Scene::GetTexture("./Textures/Cats/cat1/Hand.bmp");
    
    _headTex[0] = _texFace;
    for (int i = 1; i < 6; i++) {
        _headTex[i] = _texFaceSide;
    }
    
    _bodyTex[0] = _texBody;
    for (int i = 1; i < 5; i++) {
        _bodyTex[i] = _texHandSide;
    }
    _bodyTex[5] = _texBack;
    
    _leftLegTex[0] = _texLeftLeg;
    for (int i = 1; i < 5; i++) {
        _leftLegTex[i] = _texLegSide;
    }
    
    _rightLegTex[0] = _texRightLeg;
    for (int i = 1; i < 5; i++) {
        _rightLegTex[i] = _texLegSide;
    }
    
    _leftHandTex[0] = _texLeftHand;
    for (int i = 1; i < 5; i++) {
        _leftHandTex[i] = _texHandSide;
    }
    
    _rightHandTex[0] = _texRightHand;
    for (int i = 1; i < 5; i++) {
        _rightHandTex[i] = _texHandSide;
    }
}
void Cat::Update(const double& deltaTime) {
    _time+= deltaTime;
    if (_time > _loop * M_PI * step) _time -= _loop * M_PI * step;
}

void Cat::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2] + 1000 * sin(_time/(_loop * step)));
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    
    if (_time/(_loop * step) > M_PI / 2)
    {
        glTranslated(1, 0, -0.5);
        glRotatef(180, 0.0f, 1.0f, 0.0f);
        glTranslated(-1, 0, 0.5);
    }
    
    glDisable(GL_COLOR_MATERIAL);
    {
        glTranslated(0, 2, 0);
        drawBrickRT(1, 2, 3, _bodyTex);
        
        glTranslated(0, 3, 0);
        drawBrickRT(1, 2, 2, _headTex);
        
        glTranslated(1, 0, -0.5);
        
        glPushMatrix();
        {
            glTranslated(-0.5, -3, 0);
            glRotated(30 * sin(_time/_loop), 1, 0, 0);
            glTranslated(-0.5, -2, 0.5);
            drawBrickRT(1, 1, 2, _leftLegTex);
        }
        
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0.5, -3, 0);
            glRotated(-30 * sin(_time/_loop), 1, 0, 0);
            glTranslated(-0.5, -2, 0.5);
            drawBrickRT(1, 1, 2, _rightLegTex);
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(-1, 0, 0);
            glRotated(30 * sin(_time/_loop), 1, 0, 0);
            glTranslated(-0.5, -3, 0.5);
            drawBrickRT(1, 0.5, 3, _leftHandTex);
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(1, 0, 0);
            glRotated(-30 * sin(_time/_loop), 1, 0, 0);
            glTranslated(0, -3, 0.5);
            drawBrickRT(1, 0.5, 3, _leftHandTex);
        }
        glPopMatrix();
        
    }
    glPopAttrib();
    glPopMatrix();
}
