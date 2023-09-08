/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:03:28 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:04:14 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_push_a(t_stack *a, t_stack *b)
{
	if (is_full(a) == -1 && is_empty(b) == -1)
	{
		a->top_index--;
		a->tableau[(a->size_max) - (a->top_index) - 1]
			= b->tableau[(b->size_max) - (b->top_index) - 1];
		b->top_index++;
		ft_printf("pa\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
