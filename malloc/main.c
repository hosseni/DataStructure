#include <stdio.h>
#include <stdlib.h>

#include "includes/std.h"

int main(int argc, char const *argv[])
{
    // malloc pointer access to allocate number of byte in heap (dymanic memory)
    // malloc return void pointer
    // we cast void pointer of malloc func
    U8 size = 0;
    printf("\n Enter number of elements : ");
    scanf("%d", &size);
    // U32 *p = (U32 *)malloc(size * sizeof(U32)); // casting void pointer returned by malloc func
    U32 *p = (U32 *)calloc(size, sizeof(U32));
    printf("\n enter elements ..");

    for (U8 i = 0; i < size; i++)
    {
        printf("\n Enter element at index %d : ", i + 1);
        scanf("%d", &p[i]);
    }

    U32 test, newSize;
    printf("for edit size of list press 1 : ");
    scanf("%d", &test);
    if (test == 1)
    {
        printf("Enter new size : ");
        scanf("%d", &newSize);
        realloc(p, newSize - 1); // func to edit length of malloc list

        for (U8 i = size; i < newSize; i++)
        {
            printf("Enter element at index %d : ", i + 1);
            scanf("%d", &p[i]);
        }
        size = newSize;
    }

    for (U8 j = 1; j < size; j++)
    {

        U32 temp;
        U8 d = j;

        while (d > 0 && p[d - 1] > p[d])
        {
            temp = p[d - 1];
            p[d - 1] = p[d];
            p[d] = temp;
            d--;
        }
    }

    //free(p); // func to free malloc elements

    printf("\n sorted list : \n");
    for (U8 i = 0; i < size; i++)
    {
        printf("\n Enter element at index %d : %d", i + 1, p[i]);
    }

    return 0;
}
