/**
 * @file    division.c
 * @brief   Performs arbitrary precision division.
 *
 * @details Divides two large numbers stored as doubly linked lists using
 *          the continuous subtraction method. The remainder is repeatedly
 *          compared with the divisor and the existing subtraction function
 *          is used to calculate the next remainder until the remainder is
 *          smaller than the divisor.
 **/

#include <stdlib.h>
#include <stdio.h>
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{

    Dlist *tempHead = NULL;
    Dlist *tempTail = NULL;

    Dlist *resultHead = NULL;
    Dlist *resultTail = NULL;

    int quotient = 0;
    int cmp;
    int ret;

    /*
     * Division by zero
     */
    if (*head2 == NULL)
    {

        return FAILURE;
    }

    if ((*head2)->data == 0 && *head2 == *tail2)
    {
        printf("Can not divide by 0\n");
        return FAILURE;
    }

    /*
     * If dividend is zero
     */
    if (*head1 == NULL)
    {
        insert_first(headR, tailR, 0);
        return SUCCESS;
    }


    Dlist *temp = *head1;

    while (temp != NULL)
    {
        if (insert_last(&tempHead, &tempTail, temp->data) == FAILURE)
        {
            return FAILURE;
        }

        temp = temp->next;
    }

    while (1)
    {
        /*
         * Compare remainder with divisor
         */
        cmp = compare(tempHead, *head2);

       
        if (cmp < 0)
        {
            break;
        }

        ret = subtraction(&tempHead, &tempTail,
                          head2, tail2,
                          &resultHead, &resultTail);

        if (ret == FAILURE)
        {
            delete_list(&tempHead, &tempTail);
            return FAILURE;
        }

        /*
         * Old remainder is no longer needed
         */
        delete_list(&tempHead, &tempTail);

        /*
         * New remainder becomes temp
         */
        tempHead = resultHead;
        tempTail = resultTail;

        resultHead = NULL;
        resultTail = NULL;

        quotient++;
    }

    delete_list(&tempHead, &tempTail);

    
    if (quotient == 0)
    {
        insert_first(headR, tailR, 0);
    }
    else
    {
        while (quotient > 0)
        {
            insert_first(headR, tailR, quotient % 10);
            quotient = quotient / 10;
        }
    }

    return SUCCESS;
}

