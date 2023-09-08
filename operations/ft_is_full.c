/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:40:15 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:41:02 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

int	is_full(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	else
		return (-1);
}
