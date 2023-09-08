/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope-part2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:45:11 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/06 18:53:32 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

int	ft_max_int(t_stack *pile_a)
{
	int	i;
	int	index;
	int	max;

	i = 0;
	index = 0;
	max = pile_a->tableau[0];
	while (i != ((pile_a->size_max) - (pile_a->top_index)))
	{
		if (pile_a->tableau[i] > max)
		{
			max = pile_a->tableau[i];
			i++;
		}
		else
			i++;
	}
	while (pile_a->tableau[index] != max)
		index++;
	return (index);
}
