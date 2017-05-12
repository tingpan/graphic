//
//  Spotlight.cpp
//  G53GRA.Framework
//
//  Created by TingMiao on 11/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#include "Spotlight.hpp"
#include "VectorMath.h"

Spotlight::Spotlight()
{
    SetupLight1();
    SetupLight2();
    SetupLight3();
}

Spotlight::~Spotlight()
{
    
}

void Spotlight::Update(const double& deltaTime)
{
    
    time += deltaTime;
    if (time > 20 * M_PI) time -= 20 * M_PI;
    
    float position[7][4] = {
        { -500.f, 500.f, -1000.f, 1.f },
        { 500.f, 500.f, -1000.f, 1.f },
        { -500.f, 500.f, -100.f, 1.f },
        { 500.f, 500.f, -100.f, 1.f },
        
        { -300.f, 300.f, -1800.f, 1.f },
        { 300.f, 300.f, -1800.f, 1.f },
        {-100.f, 0.f, -1500.f, 1.f }
    };
    
    float direction[2][3] = {
        {0.f, -1.f, 0.f},
        {sin(time/10), .5f, -1.f}
    };
    
    for ( int i = 0; i < 4; i ++)
    {
        glLightfv(group1[i], GL_POSITION, position[i]);
        glLightfv(group1[i], GL_SPOT_DIRECTION, direction[0]); //set direction
    }
    
    for ( int i = 0; i < 2; i ++)
    {
        glLightfv(group2[i], GL_POSITION, position[i + 4]);
        glLightfv(group2[i], GL_SPOT_DIRECTION, direction[0]); //set direction
    }
    
    glLightfv(GL_LIGHT5, GL_POSITION, position[6]);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, direction[1]); //set direction
}

void Spotlight::Display()
{
    
}

void Spotlight::SetupLight1()
{
    float ambient[]  = { .3f, .3f, .3f, 1.f };      // ambient light (blue)
    float diffuse[]  = { .6f, .6f, .9f, 1.f };      // diffuse light (blue)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    
    for (int i = 0; i < 4; i ++) {
        glLightfv(group1[i], GL_AMBIENT, ambient);      // set ambient parameter of light source
        glLightfv(group1[i], GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
        glLightfv(group1[i], GL_SPECULAR, specular);    // set specular parameter of light source
        
        glLightf(group1[i], GL_SPOT_EXPONENT, 5.f);         //set spotlight exponent
        glLightf(group1[i], GL_SPOT_CUTOFF, 45.f);          //set spotlight cutoff
        
        // Set the non-constant attenuation function with linear and quadratic parameters
        glLightf(group1[i], GL_LINEAR_ATTENUATION, 0.0005f);
        glEnable(group1[i]);
    }
}

void Spotlight::SetupLight3()
{
    float ambient[]  = { .3f, .3f, .3f, 1.f };      // ambient light (blue)
    float diffuse[]  = { .3f, .6f, .9f, 1.f };      // diffuse light (blue)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    
    // Attach properties to single light source (GL_LIGHT1)
    glLightfv(GL_LIGHT5, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT5, GL_SPECULAR, specular);    // set specular parameter of light source
    
    glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 5.f);         //set spotlight exponent
    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 20.f);          //set spotlight cutoff
    
    glEnable(GL_LIGHT5);
    
}


void Spotlight::SetupLight2()
{
    float ambient[]  = { .3f, .3f, .3f, 1.f };      // ambient light (blue)
    float diffuse[]  = { .3f, .5f, .9f, 1.f };      // diffuse light (blue)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    
    for(int i = 0; i < 2; i++)
    {
        glLightfv(group2[i], GL_AMBIENT, ambient);      // set ambient parameter of light source
        glLightfv(group2[i], GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
        glLightfv(group2[i], GL_SPECULAR, specular);    // set specular parameter of light source
        
        glLightf(group2[i], GL_SPOT_EXPONENT, 10.f);         //set spotlight exponent
        glLightf(group2[i], GL_SPOT_CUTOFF, 25.f);          //set spotlight cutoff
        glLightf(group2[i], GL_LINEAR_ATTENUATION, 0.0008f);
        
        glEnable(group2[i]);
    }
}


void Spotlight::HandleKey(unsigned char key, int state, int mx, int my)
{
    if (!state) return;
    
    switch (key)
    {
        case 'o':
        case 'O':
            for ( int i = 0; i < 4; i ++)
            {
                glEnable(group1[i]);
            }
            
            for ( int i = 0; i < 2; i ++)
            {
                glEnable(group2[i]);
            }
            
            glEnable(GL_LIGHT5);
            break;
        case 'P':
        case 'p':
            for ( int i = 0; i < 4; i ++)
            {
                glDisable(group1[i]);
            }
            
            for ( int i = 0; i < 2; i ++)
            {
                glDisable(group2[i]);
            }
            
            glDisable(GL_LIGHT5);
            
            break;
    }
}

