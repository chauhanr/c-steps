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

### scanf 
scanf method will read the input from stdin which will match the format string and place in argument
that follows. If the operation is successful then the number of characters captured is returned
otherwise a negative number is returned. 

```
   int scanf(const char *format, ...) 
```

### fscanf
the operation is similar to scanf but the input to the fscanf can be defined by the user. The inputs
could be a file or a stream. The return type is the same as scanf. if the input stream is mentioned
as stdin then the fscanf is the same as scanf. 

```
  int fscanf(FILE *stream, const char *format, ...)

  // example
  char str[20]; 
  fscanf(stdin, "%s", str); 
```

### sscanf 
This operation is form the scanf family and it taken input as the char array or string. rest of the
functionality remains the same. 

```
   int sscanf(const char *str, const char *format, ...) 
```

### fgets 
this method reads from the specified stream and stores the line into a string pointed by the str. It
stops when either n-1 characters are read, a newline char is encountered or end of file is reached
which ever is reached first.  
**return value** 
the function returns the same value as captured in str. if the end of file is reached and no
characters are read then the function returns a null pointer 


```
  char *fgets(char *str, int n, FILE *stream)
  // exampel 
  fp = fopen("file.txt", "r"); 
  if (fp != NULL){
     if(fgets(str, 60, fp){
        printf("%s", str);
     }else{
       return -1
     }
  }else{
     perror("Error reading file"); 
  }
  fclose(fp);
```

the **gets** method does the same thing that the fgets does but it copies from stdin
```
   char *gets(char *str) 

```

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

### fclose 
this method will close the file pointer that is passed to the method. all buffers of the file are flushed. 
**return value** 
return zero value if stream is successfully closed. and on failure an EOF is sent back. 

```
  int fclose(FILE * stream)
```

### fgetpos
this method will get the current file position on the stream and store it on the pos varaible passed. 
**return value** 
return 0 on success and non zero number in case of failure. 

```
   int fgetpos(FILE * stream, fpos_t pos);
   // example 
   FILE fp * ; 
   fpos_t position; 

   fp = fopen("file.txt", "w+"); 
   fgetpos(fp, &position); 
   fputs("hello", fp); 
   fsetpos(fp, &position); 
   fputs("This will override hello.", fp); 
   fclose(fp); 
 
```

### fseek
This method will try to set the file position to the offset that is specified in the method. 

```
  int fseek(FILE * stream, long int offset, int whence) 
```

* stream - is the pointer to the FILE that identifies the stream. 
* offset - specifies the number of bytes you intend to move from whence 
* whence - this is the position from which the offset has to be applied. it can be any of the following: 
	* SEET_SET - begining of the file. 
	* SEEK_CUR - current position of the file pointer 
	* SEEK_END - end of the file. 

**return value** 
this method returns a 0 in case of success and a non zero value in case of failure. 

### ftell 
A simple method that gives us the current position on the stream 

```
   long ftell(FILE * stream)
```
**return value** 
this returns a offset value which is non negative value. if an error occurs, -1L is returned and global variable errno is also set to a positive value. 

### rewind 
This method will take the stream position to the starting of the file. 

```
  void rewind(FILE * stream); 
  
  // example 
   fp = fopen("file.txt", "w+"); 
   while(1){
      ch = fgetc(fp);
      if(feof(fp)){
        break;
      }
      printf("%c", ch);
   }

   rewind(fp); 
```

## fprintf
Set the formatted out to a stream. 

```
  int fprintf(FILE * stream, const char * format, ...); 
```
The string values passed as parameter is formatted and set to the stream.

* format is specified as the following "%[flag][width][.precision][length]specifier"
* the specifiers are defined as follows:
	* c - character 
	* d or i - signed decimal integer 
	* e - scientific notion 
	* E - scientific notion with E 
	* f - float value.


