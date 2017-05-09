//
//  Tree.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "Tree.hpp"
#include "BrickUtil.hpp"
#include <random>

Tree::Tree(){
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng{seed};
    std::uniform_int_distribution<> width(20,30);
    std::uniform_int_distribution<> height(20,32);
    w = width(eng);
    h = height(eng);
    l = w;
    leaf_size = 4;
    std::uniform_int_distribution<> dist(leaf_size/2,leaf_size);
    min = h/3 + leaf_size;
    leaf_front = dist(eng);
    leaf_back = dist(eng);
    leaf_left = dist(eng);
    leaf_right = dist(eng);
    leaf_top = dist(eng);
}

Tree::~Tree()
{
    
}

void Tree::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);
    
    glTranslatef(0, 0, 0);
    glPushMatrix();
    {
        glTranslatef(0, 0, 0);
        
        float branch_x = -w / 2 + 2;
        float branch_y = 32 - h/2;
        float branch_z = l/2 - 2;
        // Draw Trunk and Branches
        glPushMatrix();
        {
            setWallColor1(92, 45, 10);
            drawBrickR(4, 4, 32);

            glTranslatef(branch_x, branch_y, branch_z);

            setWallColor1(56, 75, 1);
            drawBrickR(l, w, h);
        }
        glPopMatrix();
        
        // Draw Leaves
        glPushMatrix();
        glTranslatef(branch_x, branch_y, branch_z);
        float leaf_w = w;
        float leaf_h = h;
        float leaf_l = 4;
        while (leaf_w > min & leaf_h > min) {
            leaf_w = leaf_w - 2 * leaf_front;
            leaf_h = leaf_h - 2 * leaf_front;
            setWallColor1(56, 75, 1);
            glTranslatef(leaf_size,leaf_size,4);
            drawBrickR(leaf_l, leaf_w, leaf_h);
        }
        glPopMatrix();

        
        leaf_w = w;
        leaf_h = h;
        leaf_l = 4;
        glPushMatrix();
        glTranslatef(branch_x, branch_y, branch_z - w + 4);
        {
            while (leaf_w > min & leaf_h > min) {
                leaf_w = leaf_w - 2 * leaf_back;
                leaf_h = leaf_h - 2 * leaf_back;
                setWallColor1(56, 75, 1);
                glTranslatef(leaf_size,leaf_size,-4);
                drawBrickR(leaf_l, leaf_w, leaf_h);
            }
        }
        glPopMatrix();
        
        leaf_w = 4;
        leaf_h = h;
        leaf_l = l;
        glPushMatrix();
        glTranslatef(branch_x, branch_y, branch_z);
        {
            while (leaf_l > min & leaf_h > min) {
                leaf_l = leaf_l - 2 * leaf_left;
                leaf_h = leaf_h - 2 * leaf_left;
                setWallColor1(56, 75, 1);
                glTranslatef(-4,leaf_size,-leaf_size);
                drawBrickR(leaf_l, leaf_w, leaf_h);
            }
        }
        glPopMatrix();
        
        leaf_w = 4;
        leaf_h = h;
        leaf_l = l;
        glPushMatrix();
        glTranslatef(branch_x + w - 4, branch_y, branch_z);
        {
            while (leaf_l > min & leaf_h > min) {
                leaf_l = leaf_l - 2 * leaf_right;
                leaf_h = leaf_h - 2 * leaf_right;
                setWallColor1(56, 75, 1);
                glTranslatef(4,leaf_size,-leaf_size);
                drawBrickR(leaf_l, leaf_w, leaf_h);
            }
        }
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(branch_x, branch_y + h - 4, branch_z);
        leaf_w = w;
        leaf_h = 4;
        leaf_l = l;
        while (leaf_w > min & leaf_l > min) {
            leaf_w = leaf_w - 2 * leaf_top;
            leaf_l = leaf_l - 2 * leaf_top;
            setWallColor1(56, 75, 1);
            glTranslatef(leaf_size,4,-leaf_size);
            drawBrickR(leaf_l, leaf_w, leaf_h);
        }
        glPopMatrix();

    }
    glPopMatrix();
    
    
    glPopAttrib();
    glPopMatrix();
    
}
void Tree::DrawTrunk() {

    
}

void Tree::DrawMainBranches()
{    
    
}

void Tree::setWallColor1(int r, int g, int b) {
    
    GLfloat mat_ambient[] = { (r-5)/255.f, (g-5)/255.f, (b-5)/255.f, 1.0f };
    GLfloat mat_diffuse[] = { r/255.f, g/255.f, b/255.f, 1.0f };
    GLfloat mat_specular[] = { (r+5)/255.f, (g+5)/255.f, (b+5)/255.f, 1.0f };
    
    GLfloat mat_shininess = 100.0f;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}
