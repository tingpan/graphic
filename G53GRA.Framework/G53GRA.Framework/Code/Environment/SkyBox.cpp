//
//  SkyBox.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "SkyBox.hpp"

SkyBox::SkyBox()
{
    _texTop = Scene::GetTexture("./Textures/Skybox/up.bmp");
    _texBottom = Scene::GetTexture("./Textures/Skybox/down.bmp");
    _texLeft = Scene::GetTexture("./Textures/Skybox/left.bmp");
    _texRight = Scene::GetTexture("./Textures/Skybox/right.bmp");
    _texNear = Scene::GetTexture("./Textures/Skybox/back.bmp");
    _texFar = Scene::GetTexture("./Textures/Skybox/front.bmp");
}

SkyBox::~SkyBox() {}

void SkyBox::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    // LEFT SIDE
    glBindTexture(GL_TEXTURE_2D, _texLeft);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
        glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
        glVertex3f(-1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
        glVertex3f(-1.f, -1.f, 1.f);
        glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
        glVertex3f(-1.f, -1.f, -1.f);
    }
    glEnd();

    // RIGHT SIDE
    glBindTexture(GL_TEXTURE_2D, _texRight);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
        glVertex3f(1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
        glVertex3f(1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
        glVertex3f(1.f, -1.f, -1.f);
        glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
        glVertex3f(1.f, -1.f, 1.f);
    }
    glEnd();

    //  FAR SIDE
    glBindTexture(GL_TEXTURE_2D, _texFar);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
        glVertex3f(1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
        glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
        glVertex3f(-1.f, -1.f, -1.f);
        glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
        glVertex3f(1.f, -1.f, -1.f);
    }
    glEnd();

    // NEAR SIDE
    glBindTexture(GL_TEXTURE_2D, _texNear);
    glBegin(GL_QUADS);
    glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
    glVertex3f(-1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
    glVertex3f(1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
    glVertex3f(1.f, -1.f, 1.f);
    glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
    glVertex3f(-1.f, -1.f, 1.f);
    glEnd();


    // TOP SIDE
    glBindTexture(GL_TEXTURE_2D, _texTop);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
        glVertex3f(1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
        glVertex3f(-1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
        glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
        glVertex3f(1.f, 1.f, -1.f);
    }
    glEnd();

    // BOTTOM SIDE

    glBindTexture(GL_TEXTURE_2D, _texBottom);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f);  // (s,t) = (1,1)
        glVertex3f(1.f, -1.f, -1.f);
        glTexCoord2f(0.f, 1.f);  // (s,t) = (0,1)
        glVertex3f(-1.f, -1.f, -1.f);
        glTexCoord2f(0.f, 0.f);  // (s,t) = (0,0)
        glVertex3f(-1.f, -1.f, 1.f);
        glTexCoord2f(1.f, 0.f);  // (s,t) = (1,0)
        glVertex3f(1.f, -1.f, 1.f);
    }
    glEnd();

    glBindTexture(GL_TEXTURE_2D, NULL);

    glDisable(GL_TEXTURE_2D);

    glPopAttrib();
    glPopMatrix();

}
