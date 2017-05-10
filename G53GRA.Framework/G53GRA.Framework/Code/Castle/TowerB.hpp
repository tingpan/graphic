//
//  TowerB.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerB_hpp
#define TowerB_hpp

#include <stdio.h>
#include "VectorMath.h"
#include "DisplayableObject.h"
#include "BrickUtil.hpp"

class TowerB :
public DisplayableObject

{
public:
    TowerB();
    ~TowerB();
    
    void Display();
    
protected:
    GLuint _textB1, _textB2, _textB3, _textB4;
    
    void DrawWall(float w);
    void DrawRoof();
    void DrawTop();
    
    void Decorate();
    
    void setWallColor1(int r, int g, int b);
    
};



#endif /* TowerB_hpp */
