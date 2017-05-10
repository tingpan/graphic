//
//  TowerB.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerB_hpp
#define TowerB_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"

class TowerB :
public Building

{
public:
    TowerB();
    ~TowerB();
    
    void Display();
    
protected:
    void DrawWall(float w);
    void DrawRoof();
    void DrawTop();
    
    void Decorate();
};



#endif /* TowerB_hpp */
