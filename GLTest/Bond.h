//
//  Bond.h
//  GLTest
//
//  Created by Dawei Li on 9/26/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#ifndef GLTest_Bond_h
#define GLTest_Bond_h

#include "QAtom.h"
#include "Point3D.h"

class Bond{
public:
    
    Point3D a, b;
    /*
    Point3f dir;
    Point3f col1, col2;
     */
    float lenght;
    //Point3f startp; // start of parameterization
    
    const QAtom *atmA, *atmB;
    
    bool hetatomFlag;
    //Point3f cola, colb;
    void Draw();
    void DrawHalo();
    void DrawShadowmap();
    //Bond(Point3f a,Point3f b, float rada, float radb, Point3f col1, Point3f col2);
    Bond(const QAtom &a,const QAtom &b);
    
    void UpdateColors(); // copies color from atoms
    
    void DrawOnTexture();  // for GPU ao.
    bool AssignNextTextPos(int texsize);
    int tx, ty;
    
};

#endif
