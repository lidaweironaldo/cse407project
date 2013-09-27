//
//  Mol.cpp
//  GLTest
//
//  Created by Dawei Li on 9/26/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#include "Mol.h"

#include<algorithm>
#include<math.h>

using namespace std;

Mol::Mol()
{
    natm = nhetatm = 0;
    ready = false;
}

void Mol::AddBond(int i, int j)
{
    bond.push_back( Bond( atom[i], atom[j] ) );
}

void Mol::ComputeSize(){
    // bounding box!
    float x0,y0,z0,x1,y1,z1;
    if (atom.size()>0)
        x0=x1=atom[0].px;
    y0=y1=atom[0].py;
    z0=z1=atom[0].pz;
    for (int i=1; i<atom.size(); i++) {
        if (x1>atom[i].px) x1=atom[i].px;
        if (y1>atom[i].py) y1=atom[i].py;
        if (z1>atom[i].pz) z1=atom[i].pz;
        if (x0<atom[i].px) x0=atom[i].px;
        if (y0<atom[i].py) y0=atom[i].py;
        if (z0<atom[i].pz) z0=atom[i].pz;
    }
    px=(x0+x1)/2;
    py=(y0+y1)/2;
    pz=(z0+z1)/2;
    int k=-4;
    r=sqrt( (x1-x0+k)*(x1-x0+k) + (y1-y0+k)*(y1-y0+k) + (z1-z0+k)*(z1-z0+k) );
    r*=0.5;
    
    //printf("pos=(%f %f %f) size=%f\n",px,py,pz,r);
    
    
}