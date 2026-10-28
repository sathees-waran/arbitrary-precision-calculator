/**
 * @file    apc.c
 * @brief   Common operations for the Arbitrary Precision Calculator (APC).
 *
 * @details Provides utility functions for creating, inserting, deleting,
 *          comparing and displaying doubly linked lists used
 *          to represent arbitrary precision operands and results.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "apc.h"

int insert_first(Dlist **headR, Dlist **tailR, int digit)
{
    Dlist *newnode = malloc(sizeof(Dlist));

    if (newnode == NULL)
    {
        printf("Memory Allocation Failed at insert_first function!\n");
        return FAILURE;
    }

    newnode->data = digit;
    newnode->prev = NULL;
    newnode->next = NULL;

    /* Result list is empty */
    if (*headR == NULL)
    {
        *headR = newnode;
        *tailR = newnode;
    }
    /* Result list already has nodes */
    else
    {
        newnode->next = *headR;
        (*headR)->prev = newnode;
        *headR = newnode;
    }
    return SUCCESS;
}

int digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    int i;
    Dlist *newnode;

    /* Convert first operand */
    for (i = 0; argv[1][i] != '\0'; i++)
    {
         
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("Input Contains Non-Digit character : %s\n", argv[1]);
            delete_list(head1,tail1);
            return FAILURE;
        }
        newnode = malloc(sizeof(Dlist));

        if (newnode == NULL)
        {
            printf("Memory Allocation Failed at digit_to_list function! \n");
            delete_list(head1,tail1);
            return FAILURE;
        }

        newnode->data = argv[1][i] - '0';
        newnode->prev = *tail1;
        newnode->next = NULL;

        if (*head1 == NULL)
        {
            *head1 = newnode;
            *tail1 = newnode;
        }
        else
        {
            (*tail1)->next = newnode;
            *tail1 = newnode;
        }
       
    }
    remove_leading_zeros(head1, tail1);

    /* Convert second operand */
    for (i = 0; argv[3][i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)argv[3][i]))
        {
            printf("Input Contains Non-Digit character : %s\n", argv[3]);
            delete_list(head2,tail2);
            return FAILURE;
        }
        newnode = malloc(sizeof(Dlist));

        if (newnode == NULL)
        {
            printf("Memory Allocation Failed at digit_to_list function! \n");
            return FAILURE;
        }

        
        newnode->data = argv[3][i] - '0';
        newnode->prev = *tail2;
        newnode->next = NULL;

        if (*head2 == NULL)
        {
            *head2 = newnode;
            *tail2 = newnode;
        }
        else
        {
            (*tail2)->next = newnode;
            *tail2 = newnode;
        }
            remove_leading_zeros(head2, tail2);
        
    }
    return SUCCESS;
}

int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));

    if (newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = *tail;

    /* Empty list */
    if (*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
    return SUCCESS;
}

int print_list(Dlist *head)
{
    Dlist *temp = head;

    if (head == NULL)
    {
        printf("\nList is Empty!\n");
        return FAILURE;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return SUCCESS;
}

int compare(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;
    Dlist *temp;

    temp = head1;
    while (temp != NULL)
    {
        count1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        count2++;
        temp = temp->next;
    }

    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    /* Same number of digits */
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
            return 1;

        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}

int remove_leading_zeros(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    /* Keep at least one zero node */
    while (*head != *tail && (*head)->data == 0)
    {
        temp = *head;

        *head = (*head)->next;
        (*head)->prev = NULL;

        free(temp);
    }

    return SUCCESS;
}