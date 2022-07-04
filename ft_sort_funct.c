/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:52:04 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/04 12:37:32 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

int	check_chunk(t_stack *a, int *chunk, int nb_chunks)
{
	int	i;
	int	j;

	i = (a->size_max - a->top_index -1);
	while (i != 0)
	{
		j = 0;
		while (j < (a->size_max) / nb_chunks)
		{
			if (a->tableau[i] == chunk[j])
				return (1);
			else
				j++;
		}
		i--;
	}
	check_chunk2(a, chunk, nb_chunks);
	return (-1);
}

t_stack	*ft_push_top(t_stack *a, int nb_chunks, int topnbr, int *chunk)
{
	topnbr = check_top(a, chunk, nb_chunks);
	while ((a->size_max - a->top_index -1) != (topnbr))
	{
		if ((topnbr) > (a->size_max - a->top_index - 1) / 2)
		{
			ft_rotate_a(a);
			(topnbr)++;
		}
		else
		{
			if ((topnbr) == 0)
			{
				ft_reverse_rotate_a(a);
				(topnbr) = a->size_max - a->top_index -1;
			}
			else
			{
				ft_reverse_rotate_a(a);
				(topnbr)--;
			}
		}
	}
	return (a);
}

t_stack	*ft_push_bottom(t_stack *a, int nb_chunks, int bottomnbr, int *chunk)
{
	bottomnbr = check_bottom(a, chunk, nb_chunks);
	while ((a->size_max - a->top_index - 1) != (bottomnbr))
	{
		if ((bottomnbr) > (a->size_max - a->top_index - 1) / 2)
		{
			ft_rotate_a(a);
			(bottomnbr)++;
		}
		else
		{
			if ((bottomnbr) == 0)
			{
				ft_reverse_rotate_a(a);
				(bottomnbr) = a->size_max - a->top_index -1;
			}
			else
			{
				ft_reverse_rotate_a(a);
				(bottomnbr)--;
			}
		}
	}
	return (a);
}

void	ft_push_chunks(t_stack *a, t_stack *b, int nb_chunks)
{
	int	**chunks;
	int	i;
	int	topnbr;
	int	bottomnbr;

	i = 0;
	chunks = ft_split_tab(a, nb_chunks);
	topnbr = check_top(a, chunks[i], nb_chunks);
	bottomnbr = check_bottom(a, chunks[i], nb_chunks);
	while (i != nb_chunks)
	{
		while (check_chunk(a, chunks[i], nb_chunks) == 1)
		{
			if ((a->size_max - check_top(a, chunks[i], nb_chunks))
				< ((0 - check_bottom(a, chunks[i], nb_chunks) - 1) * (-1)))
				a = ft_push_top(a, nb_chunks, topnbr, chunks[i]);
			else
				a = ft_push_bottom(a, nb_chunks, bottomnbr, chunks[i]);
			ft_push_b(a, b);
		}
		i++;
	}
	while (isEmpty(a) == -1)
		ft_push_b(a, b);
}

t_stack	*ft_sort_big(t_stack *a, t_stack *b, int nb_chunks)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	ft_push_chunks(a, b, nb_chunks);
	while (isEmpty(b) == -1)
	{
		if (b->tableau[(b->size_max - b->top_index - 1)]
			== b->tableau[ft_max_int(b)])
			ft_push_a(a, b);
		else
		{
			if (ft_max_int(b) < ((b->size_max - b->top_index -1) / 2))
				while ((b->size_max - b->top_index -1) != ft_max_int(b))
					ft_reverse_rotate_b(b);
			else
				while ((b->size_max - b->top_index -1) != ft_max_int(b))
					ft_rotate_b(b);
		}
	}
	return (a);
}
