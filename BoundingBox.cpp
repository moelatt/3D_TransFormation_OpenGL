#include "main.h"
float renderMinMax(int digit){
  float x = myArray.at(0).at(1);
  float y = myArray.at(0).at(2);
  float z = myArray.at(0).at(3);
  if((int)myArray.size() > 0){
    switch (digit){
      case 1:
          for(int i = 0; i < (int)myArray.size(); i++){ // x-min
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(1+ 3*j) < x){
                x = myArray.at(i).at(1+ 3*j);
              }
            }
          } return x; break;
      case 2:    
          for(int i = 0; i < (int)myArray.size(); i++){ // x-max
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(1+ 3*j) > x){
                x = myArray.at(i).at(1+ 3*j);
              }
            }
          } return x; break;
      case 3:
          for(int i = 0; i < (int)myArray.size(); i++){ // y-min
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(2+ 3*j) < y){
                y = myArray.at(i).at(2+ 3*j);
              }
            }
          } return y; break;
      case 4:
          for(int i = 0; i < (int)myArray.size(); i++){  // y-max
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(2+ 3*j) > y){
                y = myArray.at(i).at(2+ 3*j);
              }
            }
          } return y; break;
      case 5:
          for(int i = 0; i < (int)myArray.size(); i++){ // z-min
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(3+ 3*j) < z){
                z = myArray.at(i).at(3+ 3*j);
              }
            }
          } return z; break;
      case 6:
          for(int i = 0; i < (int)myArray.size(); i++){ // z-max
            for(int j = 0; j < myArray.at(i).at(0); j++){
              if(myArray.at(i).at(3+ 3*j) > z){
                z = myArray.at(i).at(3+ 3*j);
              }
            }
          } return z; break;
      default: break;
    }
  }
  return 0;
}
void boundingBox(){
    minX = renderMinMax(1); maxX = renderMinMax(2);
    minY = renderMinMax(3); maxY = renderMinMax(4);
    minZ = renderMinMax(5); maxZ = renderMinMax(6);
    float totalMin = minX;
    float totalMax = maxX;
    if(minY < totalMin){
        totalMin = minY;
    }
    if(minZ < totalMin){
        totalMin = minZ;
    }
    if(maxY > totalMax){
        totalMax = maxY;
    }
    if(maxZ > totalMax){
        totalMax = maxZ;
    }
    bigMin = totalMin;
    bigMax = totalMax;
}
float winRatio(float coord, char axis){
 float winRatio, newcoord;
 switch (axis){
  case 'x':
    winRatio = (coord - minX) / (bigMax - bigMin);
    newcoord =  290 * winRatio ;
    return newcoord; break;
  case 'y':
    winRatio = (coord - minY) / (bigMax - bigMin);
    newcoord = 290 * winRatio;
    return newcoord; break;
  case 'z':
    winRatio = (coord - minZ) / (bigMax - bigMin);
    newcoord = 290 * winRatio;
    return newcoord; break;
  default: break;
 }
  return coord;
}