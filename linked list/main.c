
// one way linkedlist

#include <stdio.h>
#include <stdlib.h>

#include "includes/std.h"

U32 AddCounter = 0;

node *head = NULL; // at first program not have data

void AddFirst(); // func to add new data at first

void AddLast(); // func to add new data at end

void PrintMylist(void); // func to print linkedlist

void removeFirst(void); // func to remove first element of list

void removeLast(void); // func to remove last element of list

void Insert(); // func for insert with location

void Run(); //run code

int main(int argc, char const *argv[])
{
    Run();
    return 0;
}

void AddFirst()
{
    U32 NewData;
    printf("\n Enter a value :");
    scanf("%d", &NewData);
    node *p = (node *)malloc(sizeof(node));
    p->data = NewData;
    p->next = head;
    head = p;
    AddCounter++;
}

void AddLast()
{
    U32 NewData;
    printf("\n Enter a value :");
    scanf("%d", &NewData);

    if (head == NULL)
    {
        AddFirst(NewData);
    }
    else
    {
        node *tempForHead = head;
        node *p = (node *)malloc(sizeof(node));
        while (tempForHead->next != NULL)
        {
            tempForHead = tempForHead->next;
        }
        tempForHead->next = p;
        p->next = NULL;
        p->data = NewData;
    }
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

void removeFirst(void)
{
    node *tempForHead = head;
    if (head == NULL)
    {
        printf("\n Empty ..");
    }
    else
    {
        head = head->next;
        free(tempForHead);
    }
    AddCounter--;
}

void removeLast(void)
{
    if (head == NULL)
    {
        printf("\n Empty ..");
    }
    if (head->next == NULL)
    {
        removeFirst();
    }
    node *tempForHead1 = head;
    node *tempForHead2 = tempForHead1->next;
    while (tempForHead2->next != NULL)
    {
        tempForHead2 = tempForHead2->next;
        tempForHead1 = tempForHead1->next;
    }
    tempForHead1->next = NULL;
    free(tempForHead2);
    AddCounter--;
}
void Insert()
{
    U8 location = 0;
    U32 NewData;
    printf("\n Enter location : ");
    scanf("%d", &location);

    if (head == NULL)
    {
        printf("\n Empty ..");
        printf("\n we will add at first ");
        AddFirst(NewData);
    }
    else if (location == 0)
    {
        AddFirst(NewData);
    }
    else if (location > AddCounter)
    {
        printf("\n you add not existed location \n add at last ");
        AddLast(NewData);
    }
    else if (location <= AddCounter)
    {
        printf(" \n Enter Data : ");
        scanf(" %d", &NewData);
        node *p = (node *)malloc(sizeof(node));
        node *tempForHead1 = head;
        node *tempForHead2 = tempForHead1->next;
        U32 i = 1;
        location = location - 1;
        while (i < location)
        {
            tempForHead1 = tempForHead1->next;
            tempForHead2 = tempForHead2->next;
            i++;
        }
        tempForHead1->next = p;
        p->next = tempForHead2;
        p->data = NewData;
        AddCounter++;
    }
}
void Run()
{
    U8 op = 0;
    printf("\n Hello ..");
    printf("\n linked list operations : "
           "\n press 1 to add element at begining of list"
           "\n press 2 to add element at ending of list"
           "\n press 3 to delete element at begining of list"
           "\n press 4 to delete element at ending of list"
           "\n press 5 to print the list "
           "\n press 6 to add by position"
           "\n press 0 to end..");

    printf("\n Enter op num : ");
    scanf("%d", &op);

    while (op != 0)
    {
        if (op == 1)
        {
            U8 NumAddedFirst = 0;
            printf("\n how many elements will added at first : ");
            scanf("%d", &NumAddedFirst);
            for (U8 i = 0; i < NumAddedFirst; i++)
            {
                AddFirst();
            }
        }
        else if (op == 2)
        {
            U8 NumAddedLast = 0;
            printf("\n how many elements will added at end: ");
            scanf("%d", &NumAddedLast);
            for (U8 i = 0; i < NumAddedLast; i++)
            {
                AddLast();
            }
        }
        else if (op == 3)
        {
            U8 RemoveFirst = 0;
            printf("\n how many elements will removed from the begining  : ");
            scanf("%d", &RemoveFirst);
            for (U8 i = 0; i < RemoveFirst; i++)
            {
                removeFirst();
            }
        }
        else if (op == 4)
        {
            U8 NumRemoveLast = 0;
            printf("\n how many elements will remove from last : ");
            scanf("%d", &NumRemoveLast);
            if (NumRemoveLast > AddCounter)
            {
                printf("\n list only have %d elements and will remove all ", AddCounter);
                for (U8 i = 0; i < AddCounter; i++)
                {
                    removeLast();
                }
            }
            else
            {
                for (U8 i = 0; i < NumRemoveLast; i++)
                {
                    removeLast();
                }
            }
        }
        else if (op == 5)
        {
            PrintMylist();
        }
        else if (op == 6)
        {
            Insert();
        }
        else
        {
            printf("\n Wrong choise ..");
        }
        printf("\n\n enter op num : ");
        scanf("%d", &op);
    }
}