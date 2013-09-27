//
//  Mol.h
//  GLTest
//
//  Created by Dawei Li on 9/26/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//
//  This code is modified from http://qutemol.sourceforge.net/

#ifndef GLTest_Mol_h
#define GLTest_Mol_h

#include "QAtom.h"
#include "Bond.h"

#include<vector>

using namespace std;

class Mol{
public:
    
    //bool sticks; // true if ball_and_stick mode
    //float colMode; // mode = 0 -> per atom
    
    //void SetColMode(float newColMode);
    
    //void SetBallAndSticks(float rad=0.3);
    //void SetLicorice(float rad=0.5);
    //void SetSpaceFill();
    
    vector<QAtom> atom;
    vector<Bond> bond;
    
    float px,py,pz,r;
    bool textureAssigned;
    
    //void Draw();
    //void DrawShadowmap(bool invert);
    
    //void DrawHalos();
    //void DrawOnTexture();
    
    //void FindBonds();
    
    void ComputeSize();
    //bool ReadPdb(const char *filename);
    
    //float tx0,ty0,tx1,ty1;  // bounding box transformed
    //void Transform(const Point3f &ax,const  Point3f &ay,const Point3f &az);
    
    /*
    void ScaleTransl(float scale){
        for (int i=0; i<atom.size(); i++)
            atom[i].ScaleTransl( -tx0, -ty0, scale);
    }
    
    void SmoothTexture(vector<Byte> &t, int siz){
        for (int i=0; i<atom.size(); i++)
            atom[i].SmoothTexture(t,siz);
    }
    
    void SmoothTexture(vector<int> &t, int siz){
        for (int i=0; i<atom.size(); i++)
            atom[i].SmoothTexture(t,siz);
    }
    
    void Zero() {
        for (int i=0; i<atom.size(); i++)
            atom[i].s.Zero();
    }
    
    void DuplicateTexels(vector<Byte> &t, int size);
    
    void FillTexture(vector<Byte> &texture, const vector<int> &sumtable,
                     int texsize, float div );
    
    bool ReassignTexture(int textsize); // for a given texture size
    
    void ReassignTextureAutosize(); // autoselect texture size
    
    int NTotTexels(){
        return atom.size()*atom[0].s.TotTexSizeX()*atom[0].s.TotTexSizeY();
    }
    
    // vertexbuffer objects
    unsigned int vboNorm, vboShadow, vboAO;
    unsigned int vboNormSt, vboShadowSt, vboAOSt; // for the sticks
    */
     
    Mol();
    
    /*
    char filename[1024];
    char* GetFilenameTex();
    char* GetFilenameSnap();
    char* GetMolName();
    
    bool PrepareAOstep(int nsteps=1);
    float PredictAO();
    
    void ResetAO();
    
    bool DoingAO();  // true if AO is being computed
    bool DecentAO(); // true if AO (being computed) is "decent"
    
    // for testing purposes
    bool PrepareAOSingleView();
    */
     
    int natm, nhetatm;  // number of atoms of type hetatm and not ...
    /*
    bool IsReady(){return ready;}
    */
    void UpdateColors();
    /*
private:
    */
    void AddBond(int i, int j);
    /*
    void PrepareAOallAtOnce();
    
    int AOdoneLvl;
    
    void PrepareAOstart();
    bool AOready;
    bool AOstarted;
    
     */
    bool ready;
};


#endif
