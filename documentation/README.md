# Library Information 

The Embedded Virtual Memory library is a library which provides a Virtual Memory Implementation for Memory Constrained Controllers. As a way to preserve RAM, the memory management technique provides an idealized abstraction of the storage resources that are actually available on the controller which allows for a very large (main) memory.

## <b> How it works: </b>

The library works as a modular system which means that unique mediums of data storage which are not supported can be written and interfaced with the library. 

<b> <i> Storing data: </b> </i>

When the library is accessed and data is prompted to be stored, the data is serialized into a JSON format. The serialized data is sent to the storage medium via the output function.

<p align = "center">
<img src = "https://github.com/nyameaama/Embedded-Virtual-Memory/blob/master/assets/Screen%20Shot%202020-09-15%20at%209.17.28%20AM.png" width = "500" height = "118"/>
</p>


<b> <i>Retrieving Stored Data: </b> </i>

When the library is accessed and data is prompted to be retrieved, data is retrieve from the storage medium through the input function. The data is then deserialized and returned.

<p align = "center">
<img src = "https://github.com/nyameaama/Embedded-Virtual-Memory/blob/master/assets/Screen%20Shot%202020-09-15%20at%209.17.42%20AM.png" width = "500" height = "118"/>
</p>

## <b> Storage Mediums </b> 

Storage mediums are the API which allows the library to interface with different methods of data storage. They include I/O functions which allow the library to send and receive data. 

Already written storage mediums for the library that have been prewritten include Arduino SD and native C++ (fstream) <b> however file dependencies have not been added as part of the library. </b>

Future Additions to library packaged storage mediums include flash storage, EEPROM etc.


## Library function documentation can be found [here](https://github.com/nyameaama/Embedded-Virtual-Memory/blob/master/documentation/API%20document.md)