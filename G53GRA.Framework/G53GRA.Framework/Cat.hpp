//
//  Cat.hpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#ifndef Cat_hpp
#define Cat_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"

class Cat:
public DisplayableObject
{
public:
    Cat();
    void Display();

    
protected:
    GLuint Body, Face, Head, Hand, LeftHand, LeftLeg, Leg, RightHand, RightLeg, Back;
    
};
#endif /* Cat_hpp */
