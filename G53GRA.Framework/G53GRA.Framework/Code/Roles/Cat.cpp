//
//  Cat.cpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Cat.hpp"
#include "VectorMath.h"

Cat::Cat(float speed, float limit, GLuint* _textures): _speed(speed), _limit(limit), _offset(0), _time(0), _flag(1)
{
    
//    _texFace = Scene::GetTexture("./Textures/Cats/cat1/Face.bmp");
//    _texFaceSide = Scene::GetTexture("./Textures/Cats/cat1/Head.bmp");
//    _texBody = Scene::GetTexture("./Textures/Cats/cat1/Body.bmp");
//    _texBodySide;
//    _texBack = Scene::GetTexture("./Textures/Cats/cat1/Back.bmp");
//    _texLeftHand = Scene::GetTexture("./Textures/Cats/cat1/LeftHand.bmp");
//    _texRightHand = Scene::GetTexture("./Textures/Cats/cat1/RightHand.bmp");
//    _texHandSide = Scene::GetTexture("./Textures/Cats/cat1/Hand.bmp");
//    _texLeftLeg = Scene::GetTexture("./Textures/Cats/cat1/LeftLeg.bmp");
//    _texRightLeg = Scene::GetTexture("./Textures/Cats/cat1/RightLeg.bmp");
//    _texLegSide = Scene::GetTexture("./Textures/Cats/cat1/Leg.bmp");
    
    _headTex[0] = _textures[0];
    for (int i = 1; i < 6; i++) {
        _headTex[i] = _textures[1];
    }
    
    _bodyTex[0] = _textures[2];
    for (int i = 1; i < 5; i++) {
        _bodyTex[i] = _textures[3];
    }
    _bodyTex[5] = _textures[4];
    
    _leftHandTex[0] = _textures[5];
    for (int i = 1; i < 5; i++) {
        _leftHandTex[i] = _textures[7];
    }
    
    _rightHandTex[0] = _textures[6];
    for (int i = 1; i < 5; i++) {
        _rightHandTex[i] = _textures[7];
    }
    
    _leftLegTex[0] = _textures[8];
    for (int i = 1; i < 5; i++) {
        _leftLegTex[i] = _textures[10];
    }
    
    _rightLegTex[0] = _textures[9];
    for (int i = 1; i < 5; i++) {
        _rightLegTex[i] = _textures[10];
    }
}

void Cat::Update(const double& deltaTime) {
    
    _time+= deltaTime;
    if (_time > _loop * M_PI * 2) _time -= _loop * M_PI * 2;
    
    _offset += _flag * _speed * deltaTime;
    
    if (_offset >= _limit || _offset <= 0) {
        _flag *= -1;
    }
    
}

void Cat::Display() {
    
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2] + _offset);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    
    if (_flag == -1)
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
