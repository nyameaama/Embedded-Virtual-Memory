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
    //Format address to addr char
    char addr[6];
    object -> strcpy(addr,address_name);
    char dataStarter[2] = {"{"};
    char dataTerminator[2] = {"}"};
    char dataNameA[2] = {"["};
    char dataNameB[2] = {"]"};
    char dataPairSep[2] = {","};
    //Temp Variables
    char* tmp1;
    char* tmp2;
    //Add { + [
    tmp1 = object -> strcat(dataStarter,dataNameA);
    //Copy char* result to char[]
    char tp[5];
    object -> strcpy(tp,tmp1);
    //Add {[ + address name
    tmp2 = object -> strcat(tp,addr);
    //Copy char* result to char[]
    char tp2[10];
    object -> strcpy(tp2,tmp2);
    //Add {[address name + ]
    char* InitialTemplate = object -> strcat(tp2,dataNameB);
    //delete object;
    return tmp1;
}

 char* _VIRTUAL_MEMORY_PARSER::dataToTemplate(char* templ,int32_t data){
    VMUTIL *object = new VMUTIL();
    //Convert int to char
    std::string convTmp = object -> itoa(data);
    char* convertedData = object -> convert_to_c_str(convTmp);
    //Format data to data char
    char _data[6];
    object -> strcpy(_data,convertedData);
    char dataValueA[2] = {"("};
    char dataValueB[2] = {")"};
    char dataTerminator[2] = {"}"};
    char dataPairSep[2] = {","};

    //Temp Variables
    char* tmp1;
    char* tmp2;
    //Add ( + data
    tmp1 = object -> strcat(dataValueA,_data);
    //Copy char* result to char[]
    char tp[5];
    object -> strcpy(tp,tmp1);
    //Add (data + )
    tmp2 = object -> strcat(tp,dataValueB);
    //Copy char* result to char[]
    char tp2[10];
    object -> strcpy(tp2,tmp2);
    //Add (data + ) + }
    char* dataTemplate = object -> strcat(tp2,dataTerminator);
    delete object;
    return dataTemplate;
}

char* _VIRTUAL_MEMORY_PARSER::dataToTemplate(char* templ, char* data){
    VMUTIL *object = new VMUTIL();
    //Format data to data char
    char _data[6];
    object -> strcpy(_data,data);
    char dataValueA[2] = {"("};
    char dataValueB[2] = {")"};
    char dataTerminator[2] = {"}"};
    char dataPairSep[2] = {","};

    //Temp Variables
    char* tmp1;
    char* tmp2;
    //Add ( + data
    tmp1 = object -> strcat(dataValueA,_data);
    //Copy char* result to char[]
    char tp[5];
    object -> strcpy(tp,tmp1);
    //Add (data + )
    tmp2 = object -> strcat(tp,dataValueB);
    //Copy char* result to char[]
    char tp2[10];
    object -> strcpy(tp2,tmp2);
    //Add (data + ) + }
    char* dataTemplate = object -> strcat(tp2,dataTerminator);
    delete object;
    return dataTemplate;
}

