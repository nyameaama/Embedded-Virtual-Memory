#include<iostream>
#include"_nativeParser.h"

int main(){
    char* testArray = "test";
    _VIRTUAL_MEMORY_PARSER *object = new _VIRTUAL_MEMORY_PARSER();
    std::cout << object -> appendTemplate(testArray);
    delete object;
    return 0;
}