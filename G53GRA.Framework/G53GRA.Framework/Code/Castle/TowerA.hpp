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

class TowerA :
    public DisplayableObject

{
public:
    TowerA();
    ~TowerA();
    
    void Display();
    
protected:
        
    void DrawBrickR(float l, float w, float h);
    void DrawBrickT(float l, float w, float h);
    void DrawSubTower1();
    void DrawSubTower2();
    void DrawSubTower3();
    void DrawRoof();
    void Decorate();
    
    void setWallColor1(int r, int g, int b);
    
};


#endif /* TowerA_hpp */
