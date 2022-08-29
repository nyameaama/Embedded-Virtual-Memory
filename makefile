#FULL BUID

CC = g++
COMPILEFLAG = -c
BUILDFLAG = -o

build: entry.o parser.o utils.o
    $(CC) BUILDFLAG entry.o parser.o utils.o

entry.o: Virtual_Mem.cpp Virtual_Mem.h
    $(CC) COMPILEFLAG src/Virtual_Mem.cpp src/Virtual_Mem.h

parser.o: _nativeParser.cpp _nativeParser.h
    $(CC) COMPILEFLAG src/Parser/_nativeParser.cpp src/Parser/_nativeParser.h

utils.o: utility.cpp utility.h
    $(CC) COMPILEFLAG src/utils/utility.cpp src/utils/utility.h