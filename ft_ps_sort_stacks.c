/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:16:24 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 18:59:11 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

void		do_op(t_stack *st, t_avlt *tr, char *cmd)
{
	void	(*op)(t_stack *);

	op = srch_avlt(tr, cmd);
	op(st);
	ft_printf("%s\n", cmd);
}

static void		basic_sort(t_stack *st, t_avlt *tr)
{
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
	else
	{
		if ((st->a)[st->lena - 3] > (st->a)[st->lena - 1])
		{
			do_op(st, tr, "sa");
			do_op(st, tr, "ra");
		}
		else
			do_op(st, tr, "rra");
	}
}

int		check_for_three(t_stack *st, t_avlt *tr)
{
	if (st->lena == 3)
	{
		if (!ft_issorted(st->a, st->lena))
			basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int		check_for_two(t_stack *st, t_avlt *tr)
{
	if (st->lena == 2)
	{
		if (!ft_issorted(st->a, st->lena))
			do_op(st, tr, "sa");
		return (1);
	}
	return (0);
}

int				ft_ps_sort_stacks(t_stack *st, t_avlt *tr)
{
	int		len;
	int		med;
	int		er;
	int		hlen;

	int		i;
	int		cntr;

	if (st->lena == 1)
		return (0);
	if (check_for_two(st, tr))
		return (0);
	if (check_for_three(st, tr))
		return (0);
	len = st->lena;
	med = ft_quicksel_medi(st, &er);
	if (er < 0)
		return (-1);
	if (er < 0)
		return (-1);
	hlen = len;
	while (len > 0)
	{
		if ((st->a)[st->lena - 1] <= med)
			do_op(st, tr, "pb");
		else
			do_op(st, tr, "ra");
		len--;
	}
	len = hlen;
	if (ft_ps_sort_stacks(st, tr) < 0)
		return (-1);
	len = ((len % 2 == 0) ? (len / 2) : (len / 2 + 1));
	i = 0;
	cntr = 0;
	while (i < len)
	{
		if ((st->b)[st->lenb - 1] < (st->a)[st->lena - 1])
		{
			do_op(st, tr, "pa");
			while (cntr > 0)
			{
				cntr--;
				do_op(st, tr, "rra");
			}
		}
		else
		{
			do_op(st, tr, "ra");
			cntr++;
			continue;
		}
		i++;
	}
	return (0);
}