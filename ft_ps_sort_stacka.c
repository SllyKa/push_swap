/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacka.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:17:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:59:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int				find_ghost_med_a(t_stack *st, int ba, int med)
{
	t_stack	*tp;
	int		i;
	int		len;

	if (!(tp = ps_chk_arg_init((st->lena - ba) / 2 + 2)))
		exit(-1);
	i = 0;
	len = st->lena - ba;
	while (len-- > 0)
	{
		if ((st->a)[st->lena - i - 1] <= med)
		{
			(tp->a)[tp->lena++] = (st->a)[st->lena - i - 1];
		}
		i++;
	}
	create_check_med_a(tp, 0, &med);
	free_stack(&tp);
	return (med);
}

static void		return_bot_a(t_stack *st, t_avlt *tr)
{
	while (st->min_bot_a > 0)
	{
		do_op(st, tr, "rra");
		(st->min_bot_a)--;
	}
}

static int		ft_ps_srta_chk(t_stack *st, t_avlt *tr, int *ba, int *bb)
{
	if ((st->lena - *ba) == 0)
		return (0);
	else if (check_for_one(st, ba))
		return (0);
	else if (check_for_two(st, tr, ba))
		return (0);
	else if (check_for_three(st, tr, ba))
		return (0);
	else
	{
		*bb = st->lenb;
		if (st->min_bot_a > 0 && st->lena - *ba == st->min_bot_a)
			return_bot_a(st, tr);
		if (st->lena - *ba > 3)
		{
			if (move_from_a(st, tr, *ba, *bb) < 0)
				return (-1);
		}
	}
	return (1);
}

static int		ft_ps_srt_stka_just_cut(t_stack *st, int *min_bot_b)
{
	if (st->lenb > 1 && (st->b[st->lenb - 1] > (st->a)[0]
	|| (st->b)[0] > (st->a)[0]))
		return (0);
	*min_bot_b = st->min_bot_b;
	st->min_bot_b = 0;
	return (1);
}

int				ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		min_bot_a;
	int		min_bot_b;

	if (!(ft_ps_srta_chk(st, tr, &ba, &bb)))
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
		if (!(ft_ps_srt_stka_just_cut(st, &min_bot_b)))
			return (0);
		if (ft_ps_sort_stacka(st, tr, st->lena - st->min_bot_a, bb) < 0)
			return (-1);
		st->min_bot_b = min_bot_b;
		st->min_bot_a = 0;
	}
	return (0);
}
