#include<iostream>
#include<fstream>
#include"../VM.h"

//Operation Functions prototypes:
//Input
char* inputDatafromFS(char* filename);
//Output
void outputDatatoFS(char* filename,char* data);
//Create
void createfileOnFS(char* filename);
//Remove
void deletefileOnFS(char* filename);


int main(){
    //Create Virtual Memory Object
    //Add input function, output function, create function and delete function as parameters.
    VIRTUAL_MEMORY *OperationObject = new VIRTUAL_MEMORY(inputDatafromFS,outputDatatoFS,createfileOnFS,deletefileOnFS);

    //Create a file with filename "ExampleFilename" and placeholer data "ExampleData"
    //Placeholder data can be of type char* and int
    //OperationObject ->createVariableContainer("ExampleFilename","ExampleData");

    //Modify data in a specified file
    OperationObject ->modifyVariableContainer("ExampleVariableName","ExampleNewData");

    //Retrieve data from a specified file 
    OperationObject ->retrieveValueFromContainer("ExampleVariableName");


}

//Operation Functions
//Input
char* inputDatafromFS(char* filename){
    std::ifstream tempFile;
    char* data;
    tempFile.open(filename,std::ios::in);
    if(tempFile.is_open()){
        while(!tempFile.eof()){
            tempFile >> data;
        }
    }
    tempFile.close();
    return data;
}
//Output
void outputDatatoFS(char* filename,char* data){
    std::ofstream tempFile;
    tempFile.open(filename,std::ios::out);
    if(tempFile.is_open()){
        tempFile << data;
    }
    tempFile.close();
}
//Create
void createfileOnFS(char* filename){
    std::fstream tempFile;
    //Creating file in Prog Directory 
    tempFile.open(filename,std::ios::out);
    if(tempFile.is_open()){
        //File created
    }
    tempFile.close();
}
//Remove
void deletefileOnFS(char* filename){
    remove(filename);
}