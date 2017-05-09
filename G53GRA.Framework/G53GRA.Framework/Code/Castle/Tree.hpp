//
//  Tree.hpp
//  G53GRA.Framework
//
//  Created by Hang on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "DisplayableObject.h"
#include "VectorMath.h"

class Tree :
public DisplayableObject

{
public:
    Tree();
    ~Tree();
    
    void Display();
    
protected:
    
    void DrawBrickR(float l, float w, float h);
    void DrawBrickT(float l, float w, float h);
    void DrawTrunk();
    void DrawMainBranches();
    void DrawSubBranches();
    void Decorate();
    
    void setWallColor1(int r, int g, int b);
    float w, h, l, leaf_size, dist, min;
    float leaf_front, leaf_back, leaf_left, leaf_right, leaf_top;

};

#endif /* Tree_hpp */