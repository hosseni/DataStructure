
#include <stdio.h>
#include <stdlib.h>

#include "includes/std.h"

U32 AddCounter = 0;
node *head = NULL;

void Enqueue();
void Dequeue();
void PrintMylist();

int main(int argc, char const *argv[])
{
    U32 op;
    printf("\n for Enqueue press 1 "
           "\n for Dequeue press 2 "
           "\n for print queue press 3"
           "\n for exit press 0 ");
    printf("\n-------------"
           "\n Enter op num :");
    scanf("%d", &op);
    while (op != 0)
    {
        if (op == 1)
        {
            U8 NumOfEnqueuedElement = 0;
            printf("\n how many element will be enqueued :");
            scanf("%d", &NumOfEnqueuedElement);
            for (U32 i = 0; i < NumOfEnqueuedElement; i++)
            {
                Enqueue();
            }
        }
        else if (op == 2)
        {
            U8 NumOfDequeuedElement = 0;
            printf("\n How many element will be dequeued : ");
            scanf("%d", &NumOfDequeuedElement);
            if (NumOfDequeuedElement > AddCounter)
            {
                printf("\n queue only have %d element and will dequeue all elements ", AddCounter);

                for (U8 i = 1; i < AddCounter + 1; i++)
                {
                    Dequeue();
                }
            }
            else
            {
                for (U8 i = 0; i < NumOfDequeuedElement; i++)
                {
                    Dequeue();
                }
            }
        }
        else if (op == 3)
        {
            PrintMylist();
        }
        else
        {
            printf("\n Wrong chiose .. \t try agin ..");
        }
        printf("\n-------------"
               "\n Enter op num :");
        scanf("%d", &op);
    }

    return 0;
}

void Enqueue()
{

    U32 NewData;
    printf("\n Enqueue value : :");
    scanf("%d", &NewData);
    node *p = (node *)malloc(sizeof(node));
    p->data = NewData;
    p->next = head;
    head = p;
    AddCounter++;
}

void Dequeue()
{
    if (head == NULL)
    {
        printf("\n Empty ..");
    }
    else if (head->next == NULL)
    {
        node *tempForHead1 = head;
        printf("\n Dequeued value is : %d ", tempForHead1->data);
        head = NULL;
        AddCounter--;
    }

    else
    {
        node *tempForHead1 = head;
        node *tempForHead2 = tempForHead1->next;
        while (tempForHead2->next != NULL)
        {
            tempForHead2 = tempForHead2->next;
            tempForHead1 = tempForHead1->next;
        }
        printf("\n Dequeued value is : %d ", tempForHead2->data);
        tempForHead1->next = NULL;
        free(tempForHead2);
        AddCounter--;
    }
}
void PrintMylist()
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
