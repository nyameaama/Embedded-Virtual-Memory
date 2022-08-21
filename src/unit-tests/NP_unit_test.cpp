//#include"_nativeParser.h"
#include"utility.h"
#include<stdint.h>
#include<iostream>
#include<string>

char * strcpy(char *strDest, const char *strSrc);
char* my_strcat(char *dest,char *src);
std::string itoa(int a);
bool AppendCharToCharArray( char *array, uint8_t n, char c );
char* convert_to_c_str(std::string str);
char* appendTemplate(char* address_name);
char* dataToTemplate(char* templ, char* data);

int main(){
    char* name = "randVariable";
    char* dataChar = "data Sample";
    char* empty = "";
    char empty2[5];
    char* num = "77";
    char emp[4] = "{";
    char jhs[20] = "container";
    char jhX[20] = "dataPcK";
    std::string val = "test";
    int dataINT = 66;
    //_VIRTUAL_MEMORY_PARSER *object = new _VIRTUAL_MEMORY_PARSER();
    //object -> parseToVariable(name, dataINT);
    //delete object;
    //VMUTIL* object2 = new VMUTIL();
    //auto size = (sizeof(name) / sizeof(name[0]));
    //std::cout << object2 -> reverse(name);//my_strcat(empty,dataChar);
    //delete object2;
    //std::cout << itoa(dataINT);
    //AppendCharToCharArray(name, strlen(name), 'T');
    strcpy(empty2,emp);
    //std::cout << empty2;
    char *ret = my_strcat(emp,jhs);
    //std::cout << ret;
    //char* yes = convert_to_c_str(val);
    std::cout << appendTemplate(jhs);
    //std::cout << dataToTemplate(appendTemplate(jhs), jhX);
    //std::cout << yes;
    return 0;
}

char* appendTemplate(char* address_name){
    //9 CHARACTERS MAX
    //Format address to addr char
    char addr[sizeof(address_name)+2];
    strcpy(addr,address_name);
    char dataStarter[2] = "{";
    char dataTerminator[2] = "}";
    char dataNameA[2] = "[";
    char dataNameB[2] = "]";
    char dataPairSep[2] = ",";
    //Temp Variables
    char* tmp1;
    char* tmp2;
    //Add { + [
    tmp1 = my_strcat(dataStarter,dataNameA);
    //Copy char* result to char[]
    char tp[10];
    strcpy(tp,tmp1);
    //Add {[ + address name
    tmp2 = my_strcat(tp,addr);
    //Copy char* result to char[]
    char tp2[sizeof(address_name)+6];
    strcpy(tp2,tmp2);
    //Add {[address name + ]
    char* InitialTemplate = my_strcat(tp2,dataNameB);
    //delete object;
    return InitialTemplate;
}

char* dataToTemplate(char* templ, char* data){
    //Format data to data char
    char _data[sizeof(data)+2];
    strcpy(_data,data);

    char _templ[20];
    strcpy(_templ,templ);

    char dataValueA[2] = "(";
    char dataValueB[2] = ")";
    char dataTerminator[2] = "}";
    char dataPairSep[2] = ",";

    //Temp Variables
    char* tmp1;
    char* tmp2;
    char* tmp3;
    //Add ( + data
    tmp1 = my_strcat(dataValueA,_data);
    //Copy char* result to char[]
    char tp[sizeof(data)+10];
    strcpy(tp,tmp1);
    //Add (data + )
    tmp2 = my_strcat(tp,dataValueB);
    //Copy char* result to char[]
    char tp2[sizeof(data)+10];
    strcpy(tp2,tmp2);
    //Add (data + ) + }
    char* dataTemplate = my_strcat(tp2,dataTerminator);

    char tp3[20];
    strcpy(tp3,dataTemplate);

    tmp3 = my_strcat(_templ,tp3);

    return tmp3;
}

std::string itoa(int a)
{
    std::string ss="";   //create empty string
    while(a)
    {
        int x=a%10;
        a/=10;
        char i='0';
        i=i+x;
        ss=i+ss;      //append new character at the front of the string!
    }
    return ss;
}

bool AppendCharToCharArray( char *array, uint8_t n, char c )
{
    uint8_t sz = std::strlen( array );

    if ( sz + 1 < n ) 
    {
        array[sz] = c;
        array[sz + 1] = '\0';
    }       

    return ( sz + 1 < n );
}

char* my_strcat(char *dest, char *src)
{
   size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

char* convert_to_c_str(std::string str){
    const char *cstr = str.c_str();
    return (char*)cstr;
}

char * strcpy(char *strDest, const char *strSrc)
{
    assert(strDest!=NULL && strSrc!=NULL);
    char *temp = strDest;
    while(*strDest++ = *strSrc++); // or while((*strDest++=*strSrc++) != '\0');
    return temp;
}