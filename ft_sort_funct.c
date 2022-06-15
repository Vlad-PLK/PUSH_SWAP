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
	int	max;

	i = 0;
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
	return (max);
}

int	ft_min_int(t_stack *pile_a)
{
	int	i;
	int index;
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

t_stack	*ft_sort_three(t_stack *pile_a)
{
	int	max;

	max = ft_max_int(pile_a);
	if (pile_a->tableau[2] == max)
	{
		ft_rotate_a(pile_a);
		if (ft_check_ascending(pile_a) == -1)
		{
			ft_swap_a(pile_a);
		}
	}
	else if (pile_a->tableau[1] == max)
	{
		ft_reverse_rotate_a(pile_a);
		if (ft_check_ascending(pile_a) == -1)
		{
			ft_swap_a(pile_a);
		}
	}
	else
		ft_swap_a(pile_a);
}

t_stack *ft_sort_five(t_stack *pile_a, t_stack *pile_b)
{
	int	min;
	int	loop_count;

	loop_count = 0;
	min = ft_min_int(pile_a);

	///min < (pile_a->size_max / 2)
	while (loop_count != 2)
	{
		if (min < (pile_a->size_max / 2))
			while ((pile_a->size_max - pile_a->top_index -1) != min)
			{
				ft_reverse_rotate_a(pile_a);
				min = ft_min_int(pile_a);
			}
		else
			while ((pile_a->size_max - pile_a->top_index -1) != min)
			{	
				ft_rotate_a(pile_a);
				min = ft_min_int(pile_a);
			}
		ft_push_b(pile_a, pile_b);
		loop_count++;
	}
	ft_sort_three(pile_a);
	ft_push_a(pile_a, pile_b);
	ft_push_a(pile_a, pile_b);
}