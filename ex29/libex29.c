#include <stdio.h> 
#include <ctype.h>
#include "../ex19/dbg.h"


int print_a_message(const char *msg){
   printf("message : %s\n",msg); 
   return 0; 
}

int uppercase(const char *msg){
  int i; 
  for(i=0; msg[i] != '\0';i++){
     printf("%c", toupper(msg[i])); 
  } 
  printf("\n");
  return 0; 
}


int lowercase(const char *msg){
  int i; 
  for(i=0; msg[i] != '\0';i++){
     printf("%c", tolower(msg[i])); 
  } 
  printf("\n");
  return 0; 
}

int fail_to_process(const char *msg){
   return 1; 
}


