//
//  SkyBox.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef SkyBox_hpp
#define SkyBox_hpp

#include "SkyBox.hpp"
#include "DisplayableObject.h"

class SkyBox :
        public DisplayableObject
{
public:
    SkyBox();

    ~SkyBox();

    void Display();

private:
    GLuint _texTop, _texBottom, _texLeft, _texRight, _texNear, _texFar;

};

#endif /* Skybox_hpp */
