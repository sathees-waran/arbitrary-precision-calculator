/**
 * @file    multiplication.c
 * @brief   Performs arbitrary precision multiplication.
 *
 * @details Multiplies two large numbers stored as doubly linked lists
 *          using the traditional digit-by-digit multiplication method.
 *          Partial products are generated, shifted using zeros, and added
 *          using the existing arbitrary precision addition function.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
                    Dlist **head2, Dlist **tail2,
                    Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;
    Dlist *temp2;

    Dlist *headR1 = NULL;
    Dlist *tailR1 = NULL;

    Dlist *headR2 = NULL;
    Dlist *tailR2 = NULL;

    int data;
    int carry;
    int count = 0;

    temp2 = *tail2;

    while (temp2 != NULL)
    {
        temp1 = *tail1;
        carry = 0;

        while (temp1 != NULL)
        {
            data = (temp1->data * temp2->data) + carry;

            insert_first(&headR2, &tailR2, data % 10);

            carry = data / 10;

            temp1 = temp1->prev;
        }

        /* Remaining carry */
        if (carry != 0)
        {
            insert_first(&headR2, &tailR2, carry);
        }

  
        for (int i = 0; i < count; i++)
        {
            insert_last(&headR2, &tailR2, 0);
        }

        if (headR1 == NULL)
        {
            headR1 = headR2;
            tailR1 = tailR2;
        }
        else
        {
            addition(&headR1, &tailR1,
                     &headR2, &tailR2,
                     headR, tailR);

          
            delete_list(&headR1, &tailR1);
            delete_list(&headR2, &tailR2);

         
            headR1 = *headR;
            tailR1 = *tailR;

            *headR = NULL;
            *tailR = NULL;
        }

        headR2 = NULL;
        tailR2 = NULL;

        count++;

        temp2 = temp2->prev;
    }

   
    *headR = headR1;
    *tailR = tailR1;

    remove_leading_zeros(headR, tailR);
    
    return SUCCESS;
}