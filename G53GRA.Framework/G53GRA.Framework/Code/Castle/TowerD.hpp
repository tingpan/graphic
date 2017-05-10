//
//  TowerD.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerD_hpp
#define TowerD_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"

class TowerD :
public Building

{
public:
    TowerD();
    ~TowerD();
    
    void Display();
    
protected:
    void DrawWall(float w);
    void DrawRoof();
    void DrawTop();
    
    void Decorate();
};



#endif /* TowerD_hpp */
