#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 

struct Person{
  char *name; 
  int age; 
  int weight; 
  int height; 
};

struct Person *person_create(char *name, int age, int height, int weight){
    struct Person *p = malloc(sizeof(struct Person)); 
    assert(p != NULL); 
    p->name = name; 
    p->age = age; 
    p->height = height; 
    p->weight = weight; 
    return p; 
}

void person_destroy(struct Person *p){
    assert(p != NULL); 
    //free(p->name); 
    free(p); 
}

void person_print(struct Person *p){
   printf("Name: %s\n", p->name); 
   printf("Age: %d\n", p->age); 
   printf("Weight: %d\n", p->weight); 
   printf("Height: %d\n", p->height); 
}

int main (int argc, char *argv[]){
    struct Person *joe = person_create("Joe Alex", 32, 64, 150); 
    struct Person *frank = person_create("Frank Abe", 20, 72, 175); 
    printf("Joe is at memory location: %p\n", joe); 
    person_print(joe); 
    printf("Frank is at memory location: %p\n", frank); 
    person_print(frank); 
    // adding 20 years to each person 
    joe->age += 20; 
    joe->height +=2; 
    frank->age +=30; 
    frank->height +=5; 

    person_print(joe);
    person_print(frank);

    person_destroy(joe);
    person_destroy(frank); 

    return 0; 
}
