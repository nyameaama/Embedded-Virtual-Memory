# Embedded Virtual Memory

### Virtual Memory Library functions 

* createVariableContainer(): 
* deleteVariableContainer():
* modifyVariableContainer():
* retrieveValueFromContainer():

### Function Documentation

            VIRTUAL_MEMORY(char*(*inputfunction)(char*),void (*outputfunction)(char*,char*),void (*createfile)(char*),void (*deletefile)(char*))

<b> Parameters:</b>

* Input Function - Function pointer for external storage file data input
* Output Function - Function pointer for external storage file data output
* Create Function - Function pointer for external storage file creation
* Remove Function - Function pointer for external storage file deletion


---------------------------------------------------------

            void createVariableContainer(char* variableName, RT data)

This function creates container for a variable (Private)

<b> Returns: </b>
    None

<b> Parameters: </b>

* Varaiable Name -> (char*)
* Variable Data -> Template 

---------------------------------------------------------

            void deleteVariableContainer(char* variableName)

This function deletes a variable container

<b> Returns: </b>
    None

<b> Parameters: </b>
* Varaiable Name -> (char*)

---------------------------------------------------------

            void modifyVariableContainer(char* variableName, RT data)

This function modifies data inside a variable container

<b> Returns: </b>
    None

<b> Parameters: </b>
* Varaiable Name -> (char*)
* Variable Data -> Template

--------------------------------------------------------

            void retrieveValueFromContainer(char* variableName)

This function retrieves value from a variable container

<b> Returns: </b>
    Container Value/Data -> Template

<b> Parameters: </b>
* Varaiable Name -> (char*)

---------------------------------------------------------

