//
//  MySunlight.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 8/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef MySunlight_hpp
#define MySunlight_hpp

#define direction(x,y,z) position(x,y,z);

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"

class MySunlight :
public DisplayableObject,
public Animation
{
    public:
    MySunlight();
    ~MySunlight();
    
    void Display(){}; // Override virtual function but do not draw any object (unseen light source)
    
    void Update(const double& deltaTime);
    
    //	inline void direction(float dx, float dy, float dz) { position(dx, dy, dz); }
    
    private:
    float ambient[4], diffuse[4], specular[4]; // member variables for the reflectance model parameters
};

#endif /* MySunlight_hpp */


