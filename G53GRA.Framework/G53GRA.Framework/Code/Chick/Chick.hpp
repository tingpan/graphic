//
//  Chick.hpp
//  G53GRA.Framework
//
//  Created by Ting Pan on 2017/5/9.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//

#ifndef Chick_hpp
#define Chick_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"
#include "Animation.h"

class Chick:
public DisplayableObject,
public Animation
{
public:
    Chick();
    void Display();
    void Update(const double& deltaTime);
    
};
#endif /* Chick_hpp */
