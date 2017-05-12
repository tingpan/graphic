//
//  Pond.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class create the round pond.

#include "Pond.hpp"
#include <cmath>

Pond::Pond()
        : xGridDims(21), zGridDims(21), time(0.0)
{
    // load textures
    _texPond = Scene::GetTexture("./Textures/Environment/water.bmp");
    _texBrick = Scene::GetTexture("./Textures/Environment/brick2.bmp");
    
    // initialise the grids texture coordinate memory
    texCoords = new float[(xGridDims + 1) * (zGridDims + 1) * 2];

    matAmbient[0] = 0.9f;   // set the material properties of the grid
    matAmbient[1] = 0.95f;
    matAmbient[2] = 0.9f;
    matAmbient[3] = 1.0f;

    matDiffuse[0] = 1.0f;
    matDiffuse[1] = 1.0f;
    matDiffuse[2] = 1.0f;
    matDiffuse[3] = 1.0f;

    matSpecular[0] = 1.0f;
    matSpecular[1] = 1.0f;
    matSpecular[2] = 1.0f;
    matSpecular[3] = 1.0f;

    matShininess = 128;
}


Pond::~Pond()
{
    if (texCoords != NULL)
    {
        delete[] texCoords;
        texCoords = NULL;
    }
}

void Pond::Display()
{

    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glDisable(GL_COLOR_MATERIAL);

        // no need for rotation since the shape is circle
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(scale[0], scale[1], scale[2]);
    
        // draw the container
        DrawBrickCircle(10, 2);
        glTranslatef(0, 1.5, 0);
        
        // draw water
        DrawPond(10);
        glTranslatef(0, -1.5, 0);
        glScaled(0.5, 0.5, 0.5);
        
        // draw the decoration
        DrawBrickCircle(1, 5);
        glTranslatef(0, 5, 0);
        DrawBrickCircle(3, 1);
        DrawBrickCircle(2, 1);
        glTranslatef(0, 0.8, 0);
        DrawPond(2);
    }
    glPopAttrib();
    glPopMatrix();
}

void Pond::Update(const double &deltaTime)
{
    float radius;
    time += deltaTime; // accumulated run time

    // use dimensions of the grid to find a sensible radius to rotate about
    radius = sqrtf((1.0f / xGridDims) * (1.0f / xGridDims) + (1.0f / zGridDims) * (1.0f / zGridDims));
    radius /= 4.0f; // make sure this radius does not intersect any of the other texture locations

    // calculate the texture coordinate for each of the grid points
    for (int j = 0; j <= zGridDims; j++)
    {
        for (int i = 0; i <= xGridDims; i++)
        {
            texCoords[(i + (xGridDims + 1) * j) * 2 + 0] =
                    (float) sin(time + (double) j) * radius + (float) i / (float) xGridDims;
            texCoords[(i + (xGridDims + 1) * j) * 2 + 1] =
                    (float) cos(time + (double) i) * radius + (float) j / (float) zGridDims;
        }
    }
}


void Pond::DrawPond(float r)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // set up the material
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMateriali(GL_FRONT, GL_SHININESS, matShininess);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texPond);
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);

    //  apply the bresenham algorithm to draw the filled circle
    int i = 0, j = r;

    float d = 3 - 2 * r;

    glBegin(GL_QUADS);

    do
    {
        // draw a line between each pair of the symmetrical point
        for (int k = -j; k <= j; k++)
        {
            DrawPondQuad(i, k);
        }

        if (i != 0)
        {
            for (int k = -j; k <= j; k++)
            {
                DrawPondQuad(-i, k);
            }
        }

        if (i != j)
        {
            for (int k = -i; k <= i; k++)
            {
                DrawPondQuad(j, k);
            }

            if (j != 0)
            {
                for (int k = -i; k <= i; k++)
                {
                    DrawPondQuad(-j, k);
                }
            }
        }

        if (d < 0)
        {
            d += 4 * i + 6;
            i++;

        } else
        {
            d += 4 * (i - j) + 10;
            j--;
            i++;
        }

    } while (i <= j);
    glEnd();
    
    glPopAttrib();
}

// draw each water textured quad
void Pond::DrawPondQuad(int i, int j)
{
    glNormal3f(0.0f, 1.0f, 0.0f);  // specify the quads normal
    float y = 0;

    // get the index of the coordinate array
    int i_i = i + 10;
    int i_j = j + 10;

    // get the tex coordinate from the array with the index
    glTexCoord2fv(&texCoords[((i_i + 1) + i_j * (xGridDims + 1)) * 2]);
    glVertex3f(i + 1.0f, y, j);

    glTexCoord2fv(&texCoords[(i_i + 1 + (i_j + 1) * (xGridDims + 1)) * 2]);
    glVertex3f(i + 1.0f, y, j - 1.0f);

    glTexCoord2fv(&texCoords[(i_i + (i_j + 1) * (xGridDims + 1)) * 2]);
    glVertex3f(i, y, j - 1.0f);

    glTexCoord2fv(&texCoords[(i_i + i_j * (xGridDims + 1)) * 2]);
    glVertex3f(i, y, j);

}

void Pond::DrawBrickCircle(float r, float h)
{
     //  apply the bresenham algorithm to draw the circle outline
    float x = 0.0f, z = r;
    float d = 3 - 2 * r;

    do
    {
        // get eight point by the circle's symmetry property
        glPushMatrix();
        {
            // x, y
            glTranslatef(x, 0, z);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // x, -y
            glTranslatef(0, 0, -2 * z);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // -x, -y
            glTranslatef(-2 * x, 0, 0);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // -x, y
            glTranslatef(0, 0, 2 * z);
            drawBrickT(1, 1, h, _texBrick, 1);
        }
        glPopMatrix();

        glPushMatrix();
        {
            // y, x
            glTranslatef(z, 0, x);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // y, -x
            glTranslatef(0, 0, -2 * x);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // -y, -x
            glTranslatef(-2 * z, 0, 0);
            drawBrickT(1, 1, h, _texBrick, 1);
            
            // -y, x
            glTranslatef(0, 0, 2 * x);
            drawBrickT(1, 1, h, _texBrick, 1);
        }
        glPopMatrix();

        if (d < 0)
        {
            d += 4 * x + 6;
            x++;
        } else
        {
            d += 4 * (x - z) + 10;
            z--;
            x++;
        }

    } while (x <= z);
}
