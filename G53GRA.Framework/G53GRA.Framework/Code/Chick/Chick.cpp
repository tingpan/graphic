//
//  Chick.cpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#include "Chick.hpp"
Chick::Chick(){
}

void Chick::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);

    
    glPushMatrix();
    {
        float w = 4;
        float l = 6;
        float h = 4;
        // Body
        setWallColor(255, 255, 255, 20);
        drawBrickR(l, w, h);
        glTranslatef(1, 3, 1);
        // Head
        drawBrickR(3, 2, 3);
        glTranslatef(0, 1, 1);
        // Mouth
        setWallColor(223, 160, 14, 20);
        drawBrickR(1, 2, 1);
        setWallColor(0, 0, 0, 20);
        glTranslatef(0, 1, -0.5);
        drawBrickR(0.5, 0.5, 0.5);
        glTranslatef(1.5, 0, 0);
        drawBrickR(0.5, 0.5, 0.5);

        glTranslatef(-3.5, -4, -2.5);
        // Wings
        setWallColor(255, 255, 255, 20);
        drawBrickR(4, 1, 3);
        glTranslatef(5, 0, 0);
        drawBrickR(4, 1, 3);

    }
    glPopMatrix();
    
    glPopAttrib();
    glPopMatrix();
}
