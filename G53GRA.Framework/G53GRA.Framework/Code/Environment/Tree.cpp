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

Tree::Tree()
{
    // load textures
    _tex_branch = Scene::GetTexture("./Textures/Environment/tree_branch.bmp");
    _tex_leave = Scene::GetTexture("./Textures/Environment/tree_leave.bmp");

    // init the random seed with a range.
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng{seed};
    std::uniform_int_distribution<> width(5, 10);
    std::uniform_int_distribution<> height(5, 10);

    // set the tree height and width randomly
    w = width(eng);
    h = height(eng);
    l = w;

    // generate the height map
    side_map = createRandomMap(l, h, 4);
    top_map = createRandomMap(l, l, 4);
}

Tree::~Tree()
{

}

int **Tree::createRandomMap(int w, int h, int max)
{

    // init the random seed.
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng{seed};
    std::uniform_int_distribution<> tSize(0, max);

    // create a random height map for each side of the tree
    int **map = 0;
    map = new int *[h];

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


void Tree::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(scale[0], scale[1], scale[2]);
        glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
        glDisable(GL_COLOR_MATERIAL);
        
        glTranslatef(0, 0, 0);
            
        // draw trunk and the main body of the tree
        glPushMatrix();
        {
            drawBrickT(1, 1, 10, _tex_branch, 1);
            glTranslatef(-w / 2, 10, l / 2);
            drawBrickT(l, w, h, _tex_leave, 1);
        }
        glPopMatrix();
        
        // generate the leaf for each side of the tree based on the height map
        // draw leaf for front side
        glPushMatrix();
        {
            glTranslatef(-w / 2, 10, l / 2);
            
            for (int i = 0; i < h; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = side_map[i][j];
                    glPushMatrix();
                    {
                        glTranslatef(0, 0, t_size);
                        drawBrickT(t_size, 1, 1, _tex_leave, 1);
                    }
                    glPopMatrix();
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        // draw leaf for right side
        glPushMatrix();
        {
            glTranslatef(-w / 2, 10, -l / 2);
            
            for (int i = 0; i < h; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = side_map[i][j];
                    glPushMatrix();
                    {
                        glTranslatef(-t_size, 0, 0);
                        drawBrickT(1, t_size, 1, _tex_leave, 1);
                    }
                    glPopMatrix();
                    glTranslatef(0, 0, 1);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        // draw leaf for left side
        glPushMatrix();
        {
            glTranslatef(w / 2, 10, -l / 2);
            
            for (int i = 0; i < h; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = side_map[i][j];
                    drawBrickT(1, t_size, 1, _tex_leave, 1);
                    glTranslatef(0, 0, 1);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        // draw leaf for back side
        glPushMatrix();
        {
            glTranslatef(-w / 2, 10, -l / 2);
            
            for (int i = 0; i < h; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = side_map[i][j];
                    drawBrickT(t_size, 1, 1, _tex_leave, 1);
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 1, 0);
            }
        }
        glPopMatrix();
        
        // draw leaf for bottom side
        glPushMatrix();
        {
            glTranslatef(-w / 2, 10, l / 2);
            
            for (int i = 0; i < l; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = top_map[i][j];
                    glPushMatrix();
                    {
                        glTranslatef(0, -t_size, 0);
                        drawBrickT(1, 1, t_size, _tex_leave, 1);
                    }
                    glPopMatrix();
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 0, -1);
            }
        }
        glPopMatrix();
        
        // draw leaf for top side
        glPushMatrix();
        {
            glTranslatef(-w / 2, 10 + h, l / 2);
            
            for (int i = 0; i < l; i++)
            {
                glPushMatrix();
                for (int j = 0; j < w; j++)
                {
                    int t_size = top_map[i][j];
                    drawBrickT(1, 1, t_size, _tex_leave, 1);
                    glTranslatef(1, 0, 0);
                }
                glPopMatrix();
                glTranslatef(0, 0, -1);
            }
        }
        glPopMatrix();
    }
    glPopAttrib();
    glPopMatrix();

}
