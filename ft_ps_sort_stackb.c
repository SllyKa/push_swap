/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stackb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:19:37 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 21:00:58 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int				find_ghost_med_b(t_stack *st, int bb, int med)
{
	t_stack	*tp;
	int		i;
	int		len;

	if (!(tp = ps_chk_arg_init((st->lenb - bb) / 2 + 2)))
		exit(-1);
	i = 0;
	len = st->lenb - bb;
	while (len-- > 0)
	{
		if ((st->b)[st->lenb - i - 1] >= med)
		{
			(tp->b)[tp->lenb++] = (st->b)[st->lenb - i - 1];
		}
		i++;
	}
	create_check_med_b(tp, 0, &med);
	free_stack(&tp);
	return (med);
}

static void		return_bot_b(t_stack *st, t_avlt *tr)
{
	while (st->min_bot_b > 0)
	{
		do_op(st, tr, "rrb");
		(st->min_bot_b)--;
	}
}

static int		ft_ps_srtb_chk(t_stack *st, t_avlt *tr, int *ba, int bb)
{
	*ba = st->lena;
	if (st->min_bot_b > 0 && st->lenb - bb == st->min_bot_b)
		return_bot_b(st, tr);
	if (st->lenb - bb == 0)
		return (0);
	else if (st->lenb - bb - st->min_bot_b == 1)
		do_op(st, tr, "pa");
	else if (check_for_two_b(st, tr, bb))
		;
	else if (check_for_three_b(st, tr, bb))
		;
	else
		move_from_b_med(st, tr, *ba, bb);
	return (1);
}

int				ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		min_bot_a;
	int		min_bot_b;

	if (!ft_ps_srtb_chk(st, tr, &ba, bb))
		return (0);
	min_bot_b = st->min_bot_b;
	st->min_bot_b = 0;
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	st->min_bot_b = min_bot_b;
	min_bot_a = st->min_bot_a;
	st->min_bot_a = 0;
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
		return (-1);
	st->min_bot_a = min_bot_a;
	if (st->min_bot_a > 0)
	{
		min_bot_b = st->min_bot_b;
		st->min_bot_b = 0;
		if (ft_ps_sort_stacka(st, tr, st->lena - st->min_bot_a, bb) < 0)
			return (-1);
		st->min_bot_b = min_bot_b;
		st->min_bot_a = 0;
	}
	return (0);
}
