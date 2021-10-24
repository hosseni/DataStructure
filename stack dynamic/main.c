
#include <stdio.h>
#include <stdlib.h>

#include "includes/std.h"

U32 AddCounter = 0;
node *head = NULL; // at first program not have data
node *stackPointer;

void Push();
void Pop();
void PrintMylist();

int main(int argc, char const *argv[])
{
    U32 op = 0;
    printf("\n Hello in stack ..");
    printf("\n for push press 1"
           "\n for pop press 2"
           "\n for print list press 3"
           "\n for exit press 0 ");
    printf("\n Enter op num : ");
    scanf("%d", &op);
    while (op != 0)
    {

        if (op == 1)
        {
            U32 NumOfPushedElement = 0;
            printf("\n how many elements will be pushed in stack : ");
            scanf("%d", &NumOfPushedElement);
            for (U32 i = 0; i < NumOfPushedElement; i++)
            {
                Push();
            }
        }
        else if (op == 2)
        {
            U32 NumOfPopedElement = 0;
            printf("\n how many element will poped from the stack : ");
            scanf("%d", &NumOfPopedElement);
            if (NumOfPopedElement > AddCounter)
            {
                printf("\n stack only have %d element and it will be poped ..", AddCounter);
            }
            for (U32 i = 0; i < NumOfPopedElement - 1; i++)
            {
                Pop();
            }
        }
        else if (op == 3)
        {
            PrintMylist();
        }
        else
        {
            printf("\n Wrong choise  ..");
        }
        printf("\n Enter op num : ");
        scanf("%d", &op);
    }

    return 0;
}

void Push()
{

    U32 NewData;
    printf("\n Enter value of element %d :", AddCounter + 1);
    scanf("%d", &NewData);
    node *p = (node *)malloc(sizeof(node));
    p->data = NewData;
    p->next = head;
    head = p;
    AddCounter++;
}

void PrintMylist(void)
{
    if (head == NULL)
    {
        printf("\n empty ..");
    }
    else
    {
        node *tempForHead = head;
        U8 i = 0;

        do
        {
            printf("\n Element number %d is : %d ", i + 1, tempForHead->data);
            tempForHead = tempForHead->next;
            i++;

        } while (tempForHead != NULL);
    }
    printf("\n ---------------------\n");
}

void Pop()
{
    node *tempForHead = head;
    if (head == NULL)
    {
        printf("\n Empty ..");
    }
    else
    {
        printf("\n poped value is : %d ", tempForHead->data);
        head = head->next;
        free(tempForHead);
    }
    AddCounter--;
}
