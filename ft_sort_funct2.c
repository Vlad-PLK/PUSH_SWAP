/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_funct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:06:49 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/31 10:47:10 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"

int	*ft_sort_int_tab2(t_stack *pile_a, int temp, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size_max)
	{
		j = i + 1;
		while (j < pile_a->size_max)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*ft_sort_int_tab(t_stack *pile_a)
{
	int		i;
	int		temp;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * pile_a->size_max);
	i = 0;
	while (i < pile_a->size_max)
	{
		tab[i] = pile_a->tableau[i];
		i++;
	}
	temp = 0;
	tab = ft_sort_int_tab2(pile_a, temp, tab);
	return (tab);
}

void	ft_sort_five(t_stack *pile_a, t_stack *pile_b)
{
	while ((pile_a->top_index != 2))
	{
		if (ft_min_int(pile_a) < (pile_a->size_max / 2))
			while ((pile_a->size_max - pile_a->top_index -1)
				!= ft_min_int(pile_a))
				ft_reverse_rotate_a(pile_a);
		else
			while ((pile_a->size_max - pile_a->top_index -1)
				!= ft_min_int(pile_a))
				ft_rotate_a(pile_a);
		ft_push_b(pile_a, pile_b);
	}
	ft_sort_three(pile_a);
	ft_push_a(pile_a, pile_b);
	ft_push_a(pile_a, pile_b);
}

int	check_top(t_stack *a, int *chunk, int nb_chunks)
{
	int	i;
	int	j;

	i = (a->size_max - a->top_index -1);
	while (i != 0)
	{
		j = 0;
		while (j != a->size_max / nb_chunks)
		{
			if (a->tableau[i] == chunk[j])
				return (i);
			else
				j++;
		}
		i--;
	}
	return (-1);
}

int	check_bottom(t_stack *a, int *chunk, int nb_chunks)
{
	int	i;
	int	j;

	i = 0;
	while (i != (a->size_max - a->top_index -1))
	{
		j = 0;
		while (j != a->size_max / nb_chunks)
		{
			if (a->tableau[i] == chunk[j])
				return (i);
			else
				j++;
		}
		i++;
	}
	return (-1);
}
