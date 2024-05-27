#include "main.h"

int main(void)
{
    memory_dump();
    return 0;
}

void pointers(void)
{
    int a = 10;
    int *p = &a;
    printf("VARIABLE &a: %d | Value  a: %d\n", &a, a);
    printf("POINTER   p: %d | Value *p: %d\n", p, *p);
}

void vectors_and_matrices(void)
{
    int a[10];
    int *p = a;

    /**
     * Both *p and a have now the very same value
     * which is the address of the first element of a.
     */

    printf(" a = hexadecimal: %08x | decimal: %d\n", a);
    printf("*p = hexadecimal: %08x | decimal: %d\n", p);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;
    a[5] = 60;
    a[6] = 70;
    a[7] = 80;
    a[8] = 90;
    a[9] = 100;

    // x prints an unsigned number in hexadecimal.
    // o prints an unsigned number in octal.
    // u prints an unsigned number in decimal.
    // d prints a signed number in decimal.
    // i prints a signed number in decimal.
    // We can then attach l to the format string for formats like %lx
    // to specify that instead of an int, we're using a long int
    // (That is, an unsigned long int, or long int).

    /**
     * while p is less than the address of the last element of a
     */
    int i = 0;
    while (p < &a[10])
    {
        // To print a pointer with printf(), you should cast the pointer to void* and use "%p"
        printf("a[%d] | %d | %p | %08lx | %lu\n", i, *p, (void *)p, p, p);
        p++; // increment pointer
        i++;
    }

    // point back to the first element of a
    // p = a;
    printf("\na[0] | %d | &a[1] | %p | %lu | p | %p | %lu | *p | %d\n", a[0], &a[0], &a[0], p, p, *p);
}

void memory_dump(void)
{    
    char *c = "0";
    int i = 0;
    int j = 0;

    while (i < 2000000)
    {
        if (j == 64)
        {
            printf("\n");
            j = 0;
        }
        printf("%c", *c);
        i++;
        j++;
        c++;
    }
}

void malloc_and_free(void)
{
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL)
    {
        printf("ERROR: memory allocation for p failed.\n");
        exit(1);
    }
    else
    {
        printf("%d bytes allocated for p.\n", sizeof(int));
        *p = 10;
    }

    printf("p = %d\n", *p);
    free(p);
}

void dynamic_vector(void)
{
    int vector_size = 10;
    int *vector = (int *)malloc(sizeof(int) * vector_size);

    if (vector == NULL)
    {
        printf("ERROR: memory allocation for vector failed.\n");
        exit(1);
    }
    else
    {
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

    for (int i = 0; i < vector_size; i++)
    {
        printf("%d\n", vector[i]);
    }
    free(vector);
}