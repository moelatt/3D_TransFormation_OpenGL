#include "main.h"

// Display Text
void renderString(const char* text, int length, int x, int y, int id){
    glMatrixMode(GL_PROJECTION);
    double *array = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,array);
    glLoadIdentity();
    glOrtho(0,293, 0, 294, -1,3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i = 0; i < length; i++){
        switch (id){
        case 0:
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]); break;
        case 1:
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]); break;
        default:
            break;
        }
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(array);
    glMatrixMode(GL_MODELVIEW);
}
void extraWinFunc(){
glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    string str = "Welcome";
    string str2 = "From";
    string str1 = "Grapic World!";
    string str3 = "Right Click Here";
    string str4 = "To See Menu";
    glColor3f(0.4,1.0,0.9);
    renderString(str.data(), str.size(), 195, 125, 0);
    glColor3f(1,0.5,0.2);
    renderString(str2.data(), str2.size(), 205, 110, 0);
    glColor3f(1,0.5,1.0);
    renderString(str1.data(), str1.size(), 185, 95, 0);
    glColor3f(1,0.2,0.3);
    renderString(str3.data(), str3.size(), 180, 65, 0);
    glColor3f(1,0.9,1.0);
    renderString(str4.data(), str4.size(), 187, 50, 0);
}