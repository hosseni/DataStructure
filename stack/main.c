#include <stdio.h>
#include <stdlib.h>

#include "includes/std.h"

U32 stack[5];
S32 stackpointer = -1;
U32 counter = 0;
state push();
state pop();
void printStack();

int main(int argc, char const *argv[])
{
    push();
    push();
    state spush = push();
    state spop = pop();
    pop();
    pop();
    printf("\n states of pop is : %d", spop);
    printf("\n states of push is : %d", spush);

    printStack();

    return 0;
}

state push()
{

    if (stackpointer > 5)
    {
        printf("\n Full stack ..");
        return Nok;
    }
    else
    {
        stackpointer++;
        printf("\n Enter element at index %d : ", stackpointer);
        scanf("%d", &stack[stackpointer]);
        return ok;
    }
}

state pop()
{
    if (stackpointer == -1)
    {
        printf("\n Empty .. ");
        return Nok;
    }
    else
    {
        stack[stackpointer] = 0;
        stackpointer--;
        return ok;
    }
}

void printStack()
{
    if (stackpointer == -1)
    {
        printf("\n Empty ..");
    }
    else
    {
        for (U32 i = 0; i <= stackpointer; i++)
        {
            printf("\n Element at index %d is : %d ", i + 1, stack[i]);
        }
        printf("\n ---------------------\n");
    }
}