/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_err_chk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:14:47 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/22 23:49:38 by gbrandon         ###   ########.fr       */
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
