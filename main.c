/**
 * @file    main.c
 * @brief   Entry point for the Arbitrary Precision Calculator (APC).
 *
 * @details Parses command-line arguments, identifies the arithmetic
 *          operator, and dispatches the operation to the corresponding
 *          module. The main function also handles input validation and
 *          displays the final result.
 * @author  Satheeswaran M
 *
 * @project Arbitrary Precision Calculator (APC)
 */

/*
    NOTE : Sample Input Format:  ./a.out 100 + 10
*/
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */

    if(argc != 4)
    {
        printf("\nEnter valid command!!\n eg. < ./a.out num1 + num2 >\n");
        return FAILURE;
    }

	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;

	char operator = argv[2][0];
	int valid;

	switch (operator)
	{
	case '+':

		valid = digit_to_list(&head1, &tail1, &head2, &tail2, argv);

		if(valid == FAILURE) return 0;

		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);

		printf("ANSWER : ");

		print_list(headR);

		break;
	case '-':

		int flag;
	
		valid = digit_to_list(&head1, &tail1, &head2, &tail2, argv);

		if(valid == FAILURE) return 0;

		flag = subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);

		if (flag)
		{

			printf("ANSWER : -");
		}
		else
		{
			printf("ANSWER : ");
		}

		print_list(headR);
		break;
	case 'x':

		valid = digit_to_list(&head1, &tail1, &head2, &tail2, argv);

		if(valid == FAILURE) return 0;

		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);

		printf("ANSWER : ");

		print_list(headR);

		break;
	case '/':
		int ret;

		valid = digit_to_list(&head1, &tail1, &head2, &tail2, argv);

		if(valid == FAILURE) return 0;

		ret = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);

		if(ret == FAILURE)
		{
			printf("Enter Valid Numbers\n");
			return FAILURE;
		}

		printf("ANSWER : ");

		print_list(headR);
		
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}
	return 0;
}
