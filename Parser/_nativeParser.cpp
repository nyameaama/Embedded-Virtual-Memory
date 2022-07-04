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
int32_t _VIRTUAL_MEMORY_PARSER::parseToValuePair(char* address_name, int32_t *data){
    appendTemplate(address_name);
}

char* _VIRTUAL_MEMORY_PARSER::appendTemplate(char* address_name){
    char dataStarter = '{';
    char dataTerminator = '}';
    char dataNameA = '[';
    char dataNameB = ']';
    char dataValueA = '(';
    char dataValueB = ')';
    char dataPairSep = ',';
    //Create template
    char* templateX;
    AppendCharToCharArray(templateX,10,dataStarter);
    return templateX;
}

bool _VIRTUAL_MEMORY_PARSER::AppendCharToCharArray( char *array, size_t n, char c )
{
    size_t sz = std::strlen( array );

    if ( sz + 1 < n ) 
    {
        array[sz] = c;
        array[sz + 1] = '\0';
    }       

    return ( sz + 1 < n );
} 

template <typename T>
int8_t _VIRTUAL_MEMORY_PARSER::lengthArray(T array){
    return sizeof(array) / sizeof(array[0]);
}

 char* dataToTemplate(char* templ,int32_t data){

}
char* dataToTemplate(char* templ, char* data){

}