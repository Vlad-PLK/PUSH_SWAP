/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:03:47 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:04:06 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_push_b(t_stack *a, t_stack *b)
{
	if (is_full(b) == -1 && is_empty(a) == -1)
	{
		b->top_index--;
		b->tableau[(b->size_max) - (b->top_index) - 1]
			= a->tableau[(a->size_max) - (a->top_index) - 1];
		a->top_index++;
		ft_printf("pb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
