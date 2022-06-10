/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:52:04 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/10 12:07:31 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

int	ft_max_int(t_stack *pile_a)
{
	int	i;
	int	j;

	i = 0;
	while (i != (pile_a->size_max - pile_a->top_index -1))
	{
		j = i +1;
		while (j != (pile_a->size_max - pile_a->top_index -1))
		{
			if (pile_a->tableau[i] > pile_a->tableau[j])
				j++;
			else
				break;
		}
		if (j == (pile_a->size_max - pile_a->top_index -1))
			return (pile_a->tableau[i]);
		else
			i++;
	}
	return (0);
}
