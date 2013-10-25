//
//  Mesh.h
//  GLTest
//
//  Created by Dawei Li on 10/25/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#ifndef GLTest_Mesh_h
#define GLTest_Mesh_h

#include "Vertex.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Mesh
{
public:
    vector<Vertex> vertices;
    vector<Triangle> trianlges;
    Mesh();
};


#endif
