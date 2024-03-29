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

#ifndef _PARSER
#define _PARSER

#include<stdint.h>
#include<iostream>
#include<stdlib.h>
#include"../utils/utility.h"
#include<string>

class _VIRTUAL_MEMORY_PARSER{
    public:
        //+1 OVERLOAD
        //TYPE: 32 BIT INT, CHAR
        char* parseToVariable(char* address_name, int32_t data);
        char* parseToVariable(char* address_name, char* data);

        //+1 OVERLOAD
        //TYPE: 32 BIT INT, CHAR
        char* parseToValuePair(char* address_name, int32_t *data);
        char* parseToValuePair(char* address_name, char *data);

        //Returns a data template with address name added
        char* appendTemplate(char* address_name);

        //+1 OVERLOAD
        char* dataToTemplate(char* templ,int32_t data);
        char* dataToTemplate(char* templ, char* data);

        bool AppendCharToCharArray( char *array, uint8_t n, char c );

        char* readLastData(char* variableName);

        char* deriveDataFromTeplate(char* data);
};

#endif