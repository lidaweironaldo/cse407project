//
//  Bond.cpp
//  GLTest
//
//  Created by Dawei Li on 9/26/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#include "Bond.h"
#include "QAtom.h"

Bond::Bond(const QAtom &_a,const QAtom &_b):
atmA(&_a), atmB(&_b)
{
    
    
    a=_a.P();
    b=_b.P();
    
    //dir=(a-b).Normalize();
    
    //float rada= _a.covalentr;
    //float radb= _b.covalentr;
    
    /*a-=dir*(rada*0.60);
     b+=dir*(radb*0.60);*/
    //lenght=(a-b).Norm();
    //startp=dir^Point3f(0,0,1);
    //if (startp.SquaredNorm()<0.1) startp=dir^Point3f(0,1,0);
    //startp.Normalize();
    
    //hetatomFlag=_a.hetatomFlag || _b.hetatomFlag;
    
    //UpdateColors();
    
}