/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:04:25 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:05:56 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_reverse_rotate_a(t_stack *a)
{
	int	temp;
	int	v_haut;
	int	v_bas;

	v_haut = ((a->size_max) - (a->top_index) - 1);
	v_bas = 0;
	if (is_empty(a) == -1)
	{
		while (v_bas != v_haut)
		{
			temp = a->tableau[v_bas];
			a->tableau[v_bas] = a->tableau[v_bas + 1];
			a->tableau[v_bas + 1] = temp;
			v_bas++;
		}
		ft_printf("rra\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}