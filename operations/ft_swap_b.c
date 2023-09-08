/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:02:44 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:09:24 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_swap_b(t_stack *b)
{
	int	temp;

	if (two_spot(b) == 1)
	{
		temp = b->tableau[(b->size_max) - (b->top_index) - 1];
		b->tableau[(b->size_max) - (b->top_index) - 1]
			= b->tableau[(b->size_max) - (b->top_index) - 2];
		b->tableau[(b->size_max) - (b->top_index) - 2] = temp;
		ft_printf("sb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}