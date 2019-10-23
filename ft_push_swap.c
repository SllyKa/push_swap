/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:09:49 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 23:17:44 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

t_stack		*sort(t_stack *st, t_avlt **tr)
{
	if (!(*tr = init_ps_avlt()))
		return (NULL);
	if (ft_issorted(st->a, st->lena))
		return (st);
	if (st->lena == 1)
		return (st);
	else if (st->lena == 2)
		for_two(st, *tr);
	else if (st->lena == 3)
		for_three(st, *tr);
	else if (st->lena < 6)
		for_five(st, *tr);
	else
	{
		if (ft_ps_sort_stacka(st, *tr, 0, 0) < 0)
			return (NULL);
	}
	if (st->op_lst)
		print_lst(st->op_lst);
	return (st);
}

int			main(int argc, char **argv)
{
	t_stack		*st;
	t_avlt		*tr;

	st = NULL;
	tr = NULL;
	if (!(st = ft_ps_arg_check(argc, argv)))
		write(2, "Error\n", 6);
	else
		st = sort(st, &tr);
	free_stack(&st);
	free_avlt(tr);
	return (0);
}
