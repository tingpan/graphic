//
//  TowerA.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerA.hpp"

TowerA::TowerA(){
    _textB1 = Scene::GetTexture("./Textures/Castle/brick1.bmp");
    _textB2 = Scene::GetTexture("./Textures/Castle/brick2.bmp");
    _textB3 = Scene::GetTexture("./Textures/Castle/brick3.bmp");
    _textB4 = Scene::GetTexture("./Textures/Castle/brick4.bmp");
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
    glPopMatrix();
    
    glTranslatef(0, 0, 10);
    
    
    glPopAttrib();
    glPopMatrix();
    
}
void TowerA::DrawSubTower3() {
    
        float w = 8;
        float f = 1;
    
        glPushMatrix();
        {
            
            glTranslatef(0, 0, 1);
            drawBrickT(20, 1, 32, _textB1, f);
            
            glTranslatef(1, 0, -1);
    
            glPushMatrix();
            {
                drawBrickT(19, w, 7, _textB4, f);
    
                glTranslatef(0, 7, 1);
                drawBrickT(20, w, 1, _textB1, f);
    
    
                glTranslatef(0, 1, -1);
                drawBrickT(19, w, 6, _textB2, f);
    
                glTranslatef(0, 6, 1);
                drawBrickT(20, w, 1, _textB1, f);
    
                glTranslatef(0, 1, -1);
                drawBrickT(19, w, 5, _textB2, f);
                
                glTranslatef(0, 5, 1);
                drawBrickT(20, w, 1, _textB1, f);
    
                glTranslatef(0, 1, -1);
                drawBrickT(19, w, 8, _textB2, f);
    
                glTranslatef(0, 8, 1);
                drawBrickT(20, w, 3, _textB1, f);
            }
            glPopMatrix();
            
            glTranslatef(8, 0, 1);
            drawBrickT(20, 1, 32, _textB1, f);
        }
        glPopMatrix();

    
}

void TowerA::DrawSubTower2() {
    
    float w = 3;
    float f = 1;
    
    glPushMatrix();
    
    {
        drawBrickT(18, w, 7, _textB4, f);
        
        glTranslatef(0, 7, 1);
        drawBrickT(19, w, 1, _textB1, 1);
        
        glTranslatef(0, 1, -1);
        drawBrickT(18, w, 6, _textB2, 1);
        
        glTranslatef(0, 6, 1);
        drawBrickT(19, w, 1, _textB1, 1);
        
        glTranslatef(0, 1, -1);

        drawBrickT(18, w, 5, _textB2, 1);
        
        glTranslatef(0, 5, 1);
        drawBrickT(19, w, 1, _textB1, 1);
        
        glTranslatef(0, 1, -1);
       
        drawBrickT(18, w, 5, _textB2, 1);
    }
    
    glPopMatrix();
    
}

void TowerA::DrawSubTower1(){
    float w = 8;
    float f = 1;
    
    glPushMatrix();
    {
        
        drawBrickT(16, w, 7, _textB4, f);
        
        glTranslatef(0, 7, 1);
        drawBrickT(17, w, 1, _textB1, f);
        
        glTranslatef(0, 1, -1);
        drawBrickT(16, w, 6, _textB4, f);
        
        glTranslatef(0, 6, 1);
        drawBrickT(17, w, 1, _textB1, f);
        
        glTranslatef(0, 1, -1);
        drawBrickT(16, w, 5, _textB4, f);
        
        glTranslatef(0, 5, 1);
        drawBrickT(17, w, 1, _textB1, f);
        
        glTranslatef(0, 1, -1);
        drawBrickT(16, w, 5, _textB4, f);
    }
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(2, 3, 0.01);
        DrawWindow();
    glPopMatrix();
    
}

void TowerA::DrawWindow()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        
        setWallColor1(200, 221, 235, 30);
        drawBrickR(1, 1.5, 3);
    glPopAttrib();
    glPopMatrix();
}

void TowerA::DrawRoof()
{
    glPushMatrix();
    
    int w = 32;
    int l = 16;
    
    for (int i = 0; i < 16; i++) {
        drawBrickT(l, w, 1, _textB3, 1);
        glTranslatef(1, 1, -0.5);
        w -= 2;
        l -= 1;
    }
    
    glPopMatrix();
}

void TowerA::setWallColor1(int r, int g, int b, int s) {
    
    GLfloat mat_ambient[] = { (r-5)/255.f, (g-5)/255.f, (b-5)/255.f, 1.0f };
    GLfloat mat_diffuse[] = { r/255.f, g/255.f, b/255.f, 1.0f };
    GLfloat mat_specular[] = { (r+5)/255.f, (g+5)/255.f, (b+5)/255.f, 1.0f };
    
    GLfloat mat_shininess = s;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}
