//
//  Tree.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class generates a tree with random shape.

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

    int **createRandomMap(int l, int h, int max); // generate the height map

    float w, h, l;
    int **side_map,  **top_map; // member variable for store the height map of the tree

    GLuint _tex_branch, _tex_leave;
};

#endif /* Tree_hpp */
