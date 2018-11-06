# Learning C the Hard way 

based on the book by the same name the exercises map to the one given in the book. 

## Pointers 
There are four useful things that you can do with pointers
* Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings and structs 
* Pass a large blocks of memory to functions with a pointer, so that you don't have to pass the whole thing. 
* Take address of a function, so you can use a dynamic call back. 
* Scan complex chuncks of memory, converting bytes off of a network socket into data structs or parsing files. 
For almost everything else we need to use arrays. 


## Stdio Functions 

### fopen 
this method opens a file specified by the file path provided and in the mode mentioned. 
**return value** 
the return value is a pointer to the FILE. if there is an error and the file is not found then a NULL is returned

```
  FILE fopen(const char *filepath, const char* mode)
```

the mode can be any one of the following 
* "r" - read only mode 
* "w" - opens a file for writing if it exists then the contents of the file are erased. if the file does not exist then a new file is created. 
* "a" - appends to a file. The file content are no deleted and all writes happen at the end of the file. the file is created if it does not exist. 
* "r+" - opens a file for reading and writing but the file must exist. 
* "w+" - creates an empty file for both reading and writing. 
* "a+" - for reading and appending. 

### freopen 
this method is used for re direction and it taken a already open stream and pipes it to a new file specified in the method 
**return value** 
this returns the reference to the new file name that has been craeted. 


```
  FILE freopen(const char *filepath, const char *mode, FILE *stream)
  // example 
  FILE *fp; 
  printf("This text is redirected to stdout\n"); 
  fp = freopen("file.txt", "w+", stdout);
  printf("This text will be redirected to the file.txt"); 
  fclose(fp); 
```




