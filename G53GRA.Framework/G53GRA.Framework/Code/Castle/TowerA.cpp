//
//  TowerA.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "TowerA.hpp"
#include "BrickUtil.hpp"

TowerA::TowerA(){

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
    
    glPushMatrix();
    {
        setWallColor1(246, 238, 204);
        glTranslatef(0, 0, 1);
        drawBrickR(20, 1, 32);
        
        
        glTranslatef(1, 0, -1);
        
        glPushMatrix();
        {
            setWallColor1(242, 219, 172);
            drawBrickR(19, w, 7);
            
            glTranslatef(0, 7, 1);
            setWallColor1(246, 238, 204);
            drawBrickR(20, w, 1);
            
            glTranslatef(0, 1, -1);
            setWallColor1(245, 179, 147);
            drawBrickR(19, w, 6);
            
            glTranslatef(0, 6, 1);
            setWallColor1(246, 238, 204);
            drawBrickR(20, w, 1);
            
            glTranslatef(0, 1, -1);
            setWallColor1(245, 179, 147);
            drawBrickR(19, w, 5);
            glTranslatef(0, 5, 1);
            setWallColor1(246, 238, 204);
            drawBrickR(20, w, 1);
            
            glTranslatef(0, 1, -1);
            setWallColor1(245, 179, 147);
            drawBrickR(19, w, 8);
            
            glTranslatef(0, 8, 1);
            setWallColor1(246, 238, 204);
            drawBrickR(20, w, 3);
        }
        glPopMatrix();
        
        glTranslatef(8, 0, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(20, 1, 32);
    }
    glPopMatrix();
    
}

void TowerA::DrawSubTower2() {
    
    float w = 3;
    glPushMatrix();
    
    {
        setWallColor1(242, 219, 172);
        drawBrickR(18, w, 7);
        
        glTranslatef(0, 7, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(19, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(245, 179, 147);
        drawBrickR(18, w, 6);
        
        glTranslatef(0, 6, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(19, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(245, 179, 147);
        drawBrickR(18, w, 5);
        glTranslatef(0, 5, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(19, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(245, 179, 147);
        drawBrickR(18, w, 5);
    }
    
    glPopMatrix();
    
}

void TowerA::DrawSubTower1(){
    float w = 8;
    glPushMatrix();
    {
        setWallColor1(242, 219, 172);
        drawBrickR(16, w, 7);
        
        glTranslatef(0, 7, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(17, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(16, w, 6);
        
        glTranslatef(0, 6, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(17, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(16, w, 5);
        glTranslatef(0, 5, 1);
        setWallColor1(246, 238, 204);
        drawBrickR(17, w, 1);
        
        glTranslatef(0, 1, -1);
        setWallColor1(242, 219, 172);
        drawBrickR(16, w, 5);
    }
    glPopMatrix();
}


void TowerA::DrawRoof()
{
    glPushMatrix();
    setWallColor1(238, 89, 56);
    
    int w = 32;
    int l = 16;
    
    for (int i = 0; i < 16; i++) {
        drawBrickR(l, w, 1);
        glTranslatef(1, 1, -0.5);
        w -= 2;
        l -= 1;
    }
    
    glPopMatrix();
}

void TowerA::setWallColor1(int r, int g, int b) {
    
    GLfloat mat_ambient[] = { (r-5)/255.f, (g-5)/255.f, (b-5)/255.f, 1.0f };
    GLfloat mat_diffuse[] = { r/255.f, g/255.f, b/255.f, 1.0f };
    GLfloat mat_specular[] = { (r+5)/255.f, (g+5)/255.f, (b+5)/255.f, 1.0f };
    
    GLfloat mat_shininess = 100.0f;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}
