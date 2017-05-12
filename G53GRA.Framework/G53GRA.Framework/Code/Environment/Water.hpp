//
//  Water.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 10/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "DisplayableObject.h"
#include "Animation.h"
#include "BrickUtil.hpp"

#include <string>

class Water :
        public DisplayableObject,
        public Animation
{
public:
    Water();

    //    Water(const int& gridX, const int& gridZ, const std::string& filename);
    ~Water();

    void Display();

    void Update(const double &delteTime);

    void HandleKey(unsigned char key, int state, int x, int y);

private:
    GLuint _texWater, _texBrick, _texCat;

    int xGridDims, zGridDims;
    float *texCoords;
    double time;
    bool frozen;

    float matAmbient[4];      // matrial properties of the grid
    float matDiffuse[4];
    int matShininess;
    float matSpecular[4];

    void DrawWater(float r);

    void DrawBrickCircle(float r, float h);

    void DrawWaterQuad(int i, int j);
};
