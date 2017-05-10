//
//  TowerC.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerC.hpp"

TowerC::TowerC(){
}

TowerC::~TowerC()
{
    
}

void TowerC::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    glPushMatrix();
    {
        DrawSubTower1();
        glTranslatef(8, 0, 0);
        DrawSubTower1();
        glTranslatef(8, 0, 0);
        DrawSubTower1();
    }
    glPopMatrix();
    glPopAttrib();
    glPopMatrix();
    
}

void TowerC::DrawSubTower1(){
    float w = 8;
    float f = 1;
    float l = 16;
    
    _Floor floor[3] = {
        _Floor{_textB4, 7},
        _Floor{_textB2, 6},
        _Floor{_textB4, 5},
    };
    
    glPushMatrix();
    {
        for (int i = 0; i < 3; i++) {
            drawBrickT(l, w, floor[i]._height, floor[i]._tex, f);
            glTranslatef(0, floor[i]._height, 1);
            drawBrickT(l + 2, w, 1, _textB1, f);
            glTranslatef(0, 1, -1);
        }
        DrawRoof();
    }
    
    glPopMatrix();
    
    glPushMatrix();
    {
        SetWindowColor(192, 212, 238, 30);
        for(int i = 0; i < 4; i++)
        {
            glPushMatrix();
            {
                glTranslatef(2, (floor[i]._height - 3.25)/2, 0.01);
                DrawWindow1();
                glTranslatef(2.5, 0, 0);
                DrawWindow1();
            }
            glPopMatrix();
            glTranslatef(0, floor[i]._height + 1, 0);
        }
    }
    
    glPopMatrix();
    
}

void TowerC::DrawRoof()
{
    glPushMatrix();
    
    int w = 8;
    int l = 16;
    
    glPushMatrix();
    for (int i = 0; i < 8; i++) {
        drawBrickT(l, w, 1, _textB3, 1);
        glTranslatef(0, 1, -0.5);
        l -= 2;
    }
    glPopMatrix();
    
    glPushMatrix();
    
    {
        glTranslatef(2, 0, 1);
        
        for (int i = 0; i < 4; i++) {
            drawBrickT(5, 4 - i, 1, _textB1, 1);
            glTranslatef(0.5, 1, 0);
        }
        
    }
    glPopMatrix();
    
    {
        glTranslatef(3.4, .5, 1.01);
        glScalef(0.8, 0.8, 0);
        SetWindowColor(134, 113, 83, 30);
        DrawWindow1();
    }
    glPopMatrix();
}


