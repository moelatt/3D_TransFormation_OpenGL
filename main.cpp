#include "main.h"
#include "readWriteFile.cpp"
#include "draw3dBD.cpp"
#include "BoundingBox.cpp"
#include "transformation.cpp"
#include "renderString.cpp"

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(screen_width, screen_height);
    win = glutCreateWindow("Project-2");
    glClearColor(0, 0.15, 0.15, 0);
    readDataFromFile();
    cha = 'y';
    // cout << "\n" << "Use Bounding Box or Not <enter: y/n> ";
    // cin >> cha;
    while((cha != 'y' && cha != 'Y') && (cha != 'n' && cha != 'N')){
        cout << "Error! you can only enter y or n"<< endl;
        cout << "Use Bounding Box or Not <enter: y/n> ";
        cin >> cha;
    }
    extraWinFunc();
    if(cha == 'y' || cha == 'Y'){
        drawLine();
        glutSetWindow(win);
        createMenuFunc();
        glutSetCursor(GLUT_CURSOR_CROSSHAIR);
        glutDisplayFunc(display);
    }
    else if(cha == 'n' || cha == 'N'){
        drawLineWithoutBB();
        glutSetWindow(win);
        createMenuFunc();
        glutSetCursor(GLUT_CURSOR_CROSSHAIR);
        glutDisplayFunc(displayWOBD);
    }
    glutMainLoop();
    return 0;
}
// ================================================================================//
void drawLine(){
    windowXY = glutCreateSubWindow(win, 5, 5, 293, 292);
    reshape(293,292);
    glutDisplayFunc(drawXY);

	windowXZ = glutCreateSubWindow(win, 302, 5, 293, 292);
    reshape(293,292);
    glutDisplayFunc(drawXZ);

	windowYZ = glutCreateSubWindow(win, 5, 300, 293, 294);
    reshape(293,294);
    glutDisplayFunc(drawYZ);

}
void drawLineWithoutBB(){
    windowXY = glutCreateSubWindow(win, 5, 5, 293, 292);
    reshapeNoBD(293,292);
    glutDisplayFunc(drawXYWithoutBD);

	windowXZ = glutCreateSubWindow(win, 302, 5, 293, 292);
    reshapeNoBD(293,292);
    glutDisplayFunc(drawXZWithoutBD);

	windowYZ = glutCreateSubWindow(win, 5, 300, 293, 294);
    reshapeNoBD(293,294);
    glutDisplayFunc(drawYZWithoutBD);

}
// ===============================================================================//
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    extraWinFunc();
    glFlush();
    glutSwapBuffers();
    glutSetWindow(windowXY);
    drawXY();
    glutSetWindow(windowXZ);
    drawXZ();
    glutSetWindow(windowYZ);
    drawYZ();
}
void displayWOBD(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    extraWinFunc();
    glFlush();
    glutSwapBuffers();
    glutSetWindow(windowXY);
    drawXYWithoutBD();
    glutSetWindow(windowXZ);
    drawXZWithoutBD();
    glutSetWindow(windowYZ);
    drawYZWithoutBD();
}
void reshape(int width, int height){
	glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 293, -20, 293, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
void reshapeNoBD(double width, double height){
	glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.1, 1.0, -0.1, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
// ========================================================================= //
void createMenuFunc(){
    translate = glutCreateMenu(translateFunc);
        for(int i = 0; i < myArray.size(); i++){
            glutAddMenuEntry(arr[i], i); 
        } 
    scale = glutCreateMenu(scaleFunc);
        for(int i = 0; i < myArray.size(); i++){
            glutAddMenuEntry(arr[i], i); 
        }
    rotation = glutCreateMenu(rotateFunc);
        for(int i = 0; i < myArray.size(); i++){
            glutAddMenuEntry(arr[i], i); 
        }
    exits = glutCreateMenu(exitFunc);
        glutAddMenuEntry("Exit-Program", 0);

    continues = glutCreateMenu(continueFunc);
        glutAddMenuEntry("Use", 0);
        glutAddMenuEntry("Not Use", 1);

    glutCreateMenu(mainMenu);
    glutAddSubMenu("Translation", translate);
    glutAddSubMenu("Rotation", rotation);
    glutAddSubMenu("Scaling", scale);
    glutAddSubMenu("Bounding Box", continues);
    glutAddSubMenu("Exit", exits);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// =====================================================================//
// ================================================================================//
void continueFunc(int id){
    if(id == 0){
        drawLine();
    }
    else if(id == 1){
        drawLineWithoutBB();
    }
    glutSetWindow(windowXY);
    glutPostRedisplay();
    glutSetWindow(windowXZ);
    glutPostRedisplay();
    glutSetWindow(windowYZ);
    writeDataToFile();
    glutPostRedisplay();
}
void exitFunc(int id){
    cout << endl;
    writeDataToFile();
    cout << "Any change will be saved in the original file the data is read in." << endl;
    cout << "Bye Bye!!" << "\n" <<endl;
    exit(0);
}