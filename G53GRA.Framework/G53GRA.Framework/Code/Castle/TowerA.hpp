//
//  TowerA.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class define the sub building model.

#ifndef TowerA_hpp
#define TowerA_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"
#include "Animation.h"

class TowerA :
        public Building,
        public Animation
{
public:
    TowerA();

    ~TowerA();

    void Display();

    void Update(const double &deltaTime);

protected:

    GLuint _texClock;

    void DrawSubTower1();

    void DrawSubTower2();

    void DrawSubTower3();

    void DrawRoof();

    void DrawTop();

    void DrawClock();

    float _time;

};


#endif /* TowerA_hpp */
