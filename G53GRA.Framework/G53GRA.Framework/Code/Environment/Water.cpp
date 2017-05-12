//
//  Water.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "Water.hpp"
#include <cmath>

Water::Water()
        : xGridDims(21), zGridDims(21), frozen(false), time(0.0)
{
    //    texID = Scene::GetTexture(filename);
    _texWater = Scene::GetTexture("./Textures/Environment/water.bmp");
    _texBrick = Scene::GetTexture("./Textures/Environment/brick2.bmp");
    _texCat = Scene::GetTexture("./Textures/Castle/flag.bmp");
    // initialise the grids texture coordinate memory we will need enough memory for both the s and t coordinate at each mesh vertex
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


Water::~Water()
{
    if (texCoords != NULL)
    {
        delete[] texCoords;
        texCoords = NULL;
    }
}

void Water::Display()
{

    glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);   // position the water
    glScalef(scale[0], scale[1], scale[2]); // scale the unit water

    DrawBrickCircle(10, 2);
    glTranslatef(0, 1.5, 0);
    DrawWater(10);
    glTranslatef(0, -1.5, 0);
    glScaled(0.5, 0.5, 0.5);
    DrawBrickCircle(1, 5);
    glTranslatef(0, 5, 0);
    DrawBrickCircle(3, 1);
    DrawBrickCircle(2, 1);
    glTranslatef(0, 0.8, 0);
    DrawWater(2);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,
                  NULL); // Bind to the blank (null) buffer to stop accidentaly using the wrong texture in the next draw call

    glDisable(GL_TEXTURE_2D); // stop using texture coordinates
}

void Water::Update(const double &deltaTime)
{
    float radius;
    time += deltaTime; // overall run time


    // use dimensions of the grid to find a sensible radius to rotate about
    radius = sqrtf((1.0f / xGridDims) * (1.0f / xGridDims) + (1.0f / zGridDims) * (1.0f / zGridDims));
    radius /= 4.0f; // make sure this radius does not intersect any of the other texture locations

    // for each of the grid points calculate the texture coordinate
    if (frozen)
    {
        for (int j = 0; j <= zGridDims; j++)
        {
            for (int i = 0; i <= xGridDims; i++)
            {
                // if the water is frozen then calculate texCoord based on the sample position
                // i+(xGridDims+1) * j gives the texture position of the ith sample on the jth row
                texCoords[(i + (xGridDims + 1) * j) * 2 + 0] = (float) i / (float) xGridDims;
                texCoords[(i + (xGridDims + 1) * j) * 2 + 1] = (float) j / (float) zGridDims;
            }
        }
    } else
    {
        for (int j = 0; j <= zGridDims; j++)
        {
            for (int i = 0; i <= xGridDims; i++)
            {
                // if the water is not frozen then calculate texCoord based on the sample position + some amount offset by a spherical function
                texCoords[(i + (xGridDims + 1) * j) * 2 + 0] =
                        (float) sin(time + (double) j) * radius + (float) i / (float) xGridDims;
                texCoords[(i + (xGridDims + 1) * j) * 2 + 1] =
                        (float) cos(time + (double) i) * radius + (float) j / (float) zGridDims;
            }
        }
    }
}


void Water::DrawWater(float r)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMateriali(GL_FRONT, GL_SHININESS, matShininess);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texWater);    // Tell OpenGL which texture buffer to apply as texture
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);


    int i = 0, j = r;

    float d = 3 - 2 * r;

    glBegin(GL_QUADS);

    do
    {
        for (int k = -j; k <= j; k++)
        {
            DrawWaterQuad(i, k);
        }

        if (i != 0)
        {
            for (int k = -j; k <= j; k++)
            {
                DrawWaterQuad(-i, k);
            }
        }

        if (i != j)
        {
            for (int k = -i; k <= i; k++)
            {
                DrawWaterQuad(j, k);
            }

            if (j != 0)
            {
                for (int k = -i; k <= i; k++)
                {
                    DrawWaterQuad(-j, k);
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

void Water::DrawWaterQuad(int i, int j)
{
    glNormal3f(0.0f, 1.0f, 0.0f);  // specify the quads normal
    float y = 0;

    int i_i = i + 10;
    int i_j = j + 10;

    // specify the fourth texture coordinate and position relative to the start postion x,y,z
    glTexCoord2fv(&texCoords[((i_i + 1) + i_j * (xGridDims + 1)) * 2]);
    glVertex3f(i + 1.0f, y, j);

    // specify the third texture coordinate and position relative to the start postion x,y,z
    glTexCoord2fv(&texCoords[(i_i + 1 + (i_j + 1) * (xGridDims + 1)) * 2]);
    glVertex3f(i + 1.0f, y, j - 1.0f);

    // specify the second texture coordinate and position relative to the start postion x,y,z
    glTexCoord2fv(&texCoords[(i_i + (i_j + 1) * (xGridDims + 1)) * 2]);
    glVertex3f(i, y, j - 1.0f);

    // specify the first texture coordinate and position relative to the start postion x,y,z
    glTexCoord2fv(&texCoords[(i_i + i_j * (xGridDims + 1)) * 2]);
    glVertex3f(i, y, j);

}

void Water::DrawBrickCircle(float r, float h)
{
    float x = 0.0f, z = r;
    float d = 3 - 2 * r;

    do
    {
        glPushMatrix();
        glTranslatef(x, 0, z);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(0, 0, -2 * z);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(-2 * x, 0, 0);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(0, 0, 2 * z);
        drawBrickT(1, 1, h, _texBrick, 1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(z, 0, x);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(0, 0, -2 * x);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(-2 * z, 0, 0);
        drawBrickT(1, 1, h, _texBrick, 1);
        glTranslatef(0, 0, 2 * x);
        drawBrickT(1, 1, h, _texBrick, 1);
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
