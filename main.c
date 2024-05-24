#include "main.h"

int main(void) 
{   
    pointers();
    return 0;
}

void pointers(void)
{
    int a = 10;
    int *p = &a;
    printf("VARIABLE &a: %d | Value  a: %d\n", &a, a);
    printf("POINTER   p: %d | Value *p: %d\n", p, *p);

}

void malloc_and_free(void) 
{
     int *p = (int*)malloc(sizeof(int));

    if(p == NULL) {
        printf("ERROR: memory allocation for p failed.\n");
        exit(1);
    } else {
        printf("%d bytes allocated for p.\n", sizeof(int));
        *p = 10;
    }

    printf("p = %d\n", *p);
    free(p);
}

void dynamic_vector(void)
{
    int vector_size = 10;
    int *vector = (int*) malloc(sizeof(int) * vector_size);

    if(vector == NULL) {
        printf("ERROR: memory allocation for vector failed.\n");
        exit(1);
    }
     else {
        printf("%d bytes allocated for vector.\n", sizeof(int) * vector_size);
    }

    vector[0] = 10;
    vector[1] = 200;
    vector[2] = 3000;
    vector[3] = 40000;
    vector[4] = 500000;
    vector[5] = 6000000;
    vector[6] = 70000000;
    vector[7] = 800000000;
    vector[8] = 900000000;
    vector[9] = 100000000;

    for(int i = 0; i < vector_size; i++) {
        printf("%d\n", vector[i]);
    }
    free(vector);
}