//
//  MyFloor.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 7/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
#pragma once
#ifndef MyFloor_hpp
#define MyFloor_hpp

#include "DisplayableObject.h"
#include <stdio.h>


class MyFloor :
public DisplayableObject
{
public:
    MyFloor();
    ~MyFloor(){};
    
    void Display();
    
private:
    GLuint _texBrick1, _texBrick2, _texBrick3, _texBrick4;
};


#endif /* MyFloor_hpp */
