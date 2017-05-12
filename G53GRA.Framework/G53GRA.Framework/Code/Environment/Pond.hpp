//
//  Pond.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class create the round pond.

#ifndef Pond_hpp
#define Pond_hpp

#include "DisplayableObject.h"
#include "Animation.h"
#include "BrickUtil.hpp"

#include <string>

class Pond :
        public DisplayableObject,
        public Animation
{
public:
    Pond();

    ~Pond();

    void Display();

    void Update(const double &delteTime);

private:
    GLuint _texPond, _texBrick;

    int xGridDims, zGridDims;
    float *texCoords;
    double time;

    float matAmbient[4];      // matrial properties of the grid
    float matDiffuse[4];
    int matShininess;
    float matSpecular[4];

    void DrawPond(float r);

    void DrawBrickCircle(float r, float h);

    void DrawPondQuad(int i, int j);
};

#endif /* Pond_hpp */
