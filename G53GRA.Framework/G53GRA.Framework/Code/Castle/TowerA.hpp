//
//  TowerA.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerA_hpp
#define TowerA_hpp

#include "DisplayableObject.h"
#include "VectorMath.h"
#include "BrickUtil.hpp"

class TowerA :
    public DisplayableObject

{
public:
    TowerA();
    ~TowerA();
    
    void Display();
    
protected:
    GLuint _textB1, _textB2, _textB3, _textB4;
    
    void DrawSubTower1();
    void DrawSubTower2();
    void DrawSubTower3();
    void DrawRoof();
    void Decorate();
    void DrawWindow();
    
    void setWallColor1(int r, int g, int b, int s);
    
};


#endif /* TowerA_hpp */
