//
//  main.cpp
//  GLTest
//
//  Created by Dawei Li on 9/25/13.
//  Copyright (c) 2013 Dawei Li. All rights reserved.
//

#include<string>
#include<map>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Mol.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#endif

using namespace std;

Mol myMol;

//General Number
float sizeofsphere=0.03;

static void AddTmpBonds(string st, vector<int> &v)
{
    int startAtom=atoi( st.substr(6,5).c_str());
	// assert(startAtom >0 && (startAtom-1)<atom.size());  // this assert cannot be used anymore from a static method
	int i=1;
	while(st.size()>6+i*5+4 && isdigit(st[6+i*5+4]))
	{
        //	printf("'%s' -> '%s' (%c)\n",st.substr(6,5).c_str(),st.substr(6+i*5,5).c_str(),st[6+i*5+4]);
        int secondAtom=atoi( st.substr(6+i*5,5).c_str());
        //printf("(%i) CONECT %i -> %i\n",i,startAtom-1,secondAtom-1);
        ++i;
        v.push_back(startAtom-1);
        v.push_back(secondAtom-1);
        //AddBond(startAtom-1,secondAtom-1);
	}
    //	printf("Found %i conect\n",i);
}



bool readPdb(const char* _filename)
{
    char filename[1024];
    sprintf(filename,"%s",_filename);
    FILE *f=fopen(filename,"r");
    
    if(!f) {
        cout<<"Error reading pdb file";
        return false;
    }
    
    long size=0;
    if (fseek(f, 0, SEEK_END)==0)
        size=ftell(f);
    
    fseek(f, 0, SEEK_SET);
    char buf[82];
    buf[81]=0;
    
    myMol.atom.clear();
    myMol.bond.clear();
    myMol.textureAssigned=false;
    
    int lineN=0;
    vector<int> tmpBondVec;
    
    while (1){
        if(! fgets(buf,81,f)) break;
        lineN++;

        string st(buf);
        if ( (strcmp( st.substr(0,6).c_str(), "ATOM  ") == 0 ) ||
            (strcmp( st.substr(0,6).c_str(), "HETATM") == 0 )    ){
            myMol.atom.push_back(QAtom(st));
        }
        if(strcmp( st.substr(0,6).c_str(), "CONECT") == 0 )
            AddTmpBonds(st, tmpBondVec); 
    }
    
    myMol.nhetatm=0;  myMol.natm=0;
    for (int i=0; i<myMol.atom.size(); i++){
        if (myMol.atom[i].hetatomFlag)  myMol.nhetatm++; else myMol.natm++;
    }
    
    myMol.ComputeSize();
    
    for (int i=0; i<tmpBondVec.size(); i+=2) {
        myMol.AddBond(tmpBondVec[i],tmpBondVec[i+1]);
    }
    myMol.ready = true;
    return true;
}



void display(void)
{
    myMol = Mol();
    readPdb("/Users/dal312/Dropbox/2013_Fall/407/GLTest/GLTest/1a0j.pdb");
    //readPdb("/Users/valdeshuang/Desktop/paper/Computer_Graphics/GLTest/GLTest/1a0j.pdb");
    void drawVertics(float spheresize);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    
    
//    glMatrixMode(GL_MODELVIEW);
    //glColor3f (1.0, 1.0, 1.0);
//    glLoadIdentity ();             /* clear the matrix */
 //   glBegin(GL_LINE_STRIP);
 //   for(int i=0; i<myMol.atom.size(); i++)
 //   {
        
   //     glColor3f(0, 1, 1);
     //   cout<<myMol.atom[i].px<<' '<<i<<endl;
        
       // glVertex3f(myMol.atom[i].px,myMol.atom[i].py,myMol.atom[i].pz );
   // }
    
 //   glEnd();
//    glFlush();
    drawVertics(sizeofsphere);
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    gluPerspective(60,1, 1, 20);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void drawVertics(float spheresize)
{
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f) ;
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    void myKeys(unsigned char key, int x, int y);
    //int size=myMol.atom.size();
    //cout<<size<<endl;
    
    
   
    
    //glBegin(GL_LINE_STRIP);
    for(int i=0; i<myMol.atom.size(); i++)
    {
        
        
        glPushMatrix();
        glTranslatef(-1, -0.2, 0);
    
        glTranslatef((GLfloat)myMol.atom[i].px/20,(GLfloat)myMol.atom[i].py/20,(GLfloat)myMol.atom[i].pz/20 );
        
        switch (myMol.atom[i].atomName)
        {
            case 'C': glColor3f(0, 1, 1);break; //cyan
            case 'N':glColor3f(1, 0, 1);break;  //magenta
            case 'O':glColor3f(1,1,0); break;   //yellow
        
        
        
        }
        glutSolidSphere(spheresize,20,16);
        
        glPopMatrix();
//        glColor3f(0, 0, 1);
//        glVertex3f((GLfloat)myMol.atom[i].px,(GLfloat)myMol.atom[i].py,(GLfloat)myMol.atom[i].pz );
       
    }
    
  //  glEnd();
    
    glFlush();
}

void myInit()
{
    glClearColor(0,0,0,0);
    glColor3f(0, 0, 0);
    glPointSize(50.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glViewport(0, 0, 480, 480);



}

void myKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'q':exit(0);
        case '=':sizeofsphere+=0.005;break;
        case '-':sizeofsphere-=0.005;break;
            
    
    }



}

void idle(void)
{
    display();


}


int main(int argc, char** argv)
{
//    myMol = Mol();
//    readPdb("/Users/valdeshuang/Desktop/paper/Computer_Graphics/GLTest/GLTest/1a0j.pdb");
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (720, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("What the fuck");
     myInit();
    glutKeyboardFunc(myKeys);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}