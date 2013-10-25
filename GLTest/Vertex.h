//
//  Vertex.h
//  GLTest
//
//  Created by Dawei Li on 10/25/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#ifndef GLTest_Vertex_h
#define GLTest_Vertex_h

#include <string>

using namespace std;

class Vertex{
public:
    double px, py, pz, dx, dy, dz;
    
    Vertex(double ptx, double pty, double ptz, double drx, double dry, double drz);
};

#endif
