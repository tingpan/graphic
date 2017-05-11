//
//  CatBlock.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef CatBlock_hpp
#define CatBlock_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "BrickUtil.hpp"

class CatBlock:
public DisplayableObject,
public Animation

{
public:
    CatBlock();
    ~CatBlock();
    
    void Display();
    void Update(const double& deltaTime);
    
private:
    GLuint _blockTex, _catTex;
    
    float width, height;
    
    float texCoords[8];
    int spriteWidth;
    int spriteFrame;
    bool runAnimate;
    double time;
    
    float dx;
};

#endif /* CatBlock_hpp */
