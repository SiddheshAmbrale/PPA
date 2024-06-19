//  Write a program which display addition of digits of element from singly linear linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node *PNODE;
typedef struct Node **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE)); //  void *__cdecl malloc(size_t)

    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

int Count(PNODE Head)
{
    int iCount = 0;

    while (Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }

    return iCount;
}

void InsertAtPos(PPNODE Head, int No, int ipos)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;

    iLength = Count(*Head);

    if ((ipos < 1) || (ipos > (iLength + 1)))
    {
        printf("Invalid input\n");
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(Head, No);
    }
    else if (ipos == (iLength + 1))
    {
        InsertLast(Head, No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int ipos)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE temp = *Head;
    PNODE tempX = *Head;

    iLength = Count(*Head);

    if ((ipos < 1) || (ipos > iLength))
    {
        printf("Invalid input\n");
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(Head);
    }
    else if (ipos == (iLength + 1))
    {
        DeleteLast(Head);
    }
    else
    {
        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ", Head->data);
        Head = Head->next;
    }

    printf("NULL\n");
}

int digitSummation(int iNo)
{
    int iDigit = 0;
    int iSum = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum += iDigit;
        iNo /= 10;
    }

    return iSum;
}

void Summation(PNODE Head)
{
    printf("Summation of digits of elements are : \n");

    while(Head != NULL)
    {
        printf("|%d| = %d\n",Head->data,digitSummation(Head->data));
        Head = Head->next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 240);
    InsertFirst(&First, 320);
    InsertFirst(&First, 230);
    InsertFirst(&First, 110);

    Display(First);

    Summation(First);
    
    return 0;
}