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
	if(isEmpty(a) == -1 && isEmpty(b) == -1)
	{
		ft_reverse_rotate_a(a);
		ft_reverse_rotate_b(b);
		ft_printf("rrr\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
