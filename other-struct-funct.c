/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other-struct-funct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:45:39 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/06 18:46:10 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "ft_push_swap.h"

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

int	two_spot(t_stack *stack)
{
	if (stack->top_index <= stack->size_max -2)
		return (1);
	else
		return (0);
}

int isFull(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	else
		return (-1);
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

void	ft_rrr(t_stack *a, t_stack *b)
{
	int	temp1;
	int v_haut;
	int v_bas;
	int	temp2;
	int v_haut2;
	int	v_bas2;

	v_haut2 = ((b->size_max) - (b->top_index) -1);
	v_bas = 0;
	v_bas2 = 0;
	v_haut = ((a->size_max) - (a->top_index) -1);

	if(isEmpty(a) == -1 && isEmpty(b) == -1)
	{	
		while (v_bas != v_haut && v_bas2 != v_haut2)
		{
			temp1 = a->tableau[v_bas];
			a->tableau[v_bas] = a->tableau[v_bas +1];
			a->tableau[v_bas +1] = temp1;
			temp2 = b->tableau[v_bas2];
			b->tableau[v_bas2] = b->tableau[v_bas2 +1];
			b->tableau[v_bas2 +1] = temp2;
			v_bas++;
			v_bas2++;
		}
		ft_printf("rrr\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
