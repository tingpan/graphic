//
//  TowerB.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerB.hpp"

TowerB::TowerB(){
    
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
        glRotatef(-45, 0, 1, 0);
        setWallColor1(242, 219, 172);
        for(int i = 0; i < 8; i++){
            drawBrickR(1, w, 4);
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
                
                drawBrickR(1, w - factor * j, 2);
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
    
    glPushMatrix();
    {
        setWallColor1(242, 219, 172);
        drawBrickR(l, w, 7);
        
        glTranslatef(-0.43, 7, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(l + 1, w + .86, 1);
        
        glTranslatef(0.43, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(l, w, 6);
        
        glTranslatef(-0.43, 6, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(l + 1, w + .86, 1);
        
        glTranslatef(0.43, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(l, w , 5);
        
        glTranslatef(-0.43, 5, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(l + 1, w + .86, 1);
        
        glTranslatef(0.43, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(l, w, 5);
        
        glTranslatef(-0.43, 5, 1);
        setWallColor1(242, 219, 172);
        
    
        drawBrickR(l + 1, 0.5 + .43 , 4);
        glTranslatef(0.5 + .43, -1, 0);
        
        for(int i = 0; i < w - 1; i++)
        {
            float h = 6;
            float offset = 1;
            
            if (i % 2 == 1) {
                h = 4;
                offset = -1;
            }
            
            drawBrickR(1, 1, h);
            glTranslatef(1, offset, 0);
        }
        
        drawBrickR(l + 1, 0.5 + .43 , 4);
        
    }
    glPopMatrix();
}

void TowerB::DrawRoof()
{
    float h = 2;
    float n = 6;
    
    setWallColor1(238, 89, 56);
    
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
                            drawBrickR(-m, w - factor * i, h);
                        } else {
                            drawBrickR(8, w - factor * i, h);
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
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}
