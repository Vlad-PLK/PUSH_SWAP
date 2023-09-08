/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:04:23 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:05:26 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_rotate_b(t_stack *b)
{
	int	temp;
	int	v_hautb;

	v_hautb = ((b->size_max) - (b->top_index) - 1);
	if (is_empty(b) == -1)
	{	
		while (v_hautb != 0)
		{
			temp = b->tableau[v_hautb];
			b->tableau[v_hautb] = b->tableau[v_hautb - 1];
			b->tableau[v_hautb -1] = temp;
			v_hautb--;
		}
		ft_printf("rb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
