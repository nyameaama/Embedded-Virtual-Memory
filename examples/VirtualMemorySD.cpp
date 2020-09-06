//#include<Arduino.h>
#include<SPI.h>
#include<SD.h>
#include"Virtual_Mem.h"

//Operation Functions prototypes:
//Input
char* inputDatafromSD(char* filename);
//Output
void outputDatatoSD(char* filename,char* data);
//Create
void createfileOnSD(char* filename);
//Remove
void deletefileOnSD(char* filename);

//Create Virtual Memory Object
 //Add input function, output function, create function and delete function as parameters.
VIRTUAL_MEMORY *OperationObject = new VIRTUAL_MEMORY(inputDatafromSD,outputDatatoSD,createfileOnSD,deletefileOnSD);

void setup(){
   if(!SD.begin()){
        Serial.println("Card failed, or not present.");
        while(1);
    }
}

void loop(){
    //Create a file with filename "ExampleFilename" and placeholer data "ExampleData"
    //Placeholder data can be of type char* and int
    OperationObject ->createVariableContainer("ExampleFilename","ExampleData");

    //Modify data in a specified file
    OperationObject ->modifyVariableContainer("ExampleFilename","ExampleNewData");

    //Retrieve data from a specified file 
    OperationObject ->retrieveValueFromContainer("ExampleFilename");


}

//Operation functions
//Input
char* inputDatafromSD(char* filename){
    File temp;
    temp = SD.open(filename,FILE_READ);
    char* buffer;
    if(temp){
        while(temp.available()){
            buffer = temp.read();
        }
    }
    return buffer;
}
//Output
void outputDatatoSD(char* filename,char* data){
    //Output data to SD
    File temp;
    temp = SD.open(filename,FILE_WRITE);
    temp.print(data);
    temp.close();
}
//Create
void createfileOnSD(char* filename){
    //Create File 
    File tempCreate;
    tempCreate = SD.open(filename,FILE_WRITE);
    tempCreate.close();
}
//Remove
void deletefileOnSD(char* filename){
    SD.remove(file);
}