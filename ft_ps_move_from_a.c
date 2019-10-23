/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_move_from_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:28:48 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:58:53 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

static int			roll_b(t_stack *st, int bb, int gh_med)
{
	int cntr;

	cntr = 0;
	if (st->lenb - bb == 0)
		return (0);
	if ((st->b)[st->lenb - 1] < gh_med)
		cntr++;
	return (cntr);
}

static int	mv_fr_a_cycle(t_stack *st, t_avlt *tr, t_conter *box)
{
	while ((box->len)-- > 0 && box->hlen)
	{
		if ((st->a)[st->lena - 1] <= box->med)
		{
			if (box->i)
				do_op(st, tr, "rb");
			(box->hlen)--;
			do_op(st, tr, "pb");
			if ((box->i = roll_b(st, box->bb, box->gh_med)) < 0)
				return (-1);
			st->min_bot_b += box->i;
		}
		else
		{
			box->ba > 0 ? (box->cntr)++ : 0;
			if (box->i)
			{
				do_op(st, tr, "rr");
				box->i = 0;
			}
			else
				do_op(st, tr, "ra");
		}
	}
	return (0);
}

int			move_from_a(t_stack *st, t_avlt *tr, int ba, int bb)
{
	t_conter	*box;

	if (!(box = (t_conter*)malloc(sizeof(t_conter))))
		exit(-1);
	box->i = 0;
	box->cntr = 0;
	box->ba = (ba > 0 ? (ba + st->min_bot_a) : st->min_bot_a);
	box->bb = bb;
	box->len = st->lena - box->ba;
	box->hlen = (st->lena - box->ba) / 2 + 1;
	if (create_check_med_a(st, box->ba, &(box->med)) < 0)
		return (-1);
	box->gh_med = find_ghost_med_a(st, box->ba, box->med);
	if (mv_fr_a_cycle(st, tr, box) < 0)
		return (-1);
	if (box->i)
	{
		do_op(st, tr, "rb");
		box->i = 0;
	}
	while ((box->cntr)-- > 0)
		do_op(st, tr, "rra");
	free(box);
	return (0);
}
