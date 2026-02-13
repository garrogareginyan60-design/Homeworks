#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int
#define DEFAULT_SIZE 8

typedef struct Vector{
    TYPE*ptr;
    size_t size;
    size_t capacity;
}Vector;

bool constructor(Vector *vector);
bool reserve(Vector *vector, size_t size);
void resize(Vector *vector);
void clear(Vector *vector);

void push_back(Vector *vector, TYPE value);
void push_front(Vector *vector, TYPE value);
void pop_back(Vector *vector);
void pop_front(Vector *vector);


int main(){

}




bool constructor(Vector *vector){
  
 vector->ptr = malloc (DEFAULT_SIZE * sizeof(TYPE));
 if(vector->ptr == NULL){
  perror("Malloc error: ");
  return false;
}

 vector->capacity = DEFAULT_SIZE;
 vector->size = 0;
  return true;


}


bool reserve(Vector *vector, size_t size){
 TYPE *tmp = realloc(vector->ptr, size * sizeof(TYPE));
if(tmp == NULL){
    perror("Realloc error");
    return false;
}
vector->ptr = tmp;


 vector->capacity = size;
 return true;


}


void resize(Vector *vector){
 if(vector->size == vector->capacity){
  reserve(vector, vector->capacity * 2);
}

}

void clear(Vector *vector){
free(vector->ptr);
vector->ptr = NULL;
vector->size = 0;
vector->capacity = 0;

}

void push_back(Vector *vector, TYPE value){
 resize(vector);
 vector->ptr[vector->size] = value;
 ++vector->size;
}

void pop_back(Vector *vector){
 --vector->size;
}

void push_front(Vector *vector, TYPE value){
 resize(vector);
 for(int i = vector->size; i > 0; --i){
    vector->ptr[i] = vector->ptr[i - 1];
}


 vector->ptr[0] = value;
 ++vector->size;
}

void pop_front(Vector *vector){
 for(int i = 0; i < vector->size - 1; ++i){
  vector->ptr[i] = vector->ptr[i + 1];
 
 }

 --vector->size;
}
