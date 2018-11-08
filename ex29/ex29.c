#include <stdio.h> 
#include <dlfcn.h> 
#include "../ex19/dbg.h"

typedef int (*lib_function) (const char *data); 

int main(int argc, char *argv[]){
   int rc=0; 
   check(argc == 4, "Usage: ex29 lib29.so fucntion data"); 

   char *lib_file = argv[1]; 
   char *func_to_run = argv[2]; 
   char *data = argv[3]; 

   void *lib = dlopen(lib_file, RTLD_NOW); 
   check(lib != NULL, "Failed to open library %s:%s", lib_file, dlerror()); 

   lib_function func = dlsym(lib, func_to_run); 
   check(func != NULL, "Did not find %s function in library %s: %s", func_to_run, lib_file, dlerror()); 

   rc = func(data); 
   check(rc == 0, "function %s returned %d for data: %s", func_to_run, rc, data); 

   rc =dlclose(lib); 
   check(rc==0, "Failed to close %s", lib_file); 

   return 0; 

error:
   return 1; 

}
