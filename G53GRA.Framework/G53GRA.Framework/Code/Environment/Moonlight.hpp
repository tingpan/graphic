//
//  Moonlight.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 8/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class sets up the environment moonlight.

#ifndef Moonlight_hpp
#define Moonlight_hpp

#define direction(x, y, z) position(x,y,z);

#include "DisplayableObject.h"
#include "Animation.h"

class Moonlight :
        public DisplayableObject,
        public Animation
{
public:
    Moonlight();

    ~Moonlight();

    void Display() {};

    void Update(const double &deltaTime);

private:
    float ambient[4], diffuse[4], specular[4]; // reflectance model parameters
};

#endif /* Moonlight_hpp */


