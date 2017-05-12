//
//  CastleWall.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef CastleWall_hpp
#define CastleWall_hpp

#include "Building.hpp"
#include "BrickUtil.hpp"

class CastleWall :
        public Building
{
public:
    CastleWall(float w);

    ~CastleWall();

    void Display();

protected:
    float _width;

    void DrawWall(float w);

    void DrawTooth(float w);
};

#endif /* CastleWall_hpp */
