#include "main.h"

void readDataFromFile(){
    vector<double> data;
    double vertices;
    fstream myFile;
    myFile.open(fileName);
    while (myFile >> vertices){
        data.push_back(vertices);
    }
    myFile.close();
    auto XYpoints = data.begin(); 
    int polyTotalForBuffer = (int)*XYpoints;

    int i = 0;
    while(i < polyTotalForBuffer){
        vector<double> Vx, Vy; 
        myArray.push_back(Vx);
        edgeArr.push_back(Vy);  
        double vertices = *(++XYpoints);
        myArray.at(i).push_back(vertices);
        int j = 0, h = 0;
        while(j < vertices){
            myArray.at(i).push_back(*(++XYpoints)); 
            myArray.at(i).push_back(*(++XYpoints)); 
            myArray.at(i).push_back(*(++XYpoints));
            j++;
        } 
        int edge = (int)*(++XYpoints);
        edgeArr.at(i).push_back(edge);
        while(h < edge){
            edgeArr.at(i).push_back(*(++XYpoints));
            edgeArr.at(i).push_back(*(++XYpoints));
            h = h + 1;
        }
        i = i + 1;
    }
}
void writeDataToFile(){
    ofstream outputFile;
    outputFile.open(fileName);
    outputFile << myArray.size() << endl;
    for (int i = 0; i < myArray.size(); i++) {
        outputFile << endl;
        for (int j = 0; j < myArray.at(i).size(); j++){
            outputFile << myArray.at(i).at(j) << " " ;
            if(j % 3 == 0){
                outputFile << endl;
            }
        }
        outputFile << edgeArr.at(i).at(0);
        outputFile << endl;
        for (int k = 1; k < edgeArr.at(i).size(); k+=2){
            outputFile << edgeArr.at(i).at(k) << " ";
            outputFile << edgeArr.at(i).at(k+1) << " ";
            outputFile << endl;
        }
        outputFile << endl;
    }
}