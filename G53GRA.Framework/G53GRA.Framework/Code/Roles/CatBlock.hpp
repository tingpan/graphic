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
#include "Input.h"

class CatBlock :
        public DisplayableObject,
        public Animation,
        public Input
{
public:
    CatBlock();

    ~CatBlock();

    void Display();

    void Update(const double &deltaTime);

    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleMouse(int button, int state, int x, int y);


private:
    GLuint _blockTex, _catTex;

    float texCoords[8];
    int spriteWidth;
    int spriteFrame;
    bool runAnimate;
    double time;

};

#endif /* CatBlock_hpp */
