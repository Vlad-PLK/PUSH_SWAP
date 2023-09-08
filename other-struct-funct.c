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
#include "libft/libft.h"
#include "ft_push_swap.h"

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
