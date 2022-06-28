/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:49 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/10 12:07:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

int	find_occur(t_stack *a)
{
	int i;
	int	j;

	i = 0;
	while (i != a->size_max)
	{
		j = i +1;
		while (j != a->size_max)
		{
			if (a->tableau[i] == a->tableau[j])
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_ascending(t_stack *pile_a)
{
	int i;
	int	j;

	i = 0;
	while (i != (pile_a->size_max) - pile_a->top_index)
	{
		j = i +1;
		while (j != (pile_a->size_max) - pile_a->top_index)
		{
			if (pile_a->tableau[i] < pile_a->tableau[j])
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

void	ft_checkErrors(t_stack *pile_a)
{
	int	i;

	i = 0;
	while (i != pile_a->size_max -1)
	{
		if (pile_a->tableau[i] == 2147483647 || pile_a->tableau[i] == -2147483646 
		|| find_occur(pile_a) == -1)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		else
			i++;
	}
	return ;
}

void	ft_display_tab(t_stack *pile)
{
	int v;

	v = 1;

	ft_printf("----PILE----\n");
	while (v != pile->size_max +1)
	{
		ft_printf("%d\n", pile->tableau[pile->size_max - v]);
		v++;
	}
	ft_printf("\n");

	ft_printf("SIZE MAX ->%d\n", pile->size_max);
	ft_printf("TOP INDEX ->%d\n", pile->top_index);
	ft_printf("VALEUR TOP INDEX ->%d\n", pile->tableau[pile->top_index]);
}

t_stack	*ft_sort_three(t_stack *pile_a)
{
	int	max;

	max = ft_max_int(pile_a);
	if (ft_check_ascending(pile_a) == 0)
		return (pile_a);
	if (pile_a->tableau[2] == pile_a->tableau[max])
	{
		ft_rotate_a(pile_a);
		if (ft_check_ascending(pile_a) == -1)
			ft_swap_a(pile_a);
	}
	else if (pile_a->tableau[1] == pile_a->tableau[max])
	{
		ft_reverse_rotate_a(pile_a);
		if (ft_check_ascending(pile_a) == -1)
			ft_swap_a(pile_a);
	}
	else
		ft_swap_a(pile_a);
}