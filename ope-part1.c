#include "ft_push_swap.h"

void	ft_swap_a(t_stack *a)
{
	int	temp;

	if (isEmpty(a) == -1)
	{
		temp = a->tableau[(a->size_max) - (a->top_index) -1];
		a->tableau[(a->size_max) - (a->top_index) -1] = a->tableau[(a->size_max) - (a->top_index) -2];
		a->tableau[(a->size_max)  - (a->top_index) -2] = temp;
		//ft_printf("sa\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_swap_b(t_stack *b)
{
	int temp;

	if (isEmpty(b) == -1)
	{
		temp = b->tableau[(b->size_max) - (b->top_index) -1];
		b->tableau[(b->size_max) - (b->top_index) -1] = b->tableau[(b->size_max) - (b->top_index) -2];
		b->tableau[(b->size_max) - (b->top_index) -2] = temp;
		//ft_printf("sb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{	
	if ((isEmpty(a) == -1) && (isEmpty(b) == -1))
	{
		ft_swap_a(a);
		ft_swap_b(b);
		//ft_printf("ss\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	if (isFull(a) == -1 && isEmpty(b) == -1)
	{
		a->top_index--;
		a->tableau[(a->size_max) - (a->top_index) -1] = b->tableau[(b->size_max) - (b->top_index) -1];
		b->top_index++;
		//ft_printf("pa\n");//
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_push_b(t_stack *a, t_stack *b)
{
	if (isFull(b) == -1 && isEmpty(a) == -1)
	{
		b->top_index--;
		b->tableau[(b->size_max) - (b->top_index) -1] = a->tableau[(a->size_max) - (a->top_index) -1];
		a->top_index++;
		//ft_printf("pa\n");//
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}