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
    std::uniform_int_distribution<> width(5,10);
    std::uniform_int_distribution<> height(5,10);
    
    w = width(eng);
    h = height(eng);
    l = w;
    
    side_map = createRandomMap(l, h, 4);
    top_map = createRandomMap(l, l, 4);
    
    _tex_branch = Scene::GetTexture("./Textures/Environment/tree_branch.bmp");
    _tex_leave = Scene::GetTexture("./Textures/Environment/tree_leave.bmp");
    
    leaf_size = 4;
    std::uniform_int_distribution<> dist(leaf_size/2, leaf_size);
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

int** Tree::createRandomMap(int w, int h, int max) {
    
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng{seed};
    std::uniform_int_distribution<> tSize(0, max);
    
    int** map = 0;
    map = new int*[h];
    
    for (int i = 0; i < h; i++)
    {
        map[i] = new int[w];
        
        for (int j = 0; j < w; j++)
        {
            map[i][j] = tSize(eng);
        }
    }
    
    return map;
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
        
        // Draw Trunk and Branches
        glPushMatrix();
        {
            drawBrickT(1, 1, 10, _tex_branch, 1);
            glTranslatef(-w/2, 10, l/2);
            drawBrickT(l, w, h, _tex_leave, 1);
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(-w/2, 10, l/2);
            
            for(int i = 0; i < h; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = side_map[i][j];
                    glPushMatrix();
                    glTranslatef(0, 0, t_size);
                    drawBrickT(t_size, 1, 1, _tex_leave, 1);
                    glPopMatrix();
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        
        glPopMatrix();
        
        
        glPushMatrix();
        {
            glTranslatef(-w/2, 10, -l/2);
            
            for(int i = 0; i < h; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = side_map[i][j];
                    glPushMatrix();
                    glTranslatef(-t_size, 0, 0);
                    drawBrickT(1, t_size, 1, _tex_leave, 1);
                    glPopMatrix();
                    glTranslatef(0, 0, 1);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(w/2, 10, -l/2);
            
            for(int i = 0; i < h; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = side_map[i][j];
                    drawBrickT(1, t_size, 1, _tex_leave, 1);
                    glTranslatef(0, 0, 1);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(-w/2, 10, -l/2);
            
            for(int i = 0; i < h; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = side_map[i][j];
                    glPushMatrix();
                    drawBrickT(t_size, 1, 1, _tex_leave, 1);
                    glPopMatrix();
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(-w/2, 10, l/2);
            
            for(int i = 0; i < l; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = top_map[i][j];
                    glPushMatrix();
                    glTranslatef(0, -t_size, 0);
                    drawBrickT(1, 1, t_size, _tex_leave, 1);
                    glPopMatrix();
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 0, -1);
            }
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(-w/2, 10 + h, l/2);
            
            for(int i = 0; i < l; i++){
                glPushMatrix();
                for (int j = 0; j < w; j++) {
                    int t_size = top_map[i][j];
                    drawBrickT(1, 1, t_size,_tex_leave, 1);
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 0, -1);
            }
        }
        glPopMatrix();
    }
    
    glPopMatrix();
    glPopAttrib();
    glPopMatrix();
    
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
