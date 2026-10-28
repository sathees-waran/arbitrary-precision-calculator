/**
 * @file    apc.h
 * @brief   Header file for the Arbitrary Precision Calculator (APC).
 *
 * @details Contains the Dlist structure, status macros, and function
 *          prototypes used by the APC modules. The calculator stores
 *          operands and results using doubly linked lists.
 **/

#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int remove_leading_zeros(Dlist **head, Dlist **tail);

int insert_first(Dlist **headR, Dlist **tailR, int digit);

int insert_last(Dlist **head, Dlist **tail, int data);

int print_list(Dlist *head);

int delete_list(Dlist **head, Dlist **tail);

int compare(Dlist *head1, Dlist *head2);

/*store the operands into the list */
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif
