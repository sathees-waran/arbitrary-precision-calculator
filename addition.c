/**
 * @file    addition.c
 * @brief   Performs arbitrary precision addition.
 *
 * @details Adds two large numbers stored as doubly linked lists. The
 *          addition is performed digit-by-digit from the least significant
 *          digit while handling carry values. The result is stored in a
 *          separate doubly linked list.
 **/
#include <stdlib.h>
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int carry = 0;
	int data;

	while(temp1 != NULL || temp2 != NULL)
	{
		/*Both numbers have digits*/
		if(temp1 != NULL && temp2 != NULL)
		{
			data = temp1 -> data + temp2 -> data + carry;

			if(data > 9)
			{
				insert_first(headR, tailR, data % 10);
				carry = data / 10;
			}
			else
			{
				insert_first(headR, tailR, data);
                carry = 0;
			}

			temp1 = temp1->prev;
            temp2 = temp2->prev;
		}

		/*only first number has digits*/
		else if(temp1 != NULL && temp2 == NULL)
		{
			data = temp1 -> data + carry;

			insert_first(headR, tailR, data % 10);

			carry = data / 10;
			 
			temp1 = temp1 -> prev;
		}
		/*only Second number has digits*/
		else if(temp1 == NULL && temp2 != NULL)
		{
			data = temp2 -> data + carry;

			insert_first(headR, tailR, data % 10);

			carry = data / 10;
			 
			temp2 = temp2 -> prev;
		}

	}

	/*remaining carry*/
	if(carry == 1)
	{
		insert_first(headR, tailR, carry);
		carry = 0;
	}
	return SUCCESS;
}
