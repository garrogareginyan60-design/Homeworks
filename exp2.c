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

bool resize(Vector*vector);
bool insert(Vector*vector, size_t index, TYPE value);
bool pop(Vector*vector, size_t index);

int main(){
 Vector* vector = malloc(sizeof(Vector));

 if (!vector){
  perror("failed to realloc");
  exit(EXIT_FAILURE);
 }

     vector->size = 6;
     vector->capacity = DEFAULT_SIZE;
     vector->ptr = malloc(vector->capacity * sizeof(TYPE));
     if (!vector->ptr) {
         perror("malloc failed");
         free(vector);
  exit(EXIT_FAILURE);
 }
 
 vector->ptr[0] = 1;
 vector->ptr[1] = 2;
 vector->ptr[2] = 3;
 vector->ptr[3] = 4;
 vector->ptr[4] = 5;
 vector->ptr[5] = 7;

 insert(vector, 4, 6);
 for(int i = 0; i < vector->size; ++i){
  printf("%d\n", vector->ptr[i]);
 }

 printf("\n");
 pop(vector, 4);
        for(int i = 0; i < vector->size; ++i){
                printf("%d\n", vector->ptr[i]);
        }
}

bool resize(Vector*vector){
 if(vector->size <  vector->capacity) return true;
 vector->ptr = (TYPE*)realloc(vector->ptr, vector->capacity *2 * sizeof(TYPE));
 if(!vector->ptr){
  perror("failed to realloc in resize: ");
  return false;
 }

 vector->capacity *= 2;
 return true;
}

bool insert(Vector*vector, size_t index, TYPE value){
 if (index >= vector->size) return false;
 resize(vector);
 for(int i = vector->size; i > index+1; --i){
  vector->ptr[i] = vector->ptr[i-1];
 }

 vector->ptr[index+1] = value;
 ++vector->size;
 return true;
}

bool pop(Vector*vector, size_t index){
 if (index >= vector->size) return false;
 for (int i = index; i < vector->size-1; ++i){
  vector->ptr[i]=vector->ptr[i+1];
 }
 
 --vector->size;
 return true;
}
