/**
 * @file    subtraction.c
 * @brief   Performs arbitrary precision subtraction.
 *
 * @details Subtracts two large numbers stored as doubly linked lists.
 *          The function compares the operands, performs digit-by-digit
 *          subtraction from the least significant digit, handles borrow
 *          values, and identifies negative results.
 **/

#include <stdlib.h>
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
				Dlist **head2, Dlist **tail2,
				Dlist **headR, Dlist **tailR)
{
	Dlist *temp1;
	Dlist *temp2;

	int borrow = 0;
	int data;
	int flag = 0;

	int cmp = compare(*head1, *head2);

	/* Equal numbers */
	if (cmp == 0)
	{
		insert_first(headR, tailR, 0);
		return SUCCESS;
	}

	/* head1 is greater */
	if (cmp > 0)
	{
		temp1 = *tail1;
		temp2 = *tail2;
	}
	/* head2 is greater */
	else
	{
		temp1 = *tail2;
		temp2 = *tail1;

		flag = 1;
	}

	while (temp1 != NULL || temp2 != NULL)
	{
		/* Both digits exist */
		if (temp1 != NULL && temp2 != NULL)
		{
			data = temp1->data - temp2->data - borrow;

			if (data < 0)
			{
				data = data + 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}

			insert_first(headR, tailR, data);

			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}

		/* Only first number has digits */
		else if (temp1 != NULL && temp2 == NULL)
		{
			data = temp1->data - borrow;

			if (data < 0)
			{
				data = data + 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}

			insert_first(headR, tailR, data);

			temp1 = temp1->prev;
		}
	}

	    remove_leading_zeros(headR, tailR);
	
	return flag;
}