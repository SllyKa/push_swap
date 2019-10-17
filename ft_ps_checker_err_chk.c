/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_err_chk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:14:47 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/16 13:12:08 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "ft_ps_checker.h"

int		echk_atoi(int er_code, t_stack *stack)
{
	if (er_code < 0)
	{
		free_stack(&stack);
		return (-1);
	}
	return (0);
}

int		echk_duplicate(t_stack *stack, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if ((stack->a)[i] == (stack->a)[j])
			{
				free_stack(&stack);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static t_stack		*ps_chk_arg_init(int *i, int *er_code, int argc)
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
	*i = 0;
	stack->lena = 0;
	stack->lenb = 0;
	*er_code = 0;
	return (stack);
}

t_stack				*ft_ps_arg_check(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	int			er_code;

	if (!(stack = ps_chk_arg_init(&i, &er_code, argc)))
		return (NULL);
	while (i < argc - 1)
	{
		(stack->a)[i] = ft_satoi(argv[argc - i - 1], &er_code);
		if (echk_atoi(er_code, stack) < 0)
			return (NULL);
		i++;
	}
	if (echk_duplicate(stack, i) < 0)
		return (NULL);
	stack->lena = i;
	return (stack);
}