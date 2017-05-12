//
//  Floor.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 7/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class draw the floor of the scene.

#ifndef Floor_hpp
#define Floor_hpp

#include "DisplayableObject.h"
#include <stdio.h>


class Floor :
        public DisplayableObject
{
public:
    Floor();

    ~Floor() {};

    void Display();

private:
    GLuint _texBrick1, _texBrick2, _texBrick3, _texBrick4;
};


#endif /* Floor_hpp */
