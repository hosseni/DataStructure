#include <stdio.h>
#include "includes/std.h"
#define QueueSize 5
U32 Queue[QueueSize];
S32 front = -1;
S32 rear = -1;

typedef enum
{
    Nok,
    ok
} state;

state Enqueue(U32 Data);
state PrintQueue(U32 *p);
state DeQueue(U32 *p);

void main(void)
{
    U32 Data, NumOfData, op, NumOfDequeued;
    printf("\n press 1 to Enqueue \n press 2 to Dequeue \n press 3 to display \n press 0 to exit \n");
loop:
    printf(" \n op num : ");
    scanf("%d", &op);

    while (op != 0)
    {
        if (op == 1)
        {
            printf("How many element will be Enqueued : ");
            scanf("%d", &NumOfData);
            if (NumOfData > QueueSize)
            {
                printf(" \n it is to larg ..\n try again ..\n");
                goto loop;
            }
            else
            {
                for (U8 i = 0; i < NumOfData; i++)
                {
                    printf(" \n Enter element at index %d : ", rear + 1);
                    scanf("%d", &Data);
                    Enqueue(Data);
                }
            }
        }
        else if (op == 2)
        {
            printf(" \n How many element will be Dequeued : ");
            scanf("%d", &NumOfDequeued);
            for (U8 i = 0; i < NumOfDequeued; i++)
            {
                DeQueue(Queue);
            }
        }
        else if (op == 3)
        {
            PrintQueue(Queue);
        }
        printf("\n Enter op num : ");
        scanf("%d", &op);
    }
}

state Enqueue(U32 Data)
{
    if (rear == (front - 1))
    {
        printf("Queue if full ...\n");
        return Nok;
    }
    else if (front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
        Queue[rear] = Data;
    }
    //      else if (rear == -1 && front < 0)
    // {
    //     rear = 0;
    //     scanf("%d",&Queue[rear]);

    // }

    else
    {
        rear++;
        Queue[rear] = Data;
        if (rear == (QueueSize - 1))
        {
            PrintQueue(Queue);
            rear = -1;
        }
    }
    return ok;
}

state PrintQueue(U32 *p)
{

    if (rear == -1 && front == -1)
    {
        printf("Empty Queue ..\n");
        printf("rear = %d ,front = %d \n", rear, front);

        return Nok;
    }
    else
    {

        printf("\n");
        for (U8 i = 0; i < QueueSize; i++)
        {
            printf(" %d \t", p[i]);
        }

        printf(" \n rear = %d ,front = %d \n ", rear, front);
        return ok;
    }
}

state DeQueue(U32 *p)
{
    if (rear == -1 && front == -1)
    {
        printf("Empty Queue ..\n");
        printf("rear = %d ,front = %d \n", rear, front);

        return Nok;
    }
    else
    {
        if (front < rear)
        {
            *p = Queue[front];
            printf("Dequeue value is : %d \n", p[front]);
            p[front] = 0;
            front++;
            printf("rear = %d ,front = %d \n", rear, front);
        }
        else if (rear == front)
        {
            *p = Queue[front];
            printf("Dequeue value is : %d \n", p[front]);

            p[front] = 0;
            rear = -1;
            front = -1;
            printf("rear = %d ,front = %d \n", rear, front);
        }

        else if (rear < front)
        {
            if (front == QueueSize-1)
            {
                *p = Queue[front];
                printf("\nDequeue value is : %d \n ", p[front]);

                p[front] = 0;
                front = 0;
                printf("rear = %d ,front = %d \n", rear, front);
            }
            else
            {
                *p = Queue[front];
                printf("\nDequeue value is : %d \n ", p[front]);

                p[front] = 0;
                front ++;
                printf("rear = %d ,front = %d \n", rear, front);
            }
           
        }
    }
}