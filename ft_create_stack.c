/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:51:17 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/28 20:25:26 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_max = size;
	stack->top_index = size;
	stack->tableau = (int *)malloc(sizeof(int) * size);
	return (stack);
}

void	ft_free_chunks(int **chunks, int nb_chunks, t_stack *a, t_stack *b)
{
	int	i;

	while (is_empty(a) == -1)
		ft_push_b(a, b);
	i = 0;
	while (i != nb_chunks)
	{
		free(chunks[i]);
		i++;
	}
	free(chunks);
}

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	free(a->tableau);
	free(a);
	free(b->tableau);
	free(b);
}
