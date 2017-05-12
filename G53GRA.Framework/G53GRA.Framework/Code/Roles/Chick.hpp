//
//  Chick.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 2017/5/9.
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
    Chick(float speed, float radius);
    ~Chick();
    
    void Display();
    void Update(const double& deltaTime);
private:
    float _speed, _radius;
    
};
#endif /* Chick_hpp */
