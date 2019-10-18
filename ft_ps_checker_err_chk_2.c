/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_err_chk_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:52:11 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/18 15:47:16 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "ft_ps_checker.h"

static t_stack		*fill_stck(t_stack *st, int argc, char **argv)
{
	char	**tab_temp;
	char	**tab;
	int		er_code;

	er_code = 0;
	while (argc-- > 1)
	{
		if (!(tab = ft_strsplit(argv[argc], ' ')))
			return (NULL);
		tab_temp = tab;
		while (*tab)
			tab++;
		while (tab != tab_temp)
		{
			tab--;
			(st->a)[st->lena] = ft_satoi(*tab, &er_code);
			if (echk_atoi(er_code, st) < 0)
				return (NULL);
			(st->lena)++;
		}
		free_tab(tab);
	}
	return (st);
}

static int			num_size(int argc, char **argv)
{
	char	**tab_temp;
	char	**tab;
	int		i;

	i = 0;
	while (argc-- > 1)
	{
		if (!(tab = ft_strsplit(argv[argc], ' ')))
			return (-1);
		tab_temp = tab;
		while (*tab_temp)
		{
			i++;
			tab_temp++;
		}
		free_tab(tab);
	}
	return (i);
}

t_stack		*ps_chk_arg_init(int argc)
{
	t_stack *stack;

	if (argc <= 1)
		return (NULL);
	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		exit(-1);
	if (!(stack->a = (int*)malloc(sizeof(int) * argc)))
		exit(-1);
	if (!(stack->b = (int*)malloc(sizeof(int) * argc)))
		exit(-1);
	stack->op_lst = NULL;
	stack->lena = 0;
	stack->lenb = 0;
	stack->min_bot_b = 0;
	return (stack);
}

t_stack				*ft_ps_arg_check(int argc, char **argv)
{
	t_stack		*stack;
	int			nms;

	if ((nms = num_size(argc, argv)) < 0)
		return (NULL);
	if (!(stack = ps_chk_arg_init(nms)))
		return (NULL);
	if (!(stack = fill_stck(stack, argc, argv)))
		return (NULL);
	if (echk_duplicate(stack, stack->lena) < 0)
		return (NULL);
	return (stack);
}
