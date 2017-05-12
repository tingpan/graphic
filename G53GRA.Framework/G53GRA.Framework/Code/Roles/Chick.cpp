//
//  Chick.cpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Chick.hpp"

Chick::Chick(float speed, float radius): _speed(speed), _radius(radius)
{
    
}

Chick::~Chick()
{

}

void Chick::Update(const double& deltaTime)
{
    rotation[1] -= static_cast<float>(deltaTime) * _speed;
}

void Chick::Display() {
    
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    
    glTranslatef(_radius, 0, 0);
    
    glDisable(GL_COLOR_MATERIAL);
    
    {
        // Body
        setWallColor(255, 255, 255, 20);
        
        drawBrickR(6, 4, 4);
        
        glTranslatef(0.5, 3, 1);
        // Head
        drawBrickR(3, 3, 3);
        
        glPushMatrix();
        {
            glTranslatef(0, 1, 1.0);
            // Mouth
            setWallColor(223, 160, 14, 20);
            drawBrickR(1, 3, 0.8);
            
            setWallColor(0, 0, 0, 20);
            glTranslatef(0.5, 1, -0.5);
            
            drawBrickR(0.5, 0.5, 0.5);
            glTranslatef(1.5, 0, 0);
            drawBrickR(0.5, 0.5, 0.5);
        }
        glPopMatrix();
        
        setWallColor(255, 255, 255, 20);
        glTranslatef(-1.5, -3, -2);
        drawBrickR(4, 1, 3);
        
        glTranslatef(5, 0, 0);
        drawBrickR(4, 1, 3);
    }
    
    glPopAttrib();
    glPopMatrix();
}
