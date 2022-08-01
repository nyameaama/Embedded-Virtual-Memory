#include"Virtual_Mem.h"
#include<iostream>
#include<fstream>

char* inputDatafromFS(char* filename);
void outputDatatoFS(char* filename,char* data);
void createfileOnFS(char* filename);
void deletefileOnFS(char* filename);


int main(){
    char* name = "randVariable";
    char* dataChar = "data Sample";
    VIRTUAL_MEMORY *object = new VIRTUAL_MEMORY(inputDatafromFS,outputDatatoFS,createfileOnFS,deletefileOnFS);
    object -> createVariableContainer(name,dataChar);
    delete object;
    return 0;
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