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

int	*ft_sort_int_tab2(t_stack *pile_a, int i, int j, int temp, int *tab)
{
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
	int		j;
	int		temp;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * pile_a->size_max);
	i = 0;
	while (i < pile_a->size_max)
	{
		tab[i] = pile_a->tableau[i];
		i++;
	}
	i = 0;
	tab = ft_sort_int_tab2(pile_a, i, j, temp, tab);
	return (tab);
}

t_stack *ft_sort_five(t_stack *pile_a, t_stack *pile_b)
{
	while ((pile_a->top_index != 2))
	{
		if (ft_min_int(pile_a) < (pile_a->size_max / 2))
			while ((pile_a->size_max - pile_a->top_index -1) != ft_min_int(pile_a))
				ft_reverse_rotate_a(pile_a);
		else
			while ((pile_a->size_max - pile_a->top_index -1) != ft_min_int(pile_a))
				ft_rotate_a(pile_a);
		ft_push_b(pile_a, pile_b);
	}
	ft_sort_three(pile_a);
	ft_push_a(pile_a, pile_b);
	ft_push_a(pile_a, pile_b);
}

t_stack *ft_push_med(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i != a->size_max)
	{
		if (a->tableau[(a->size_max - a->top_index -1)] < ft_mediane(a))
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
		i++;
	}
	return (a);
}

int check_top(t_stack *a, int *chunk)
{
	int	i;
	int	j;
	int	n;
	
	n = 5;
	i = (a->size_max - a->top_index -1);
	while (i != 0)
	{
		j = 0;
		while (j != a->size_max /n)
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

int	check_bottom(t_stack *a, int *chunk)
{
	int	i;
	int	j;
	int	n;
	
	n = 5;
	i = 0;
	while (i != (a->size_max - a->top_index -1))
	{
		j = 0;
		while (j != a->size_max /n)
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

t_stack	*ft_push_chunks(t_stack *a, t_stack *b)
{
	int	**chunks;
	int	i;
	int	n;
	int	topnbr;
	int bottomnbr;
	
	i = 0;
	n = 5;
	chunks = ft_split_tab(a);
	topnbr = check_top(a, chunks[i]);
	bottomnbr = check_bottom(a, chunks[i]);
	while (i != n)
	{
		while (check_top(a, chunks[i]) != -1)
		{
			if ((a->size_max - check_top(a, chunks[i])) < ((0 - check_bottom(a, chunks[i]) -1) *-1))
			{
				topnbr = check_top(a, chunks[i]);
				while ((a->size_max - a->top_index -1) != topnbr)
				{
					///ft_printf("%d %d\n", (a->size_max - a->top_index -1), check_top(a, chunks[i]));
					if (topnbr > a->size_max /2)
					{
						ft_rotate_a(a);
						topnbr++;
					}
					else
					{
						if (topnbr == 0)
						{
							ft_reverse_rotate_a(a);
							topnbr = a->size_max - a->top_index -1;
						}
						else
						{
							ft_reverse_rotate_a(a);
							topnbr--;
						}
					}
				}
				ft_push_b(a, b);
			}
			else
			{
				bottomnbr = check_bottom(a, chunks[i]);
				while ((a->size_max - a->top_index -1) != bottomnbr)
				{
					//ft_printf("%d %d\n", (a->size_max - a->top_index -1), check_top(a, chunks[i]));
					if (bottomnbr > a->size_max /2)
					{
						ft_rotate_a(a);
						bottomnbr++;
					}
					else
					{
						if (bottomnbr == 0)
						{
							ft_reverse_rotate_a(a);
							bottomnbr = a->size_max - a->top_index -1;
						}
						else
						{
							ft_reverse_rotate_a(a);
							bottomnbr--;
						}
					}
				}
				ft_push_b(a, b);
			}
		}
		i++;
	}
}

t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{
	int	k;
	int	j;
	k = 0;
	j = 0;
	ft_push_chunks(a, b);
	while (isEmpty(b) == -1)
	{
		if (b->tableau[(b->size_max - b->top_index -1)] == b->tableau[ft_max_int(b)])
			ft_push_a(a, b);
		else
			if (ft_max_int(b) < (b->size_max / 2))
				while ((b->size_max - b->top_index -1) != ft_max_int(b))
					ft_reverse_rotate_b(b);
			else
				while ((b->size_max - b->top_index -1) != ft_max_int(b))
					ft_rotate_b(b);
	}
}