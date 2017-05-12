//
//  Duck.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 2017/5/11.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//
// This class creates the animating duck model.

#ifndef Duck_hpp
#define Duck_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"
#include "Animation.h"
#include "Input.h"

class Duck :
        public DisplayableObject,
        public Animation,
        public Input
{
public:
    Duck(float speed, float radius);

    ~Duck();

    void Display();

    void Update(const double &deltaTime);
    
    void HandleKey(unsigned char key, int state, int x, int y);

private:
    float _speed, _radius; //animation parameters
    bool runAnimate;

};

#endif /* Duck_hpp */
