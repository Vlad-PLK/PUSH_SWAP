/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:49 by vpolojie          #+#    #+#             */
/*   Updated: 2022/05/30 15:41:43 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

t_stack *createStack(int size)
{
	t_stack *stack = (t_stack*)malloc(sizeof(t_stack));

	stack->size_max = size;
	stack->top_index = size;
	stack->tableau = (int *)malloc(sizeof(int) * size);

	return (stack);
}

int size(t_stack *stack)
{
	return (stack->size_max - stack->top_index);
}

int	isEmpty(t_stack *stack)
{
	if (stack->top_index == stack->size_max)
		return (0);
	else
		return (-1);
}

int isFull(t_stack *stack)
{
	return stack->top_index == 0;
}

void	push(t_stack *stack, int x)
{
	/*if (isFull(stack))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}*/
	stack->top_index--;
	stack->tableau[stack->top_index] = x;
}

int peek(t_stack *stack)
{
	if (!isEmpty(stack))
	{
		return (stack->tableau[stack->top_index]);
	}
	else
		exit(EXIT_FAILURE);
}

void	ft_swap_a(t_stack *a)
{
	int	temp;
	temp = a->tableau[a->top_index];
	a->tableau[a->top_index] = a->tableau[a->top_index +1];
	a->tableau[a->top_index +1] = temp;
	//ft_printf("sa\n");
}

void	ft_swap_b(t_stack *b)
{
	int temp;
	temp = b->tableau[b->top_index];
	b->tableau[b->top_index] = b->tableau[b->top_index +1];
	b->tableau[b->top_index +1] = temp;
	//ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	//ft_printf("ss\n");
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	a->top_index--;
	a->tableau[a->top_index] = b->tableau[b->top_index];
	b->top_index++;
	//ft_printf("pa\n");
}

/*void	*ft_push_b(t_stack *a, t_stack *b)
{
	b->top_index--;
	b->tableau[b->top_index] = a->tableau[b->top_index];
	a->top_index++;
	//ft_printf("pb\n");
}*/

int	main(int argc, char **argv)
{
	int	v = 5;
	int	a = 1;
	int j;
	int	i = 1;

	ft_printf("-------------START--------------\n");

	t_stack *pile_a = createStack(argc -1);
	t_stack *pile_b = createStack(argc -1);

	ft_printf("----------TOP_INDEX=%d----------\n", pile_a->top_index);	
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		pile_a->top_index--;
		pile_a->tableau[pile_a->top_index] = ft_atoi(argv[i]);
		i++;
	}
	ft_printf("----A----           ----B----\n");
	while (v != -1)
	{
		ft_printf("---TOP_INDEX=%d---\n", pile_a->top_index);
		ft_printf("%d\n", pile_a->tableau[v]);
		v--;
		a++;
	}
	ft_printf("----------TEST----------\n");
	ft_printf("----A----           ----B----\n");
	/*ft_swap_a(pile_a);
	ft_printf("%d\n", pile_a->tableau[pile_a->top_index]);*/
}


