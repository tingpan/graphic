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
    _texBrick = Scene::GetTexture("./Textures/Environment/brick.bmp");
    
//    for (int i = 0; i < 6; i++)
//    {
//        div(diffuse[i], 255);
//    }
//    
//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < 100; j++) {
//            
//            int d = rand() % 48;
//            
//            if (d < 32)
//            {
//                diffusemax[i][j] = 0;
//            }
//            else if (d < 40)
//            {
//                diffusemax[i][j] = 1;
//            }
//            else if (d < 42)
//            {
//                diffusemax[i][j] = 2;
//            }
//            else if (d < 44)
//            {
//                diffusemax[i][j] = 3;
//
//            }
//            else if (d < 46)
//            {
//                diffusemax[i][j] = 4;
//            }
//            else
//            {
//                diffusemax[i][j] = 5;
//            }
//        }
//    }
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
    glBindTexture(GL_TEXTURE_2D, _texBrick);
    
    glBegin(GL_QUADS);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
//            cout << rand() <<endl;
            
//            int d = diffusemax[i][j];
            
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
    }
    glEnd();
    glEnable(GL_COLOR_MATERIAL);
    glPopAttrib();
    glPopMatrix();
}
