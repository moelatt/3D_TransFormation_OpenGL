#include "main.h"

void drawXY(){
	glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    string str = "Window-XY with BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 68, 280, 1);
    glClearColor(0.05,0.0,0.0,0);
    boundingBox();
    glLineWidth(1.8);
	glBegin(GL_LINES);
		for (int i = 0; i < edgeArr.size(); i++) { 
			for (int j = 1; j < edgeArr.at(i).size(); j = j+2) {  
				float x1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+1) ;    
        float y1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+2) ; 
        float x2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+1);   
        float y2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+2);   
				glColor3f(0.8, 0.4, 0.9); 
				glVertex2f(winRatio(x1, 'x'), winRatio(y1, 'y'));
				glVertex2f(winRatio(x2, 'x'), winRatio(y2, 'y'));
			}
		}
	glEnd();

    glLineWidth(0.8);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vx1, vy1);
      glVertex2f(vx2, vy2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(-10, 136, 0.0f);
    //    glVertex3f(275, 136, 0.0f);
    //    glVertex3f(136, -10, 0.0f);
    //     glVertex3f(136, 275, 0.0f);
    // glEnd();
    glFlush();
}

//==============================================================================================//
void drawXZ(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    string str = "Window-XZ with BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 68, 280, 1);  
    glClearColor(0.0,0.05,0.0,0);
    boundingBox();
    glLineWidth(1.8);
    glBegin(GL_LINES);
      for (int i = 0; i < edgeArr.size(); i++) { 
          for (int j = 1; j < edgeArr.at(i).size(); j = j+2) { 
            float x1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+1);    
            float z1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+3);    
        
            float x2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+1);   
            float z2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+3);   

            glColor3f(0.8, 0.9, 0.4);
            glVertex2f(winRatio(x1, 'x'),winRatio(z1, 'z'));
            glVertex2f(winRatio(x2, 'x'), winRatio(z2, 'z'));
          }
      }
    glEnd(); 
    glLineWidth(0.8);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vx1, vz1);
      glVertex2f(vx2, vz2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(-10, 136, 0.0f);
    //    glVertex3f(275, 136, 0.0f);
    //    glVertex3f(136, -10, 0.0f);
    //     glVertex3f(136, 275, 0.0f);
    // glEnd();
    glFlush(); 
}
// =========================================================================================//
void drawYZ(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    string str = "Window-YZ with BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 68, 280, 1);  
    glClearColor(0.0,0.0,0.05,0);
    boundingBox();
    glLineWidth(1.8);
    glBegin(GL_LINES);
      for (int i = 0; i < edgeArr.size(); i++) {
        for (int j = 1; j < edgeArr.at(i).size(); j = j+2) {  
          float y1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+2) ;    
          float z1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+3) ;   

          float y2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+2) ;   
          float z2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+3) ;   
          glColor3f(0.4, 0.8, 0.9);
          glVertex2f(winRatio(y1, 'y'), winRatio(z1, 'z'));
          glVertex2f(winRatio(y2, 'y'), winRatio(z2, 'z'));
        }
      }
    glEnd();
    glLineWidth(1);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vy1, vz1);
      glVertex2f(vz2, vz2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(-10, 136, 0.0f);
    //    glVertex3f(275, 136, 0.0f);
    //    glVertex3f(136, -10, 0.0f);
    //     glVertex3f(136, 275, 0.0f);
    // glEnd();
    glFlush(); 
}
// =============================================================================================//
// =============================================================================================//
// ==============================================================================================//
// ============================================================================//
// Draw object without Bounding Box
void drawXYWithoutBD(){
	glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    string str = "Window-XY without BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 58, 280, 1);
    glClearColor(0.05,0.0,0.0,0);
    boundingBox();
    glLineWidth(1.8);
	glBegin(GL_LINES);
		for (int i = 0; i < edgeArr.size(); i++) { 
			for (int j = 1; j < edgeArr.at(i).size(); j = j+2) {  
				float x1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+1) ;    
        float y1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+2) ; 
        float x2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+1);   
        float y2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+2);   
				glColor3f(0.8, 0.4, 0.9); 
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
			}
		}
	glEnd();
  // glBegin(GL_TRIANGLES);
  //   glColor3f(1, 0, 0);
  //   glVertex3f(1, 0, 0);
  //   glColor3f(0, 1, 0);
  //   glVertex3f(0, 1, 0);
  //   glColor3f(0, 0, 1);
  //   glVertex3f(0, 0, 1);
  // glEnd();
    glLineWidth(0.8);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vx1, vy1);
      glVertex2f(vx2, vy2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(0, 0.45f, 0.0f);
    //    glVertex3f(0.9, 0.45f, 0.0f);
    //    glVertex3f(0.45, 0.0f, 0.0f);
    //     glVertex3f(0.45, 0.9f, 0.0f);
    // glEnd();
    glFlush();
}

void drawXZWithoutBD(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    string str = "Window-XZ without BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 58, 280, 1);  
    glClearColor(0.0,0.05,0.0,0);
    boundingBox();
    glLineWidth(1.8);
    glBegin(GL_LINES);
      for (int i = 0; i < edgeArr.size(); i++) { 
          for (int j = 1; j < edgeArr.at(i).size(); j = j+2) { 
            float x1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+1);    
            float z1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+3);    
        
            float x2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+1);   
            float z2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+3);   

            glColor3f(0.8, 0.9, 0.4);
            glVertex2d(x1, z1);
            glVertex2d(x2, z2);
          }
      }
    glEnd(); 
    glLineWidth(0.8);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vx1, vz1);
      glVertex2f(vx2, vz2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(0, 0.45f, 0.0f);
    //    glVertex3f(0.9, 0.45f, 0.0f);
    //    glVertex3f(0.45, 0.0f, 0.0f);
    //     glVertex3f(0.45, 0.9f, 0.0f);
    // glEnd();
    glFlush(); 
}
// =========================================================================================//
void drawYZWithoutBD(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    string str = "Window-YZ without BB";
    glColor3f(1,1,1);
    renderString(str.data(), str.size(), 58, 280, 1);  
    glClearColor(0.0,0.0,0.05,0);
    boundingBox();
    glLineWidth(1.8);
    glBegin(GL_LINES);
      for (int i = 0; i < edgeArr.size(); i++) {
        for (int j = 1; j < edgeArr.at(i).size(); j = j+2) {  
          float y1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+2) ;    
          float z1 = myArray.at(i).at((edgeArr.at(i).at(j) - 1)*3+3) ;   

          float y2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+2) ;   
          float z2 = myArray.at(i).at((edgeArr.at(i).at(j+1) - 1)*3+3) ;   
          glColor3f(0.4, 0.8, 0.9);
          glVertex2f(y1, z1);
          glVertex2f(y2, z2);
        }
      }
    glEnd();
    glLineWidth(1);
    glColor3f(1, 0.5,0.7);
    glBegin(GL_LINES);
      glVertex2f(vy1, vz1);
      glVertex2f(vz2, vz2);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    // glBegin(GL_LINES);
    //    glVertex3f(0, 0.45f, 0.0f);
    //    glVertex3f(0.9, 0.45f, 0.0f);
    //    glVertex3f(0.45, 0.0f, 0.0f);
    //     glVertex3f(0.45, 0.9f, 0.0f);
    // glEnd();
    glFlush(); 
}