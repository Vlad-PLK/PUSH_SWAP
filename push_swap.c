/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:49 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/08 19:35:23 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"

t_stack	*create_stack_tab(t_stack *pile_a, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	pile_a = create_stack(argc -1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error : non-digit arguments are forbidden\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		pile_a->top_index--;
		pile_a->tableau[pile_a->top_index] = ft_atoi(argv[i]);
		i++;
	}
	return (pile_a);
}

t_stack	*create_stack_tab_split(t_stack *a, int argc, char **arg_list)
{
	int	i;
	int	j;

	i = 0;
	a = create_stack(argc);
	while (i < argc)
	{
		j = 0;
		while (arg_list[i][j] != '\0')
		{
			if (ft_isdigit(arg_list[i][j]) == 0)
			{
				ft_printf("Error : non-digit arguments are forbidden\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		a->top_index--;
		a->tableau[a->top_index] = ft_atoi(arg_list[i]);
		i++;
	}
	return (a);
}

t_stack	*ft_split_arg(char *arg, t_stack *a)
{
	char	**arg_list;
	int		i;
	int		argc;

	argc = 0;
	i = 0;
	arg_list = ft_split(arg, 32);
	while (arg_list[argc] != 0)
		argc++;
	a = create_stack_tab_split(a, argc, arg_list);
	while (i != argc)
	{
		free(arg_list[i]);
		i++;
	}
	free(arg_list);
	return (a);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	pile_a = NULL;
	if (!((argc - 1) == 1) || ((argc -1) == 1 && ft_strlen(argv[1]) == 1))
		pile_a = create_stack_tab(pile_a, argc, argv);
	else
		pile_a = ft_split_arg(argv[1], pile_a);
	ft_check_errors(pile_a);
	pile_b = create_stack(pile_a->size_max);
	if (ft_check_ascending(pile_a) == -1)
	{
		if (pile_a->size_max == 3)
			ft_sort_three(pile_a);
		if (pile_a->size_max == 5)
			ft_sort_five(pile_a, pile_b);
		if (pile_a->size_max > 5 && pile_a->size_max < 500)
			ft_sort_big(pile_a, pile_b, 5);
		if (pile_a->size_max >= 500)
			ft_sort_big(pile_a, pile_b, 10);
	}
	ft_free_stacks(pile_a, pile_b);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Nothing to sort\n");
	else
		push_swap(argc, argv);
}
