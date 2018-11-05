#include <stdio.h> 
#include "ex22.h"
#include "../ex19/dbg.h"

int THE_SIZE=1000; 

static int THE_AGE=38; 

int get_age(){    
    return THE_AGE; 
}

void set_age(int age){
   THE_AGE=age; 
}

double update_ratio(double new_ratio){
  static double ratio = 1.0; 
  double old_ratio = ratio; 
  ratio = new_ratio; 
  return old_ratio; 
}

void print_size(){
   log_info("I think the size is: %d", THE_SIZE); 
}

const char *MY_NAME= "Ritesh Chauhan";

void scope_demo(int count){
	log_info("count is: %d", count); 
	if (count > 10) {
	  int count = 100; 
	  log_info("count in this scope is %d", count); 
	}
	log_info("count is at exit: %d", count); 
	count=3000; 
	log_info("count after assign: %d", count); 
}

int main(int argc, char *argv[]){
   log_info("My name is :%s, and age is: %d", MY_NAME, get_age());
   set_age(30); 
   log_info("My age is now: %d", get_age()); 

   log_info("Size is :%d", THE_SIZE); 
   print_size(); 
   THE_SIZE=9; 
   log_info("The Size is now: %d", THE_SIZE); 
   print_size(); 

   log_info("Ratio at first: %f", update_ratio(2.0));
   log_info("Ratio again: %f", update_ratio(10.0));
   log_info("Ratio once again: %f", update_ratio(300.0));
   int count = 4; 
   scope_demo(count); 
   scope_demo(count*20);
   log_info("count after calling scope_demo: %d",count); 
   return 0; 
}
