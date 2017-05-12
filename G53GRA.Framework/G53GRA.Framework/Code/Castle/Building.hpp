//
//  Building.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This is the base class for all buildings.

#ifndef Building_hpp
#define Building_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"

class Building :
        public DisplayableObject
{
public:
    Building();

protected:
    struct _Floor
    {
        GLuint _tex;
        int _height;
    };

    void DrawWindow1();
    
    void DrawWindow2();
    
    void DrawFlag();
    
    void SetWindowColor(int r, int g, int b, int s);

    GLuint _textB1, _textB2, _textB3, _textB4, _textB5, _textB6, _textWD, _textFlag;
    int _winColor[4] = {192, 212, 238, 30}; // default window color
};

#endif /* Building_hpp */
