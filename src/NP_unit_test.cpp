#include"_nativeParser.h"
#include"utility.h"
#include<stdint.h>
#include<iostream>

int main(){
    char* name = "randVariable";
    char* dataChar = "data Sample";
    char* empty = "";
    char* num = "77";
    int dataINT = 66;
    //_VIRTUAL_MEMORY_PARSER *object = new _VIRTUAL_MEMORY_PARSER();
    //object -> parseToVariable(name, dataINT);
    //delete object;
    VMUTIL* object2 = new VMUTIL();
    //auto size = (sizeof(name) / sizeof(name[0]));
    std::cout << object2 -> reverse(name);//my_strcat(empty,dataChar);
    delete object2;
    return 0;
}