//
//  QAtom.h
//  GLTest
//
//  Created by Dawei Li on 9/26/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#ifndef GLTest_QAtom_h
#define GLTest_QAtom_h

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#endif

#include<string>
#include "Point3D.h"
using namespace std;

class QAtom{
public:
    float px,py,pz,r;
    float cr,cg,cb;
    int serial;
    char atomName;
    string fullName;
    int chainIndex;
    unsigned int atomColor;
    
    float spacefillr, covalentr;
    
    int tx,ty; // starting places for texture
    
    bool hetatomFlag;
    //CubeMapSamp s;
    QAtom(std::string st);
    /*
    OctaMapSamp s;
    */
    inline Point3D P() const {
        return Point3D(px, py, pz);
    }
    /*
    bool AssignNextTextPos(int texsize);
    
    
    void SmoothTexture(vector<Byte> &t, int siz){
    }
    void SmoothTexture(vector<int> &t, int siz){
    }
    
    void FillTexture(vector<Byte> &texture, int textsize) {
        s.FillTexture(texture, textsize, tx,ty, cr,cg,cb);
    }
    
    Point3f trp; float trr; // transormed pos and radius
    
    void Transform(const Point3f &ax,const  Point3f &ay,const Point3f &az){
        Point3f p(px,py,pz);
        trp[0]=p*ax;
        trp[1]=p*ay;
        trp[2]=p*az;
        //printf("[r=%f] (%f %f %f) -> (%f %f %f)\n", r, px,py,pz, trp[0],trp[1],trp[2] );
    }
    
    void ScaleTransl(float dx, float dy, float scale){
        trp[0]=(trp[0]+dx)*scale;
        trp[1]=(trp[1]+dy)*scale;
        trr=r*scale;
        //printf("[%f*%f] -> (%f %f %f %f)\n", r, scale, trp[0],trp[1],trp[2],trr );
    }
    
    // color from atom name
    void getCol(const char* st);
    
    static bool readError;
    static char lastReadError[1024];
    */
    void UpdateColors(float mode);
    /*
    // sends impostors on screnbuffer
    void Draw();
    // sends halos on screnbuffer
    void DrawHalo();
    void DrawShadowmap();
    
    // for GPU ao.
    void DrawOnTexture();
    
    static unsigned int VBOsize();
    void VBOfill(float * f);
    static void VBOsetup(float *f);
    
    //inline bool operator <= (QAtom const &a) const {  return px<=a.px;  };
    inline bool operator <  (QAtom const &a) const {  return px< a.px;  };
    */     
};

#endif
