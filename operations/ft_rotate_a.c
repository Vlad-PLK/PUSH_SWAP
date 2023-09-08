/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:04:20 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:05:24 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_rotate_a(t_stack *a)
{
	int	temp;
	int	v_haut;

	v_haut = (a->size_max) - (a->top_index) - 1;
	if (is_empty(a) == -1)
	{	
		while (v_haut != 0)
		{
			temp = a->tableau[v_haut];
			a->tableau[v_haut] = a->tableau[v_haut -1];
			a->tableau[v_haut -1] = temp;
			v_haut--;
		}
		ft_printf("ra\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
