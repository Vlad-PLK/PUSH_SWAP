/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope-part2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:45:11 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/06 18:53:32 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
void	ft_rotate_a(t_stack *a)
{
	int	temp;
	int	v_haut;

	v_haut = (a->size_max) - (a->top_index) -1;

	if (isEmpty(a) == -1)
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

void	ft_rotate_b(t_stack *b)
{
	int	temp;
    int v_hautB;

	v_hautB = ((b->size_max) - (b->top_index) -1);

	if (isEmpty(b) == -1)
	{	
		while (v_hautB != 0)  
		{
			temp = b->tableau[v_hautB];
			b->tableau[v_hautB] = b->tableau[v_hautB -1];
			b->tableau[v_hautB -1] = temp;
			v_hautB--;
		}
		ft_printf("rb\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if ((isEmpty(a) == -1 && isEmpty(b) == -1))
	{
		ft_rotate_a(a);
		ft_rotate_b(b);
		ft_printf("rr\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_reverse_rotate_a(t_stack *a)
{
	int	temp;
	int v_haut;
	int v_bas;

	v_haut = ((a->size_max) - (a->top_index) -1);
	v_bas = 0;

	if (isEmpty(a) == -1)
	{
		while (v_bas != v_haut)
		{
			temp = a->tableau[v_bas];
			a->tableau[v_bas] = a->tableau[v_bas +1];
			a->tableau[v_bas +1] = temp;
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

void	ft_reverse_rotate_b(t_stack *b)
{
	int	temp;
	int v_haut;
	int v_bas;

	v_haut = ((b->size_max) - (b->top_index) -1);
	v_bas = 0;
	
	if (isEmpty(b) == -1)
	{
		while (v_bas != v_haut)
		{
			temp = b->tableau[v_bas];
			b->tableau[v_bas] = b->tableau[v_bas +1];
			b->tableau[v_bas +1] = temp;
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
