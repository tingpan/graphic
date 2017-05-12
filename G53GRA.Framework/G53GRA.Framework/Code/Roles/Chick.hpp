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
#include "Input.h"

class Chick :
        public DisplayableObject,
        public Animation,
        public Input
{
public:
    Chick(float speed, float radius);

    ~Chick();

    void Display();

    void Update(const double &deltaTime);
    
    void HandleKey(unsigned char key, int state, int x, int y);

private:
    float _speed, _radius;
    bool runAnimate;

};

#endif /* Chick_hpp */
