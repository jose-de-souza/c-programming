#include "main.h"

int main(void) {

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

    return 0;
}