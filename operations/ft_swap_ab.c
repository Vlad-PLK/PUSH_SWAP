/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:03:07 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:03:21 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_ss(t_stack *a, t_stack *b)
{	
	int	temp1;
	int	temp2;

	if ((two_spot(a) == 1) && (two_spot(b) == 1))
	{
		temp1 = a->tableau[(a->size_max) - (a->top_index) - 1];
		a->tableau[(a->size_max) - (a->top_index) - 1]
			= a->tableau[(a->size_max) - (a->top_index) - 2];
		a->tableau[(a->size_max) - (a->top_index) - 2] = temp1;
		temp2 = b->tableau[(b->size_max) - (b->top_index) - 1];
		b->tableau[(b->size_max) - (b->top_index) - 1]
			= b->tableau[(b->size_max) - (b->top_index) - 2];
		b->tableau[(b->size_max) - (b->top_index) - 2] = temp2;
		ft_printf("ss\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}