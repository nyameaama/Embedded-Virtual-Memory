//#include"../VIRTUAL_PROGMEM/Virtual_Mem.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

char* input(char* name);
void output(char* name, char* data);
void create(char* name);
void deleteF(char* name);

char* sub = ".txt";

int main(){
    //VIRTUAL_MEMORY *pointer = new VIRTUAL_MEMORY(input,output,create,deleteF);
    //pointer ->createVariableContainer("Temp",1);

    //int value = pointer ->retrieveValueFromContainer("Temp");
    //std::cout << value;

    //pointer ->modifyVariableContainer("Temp",5);

    //pointer ->retrieveValueFromContainer("Temp");

    //pointer ->deleteVariableContainer("Temp");

    create("Temp");
    //delete pointer;
}

char* input(char* name){
    char*data;
    std::ifstream file;
    file.open(strcat(name,sub),std::ios::in);
    while(!file.eof())
        file >> data;
    file.close();
    return data;
}

void output(char* name, char* data){
    //char*data;
    std::ofstream file;
    file.open(strcat(name,sub),std::ios::out);
    file << data;
    file.close();
}

void create(char* name){
    std::ifstream file;
    file.open(strcat(name,sub),std::ios::in);
    if(file.is_open()){
        std::cout << "Opened";
    }else{
        std::cout << "Failed";
    }
    file.close();
}

void deleteF(char* name){
    std::ifstream file;
    file.open(strcat(name,sub),std::ios::in);
    std::remove(name);
}