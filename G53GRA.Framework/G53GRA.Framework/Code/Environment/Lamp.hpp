//
//  lamp.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class creates the lamp model.

#ifndef Lamp_hpp
#define Lamp_hpp

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
    
    // Draw each lamp bulb
    void DrawLamp();

};

#endif /* Lamp_hpp */


