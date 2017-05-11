//
//  TowerB.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerB.hpp"

TowerB::TowerB(){
    SetWindowColor(179, 206, 236, 30);
}

TowerB::~TowerB()
{
    
}

void TowerB::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    glPushMatrix();
    {
        glRotatef(-45, 0, 1, 0);
        
        for(int i = 0; i < 8; i++){
            float w = 8;
            
            if ((i + 1) % 4 == 0) {
                w = 16;
            }
            DrawWall(w);
            glTranslatef(w, 0, 0);
            glRotatef(45, 0, 1, 0);
        }
    }
    glPopMatrix();
    
    glTranslatef(0, 27, 0);
    DrawRoof();
    glTranslatef(6, 12, -7);
    DrawTop();
    
    glPopAttrib();
    glPopMatrix();
}

void TowerB::DrawTop(){
    
    
    glPushMatrix();
    {
        float w = 3;
        float f = 1;
        
        glRotatef(-45, 0, 1, 0);
        
        for(int i = 0; i < 8; i++){
            drawBrickT(1, w, 4, _textB4, f);
            
          
                glPushMatrix();
                glTranslatef(1.0, 0.5, 0.05);
                glScalef(0.8, 0.8, 1);
                DrawWindow1();
                glPopMatrix();
           
            
            glTranslatef(w, 0, 0);
            glRotatef(45, 0, 1, 0);
        }
    }
    glPopMatrix();
    
    glTranslatef(-0.6, 4, 0.6);
    glScalef(1.2, 1.2, 1.2);
    
    glPushMatrix();
    {
        float w = 3;
        glRotatef(-45, 0, 1, 0);
        
        for(int i = 0; i < 8; i++){
            
            float factor = 0.7;
            glPushMatrix();
            
            for (int j = 0; j < 4; j++) {
                
                drawBrickT(1, w - factor * j, 2, _textB3, 1);
                glTranslatef(factor/2, 2, -0.8);
            };
            
            if (i == 7)
            {
                glPushAttrib(GL_ALL_ATTRIB_BITS);
                setWallColor(234, 197, 127, 20);
                drawBrickR(1, 1, 2);
                glTranslatef(0.25, 0.25, -0.25);
                DrawFlag();
                glPopAttrib();
            }
            
            glPopMatrix();
        
            glTranslatef(w, 0, 0);
            glRotatef(45, 0, 1, 0);
        }
    }
    
    glPopMatrix();
}

void TowerB::DrawWall(float w)
{
    float l = 1;
    float f = 1;
    
    _Floor floor[4] = {
        _Floor{_textB4, 7},
        _Floor{_textB2, 6},
        _Floor{_textB2, 5},
        _Floor{_textB2, 5},
    };
    
    glPushMatrix();
    {
        for (int i = 0; i < 4; i++) {
            drawBrickT(l, w, floor[i]._height, floor[i]._tex, f);
            
            if (i != 3) {
                glTranslatef(-.43, floor[i]._height, 1);
                drawBrickT(l + 2, w + .86, 1, _textB1, f);
                glTranslatef(.43, 1, -1);
            }
        }
        
        glTranslatef(-0.43, 5, 1);
        
        drawBrickT(l + 1, 0.5 + .43 , 4, _textB1, f);
        glTranslatef(0.5 + .43, -1, 0);
        
        for(int i = 0; i < w - 1; i++)
        {
            float h = 6;
            float offset = 1;
            
            if (i % 2 == 1) {
                h = 4;
                offset = -1;
            }
            
            drawBrickT(1, 1, h, _textB1, f);
            glTranslatef(1, offset, 0);
        }
        
        drawBrickT(l + 1, 0.5 + .43 , 4, _textB1, f);
    }
    glPopMatrix();
    
    glPushMatrix();
    
    {
        glPushMatrix();
        {
            for (int j = 0; j < int(w) / 8; j ++) {
                glTranslatef(2, 0, 0);
                DrawWindow2();
                glTranslatef(6, 0, 0);
            }
        }
        glPopMatrix();
       
        glTranslatef(0, floor[0]._height + 1, 0);
        
        for(int i = 1; i < 4; i++)
        {
            glPushMatrix();
            {
                glTranslatef(2 , (floor[i]._height - 3.25)/2, 0.01);
                
                for (int j = 0; j < int(w) / 8; j ++) {
                    DrawWindow1();
                    glTranslatef(2.5, 0, 0);
                    DrawWindow1();
                    glTranslatef(5.5, 0, 0);
                }
            }
            glPopMatrix();
            glTranslatef(0, floor[i]._height + 1, 0);
        }
    }
    
    glPopMatrix();
    
}

void TowerB::DrawRoof()
{
    float h = 2;
    float n = 6;
    float f = 1;
    
    glPushMatrix();
    {
        glRotatef(-45, 0, 1, 0);
        
        for (int j = 0; j < 8; j++) {

            float w = 8;
            float factor = 1;
            float m = -1;
            
            if (j % 2 == 0) {
                factor = 0.71;
                m = -1.06;
            }
            
            if ((j + 1) % 4 == 0 ) {
                w = 16;
            }

            glPushMatrix();
            
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    drawBrickT(-m, w - factor * i, h, _textB3, f);
                } else {
                    drawBrickT(8, w - factor * i, h, _textB3, f);
                }
                
                
                glTranslatef(factor/2, h, m);
            };
            glPopMatrix();

            glTranslatef(w, 0, 0);
            glRotatef(45, 0, 1, 0);
        }
    
    }
    glPopMatrix();
}
