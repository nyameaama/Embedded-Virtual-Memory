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

#include"PACKAGE_JSON.h"

char* placeholderTag = "Value";

//Function serializes JSON object and returns JSON doc in array
char* PACKAGE_JSON::serializeToJson(JSON_OBJECT object){
    //Return array
    char* serialized;
    //Serialize to JSON
    serializeJson(object,serialized,200);
    return serialized;
}

//Function deserializes json doc array 
const char* PACKAGE_JSON::deserialize(char* jsonDoc){
    //Create object
    StaticJsonDocument<50> temp;
    //Deserialize the JSON document
    DeserializationError error = deserializeJson(temp, jsonDoc);
    //Test if parsing succeeds.
    if(error){
        //Handle error
    }
    auto x = temp[placeholderTag].as<char*>();
    return x;
}
int PACKAGE_JSON::deserialize(char* jsonDoc,int type){
    //Create object
    StaticJsonDocument<50> temp;
    //Deserialize the JSON document
    DeserializationError error = deserializeJson(temp, jsonDoc);
    //Test if parsing succeeds.
    if(error){
        //Handle error
    }
    auto x = temp[placeholderTag].as<int>();
    return x;
}


//Function adds data to JSON object 
//+1 OVERLOAD
int32_t addToJsonObject(JSON_OBJECT object, int32_t data){
    //Add data to JSON object
    object[placeholderTag] = data;
    return data;
}
char* addToJsonObject(JSON_OBJECT object, char* data){
    //Add data to JSON object
    object[placeholderTag] = data;
    return data;
}