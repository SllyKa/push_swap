/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_extra_algs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:49:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 23:12:32 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_push_swap.h"

void		for_two(t_stack *st, t_avlt *tr)
{
	if ((st->a)[st->lena - 1] > (st->a)[st->lena - 2])
		do_op(st, tr, "sa");
}

void		for_three(t_stack *st, t_avlt *tr)
{
	if (ft_issorted(st->a, st->lena))
		return ;
	if ((st->a)[st->lena - 1] > (st->a)[st->lena - 2])
	{
		if ((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
		{
			do_op(st, tr, "sa");
			do_op(st, tr, "rra");
		}
		else if ((st->a)[st->lena - 1] > (st->a)[st->lena - 3])
			do_op(st, tr, "ra");
		else
			do_op(st, tr, "sa");
	}
	else if ((st->a)[st->lena - 3] > (st->a)[st->lena - 1] &&
	(st->a)[st->lena - 2] > (st->a)[st->lena - 3])
	{
		do_op(st, tr, "sa");
		do_op(st, tr, "ra");
	}
	else if (((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
			&& ((st->a)[st->lena - 2] > (st->a)[st->lena - 1]))
		do_op(st, tr, "rra");
}

static void	find_mx_mn(t_stack *st, int *max, int *min)
{
	int i;

	i = 0;
	*max = (st->a)[0];
	*min = *max;
	while (i < st->lena)
	{
		*min = (*min > (st->a)[i] ? (st->a)[i] : *min);
		*max = (*max < (st->a)[i] ? (st->a)[i] : *max);
		i++;
	}
}

void		for_five(t_stack *st, t_avlt *tr)
{
	int		max;
	int		min;

	if (ft_issorted(st->a, st->lena))
		return ;
	find_mx_mn(st, &max, &min);
	while (st->lenb < 2)
	{
		if (((st->a)[st->lena - 1] == max) ||
		((st->a)[st->lena - 1] == min))
			do_op(st, tr, "pb");
		else
			do_op(st, tr, "ra");
	}
	if (st->lena == 3)
		for_three(st, tr);
	else if (st->lena == 2)
		for_two(st, tr);
	if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
		do_op(st, tr, "sb");
	do_op(st, tr, "pa");
	do_op(st, tr, "ra");
	do_op(st, tr, "pa");
}
