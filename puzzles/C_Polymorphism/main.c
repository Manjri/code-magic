#include <stdio.h>
#include <stdlib.h>

struct Animal;

struct Animal_Vtable{
        void (*Walk)(struct Animal *a_This);
        struct Animal* (*Dtor)(struct Animal *a_This);
};

typedef struct Animal{
        struct Animal_Vtable vtable;
        char *Name;
}Animal;

typedef struct Dog{
        struct Animal_Vtable vtable;
        char *Name; // mirror member variables for easy access
        char *Type;
}Dog;


void Animal_Walk(struct Animal *a_This){
        printf("Animal (%s) walking\n", a_This->Name);
}

struct Animal* Animal_Dtor(struct Animal *a_This){
        printf("animal::dtor\n");
        return a_This;
}

Animal* Animal_Alloc(){
        return (Animal*)malloc(sizeof(Animal));
}

Animal* Animal_New(Animal* a_Animal){
        a_Animal->vtable.Walk = Animal_Walk;
        a_Animal->vtable.Dtor = Animal_Dtor;
        a_Animal->Name = "Anonymous";
        return a_Animal;
}

void Animal_Free(Animal* a_This){
        a_This->vtable.Dtor(a_This);
        free(a_This);
}

void Dog_Walk(struct Dog *a_This){
        printf("Dog walking %s (%s)\n", a_This->Type, a_This->Name);
}


Dog* Dog_Dtor(struct Dog* a_This){
    Animal_Dtor((Animal*)a_This);
    printf("dog::dtor\n");
    return a_This;
}

Dog* Dog_Alloc(){
        return (Dog*)malloc(sizeof(Dog));
}

Dog* Dog_New(Dog* a_Dog){
    Animal_New((Animal*)a_Dog);
    a_Dog->Type = "Dog type";
    a_Dog->vtable.Walk = Dog_Walk;
    a_Dog->vtable.Dtor = Dog_Dtor;
    return a_Dog;
}

int main(int argc, char **argv){

    // do this for animal - base class
    Animal *a_Animal; 
    a_Animal = (Animal*)Animal_New(Animal_Alloc());
    a_Animal->vtable.Walk(a_Animal);
    Animal_Free(a_Animal);
   
    // do this for dog - derived class
    a_Animal = (Animal*)Dog_New(Dog_Alloc());
    a_Animal->vtable.Walk(a_Animal);
    Animal_Free(a_Animal);
}
