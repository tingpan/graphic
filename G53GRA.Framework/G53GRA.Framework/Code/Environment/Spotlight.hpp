//
//  Spotlight.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class control the spotlight of the whole scene.

#ifndef Spotlight_hpp
#define Spotlight_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class Spotlight :
        public DisplayableObject,
        public Animation,
        public Input
{
public:
    Spotlight();

    ~Spotlight();

    void Display() {};

    void Update(const double &deltaTime);

    void HandleKey(unsigned char key, int state, int mx, int my);

private:
    bool runAnimate;
    float _time;

    void SetupLight1();

    void SetupLight2();

    void SetupLight3();

    int group1[4] = {GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4};
    int group2[2] = {GL_LIGHT6, GL_LIGHT7};
};


#endif /* Spotlight_hpp */
