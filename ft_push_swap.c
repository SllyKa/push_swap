/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:09:49 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/24 16:09:41 by gbrandon         ###   ########.fr       */
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
	if (st->op_lst && ((st->flags & 1) != 1))
		print_lst(st->op_lst, 0, st);
	return (st);
}

int			main(int argc, char **argv)
{
	t_stack		*st;
	t_avlt		*tr;
	char		*fname;
	int			flags;

	fname = NULL;
	st = NULL;
	tr = NULL;
	if ((flags = check_flags(argc, argv, &fname)) > 0)
		set_argv_argc(&argc, &argv, &flags, fname);
	if (!(st = ft_ps_arg_check(argc, argv)))
		write(2, "Error\n", 6);
	else
	{
		st->flags = flags;
		st = sort(st, &tr);
	}
	free_stack(&st);
	free_avlt(tr);
	return (0);
}
