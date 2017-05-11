//
//  lamp.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef lamp_hpp
#define lamp_hpp

#include "DisplayableObject.h"
#include "BrickUtil.hpp"

class Lamp :
public DisplayableObject
{
public:
    Lamp(float h);
    ~Lamp();
    void Display();

    
    
private:
    GLuint _texS1, _texLamp, _texS2;
    float _height;
    void DrawLamp();
    void SetupLight();
    
};

#endif /* lamp_hpp */


