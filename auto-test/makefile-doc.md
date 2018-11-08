# Makefile documentation

This file will document all the important features of the makefile that is generally used to build c projects. 

## CFLAGS 
CFLAGS are arguments the you intend to pass to the c compiler. 
* -g flag tells the compiler to generate debugging information 
* -O2 another optimization that the compiler needs to do with right level of logging to make builds fast. 
* -Wall indicates that all warnings need to be shown 
* -I specifies the source folder for teh code. 
* -D sets a variable that can be used in a MACRO therefore NDEBUG is set for the dbg.h marco file. 
* the $(OPTFLAGS) at the end will all for users to send additional flags to the compiler 

## LIBS
The LIBS section in the make file allows for options at the library linking level. To add more options $(OPTFLAG) is provided.

## PREFIX 
the PREFIX is a variable that the user needs to set if there is no PREFIX set it will default to /usr/local

## SOURCES
The sources section mentions that the c code user under the src folder with .c suffix and is at multiple levels. 
```
SOURCES:$(wildcard src/**/*.c src/*.c)    
```
this creates a list of all the files in the src folder recursively. 

## OBJECTS 
the object uses a makefile function patsubst which takes the list of $(SOURCES) and creates a new list by replacing all words ending with .c and make a new list with .o These file names are then assigend to OBJECTS variable. 
```
OBJECTS=$(patsubst %.c, %.o, $(SOURCES)) 
```
this will take the list created in the SORUCE section above and will replace the value of .c with .o to get the object file for all c file. 

## TEST_SRC and TESTS 
These do the same thing that SOURCES and OBJECTS do for source files but this is done for test file. 
```
TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c, %, $(TEST_SRC)) 
```

## TARGET and SO_TARGET
the target mentions the name build/libYOUR_LIBRARY.a and we need to replace the YOUR_LIBRARY with the name you want to give.  

```
TARGET=build/libYOUR_LIBRARY.a
SO_TRAGET=$(patsubst %.a, %.so, $(TARGET))
```


## all 
the all is the default target that is run by the make file when there is no other target specified. in our case we have give a list of files in the soruce and test folders. 
```
all: $(TARGET) $(SO_TARGET) tests  
```
the test target is lower down in the make file.

## dev target 
the dev target is for developer builds it gives the opportunity to change the build options for developer builds and eventually call the all target. 

## $(TRAGET) 
we will try and explain the following section here: 
```
$(TARGET): CFLAGS += -fPIC 
$(TARGET): build $(OBJECTS) 
	ar rcs $@ $(OBJECTS) 
	ranlib $@

....

build: 
	@mkdir -p build 
	@mkdir -p bin   
``` 

1. CFLAGS are added with the -fPIC option. 
2. in the $(TRAGET) which is nothing but build/lib<name>.a  
	* will first try to make the build and bin folders.
	* next $(OBJECTS) will force the make to compile the source files and create .o files. 
3. ar command is used to prepare the library $@ translates to $(TARGET) or lib<name>.a and the files to build are $(OBJECTS) 
4. ranlib will make the library that you want with the name give in $(TRAGET)

## SO_TARGET
The SO target is as follows 

```
$(SO_TRAGET): $(TARGET) $(OBJECTS) 
	$(CC) -shared -o $@ $(OBJECTS)   
```

the SO_TRAGET is dependent on TARGET and OBJECTS being run prior to this target.


## Tests | .PHONY 
If your program structure has a file or folder in tests that is not real then we need to use the .PHONY to tag that file so that make can ignore the file and still run successfully

```
.PHONY: tests 
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh
```

1. first we add the library that we craeted in $(TARGET) and link it to tests use the CFLAGS 
2. The the tests target is run that depends on all the files listed in the $(TEST) variable.
3. finally the shell script that runs the test programs once the build is successful. 

## Cleaner 
The cleaner target will try and clean all the builds that we are trying to make. 

```  
clean: 
	rm -rf build $(OBJECTS) $(TESTS) 
	rm -f tests/tests.log 
	find . -name "*.gc*" -exec rm {}\; 
	rm -rf `find . -name "*.dSYM" - print`
```

this set of commands tries to clean up all the files that are genearted by the c compiler when building the code. 


## Install traget 
The install target depends on all which means the files and library needs to be created after which the executable code is sent to 
right folder specified by the location. 

```
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/
```

1. first create a lib directory if it is already not present. 
2. install command will move the traget to the lib folder. 


