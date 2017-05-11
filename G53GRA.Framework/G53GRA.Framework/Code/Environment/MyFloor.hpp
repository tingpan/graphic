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
    GLuint _texBrick;
    
    float diffuse[6][4] = {
        {101.f, 163.f, 53.f, 1.0f},
        {0.f, 119.f, 61.f, 1.0f },
        {125.f, 177.f, 106.f, 1.0f},
        {127.f, 176.f, 60.f, 1.0f},
        {128.f, 131.f, 103.f, 1.0f},
        {128.f, 131.f, 103.f, 1.0f}
    };
    
    int diffusemax[400][400];
};


#endif /* MyFloor_hpp */
