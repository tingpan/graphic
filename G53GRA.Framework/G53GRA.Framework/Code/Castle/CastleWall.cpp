//
//  CastleWall.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "CastleWall.hpp"

CastleWall::CastleWall(float w)
{
    _width = w;
}

CastleWall::~CastleWall()
{

}

void CastleWall::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
    glDisable(GL_COLOR_MATERIAL);

    glPushMatrix();
    {
        DrawWall(_width);
        glTranslatef(-1, 20, 1);
        DrawTooth(_width + 2);

        glTranslatef(_width + 2, 0, -1);
        glRotatef(90, 0, 1, 0);
        DrawTooth(8);

        glTranslatef(0, 0, -_width - 1);
        DrawTooth(8);

        glTranslatef(8, 0, -1);
        glRotatef(-90, 0, 1, 0);
        DrawTooth(_width + 2);

    }
    glPopMatrix();
    glPopAttrib();
    glPopMatrix();

}

void CastleWall::DrawWall(float w)
{

    float f = 1;
    float l = 8;

    _Floor floor[3] = {
            _Floor{_textB4, 7},
            _Floor{_textB2, 6},
            _Floor{_textB4, 5},
    };

    glPushMatrix();
    {
        for (int i = 0; i < 3; i++)
        {
            drawBrickT(l, w, floor[i]._height, floor[i]._tex, f);
            glTranslatef(0, floor[i]._height, 1);
            if (i != 2)
            {
                drawBrickT(l + 2, w, 1, _textB1, f);
                glTranslatef(0, 1, -1);
            }
        }
    }
    glPopMatrix();

}

void CastleWall::DrawTooth(float w)
{
    glPushMatrix();
    for (int i = 0; i < w; i++)
    {
        float h = 6;
        float offset = 1;

        if (i % 2 == 0)
        {
            h = 4;
            offset = -1;
        }
        drawBrickT(1, 1, h, _textB1, _text_f);
        glTranslatef(1, offset, 0);
    }
    glPopMatrix();

}

