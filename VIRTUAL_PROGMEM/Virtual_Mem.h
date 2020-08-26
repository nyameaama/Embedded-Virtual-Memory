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

#ifndef VIRTUAL
#define VIRTUAL


#include"../JSON/PACKAGE_JSON.h"
//#include"../STORAGE_SD/SD_API.h"

#define JSON_OBJECT StaticJsonDocument<200>

class VIRTUAL_MEMORY {
    public:
        //Constructor - 2 overloads
        //VIRTUAL_MEMORY(char (*function)());

        //Create container for variable
        void createVariableContainer(char* variableName);
        
        //Delete variable container
        void deleteVariableContainer(char* variableName);

        //Add value to variable container
        template<typename RT>
        RT addToVariableContainer(char* container, RT data);

        //Retrieve value from variable container
        template<typename RT>
        RT retrieveValueFromContainer(char* container);

};

#endif