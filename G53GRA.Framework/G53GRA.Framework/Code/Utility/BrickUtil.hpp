//
//  BrickUtil.hpp
//  G53GRA.Framework
//
//  Created by TingMiao on 9/5/2017.
//  Copyright © 2017 w.o.c.ward. All rights reserved.
//

#ifndef BrickUtil_hpp
#define BrickUtil_hpp

inline void drawBrickR(float l, float w, float h){
    
    // LEFT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(-1.f, 0.0f, 0.0f);
        glVertex3f(0, h, -l);
        glVertex3f(0, 0, -l);
        glVertex3f(0, 0, 0);
        glVertex3f(0, h, 0);
    }
    glEnd();
    
    // FFRONT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.0f, 0.0f, 1.f);
        glVertex3f(0, h, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(w, 0, 0);
        glVertex3f(w, h, 0);
    }
    glEnd();
    
    // RIGHT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(1.f, 0.0f, 0.0f);
        glVertex3f(w, h, 0);
        glVertex3f(w, 0, 0);
        glVertex3f(w, 0, -l);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BACK SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 0.0f, -1.f);
        glVertex3f(w, h, -l);
        glVertex3f(w, 0, -l);
        glVertex3f(0, 0, -l);
        glVertex3f(0, h, -l);
    }
    glEnd();
    
    // TOP SIDE
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 1.0f, 0.f);
        glVertex3f(0, h, -l);
        glVertex3f(0, h, 0);
        glVertex3f(w, h, 0);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BOT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, -1.0f, 0.0f);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -l);
        glVertex3f(w, 0, -l);
        glVertex3f(w, 0, 0);
    }
    glEnd();
    
}

#endif /* BrickUtil_hpp */
