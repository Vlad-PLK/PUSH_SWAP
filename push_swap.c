/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:49 by vpolojie          #+#    #+#             */
/*   Updated: 2022/06/10 12:07:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_push_swap.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

t_stack *createStack(int size)
{
	t_stack *stack = (t_stack*)malloc(sizeof(t_stack));

	stack->size_max = size;
	stack->top_index = size;
	stack->tableau = (int *)malloc(sizeof(int) * size);

	return (stack);
}

t_stack	*createStack_tab(t_stack *pile_a, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	pile_a = createStack(argc -1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error\n");
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

t_stack	*createStack_tab_split(t_stack *a, int argc, char **arg_list)
{
	int	i;
	int	j;

	i = 0;
	a = createStack(argc);

	while (i < argc)
	{
		j = 0;
		while (arg_list[i][j] != '\0')
		{
			if (ft_isdigit(arg_list[i][j]) == 0)
			{
				ft_printf("Error\n");
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

t_stack	*ft_split_arg(char *arg, t_stack *a, t_stack *b)
{
	char **arg_list;
	int		i;
	int		argc;

	argc = 0;
	i = 0;
	arg_list = ft_split(arg, 32);

	while (arg_list[argc] != 0)
		argc++;
	a = createStack_tab_split(a, argc, arg_list);
	return (a);
}

void	push_swap(int argc, char **argv)
{
	t_stack *pile_a;
	t_stack *pile_b;
	int		i;

	i = 1;
	if (argc == 1)
		return ;
	if ((argc - 1) == 1)
		pile_a = ft_split_arg(argv[1], pile_a, pile_b);
	else
		pile_a = createStack_tab(pile_a, argc, argv);
	ft_checkErrors(pile_a);
	pile_b = createStack(pile_a->size_max);
	if (ft_check_ascending(pile_a) == 0)
		return ;
	else
		if (pile_a->size_max == 3)
			ft_sort_three(pile_a);
		if (pile_a->size_max == 5)
			ft_sort_five(pile_a, pile_b);
		if (pile_a->size_max > 5)
		{
			ft_sort_big(pile_a, pile_b);
			//ft_display_tab(pile_a);
		}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
