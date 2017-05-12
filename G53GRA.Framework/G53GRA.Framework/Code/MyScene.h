//
//  MyScene.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 8/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//
// This class create the scene of the project.

#ifndef MyScene_hpp
#define MyScene_hpp

#include "../Framework/Engine/Scene.h"

class MyScene :
        public Scene
{
public:
    MyScene(int argc, char **argv, const char *title, const int &windowWidth, const int &windowHeight);

    ~MyScene() {};

private:
    void Initialise();

    void Projection();

    void DisplayCastle(float s, float x, float y, float z);

    void DisplayEnvorinment();

    void DisplayRoles();

};

#endif /* MyScene_hpp */
