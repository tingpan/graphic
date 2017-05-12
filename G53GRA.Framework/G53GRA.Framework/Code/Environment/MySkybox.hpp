//
//  MySkybox.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#define MySkybox_hpp

#pragma once

#include "MySkybox.hpp"
#include "DisplayableObject.h"

class MySkybox :
public DisplayableObject
{
public:
    MySkybox();
    ~MySkybox();
    
    void Display();
    
private:
    GLuint _texTop, _texBottom, _texLeft, _texRight, _texNear, _texFar;
    
};
