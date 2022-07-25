/*MIT License

Copyright (c) 2020 Nyameaama Gambrah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "_nativeParser.h"

/*
    Separators:

    data starter - '{'
    data terminator - '}'
    data name/address - [name]
    data value - '()'
    data value pair - '(,,,)'

*/
//+1 OVERLOAD
//TYPE: 32 BIT INT, CHAR
char* _VIRTUAL_MEMORY_PARSER::parseToVariable(char* address_name, int32_t data){
    //Append to a template
    char* withoutData = appendTemplate(address_name);
    //Add data 
    char* formatted = dataToTemplate(withoutData,data);
    //Return 
    return formatted;
}
char* _VIRTUAL_MEMORY_PARSER::parseToVariable(char* address_name, char* data){
    //Append to a template
    char* withoutData = appendTemplate(address_name);
    //Add data 
    char* formatted = dataToTemplate(withoutData,data);
    //Return 
    return formatted;
}

//+1 OVERLOAD
//TYPE: 32 BIT INT, CHAR
char* _VIRTUAL_MEMORY_PARSER::parseToValuePair(char* address_name, int32_t *data){
    appendTemplate(address_name);
}

char* _VIRTUAL_MEMORY_PARSER::appendTemplate(char* address_name){
    VMUTIL *object = new VMUTIL();
    char* dataStarter = "{";
    char* dataTerminator = "}";
    char* dataNameA = "[";
    char* dataNameB = "]";
    char* dataValueA = "(";
    char* dataValueB = ")";
    char* dataPairSep = ",";
    //Create template
    char* templateX;
    object -> my_strcat(templateX,dataStarter);
    object -> my_strcat(templateX,dataNameA);
    object -> my_strcat(templateX,address_name);
    object -> my_strcat(templateX,dataNameB);
    delete object;
    return templateX;
}

 char* _VIRTUAL_MEMORY_PARSER::dataToTemplate(char* templ,int32_t data){
    VMUTIL *object = new VMUTIL();
    char* dataValueA = "(";
    char* dataValueB = ")";
    char* dataTerminator = "}";
    //Conv
    char* dataX; 
    object -> itoa(data,dataX,10);
    object -> my_strcat(templ,dataValueA);
    object -> my_strcat(templ,dataX);
    object -> my_strcat(templ,dataValueB);
    object -> my_strcat(templ,dataTerminator);
    delete object;
    return templ;
}
char* _VIRTUAL_MEMORY_PARSER::dataToTemplate(char* templ, char* data){
    VMUTIL *object = new VMUTIL();
    char* dataValueA = "(";
    char* dataValueB = ")";
    char* dataTerminator = "}";
    object -> my_strcat(templ,dataValueA);
    object -> my_strcat(templ,data);
    object -> my_strcat(templ,dataValueB);
    object -> my_strcat(templ,dataTerminator);
    delete object;
    return templ;
}

