//
//  TowerA.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerA_hpp
#define TowerA_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"

class TowerA :
    public Building

{
public:
    TowerA();
    ~TowerA();
    
    void Display();
    
protected:
    
    void DrawSubTower1();
    void DrawSubTower2();
    void DrawSubTower3();
    void DrawRoof();
    void DrawTop();
};


#endif /* TowerA_hpp */
