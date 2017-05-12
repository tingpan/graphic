//
//  TowerC.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef TowerC_hpp
#define TowerC_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"

class TowerC :
        public Building
{
public:
    TowerC();

    ~TowerC();

    void Display();

protected:

    void DrawSubTower1();

    void DrawRoof();
};

#endif /* TowerC_hpp */
