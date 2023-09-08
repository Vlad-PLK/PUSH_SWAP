/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:04:28 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:05:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_reverse_rotate_b(t_stack *b)
{
	int	temp;
	int	v_haut;
	int	v_bas;

	v_haut = ((b->size_max) - (b->top_index) - 1);
	v_bas = 0;
	if (is_empty(b) == -1)
	{
		while (v_bas != v_haut)
		{
			temp = b->tableau[v_bas];
			b->tableau[v_bas] = b->tableau[v_bas + 1];
			b->tableau[v_bas + 1] = temp;
			v_bas++;
		}
		ft_printf("rrb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
