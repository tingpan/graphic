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

inline void drawBrickT(float l, float w, float h, int textureID, float f){
    
    // LEFT SIDE
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glBegin(GL_QUADS);
    {
        glNormal3f(-1.f, 0.0f, 0.0f);
        
        glTexCoord2f(0, h/f);
        glVertex3f(0, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(l/f, 0);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(l/f, h/f);
        glVertex3f(0, h, 0);
    }
    glEnd();
    
    // FRONT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.0f, 0.0f, 1.f);
        
        glTexCoord2f(0, h/f);
        glVertex3f(0, h, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(w/f, 0);
        glVertex3f(w, 0, 0);
        
        glTexCoord2f(w/f, h/f);
        glVertex3f(w, h, 0);
    }
    glEnd();
    
    // RIGHT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(1.f, 0.0f, 0.0f);
        
        glTexCoord2f(0, h/f);
        glVertex3f(w, h, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(w, 0, 0);
        
        glTexCoord2f(l/f, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(l/f, h/f);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BACK SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 0.0f, -1.f);
        
        glTexCoord2f(0, h/f);
        glVertex3f(w, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(w/f, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(w/f, h/f);
        glVertex3f(0, h, -l);
    }
    glEnd();
    
    // TOP SIDE
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 1.0f, 0.f);
        
        glTexCoord2f(0, l/f);
        glVertex3f(0, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, h, 0);
        
        glTexCoord2f(w/f, 0);
        glVertex3f(w, h, 0);
        
        glTexCoord2f(w/f, l/f);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BOT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, -1.0f, 0.0f);
        
        glTexCoord2f(0, l/f);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(w/f, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(w/f, l/f);
        glVertex3f(w, 0, 0);
    }
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
}
inline void drawBrickRT(float l, float w, float h, int textureID){
    
    // LEFT SIDE
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glBegin(GL_QUADS);
    {
        glNormal3f(-1.f, 0.0f, 0.0f);
        
        glTexCoord2f(0, 1);
        glVertex3f(0, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(1, 0);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(1, 1);
        glVertex3f(0, h, 0);
    }
    glEnd();
    
    // FRONT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.0f, 0.0f, 1.f);
        
        glTexCoord2f(0, 1);
        glVertex3f(0, h, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(1, 0);
        glVertex3f(w, 0, 0);
        
        glTexCoord2f(1, 1);
        glVertex3f(w, h, 0);
    }
    glEnd();
    
    // RIGHT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(1.f, 0.0f, 0.0f);
        
        glTexCoord2f(0, 1);
        glVertex3f(w, h, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(w, 0, 0);
        
        glTexCoord2f(1, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(1, 1);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BACK SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 0.0f, -1.f);
        
        glTexCoord2f(0, 1);
        glVertex3f(w, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(1, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(1, 1);
        glVertex3f(0, h, -l);
    }
    glEnd();
    
    // TOP SIDE
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, 1.0f, 0.f);
        
        glTexCoord2f(0, 1);
        glVertex3f(0, h, -l);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, h, 0);
        
        glTexCoord2f(1, 0);
        glVertex3f(w, h, 0);
        
        glTexCoord2f(1, 1);
        glVertex3f(w, h, -l);
    }
    glEnd();
    
    // BOT SIDE
    glBegin(GL_QUADS);
    {
        glNormal3f(0.f, -1.0f, 0.0f);
        
        glTexCoord2f(0, 1);
        glVertex3f(0, 0, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, -l);
        
        glTexCoord2f(1, 0);
        glVertex3f(w, 0, -l);
        
        glTexCoord2f(1, 1);
        glVertex3f(w, 0, 0);
    }
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
}


inline void setWallColor(int r, int g, int b, int s) {
    
    GLfloat mat_ambient[] = { (r-5)/255.f, (g-5)/255.f, (b-5)/255.f, 1.0f };
    GLfloat mat_diffuse[] = { r/255.f, g/255.f, b/255.f, 1.0f };
    GLfloat mat_specular[] = { (r+5)/255.f, (g+5)/255.f, (b+5)/255.f, 1.0f };
    
    GLfloat mat_shininess = s;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}

#endif /* BrickUtil_hpp */
