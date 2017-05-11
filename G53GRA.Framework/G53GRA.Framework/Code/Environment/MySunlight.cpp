//
//  MySunlight.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 8/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "MySunlight.hpp"

MySunlight::MySunlight()
{
    ambient[0] = 0.2f;    // Set the ambient colour of the light
    ambient[1] = 0.2f;
    ambient[2] = 0.2f;
    ambient[3] = 1.0f;
    
    diffuse[0] = 0.3f;    // Set the diffuse colour of the light
    diffuse[1] = 0.4;
    diffuse[2] = 0.5f;
    diffuse[3] = 1.0f;;
    
    specular[0] = .8f;   // Set the specular colour of the light
    specular[1] = .8f;
    specular[2] = .8f;
    specular[3] = .8f;
}


MySunlight::~MySunlight()
{
}

void MySunlight::Update(const double& deltaTime)
{
    // turn lighting on
    glEnable(GL_LIGHTING);
    
    // pass openGL the lighting model parameters for the Phong reflection model
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);
    
    float ldirection[] = { pos[0], pos[1], pos[2], 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, ldirection);
    
    // enable light 0
    glEnable(GL_LIGHT0);
    
    //    glDisable(GL_LIGHT0);
}
