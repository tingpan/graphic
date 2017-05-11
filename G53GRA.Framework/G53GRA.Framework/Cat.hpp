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
#include "Animation.h"

class Cat:
public DisplayableObject,
public Animation
{
public:
    Cat();
    void Display();
    void Update(const double& deltaTime);

    
protected:
    GLuint _texBody, _texFace, _texFaceSide, _texHandSide, _texLeftHand, _texLeftLeg, _texLegSide, _texRightHand, _texRightLeg, _texBack;
    
    GLuint _headTex[6];
    GLuint _bodyTex[6];
    GLuint _leftHandTex[6];
    GLuint _rightHandTex[6];
    GLuint _leftLegTex[6];
    GLuint _rightLegTex[6];
    
    float _time;
    float _loop = 0.3;
    int step = 30;
    
};
#endif /* Cat_hpp */
