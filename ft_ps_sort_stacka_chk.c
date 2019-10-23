/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacka_chk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:43:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:02:51 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int		check_for_three(t_stack *st, t_avlt *tr, int *ba)
{
	if ((st->lena - *ba - st->min_bot_a) == 3)
	{
		if (!ft_issorted(&(st->a)[*ba + st->min_bot_a],
		st->lena - *ba - st->min_bot_a))
			basic_sort(st, tr);
		*ba += 3;
		if (st->min_bot_a > 0)
		{
			if (st->lenb > 1 && (st->b[st->lenb - 1] > (st->a)[0]
			|| (st->b)[0] > (st->a)[0]))
				return (1);
		}
	}
	return (0);
}

int		check_for_two(t_stack *st, t_avlt *tr, int *ba)
{
	if ((st->lena - *ba - st->min_bot_a) == 2)
	{
		if (!ft_issorted(&(st->a)[*ba + st->min_bot_a],
		st->lena - *ba - st->min_bot_a))
		{
			if (st->lenb > 1 && (st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
		}
		*ba += 2;
		if (st->min_bot_a > 0)
		{
			if (st->lenb > 1 && (st->b[st->lenb - 1]
			> (st->a)[0] || (st->b)[0] > (st->a)[0]))
				return (1);
		}
	}
	return (0);
}

int		check_for_one(t_stack *st, int *ba)
{
	if ((st->lena - *ba - st->min_bot_a) == 1)
	{
		(*ba)++;
		if (st->min_bot_a > 0)
		{
			if (st->lenb > 1 && (st->b[st->lenb - 1]
			> (st->a)[0] || (st->b)[0] > (st->a)[0]))
				return (1);
		}
	}
	return (0);
}

int		create_check_med_a(t_stack *st, int ba, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->a[ba], st->lena - ba, &er);
	if (er < 0)
		return (-1);
	return (0);
}
