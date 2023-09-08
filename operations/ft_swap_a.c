/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:01:58 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:02:38 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_swap_a(t_stack *a)
{
	int	temp;

	if (two_spot(a) == 1)
	{
		temp = a->tableau[(a->size_max) - (a->top_index) - 1];
		a->tableau[(a->size_max) - (a->top_index) - 1]
			= a->tableau[(a->size_max) - (a->top_index) - 2];
		a->tableau[(a->size_max) - (a->top_index) - 2] = temp;
		ft_printf("sa\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}