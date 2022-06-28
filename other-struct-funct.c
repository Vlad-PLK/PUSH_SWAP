/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other-struct-funct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:45:39 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/06 18:46:10 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "ft_push_swap.h"

int	isEmpty(t_stack *stack)
{
	if (stack->top_index == stack->size_max)
		return (1);
	else
		return (-1);
}

int	two_spot(t_stack *stack)
{
	if (stack->top_index <= stack->size_max -2)
		return (1);
	else
		return (0);
}

int isFull(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	else
		return (-1);
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

int	**ft_split_tab(t_stack *pile_a)
{
	int	n;
	int	*tab;
	int	i;
	int	**chunks;
	int	j;
	int k;

	tab = ft_sort_int_tab(pile_a);
	n = 5;
	i = 0;
	k = 0;
	chunks = (int **)malloc(sizeof(int *) * n);
	while (i != n)
	{
		j = 0;
		chunks[i] = (int *)malloc(sizeof(int) * (pile_a->size_max /n));
		while (j != (pile_a->size_max /n))
		{
			chunks[i][j] = tab[k];
			j++;
			k++;
		}
		i++;
	}
	return (chunks);
}

int	ft_mediane(t_stack *pile_a)
{
	int	*tab;
	int	med;
	int	n;

	n = pile_a->size_max;
	tab = ft_sort_int_tab(pile_a);
	if ((n / 2) == 0)
		med = ((tab[(n /2) -1] + tab[((n /2) +1) -1]) /2);
	else
		med = tab[((n +1) /2) -1];
	return (med);
}