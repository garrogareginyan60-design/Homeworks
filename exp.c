#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int
#define DEFAULT_SIZE 8

typedef struct Vector{
    TYPE *ptr;
    size_t size;
    size_t capacity;
} Vector;

bool constructor(Vector *vector);
bool reserve(Vector *vector, size_t size);
void resize(Vector *vector);
void clear(Vector *vector);

int main(){
    Vector array;

    if(!constructor(&array)){
        printf("Constructor failed!\n");
        return 1;
    }

    printf("%zu\n", array.capacity);
    printf("%zu\n", array.size);

    clear(&array);
    return 0;
}

bool constructor(Vector *vector){

    vector->ptr = malloc(DEFAULT_SIZE * sizeof(TYPE));
    if(vector->ptr == NULL){
        perror("Malloc error");
        return false;
    }

    vector->capacity = DEFAULT_SIZE;
    vector->size = 0;

    return true;
}

bool reserve(Vector *vector, size_t size){

    TYPE *temp = realloc(vector->ptr, size * sizeof(TYPE));
    if(temp == NULL){
        perror("Realloc error");
        return false;
    }

    vector->ptr = temp;
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
