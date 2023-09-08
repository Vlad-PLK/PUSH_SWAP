/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:40:16 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:41:13 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

int	ft_min_int(t_stack *pile_a)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = pile_a->tableau[0];
	while (i != ((pile_a->size_max) - (pile_a->top_index)))
	{
		if (pile_a->tableau[i] < min)
		{
			min = pile_a->tableau[i];
			i++;
		}
		else
			i++;
	}
	while (pile_a->tableau[index] != min)
		index++;
	return (index);
}
