//
//  Building.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef Building_hpp
#define Building_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"

class Building:
public DisplayableObject
{
public:
    Building()
    {
        _textB1 = Scene::GetTexture("./Textures/Castle/brick1.bmp");
        _textB2 = Scene::GetTexture("./Textures/Castle/brick2.bmp");
        _textB3 = Scene::GetTexture("./Textures/Castle/brick3.bmp");
        _textB4 = Scene::GetTexture("./Textures/Castle/brick4.bmp");
        _textB5 = Scene::GetTexture("./Textures/Castle/brick5.bmp");
        _textB6 = Scene::GetTexture("./Textures/Castle/brick6.bmp");
        _textFlag = Scene::GetTexture("./Textures/Castle/flag.bmp");
        
        _text_f = 1;
    }
    
    void SetWindowColor(int r, int g, int b, int s)
    {
        _winColor[0] = r;
        _winColor[1] = g;
        _winColor[2] = b;
        _winColor[3] = s;
    }
    
protected:
    struct _Floor{
        GLuint _tex;
        int _height;
    };
    
    GLuint _textB1, _textB2, _textB3, _textB4, _textB5, _textB6, _textWD, _textFlag;
    int _text_f;
    int _winColor[4] = {192, 212, 238, 30};
    
    void DrawWindow1()
    {
        glPushMatrix();
        glTranslatef(0, 0, 0.3);
        drawBrickT(1, 1.5, 0.5, _textB5, 1);
        glPopMatrix();
        
        glPushMatrix();
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        {
            glTranslatef(0, 0.5, 0);
            setWallColor(_winColor[0], _winColor[1], _winColor[2], _winColor[3]);
            drawBrickR(1, 1.5, 2);
            glTranslatef(0.25, 2, 0);
            drawBrickR(1, 1, 0.5);
            glTranslatef(0.25, 0.5, 0);
            drawBrickR(1, 0.5, 0.25);
        }
        glPopAttrib();
        glPopMatrix();
    }
    
    
    void DrawWindow2()
    {
        glPushMatrix();
        {
            glTranslatef(1, 0, 0.8);
            drawBrickT(1, 0.5, 3.7, _textB1, 1);
            glTranslatef(1.5, 0, 0);
            drawBrickT(1, 0.5, 3.7, _textB1, 1);
        }
        glPopMatrix();
        
        
        glPushMatrix();
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        {
            glTranslatef(0, 0, 0.05);
            setWallColor(_winColor[0], _winColor[1], _winColor[2], _winColor[3]);
            for(int i = 0; i < 3; i++) {
                drawBrickR(0.5, 1, 3.5);
                glTranslatef(1.5, 0, 0);
            }
            
        }
        glPopAttrib();
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(-0.5, 3.5, 0.5);
            drawBrickT(1, 5, 0.8, _textB6, 1);
            glTranslatef(1, 0.8, 0);
            drawBrickT(1, 3, 0.8, _textB6, 1);
        }
        glPopMatrix();
        
    }
    
    void DrawFlag()
    {
        glPushMatrix();
        {
            setWallColor(230, 230, 230, 20);
            drawBrickR(0.5, 0.5, 15);
            glTranslatef(0, 5, -0.5);
            drawBrickT(12, 1, 10, _textFlag, 10);
        }
        glPopMatrix();
    }
    
};
#endif /* Building_hpp */
