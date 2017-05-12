//
//  MyFloor.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 7/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "MyFloor.hpp"
#include "VectorMath.h"

MyFloor::MyFloor()
{
    _texBrick1 = Scene::GetTexture("./Textures/Environment/brick.bmp");
    _texBrick2 = Scene::GetTexture("./Textures/Environment/brick2.bmp");
    _texBrick3 = Scene::GetTexture("./Textures/Environment/brick3.bmp");
    _texBrick4 = Scene::GetTexture("./Textures/Environment/brick4.bmp");
}

void MyFloor::Display()
{
    // Draws an exciting chequered floor
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_COLOR_MATERIAL);
    
    float shininess = 128.0f;
    
    glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            glBindTexture(GL_TEXTURE_2D, _texBrick1);
            
             if ((50 - i) * (50 - i) + (38 - j) * (38 - j) > 2000) glBindTexture(GL_TEXTURE_2D, _texBrick4);
            
            if (i > 45 && i < 54) glBindTexture(GL_TEXTURE_2D, _texBrick3);
            if (j > 33 && j < 42) glBindTexture(GL_TEXTURE_2D, _texBrick3);
            
            if (i > j + 7 && i < j + 18) glBindTexture(GL_TEXTURE_2D, _texBrick2);
            if (i < 100 - (j + 7) && i > 100 - (j + 18)) glBindTexture(GL_TEXTURE_2D, _texBrick2);
            
            if ((50 - i) * (50 - i) + (38 - j) * (38 - j) < 200) glBindTexture(GL_TEXTURE_2D, _texBrick4);
            
            
            
            glBegin(GL_QUADS);
            {
                glNormal3f(0.0f, 1.0f, 0.0f);
                
                glTexCoord2d(1, 0);
                glVertex3f(pos[0] + scale[0] * static_cast<float>(i) + scale[0], pos[1], pos[2] - (scale[2] * static_cast<float>(j)));
                
                glTexCoord2d(1, 1);
                glVertex3f(pos[0] + scale[0] * static_cast<float>(i) + scale[0], pos[1], pos[2] - (scale[2] * static_cast<float>(j) + scale[2]));
                
                glTexCoord2d(0, 1);
                glVertex3f(pos[0] + scale[0] * static_cast<float>(i), pos[1], pos[2] - (scale[2] * static_cast<float>(j)+ scale[2]));
                
                glTexCoord2d(0, 0);
                glVertex3f(pos[0] + scale[0] * static_cast<float>(i), pos[1], pos[2] - (scale[2] * static_cast<float>(j)));
            }
            glEnd();
        }
    }
    
    glEnable(GL_COLOR_MATERIAL);
    glPopAttrib();
    glPopMatrix();
}
