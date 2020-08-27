# Embedded Virtual Memory

Virtual Memory API functions

* createVariableContainer(): 
* deleteVariableContainer():
* modifyVariableContainer():
* retrieveValueFromContainer():

* Function Documentation

            VIRTUAL_MEMORY(char*(*inputfunction)(char*),char* (*outputfunction)(char*,char*),void (*createfile)(char*),void (*deletefile)(char*))

Parameters:
    * Input Function - Function pointer for external storage file data input
    * Output Function - Function pointer for external storage file data output
    * Create Function - Function pointer for external storage file creation
    * Remove Function - Function pointer for external storage file deletion


---------------------------------------------------------

            void createVariableContainer(char* variableName, RT data)

This function creates container for a variable

Returns:
    None

Parameters:
    * Varaiable Name -> (char*)
    * Variable Data -> Template 

---------------------------------------------------------

            void deleteVariableContainer(char* variableName)

This function deletes a variable container

Returns:
    None

Parameters:
    * Varaiable Name -> (char*)

---------------------------------------------------------

            void modifyVariableContainer(char* variableName, RT data)

This function modifies data inside a variable container

Returns:
    None

Parameters:
    * Varaiable Name -> (char*)
    * Variable Data -> Template

--------------------------------------------------------

            void retrieveValueFromContainer(char* variableName)

This function retrieves value from a variable container

Returns:
    Container Value/Data -> Template

Parameters:
    * Varaiable Name -> (char*)

---------------------------------------------------------

