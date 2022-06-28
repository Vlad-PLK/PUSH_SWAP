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
t_stack	*createStack_tab(t_stack *pile_a, int argc, char **argv);
t_stack	*createStack_tab_split(t_stack *a, int argc, char **arg_list);
t_stack	*ft_split_arg(char *arg, t_stack *a, t_stack *b);
void	ft_display_tab(t_stack *pile);
int		isEmpty(t_stack *stack);
int 	isFull(t_stack *stack);
void	ft_swap_a(t_stack *a);
void	ft_swap_b(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_push_b(t_stack *a, t_stack *b);
void	ft_rotate_a(t_stack *a);
void	ft_rotate_b(t_stack *b);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_reverse_rotate_b(t_stack *b);
int 	two_spot(t_stack *stack);
int		find_occur(t_stack *a);
int		ft_max_int(t_stack *pile_a);
t_stack	*ft_sort_three(t_stack *pile_a);
t_stack *ft_sort_five(t_stack *pile_a, t_stack *pile_b);
t_stack	*ft_sort_big(t_stack *a, t_stack *b);
int	ft_check_ascending(t_stack *pile_a);
void	ft_checkErrors(t_stack *pile_a);
int	ft_min_int(t_stack *pile_a);
int	ft_mediane(t_stack *pile_a);
int	*ft_sort_int_tab(t_stack *pile_a);
int	**ft_split_tab(t_stack *pile_a);
int check_top(t_stack *a, int *chunk);
void	push_swap(int argc, char **argv);

#endif
