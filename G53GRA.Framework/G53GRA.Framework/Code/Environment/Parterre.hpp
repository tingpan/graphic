//
//  Parterre.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef Parterre_hpp
#define Parterre_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"

#endif /* Parterre_hpp */
class Parterre :
public DisplayableObject
{
public:
    Parterre(int w, int h, GLuint tex);
    ~Parterre();
    void Display();
    
    void width(int w)
    {
        _width = w;
    }
    
private:
    GLuint _texBrick, _texFlower;
    int _width;
    int _height;
};
