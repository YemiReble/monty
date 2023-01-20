#include "monty.h"

/**
 * pchar - print top of stack as a char
 *
 * @top: top of stack
 */
void pchar(stack_t **top)
{
	stack_t *ptr = *top;

	if (ptr == NULL)
		exitwrap(EXIT_FAILURE, "can't pchar, stack empty", *top);
	if (ptr->n > 127 || ptr->n < 0)
		exitwrap(EXIT_FAILURE, "can't pchar, value out of range", *top);
	printf("%c\n", ptr->n);
}

/**
 * pstr - print stack as string starting from the top
 * stop on 0 or out of ascii bounds
 *
 * @top: top of stack
 */
void pstr(stack_t **top)
{
	stack_t *ptr = *top;

	while (ptr != NULL && ptr->n <= 127 && ptr->n > 0)
	{
		printf("%c", ptr->n);
		ptr = ptr->prev;
	}
	printf("\n");
}

/**
 * rotl - "rotate left" put top of stack on bottom
 *
 * @top: top of stack
 * @bot: bottom of stack
 */
void rotl(stack_t **top, stack_t **bot)
{
	stack_t *ptrt = *top, *ptrb = *bot;

	if (ptrt == NULL || ptrt->prev == NULL)
		return;
	ptrt->next = ptrb;
	ptrb->prev = ptrt;
	*top = ptrt->prev;
	(*top)->next = NULL;
	*bot = ptrt;
	ptrt->prev = NULL;
}

/**
 * rotr - "rotate right" put bottom of stack on top
 *
 * @top: top of stack
 * @bot: bottom of stack
 */
void rotr(stack_t **top, stack_t **bot)
{
	stack_t *ptrt = *top, *ptrb = *bot;

	if (ptrt == NULL || ptrt->prev == NULL)
		return;
	ptrt->next = ptrb;
	ptrb->prev = ptrt;
	*bot = ptrb->next;
	(*bot)->prev = NULL;
	*top = ptrb;
	ptrb->next = NULL;
}
