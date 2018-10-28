#include <stdio.h> 

int main(){
   int ages[] = {23, 32, 21, 2}; 
   char *names[] = {"Lisa", "John", "David", "Mike"}; 

   int size = sizeof(ages)/sizeof(int); 
   int i = 0; 

   printf("size of ages is %ld\n\n",sizeof(ages));

   for (i=0; i<size; i++){
      printf("%s age is %d\n", names[i], ages[i]); 
   }
   printf("------------\n");

   int *cur_age = ages; 
   char **cur_names = names; 

   for(i=0; i<size; i++){
     printf("%s is %d years old \n",*(cur_names+i), *(cur_age+i)); 
   }  
   printf("-----------------\n"); 
   
   for(i=0; i<size; i++){
     printf("%s is %d years old \n",cur_names[i], cur_age[i]); 
   }  
   printf("-----------------\n"); 

}
