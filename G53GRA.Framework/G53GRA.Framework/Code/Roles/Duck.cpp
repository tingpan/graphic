//
//  Duck.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//
// This class creates the animating duck model.

#include "Duck.hpp"

Duck::Duck(float speed, float radius) : _speed(speed), _radius(radius), runAnimate(true)
{

}

Duck::~Duck()
{

}

void Duck::Update(const double &deltaTime)
{
    if(runAnimate)
    {
        // change the orientation of the duck
        rotation[1] -= static_cast<float>(deltaTime) * _speed;
    }
}

void Duck::HandleKey(unsigned char key, int state, int x, int y)
{
    if (key == 'r' && state)
    {
        // pause the animation when press 'r'
        runAnimate = !runAnimate;
    }
}

void Duck::Display()
{

    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(scale[0], scale[1], scale[2]);
        glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);

        // transform the duck with _radius distance in the oriented direction
        glTranslatef(_radius, 0, 0);

        glDisable(GL_COLOR_MATERIAL);

        {
            // Body
            setWallColor(255, 255, 255, 20);
            drawBrickR(6, 4, 4);

            // Head
            glTranslatef(0.5, 3, 1);
            drawBrickR(3, 3, 3);

            glPushMatrix();
            {
                glTranslatef(0, 1, 1.0);
                
                // Mouth
                setWallColor(223, 160, 14, 20);
                drawBrickR(1, 3, 0.8);

                // Eyes
                setWallColor(0, 0, 0, 20);
                glTranslatef(0.5, 1, -0.5);

                drawBrickR(0.5, 0.5, 0.5);
                glTranslatef(1.5, 0, 0);
                drawBrickR(0.5, 0.5, 0.5);
            }
            glPopMatrix();

            // Wings
            setWallColor(255, 255, 255, 20);
            glTranslatef(-1.5, -3, -2);
            drawBrickR(4, 1, 3);

            glTranslatef(5, 0, 0);
            drawBrickR(4, 1, 3);
        }
    }
    glPopAttrib();
    glPopMatrix();
}
