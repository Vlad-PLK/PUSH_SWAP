/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:49 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/01 11:55:20 by vpolojie         ###   ########.fr       */
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
		return (1);
	else
		return (-1);
}

int isFull(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	else
		return (-1);
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

void	ft_rotate_a(t_stack *a)
{
	int	temp;
	int	v_haut;

	v_haut = (a->size_max) - (a->top_index) -1;

	if (isEmpty(a) == -1)
	{	
		while (v_haut != 0)  
		{
			temp = a->tableau[v_haut];
			a->tableau[v_haut] = a->tableau[v_haut -1];
			a->tableau[v_haut -1] = temp;
			v_haut--;
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int j;
	int	i;
	int	v;
	int	w;
	
	i = 1;
	ft_printf("-------------START--------------\n");

	t_stack *pile_a = createStack(argc -1);
	t_stack *pile_b = createStack(argc -1);
	
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
		//ft_printf("index ->%d\n", pile_a->top_index);//
		pile_a->top_index--;
		pile_a->tableau[pile_a->top_index] = ft_atoi(argv[i]);
		i++;
	}	
	ft_printf("----A----           ----B----\n");
	v = 1;
	while (v != pile_a->size_max +1)
	{
		ft_printf("%d\n", pile_a->tableau[pile_a->size_max - v]);
		v++;
	}
	ft_printf("\n");
	ft_printf("SIZE MAX ->%d\n", pile_a->size_max);
	ft_printf("TOP INDEX ->%d\n", pile_a->top_index);
	ft_printf("VALEUR TOP INDEX ->%d\n", pile_a->tableau[pile_a->top_index]);


	ft_printf("------------OPERATION------------\n");
	
	ft_rotate_a(pile_a);	
	///ft_swap_a(pile_a);
	///ft_push_b(pile_a, pile_b);
	///ft_push_b(pile_a, pile_b);
	///ft_swap_b(pile_b);
	///ft_push_a(pile_a, pile_b);
	///ft_push_a(pile_a, pile_b);
	
	ft_printf("---------------------------------\n");
	ft_printf("----A----           ----B----\n");
	v = 1;
	w = 1;
	while (v != ((pile_a->size_max) +1) && w != ((pile_b->size_max) +1))
	{
		ft_printf("%d                  %d\n", pile_a->tableau[pile_a->size_max - v], pile_b->tableau[pile_b->size_max - w]);
		v++;
		w++;
	}
	ft_printf("\n");
	ft_printf("SIZE MAX_A ->%d            SIZE MAX_B ->%d\n", pile_a->size_max, pile_b->size_max);
	ft_printf("TOP INDEX_A ->%d           TOP_INDEX_B ->%d\n", pile_a->top_index, pile_b->top_index);
	ft_printf("VALEUR TOP INDEX_A ->%d    VALEUR TOP INDEX_B ->%d\n", pile_a->tableau[pile_a->top_index], pile_b->tableau[pile_b->top_index]);
}


