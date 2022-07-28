/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other-struct-funct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:45:39 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/04 12:20:08 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "ft_push_swap.h"

int	is_empty(t_stack *stack)
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

int	is_full(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	else
		return (-1);
}

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

int	**ft_split_tab(t_stack *pile_a, int nb_chunks)
{
	int	*tab;
	int	i;
	int	**chunks;
	int	j;
	int	k;

	tab = ft_sort_int_tab(pile_a);
	i = 0;
	k = 0;
	chunks = (int **)malloc(sizeof(int *) * nb_chunks);
	while (i != nb_chunks)
	{
		j = 0;
		chunks[i] = (int *)malloc(sizeof(int) * (pile_a->size_max / nb_chunks));
		while (j != (pile_a->size_max / nb_chunks))
		{
			chunks[i][j] = tab[k];
			j++;
			k++;
		}
		i++;
	}
	free(tab);
	return (chunks);
}
