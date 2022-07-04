/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope-part1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:44:38 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/04 10:09:13 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

void	ft_swap_a(t_stack *a)
{
	int	temp;

	if (two_spot(a) == 1)
	{
		temp = a->tableau[(a->size_max) - (a->top_index) -1];
		a->tableau[(a->size_max) - (a->top_index) -1] = a->tableau[(a->size_max) - (a->top_index) -2];
		a->tableau[(a->size_max)  - (a->top_index) -2] = temp;
		ft_printf("sa\n");
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

	if (two_spot(b) == 1)
	{
		temp = b->tableau[(b->size_max) - (b->top_index) -1];
		b->tableau[(b->size_max) - (b->top_index) -1] = b->tableau[(b->size_max) - (b->top_index) -2];
		b->tableau[(b->size_max) - (b->top_index) -2] = temp;
		ft_printf("sb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{	
	int	temp1;
	int	temp2;
	
	if ((two_spot(a) == 1) && (two_spot(b) == 1))
	{
		temp1 = a->tableau[(a->size_max) - (a->top_index) -1];
		a->tableau[(a->size_max) - (a->top_index) -1] = a->tableau[(a->size_max) - (a->top_index) -2];
		a->tableau[(a->size_max)  - (a->top_index) -2] = temp1;
		temp2 = b->tableau[(b->size_max) - (b->top_index) -1];
		b->tableau[(b->size_max) - (b->top_index) -1] = b->tableau[(b->size_max) - (b->top_index) -2];
		b->tableau[(b->size_max) - (b->top_index) -2] = temp2;
		ft_printf("ss\n");
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
		ft_printf("pa\n");
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
		ft_printf("pb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
