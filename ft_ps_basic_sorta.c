/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_basic_sorta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:47:32 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:07:06 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

static int		check_sort_b(t_stack *st)
{
	if (st->lenb < 3)
		return (-1);
	if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
	{
		if ((st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
			return (2);
		else if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 3])
			return (3);
		else
			return (1);
	}
	else if (((st->b)[st->lenb - 3] < (st->b)[st->lenb - 1])
			&& (st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
		return (4);
	else if (((st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
			&& ((st->b)[st->lenb - 2] > (st->b)[st->lenb - 1]))
		return (5);
	return (0);
}

void			basic_sort(t_stack *st, t_avlt *tr)
{
	int		sb;

	sb = check_sort_b(st);
	if ((st->a)[st->lena - 1] > (st->a)[st->lena - 2])
	{
		if ((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
			bsrt_case2(st, tr, sb);
		else if ((st->a)[st->lena - 1] > (st->a)[st->lena - 3])
			bsrt_case4(st, tr, sb);
		else
			bsrt_case3(st, tr, sb);
	}
	else if ((st->a)[st->lena - 3] > (st->a)[st->lena - 1] &&
			(st->a)[st->lena - 2] > (st->a)[st->lena - 3])
		bsrt_case5(st, tr, sb);
	else if (((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
			&& ((st->a)[st->lena - 2] > (st->a)[st->lena - 1]))
		bsrt_case1(st, tr, sb);
	if (sb == 5)
		do_op(st, tr, "sb");
}
