/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_move_from_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:56:00 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 21:27:47 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

static int	roll_a(t_stack *st, int ba, int gh_med)
{
	int cntr;

	cntr = 0;
	if (st->lena - ba == 0)
		return (0);
	if ((st->a)[st->lena - 1] < gh_med)
		cntr++;
	return (cntr);
}

static int	mv_fr_b_md_cycle(t_stack *st, t_avlt *tr, t_conter *box)
{
	while ((box->len)-- > 0 && (box->hlen))
	{
		if ((st->b)[st->lenb - 1] >= box->med)
		{
			if (box->i)
				do_op(st, tr, "ra");
			(box->hlen)--;
			do_op(st, tr, "pa");
			if ((box->i = roll_a(st, box->ba, box->gh_med)) < 0)
				return (-1);
			st->min_bot_a += box->i;
		}
		else
		{
			box->bb > 0 ? (box->cntr)++ : 0;
			if (box->i)
			{
				do_op(st, tr, "rr");
				box->i = 0;
			}
			else
				do_op(st, tr, "rb");
		}
	}
	return (0);
}

int			move_from_b_med(t_stack *st, t_avlt *tr, int ba, int bb)
{
	t_conter	*box;

	if (!(box = (t_conter*)malloc(sizeof(t_conter))))
		exit(-1);
	box->i = 0;
	box->cntr = 0;
	box->bb = (bb > 0 ? (bb + st->min_bot_b) : st->min_bot_b);
	box->ba = ba;
	box->len = st->lenb - box->bb;
	box->hlen = (st->lenb - box->bb) / 2 + 1;
	if (create_check_med_b(st, box->bb, &(box->med)) < 0)
		return (-1);
	box->gh_med = find_ghost_med_b(st, box->bb, box->med);
	if (mv_fr_b_md_cycle(st, tr, box) < 0)
		return (-1);
	if (box->i)
	{
		do_op(st, tr, "ra");
		box->i = 0;
	}
	while ((box->cntr)-- > 0)
		do_op(st, tr, "rrb");
	free(box);
	return (0);
}
