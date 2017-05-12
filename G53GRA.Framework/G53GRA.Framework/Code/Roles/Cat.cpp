//
//  Cat.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Cat.hpp"
#include "VectorMath.h"

Cat::Cat(float speed, float limit, GLuint *_textures) : _speed(speed), _limit(limit), _offset(0), _time(0), _flag(1), runAnimate(true)
{

// The order of the *_textures
//    _texFace
//    _texFaceSide
//    _texBody
//    _texBodySide;
//    _texBack
//    _texLeftHand
//    _texRightHand
//    _texHandSide
//    _texLeftLeg
//    _texRightLeg
//    _texLegSide

    // assign the texture id to each texture array
    _headTex[0] = _textures[0];
    for (int i = 1; i < 6; i++)
    {
        _headTex[i] = _textures[1];
    }

    _bodyTex[0] = _textures[2];
    for (int i = 1; i < 5; i++)
    {
        _bodyTex[i] = _textures[3];
    }
    _bodyTex[5] = _textures[4];

    _leftHandTex[0] = _textures[5];
    for (int i = 1; i < 5; i++)
    {
        _leftHandTex[i] = _textures[7];
    }

    _rightHandTex[0] = _textures[6];
    for (int i = 1; i < 5; i++)
    {
        _rightHandTex[i] = _textures[7];
    }

    _leftLegTex[0] = _textures[8];
    for (int i = 1; i < 5; i++)
    {
        _leftLegTex[i] = _textures[10];
    }

    _rightLegTex[0] = _textures[9];
    for (int i = 1; i < 5; i++)
    {
        _rightLegTex[i] = _textures[10];
    }
}

void Cat::HandleKey(unsigned char key, int state, int x, int y)
{
    // pause the animation when press 'r'
    if (key == 'r' && state)
    {
        runAnimate = !runAnimate;
        if (!runAnimate) _time = 0;
    }
}

void Cat::Update(const double &deltaTime)
{

    if (!runAnimate) {
        return;
    }
    
    _time += deltaTime;
    if (_time > _loop * M_PI * 2) _time -= _loop * M_PI * 2;

    _offset += _flag * _speed * deltaTime;

    // move back if reach the maximum position
    if (_offset >= _limit)
    {
        _flag *= -1;
        _offset = _limit - _speed * deltaTime;
    }

    // move forward if reach the original position
    if (_offset <= 0)
    {
        _flag *= -1;
        _offset = 0 + _speed * deltaTime;
    }
}

void Cat::Display()
{

    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
        glScalef(scale[0], scale[1], scale[2]);

        // rotate the model if the cat is moving backward
        if (_flag == -1)
        {
            glTranslated(1, 0, -0.5);
            glRotatef(180, 0.0f, 1.0f, 0.0f);
            glTranslated(-1, 0, 0.5);
        }

        // move in the facing direction
        glTranslatef(0, 0, _offset * _flag / scale[0]);

        glDisable(GL_COLOR_MATERIAL);
        {
            // draw body
            glTranslated(0, 2, 0);
            drawBrickT(1, 2, 3, _bodyTex);

            // dra head
            glTranslated(0, 3, 0);
            drawBrickT(1, 2, 2, _headTex);

            glTranslated(1, 0, -0.5);

            // rotate the left leg, first transfer the rotate center to the top-mid of the leg
            // the rotation is calculated with 'sin' function so that the animation is looped
            glPushMatrix();
            {
                glTranslated(-0.5, -3, 0);
                glRotated(30 * sin(_time / _loop), 1, 0, 0);
                glTranslated(-0.5, -2, 0.5);
                drawBrickT(1, 1, 2, _leftLegTex);
            }

            glPopMatrix();

            // rotate the right leg
            glPushMatrix();
            {
                glTranslated(0.5, -3, 0);
                glRotated(-30 * sin(_time / _loop), 1, 0, 0);
                glTranslated(-0.5, -2, 0.5);
                drawBrickT(1, 1, 2, _rightLegTex);
            }
            glPopMatrix();

            // rotate the left hand
            glPushMatrix();
            {
                glTranslated(-1, 0, 0);
                glRotated(30 * sin(_time / _loop), 1, 0, 0);
                glTranslated(-0.5, -3, 0.5);
                drawBrickT(1, 0.5, 3, _leftHandTex);
            }
            glPopMatrix();

            // rotate the right hand
            glPushMatrix();
            {
                glTranslated(1, 0, 0);
                glRotated(-30 * sin(_time / _loop), 1, 0, 0);
                glTranslated(0, -3, 0.5);
                drawBrickT(1, 0.5, 3, _leftHandTex);
            }
            glPopMatrix();

        }
    }
    glPopAttrib();
    glPopMatrix();
}
