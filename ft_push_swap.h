/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:02:39 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/10 12:06:12 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	size_max;
	int	top_index;
	int	*tableau;
}t_stack;

t_stack *createStack(int size);
int 	size(t_stack *stack);
int		isEmpty(t_stack *stack);
int 	isFull(t_stack *stack);
int 	peek(t_stack *stack);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_swap_a(t_stack *a);
void	ft_swap_b(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_push_b(t_stack *a, t_stack *b);
void	ft_rotate_a(t_stack *a);
void	ft_rotate_b(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_reverse_rotate_b(t_stack *b);
int 	two_spot(t_stack *stack);
int		find_occur(t_stack *a);
int		ft_max_int(t_stack *pile_a);
t_stack	*ft_sort_three(t_stack *pile_a);
t_stack *ft_sort_five(t_stack *pile_a, t_stack *pile_b);
int	ft_check_ascending(t_stack *pile_a);
int	ft_min_int(t_stack *pile_a);

#endif
