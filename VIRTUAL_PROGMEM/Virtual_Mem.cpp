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

#include"Virtual_Mem.h"

//Storing functions with function pointers
char*(*inputF)(char*);
void (*outputF)(char*,char*);
void (*createF)(char*);
void (*deleteF)(char*);

//Constructor - 2 overloads
//Constructor parameters hold four task functions needed
/*
Foreign Functions:
    Input
    Output
    Create
    Remove
*/
VIRTUAL_MEMORY::VIRTUAL_MEMORY(char*(*inputfunction)(char*),void (*outputfunction)(char*,char*),void (*createfile)(char*),void (*deletefile)(char*)){
    inputF = inputfunction;
    outputF = outputfunction;
    createF = createfile;
    deleteF = deletefile;
}

//Create container for variable
template<typename RT>
void VIRTUAL_MEMORY::createVariableContainer(char* variableName,RT data){
    PACKAGE_JSON *jsonObject = new PACKAGE_JSON();
    //SD_API *sdObject = new SD_API();
    //Create JSON object and add placeholder data
    JSON_OBJECT file;
    jsonObject -> addToJsonObject(file,data);
    //Serialize Json
    auto serialized = jsonObject -> serializeToJson(file);
    //Output 
    outputF(variableName,serialized);
    delete jsonObject;
}

//Delete variable container
void VIRTUAL_MEMORY::deleteVariableContainer(char* variableName){
    //When function is called file is deleted
    deleteF(variableName);
}

//Add value to variable container
template<typename RT>
RT VIRTUAL_MEMORY::modifyVariableContainer(char* variableName, RT data){
    PACKAGE_JSON *jsonObject = new PACKAGE_JSON();
    //Get container by calling input function 
    auto container_data = inputF(variableName);
    //Deserialize data
    auto previousValue = jsonObject -> deserialize(container_data);
    if(data != previousValue){
        //Remove previous file
        deleteF(variableName);
        //Create new file
        createVariableContainer(variableName,data);
    }else{
        //Leave the file alone
    }
    delete jsonObject;
}

//Retrieve value from variable container
template<typename RT>
RT retrieveValueFromContainer(char* container){
     PACKAGE_JSON *jsonObject = new PACKAGE_JSON();
    //Get container by calling input function
    char* containerdata = inputF(container);
    //Deserialize and return value
    auto deserializedvalue = jsonObject -> deserialize(containerdata);
    delete jsonObject;
    return deserializedvalue;
}