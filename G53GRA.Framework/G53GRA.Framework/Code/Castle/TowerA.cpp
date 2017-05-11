//
//  TowerA.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerA.hpp"
#include "VectorMath.h"

TowerA::TowerA()
: _time(0)
{
    _texClock = Scene::GetTexture("./Textures/Castle/clock.bmp");
}

TowerA::~TowerA()
{
    
}

void TowerA::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    glPushMatrix();
    {
        DrawSubTower1();
        glTranslatef(8, 0, 2);
        DrawSubTower2();
        glTranslatef(3, 0, 1);
        DrawSubTower3();
        glTranslated(10, 0, -1);
        DrawSubTower2();
        glTranslatef(3, 0, -2);
        DrawSubTower1();
    }
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 26, 0);
    DrawRoof();
    glTranslatef(12, 12, -6.5);
    DrawTop();
    glPopMatrix();
    
    glTranslatef(16, 32, 4);
    glScalef(2.5, 2.5, 1.5);
    DrawClock();
    
    glPopAttrib();
    glPopMatrix();
    
}
void TowerA::DrawSubTower3() {
    
    float w = 8;
    float f = 1;
    float l = 19;
    
    _Floor floor[4] = {
        _Floor{_textB4, 7},
        _Floor{_textB2, 6},
        _Floor{_textB2, 5},
        _Floor{_textB2, 8},
    };
    
    glPushMatrix();
    {
        
        glTranslatef(0, 0, 1);
        drawBrickT(l + 2, 1, 32, _textB1, f);
        
        glTranslatef(1, 0, -1);
        glPushMatrix();
        
        {
            for (int i = 0; i < 4; i++) {
                drawBrickT(l, w, floor[i]._height, floor[i]._tex, f);
                
                if (i < 3)
                {
                    glTranslatef(0, floor[i]._height, 1);
                    drawBrickT(l + 2, w, 1, _textB1, f);
                    glTranslatef(0, 1, -1);
                }
                
                else
                {
                    glTranslatef(0, 8, 1);
                    drawBrickT(l + 2, w, 3, _textB1, f);
                }
                
            }
        }
        glPopMatrix();
        glTranslatef(8, 0, 1);
        drawBrickT(l + 2, 1, 32, _textB1, f);
    }
    glPopMatrix();
    
    
    glPushMatrix();
    {
        glPushMatrix();
        {
            glTranslatef(3, 0, 0);
            DrawWindow2();
        }
        glPopMatrix();
        glTranslatef(0, floor[0]._height + 1, 0);
        
        glPushMatrix();
        {
            glTranslatef(3, 0, 0);
            DrawWindow2();
        }
        glPopMatrix();
        
        
        glTranslatef(0, floor[1]._height + 1, 0);
        
        glPushMatrix();
        {
            glTranslatef(3, (floor[2]._height - 3.25)/2, 0.01);
            DrawWindow1();
            glTranslatef(2.5, 0, 0);
            DrawWindow1();
        }
        glPopMatrix();
        
        glTranslatef(0, floor[2]._height + 1, 0);
        
        glPushMatrix();
        {
            glTranslatef(3, (floor[3]._height - 3.25 - 3)/2, 0.01);
            DrawWindow1();
            glTranslatef(2.5, 0, 0);
            DrawWindow1();
        }
        glPopMatrix();
    }
    glPopMatrix();
}

void TowerA::DrawSubTower2() {
    
    float w = 3;
    float f = 1;
    float l = 18;
    
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
            glTranslatef(0, floor[i]._height, 1);
            drawBrickT(l + 2, w, 1, _textB1, f);
            glTranslatef(0, 1, -1);
            
        }
    }
    glPopMatrix();
    
    
    glPushMatrix();
    
    {
        for(int i = 0; i < 4; i++)
        {
            glPushMatrix();
            {
                glTranslatef(0.7, (floor[i]._height - 3.25)/2, 0.01);
                DrawWindow1();
            }
            glPopMatrix();
            glTranslatef(0, floor[i]._height + 1, 0);
        }
    }
    
    glPopMatrix();
    
}

void TowerA::DrawSubTower1(){
    float w = 8;
    float f = 1;
    float l = 16;
    
    _Floor floor[4] = {
        _Floor{_textB4, 7},
        _Floor{_textB4, 6},
        _Floor{_textB4, 5},
        _Floor{_textB4, 5},
    };
    
    glPushMatrix();
    {
        for (int i = 0; i < 4; i++) {
            drawBrickT(l, w, floor[i]._height, floor[i]._tex, f);
            glTranslatef(0, floor[i]._height, 1);
            drawBrickT(l + 2, w, 1, _textB1, f);
            glTranslatef(0, 1, -1);
            
        }
    }
    
    glPopMatrix();
    
    glPushMatrix();
    
    {
        
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

void TowerA::DrawTop(){
    
    
    glPushMatrix();
    {
        float w = 3;
        float f = 1;
        
        glRotatef(-45, 0, 1, 0);
        
        for(int i = 0; i < 8; i++){
            drawBrickT(1, w, 6, _textB4, f);
            
            
            glPushMatrix();
            glTranslatef(1.0, 1.5, 0.05);
            DrawWindow1();
            glPopMatrix();
            
            
            glTranslatef(w, 0, 0);
            glRotatef(45, 0, 1, 0);
        }
    }
    glPopMatrix();
    
    glTranslatef(-1.8, 6, 0.6);
    glScalef(1.5, 1.5, 1.5);
    
    glPushMatrix();
    {
        float w = 3;
        glRotatef(-45, 0, 1, 0);
        
        for(int i = 0; i < 8; i++){
            
            float factor = 0.325;
            glPushMatrix();
            
            for (int j = 0; j < 8; j++) {
                drawBrickT(1, w - factor * j, 2 + 0.2 * j, _textB3, 1);
                glTranslatef(factor/2 , 2 + 0.2 * j, -0.4);
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

void TowerA::Update(const double& deltaTime)
{
    _time += deltaTime;
    if (_time > 60) _time -= 60;
}

void TowerA::DrawClock()
{
    
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.86f, 0.86f, 0.54f);
    
    float th = 0.0f;
    float res = 2.0f * M_PI / 15.0f;
    float y = 1.0f, x = 0.0f;
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textB4);
    do
    {
        glBegin(GL_QUADS);
        {
            glNormal3f(x, y, 0.0f);
            
            glTexCoord2d(0, 1);
            glVertex3f(x, y, -0.5f);
            
            glTexCoord2d(0, 0);
            glVertex3f(x, y, 0.5f);
            
            th += res;
            y = cos(th); x = sin(th);
            
            glNormal3f(x, y, 0.0f);
            
            glTexCoord2d(1, 0);
            glVertex3f(x, y, 0.5f);
            
            glTexCoord2d(1, 1);
            glVertex3f(x, y, -0.5f);
        }
        glEnd();
        
    } while (th <= 2.0f * M_PI);
    
    y = 1.0f, x = 0.0f; th = 0.0f;
    
    glBindTexture(GL_TEXTURE_2D, _texClock);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_TRIANGLE_FAN);
    {
        glNormal3f(1.0f, 0.0f, 0.0f);
        
        glTexCoord2d(0.5, 0.5);
        glVertex3f(0.0f, 0.0f, 0.5f);
        
        do
        {
            glTexCoord2d((x + 1)/2, (y + 1)/2);
            glVertex3f(x, y, 0.5f);
            
            th += res;
            y = cos(th); x = -sin(th);
            
            glTexCoord2d((x + 1)/2, (y + 1)/2);
            glVertex3f(x, y, 0.5f);
            
        } while (th <= 2.0f * M_PI);
    }
    glEnd();
    
    y = 1.0f, x = 0.0f; th = 0.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.86f, 0.86f, 0.54f);
    
    {
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -0.5f);
        do
        {
            glVertex3f(x, y, -0.5f);
            th += res;
            y = cos(th); x = sin(th);
            glVertex3f(x, y, -0.5f);
        } while (th <= 2.0f * M_PI);
    }
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    
    glTranslatef(0, 0, 0.6);
    setWallColor(0, 0, 0, 20);
    drawBrickR(0.2, 0.1, 0.6);
    glRotated(_time / 60 * -360, 0, 0, 1);
    drawBrickR(0.2, 0.1, 0.8);
    
    glPopAttrib();
    glPopMatrix();
}

void TowerA::DrawRoof()
{
    glPushMatrix();
    
    int w = 32;
    int l = 16;
    
    for (int i = 0; i < 12; i++) {
        drawBrickT(l, w, 1, _textB3, 1);
        glTranslatef(1, 1, -0.5);
        w -= 2;
        l -= 1;
    }
    
    glPopMatrix();
}


