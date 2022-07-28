/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:02:39 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/28 20:25:10 by vpolojie         ###   ########.fr       */
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

t_stack	*create_stack(int size);
t_stack	*create_stack_tab(t_stack *pile_a, int argc, char **argv);
t_stack	*create_stack_tab_split(t_stack *a, int argc, char **arg_list);
t_stack	*ft_split_arg(char *arg, t_stack *a);
void	ft_display_tab(t_stack *pile);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
void	ft_swap_a(t_stack *a);
void	ft_swap_b(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_push_b(t_stack *a, t_stack *b);
void	ft_rotate_a(t_stack *a);
void	ft_rotate_b(t_stack *b);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_reverse_rotate_b(t_stack *b);
int		two_spot(t_stack *stack);
int		find_occur(t_stack *a);
int		ft_max_int(t_stack *pile_a);
t_stack	*ft_sort_three(t_stack *pile_a);
void	ft_sort_five(t_stack *pile_a, t_stack *pile_b);
t_stack	*ft_sort_big(t_stack *a, t_stack *b, int nb_chunks);
int		ft_check_ascending(t_stack *pile_a);
void	ft_check_errors(t_stack *pile_a);
int		ft_min_int(t_stack *pile_a);
int		ft_mediane(t_stack *pile_a);
int		*ft_sort_int_tab(t_stack *pile_a);
int		*ft_sort_int_tab2(t_stack *pile_a, int temp, int *tab);
int		**ft_split_tab(t_stack *pile_a, int nb_chunks);
int		check_top(t_stack *a, int *chunk, int nb_chunks);
int		check_bottom(t_stack *a, int *chunk, int nb_chunks);
void	push_swap(int argc, char **argv);
int		check_chunk(t_stack *a, int *chunk, int nb_chunks);
int		check_chunk2(t_stack *a, int *chunk, int nb_chunks);
t_stack	*ft_push_top(t_stack *a, int nb_chunks, int topnbr, int *chunk);
t_stack	*ft_push_bottom(t_stack *a, int nb_chunks, int bottomnbr, int *chunk);
void	ft_push_chunks(t_stack *a, t_stack *b, int nb_chunks);
void	ft_free_chunks(int **chunks, int nb_chunks, t_stack *a, t_stack *b);
void	ft_free_stacks(t_stack *a, t_stack *b);

#endif
