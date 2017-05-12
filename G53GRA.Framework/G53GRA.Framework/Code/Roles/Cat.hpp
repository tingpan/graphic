//
//  Cat.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 2017/5/11.
//  Copyright © 2017年 w.o.c.ward. All rights reserved.
//
// This class creates the animating cat model.

#ifndef Cat_hpp
#define Cat_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"
#include "Animation.h"
#include "Input.h"

class Cat :
        public DisplayableObject,
        public Animation,
        public Input
{
public:
    Cat(float _speed, float _limit, GLuint *_textures);

    void Display();

    void Update(const double &deltaTime);
    
    void HandleKey(unsigned char key, int state, int x, int y);
    
protected:

    // textures for each body part
    GLuint _headTex[6];
    GLuint _bodyTex[6];
    GLuint _leftHandTex[6];
    GLuint _rightHandTex[6];
    GLuint _leftLegTex[6];
    GLuint _rightLegTex[6];

    // animation parameters
    float _loop = 0.3;
    float _speed, _limit, _offset, _flag, _time;
    bool runAnimate; 

};

#endif /* Cat_hpp */
