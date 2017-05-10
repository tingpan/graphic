//
//  TowerB.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerB.hpp"

TowerB::TowerB(){
    _textB1 = Scene::GetTexture("./Textures/Castle/brick1.bmp");
    _textB2 = Scene::GetTexture("./Textures/Castle/brick2.bmp");
    _textB3 = Scene::GetTexture("./Textures/Castle/brick3.bmp");
    _textB4 = Scene::GetTexture("./Textures/Castle/brick4.bmp");
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
        setWallColor1(238, 89, 56);
        
        for(int i = 0; i < 8; i++){
            
            float factor = 0.8;
            glPushMatrix();
            
            for (int j = 0; j < 4; j++) {
                
                drawBrickT(1, w - factor * j, 2, _textB3, 1);
                glTranslatef(factor/2, 2, -1);
            };
            
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
    
    glPushMatrix();
    {
        drawBrickT(l, w, 7, _textB4, f);
        
        glTranslatef(-0.43, 7, 1);
        drawBrickT(l + 1, w + .86, 1, _textB1, f);
        
        glTranslatef(0.43, 1, -1);
        drawBrickT(l, w, 6, _textB2, f);
        
        glTranslatef(-0.43, 6, 1);
        drawBrickT(l + 1, w + .86, 1, _textB1, f);
        
        glTranslatef(0.43, 1, -1);
        drawBrickT(l, w , 5, _textB2, f);
        
        glTranslatef(-0.43, 5, 1);
        drawBrickT(l + 1, w + .86, 1, _textB1, f);
        
        glTranslatef(0.43, 1, -1);

        drawBrickT(l, w, 5, _textB2, f);
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

void TowerB::setWallColor1(int r, int g, int b)
{
    
    GLfloat mat_ambient[] = { (r-5)/255.f, (g-5)/255.f, (b-5)/255.f, 1.0f };
    GLfloat mat_diffuse[] = { r/255.f, g/255.f, b/255.f, 1.0f };
    GLfloat mat_specular[] = { (r+5)/255.f, (g+5)/255.f, (b+5)/255.f, 1.0f };
    
    GLfloat mat_shininess = 100.0f;
    
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}
