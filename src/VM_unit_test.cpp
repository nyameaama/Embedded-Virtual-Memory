 #include"Virtual_Mem.h"
 #include<iostream>

 int main(){
    char* name = "randVariable";
    char* dataChar = "data Sample";
    char* empty = "";
    char empty2[5];
    char* num = "77";
    char emp[4] = "hel";
    char jhs[4] = "iop";
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
    //strcpy(empty2,emp);
    //std::cout << empty2;
    //char *ret = my_strcat(emp,jhs);
    //std::cout << ret;
    //char* yes = convert_to_c_str(val);
    //std::cout << yes;
    VIRTUAL_MEMORY *object = new VIRTUAL_MEMORY(inputDatafromFS,outputDatatoFS,createfileOnFS,deletefileOnFS);

    return 0;
}


//Operation Functions
//Input
char* inputDatafromFS(char* filename){
    std::ifstream tempFile;
    char* data;
    tempFile.open(filename,std::ios::in);
    if(tempFile.is_open()){
        while(!tempFile.eof()){
            tempFile >> data;
        }
    }
    tempFile.close();
    return data;
}
//Output
void outputDatatoFS(char* filename,char* data){
    std::ofstream tempFile;
    tempFile.open(filename,std::ios::out);
    if(tempFile.is_open()){
        tempFile << data;
    }
    tempFile.close();
}
//Create
void createfileOnFS(char* filename){
    std::fstream tempFile;
    //Creating file in Prog Directory 
    tempFile.open(filename,std::ios::out);
    if(tempFile.is_open()){
        //File created
    }
    tempFile.close();
}
//Remove
void deletefileOnFS(char* filename){
    remove(filename);
}