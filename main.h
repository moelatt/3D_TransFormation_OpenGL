#ifndef MAIN_H
#define MAIN_H
#if defined (__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include  <GL/glut.h>
#endif
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int screen_width = 600, screen_height = 600;
char spinRotate = 0;
vector<vector<double> > myArray, edgeArr;
string fileName = "bunny_scene";
int windowID, windowXY, windowXZ, windowYZ, extraWin, win;
int translate, scale, rotation, list ,continues, exits, animation;
float vx1, vy1, vz1, vx2, vy2, vz2;
float minX, maxX, minY, maxY, minZ, maxZ;
float newX, newY, newZ, tX, tY, tZ, bigMin, bigMax;
char cha;
const char* arr[] = {"Object-1", "Object-2", "Object-3", "Object-4", "Object-5", 
                     "Object-6"};
void display();
void displayWOBD();
void renderString(const char* text, int length, int x, int y, int id);
void reshape(int , int);
void reshapeNoBD(double, double);
void readDataFromFile();
void writeDataToFile();
void boundingBox();
float renderMinMax(int);
float winRatio(float coord, char);
void drawLine();
void drawLineWithoutBB();
void drawXY();
void drawXZ();
void drawYZ();
void drawXYWithoutBD();
void drawXZWithoutBD();
void drawYZWithoutBD();
void extraWinFunc();
void createMenuFunc();
void translateFunc(int id);
void translation(float, float, float, int);
void scaleFunc(int id);
void rotateFunc(int id);
void rotationMethod(double, double, double, double, double, double, double, int);
inline void mainMenu(int id) {;}
void list_menuFunc(int id){};
void continueFunc(int);
void exitFunc(int id);
#endif