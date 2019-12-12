#include "main.h"

// Transformation
void translateFunc(int id){
    double x,y,z;
    cout << "Please enter translation value for" << " object-" << 1 + id << " x, y, and z <eg. 0.1 0.2 0.4> :" << endl;
    cout << "x point: "; cin >> x;
    cout << "y point: "; cin >> y;
    cout << "z point: "; cin >> z;
    translation(x, y, z, id);
    glutSetWindow(windowXY);
    glutPostRedisplay();
    glutSetWindow(windowXZ);
    glutPostRedisplay();
    glutSetWindow(windowYZ);
    writeDataToFile();
    glutPostRedisplay();
}
void translation(float x, float y, float z, int id){
  int objectSize = myArray.at(id).at(0), i = 0;
  while(i < objectSize){
        myArray.at(id).at(1+3*i) =  (myArray.at(id).at(1+3*i) + x);
        myArray.at(id).at(2+3*i) =  (myArray.at(id).at(2+3*i) + y);
        myArray.at(id).at(3+3*i) =  (myArray.at(id).at(3+3*i) + z);
        i = i + 1;
    }
}
void rotateFunc(int id){
    double x1, y1, z1, x2, y2, z2, degree;
    cout << "Please enter" << " object-" << 1+id <<" first points for x1, y1, z1 < eg: 0.1 0.1 0.1 > " << endl;
    cout << "x1 point: "; cin >> x1;
    cout << "y1 point: "; cin >> y1;
    cout << "z1 point: "; cin >> z1;
    cout << "Please enter" << " object-"<< 1+id << " Second points for x2, y2, z2 < eg: 0.2 0.2 0.2 > "<< endl;
    cout << "x2 point: "; cin >> x2;
    cout << "y2 point: "; cin >> y2;
    cout << "z2 point: "; cin >> z2;
    cout << "Please enter degree for rotation: " ;
    cin >> degree ;
    if(x1 == x2){
        x2 = x2 + 0.1;
    }
    if(y1 == y2){
        y2 = y2 + 0.1;
    }
    if(z1 == z2){
        z2 = z2 + 0.1;
    }
    degree = (double)degree /180.0 * 3.14159265359;
    vx1 = x1; vy1 = y1; vz1 = z1;
    vx2 = x2 * 200; vy2 = y2 * 200; vz2 = z2 * 200;
    if(vx2 > 280){
        vx2 = 280;
    }
    if(vy2 > 300){
        vy2 = 280;
    }
    if(vz2 > 300){
        vz2 = 280;
    }
    rotationMethod(x1, x2, y1, y2, z1, z2, degree, id);
    glutSetWindow(windowXY);
    glutPostRedisplay();
    glutSetWindow(windowXZ);
    glutPostRedisplay();
    glutSetWindow(windowYZ);
    writeDataToFile();
    glutPostRedisplay();
}

void rotationMethod(double x1, double x2, double y1, double y2, double z1, double z2, double degree, int id){
  int objectSize = myArray.at(id).at(0), i = 0;
  float mag = sqrt(pow((x2 - x1), 2) + pow((y2 -y1), 2) + pow((z2 - z1), 2)); 
	float a = (x2 - x1) / mag; 
	float xs = (y2 -y1) / mag; 
	float ys = (z2 - z1) / mag; 
	float r = sqrt(pow(xs, 2) + pow(ys, 2));
        
    cout << objectSize << endl;
    while(i < objectSize) {
		newX = myArray.at(id).at(1+i*3) - x1; 
		newY = myArray.at(id).at(2+i*3) - y1; 
		newZ = myArray.at(id).at(3+i*3) - z1; 

		tX = newX; 
		tY = (ys/r)*newY - (xs/r)*newZ;
		tZ = (xs/r)*newY + (ys/r)*newZ; 

		newX = r*tX - a*tZ; 
		newY = tY; 
		newZ = a*tX + r*tZ; 

		tX = newX*cos(degree) - newY*sin(degree);
		tY = newX*sin(degree) + newY*cos(degree);
		tZ = newZ; 

		newX = r*tX + a*tZ; 
		newY = tY;
		newZ = r*tZ - a*tX;

		tX = newX;
		tY = (ys/r)*newY + (xs/r)*newZ; 
		tZ = (ys/r)*newZ - (xs/r)*newY; 

        myArray.at(id).at(1+i*3) = (tX + x1); 
        myArray.at(id).at(2+i*3) = (tY + y1);
        myArray.at(id).at(3+i*3) = (tZ + z1);
        i = i +1; 
	}
}
void scaleFunc(int id){
    int vertices = myArray.at(id).at(0), i = 0, j = 0;
    double addX = 0, addY = 0 , addZ = 0, scale, dVertices = (double)vertices; 
    double centX, centY, centZ;

    cout << "\n" << "Please enter the magnitude to scale the object-" << id + 1 << "\n"
    << "0 to 1 decrease size, 1 to 10 increase size: ";
    cin >> scale;
    while(j < vertices){
       addX += myArray.at(id).at(1+j*3);
       addY += myArray.at(id).at(2+j*3);
       addZ += myArray.at(id).at(3+j*3);
       j = j + 1;
    }
	centX = addX / dVertices;
	centY = addY / dVertices;
	centZ = addZ / dVertices; 
	while(i < vertices) {
        myArray.at(id).at(1+i*3) = scale*(myArray.at(id).at(1+i*3) - centX) + centX;
        myArray.at(id).at(2+i*3) = scale*(myArray.at(id).at(2+i*3) - centY) + centY;
        myArray.at(id).at(3+i*3) = scale*(myArray.at(id).at(3+i*3) - centZ) + centZ;
        i = i + 1; 
    }
    glutSetWindow(windowXY);
    glutPostRedisplay();
    glutSetWindow(windowXZ);
    glutPostRedisplay();
    glutSetWindow(windowYZ);
    writeDataToFile();
    glutPostRedisplay();
}


