#include"../VIRTUAL_PROGMEM/Virtual_Mem.h"
#include<iostream>
#include<fstream>

char* input(char* name);
char* output(char* name, char* data);
char* create(char* name);
char* deleteF(char* name);

int main(){
    VIRTUAL_MEMORY *pointer = new VIRTUAL_MEMORY(input,output,create,deleteF);
    pointer ->createVariableContainer("Temp",1);

    int value = pointer ->retrieveValueFromContainer("Temp");
    std::cout << value;

    pointer ->modifyVariableContainer("Temp",5);

    pointer ->retrieveValueFromContainer("Temp");

}

char* input(char* name){
    char*data;
    std::ifstream file;
    file.open(name,std::ios::in);
    while(!file.eof())
        file >> data;
    file.close();
    return data;
}
char* output(char* name, char* data){
    //char*data;
    std::ofstream file;
    file.open(name,std::ios::out);
    file << data;
    file.close();
}

char* create(char* name){
    std::ifstream file;
    file.open(name,std::ios::in);
    file.close();
}

char* deleteF(char* name){
    std::ifstream file;
    file.open(name,std::ios::in);
    std::remove(name);
}