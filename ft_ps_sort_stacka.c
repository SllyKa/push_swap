/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacka.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:17:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/19 12:10:17 by gbrandon         ###   ########.fr       */
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
		{
			return (2);
		}
		else if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 3])
		{
			return (3);
		}
		else
		{
			return (1);
		}
	}
	else if (((st->b)[st->lenb - 3] < (st->b)[st->lenb - 1])
			&& (st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
		return (4);
	else if (((st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
			&& ((st->b)[st->lenb - 2] > (st->b)[st->lenb - 1]))
		return (5);
	return (0);
}

void		basic_sort(t_stack *st, t_avlt *tr)
{
	int		sb;

	//ft_ps_print_stcks(st);
	sb = check_sort_b(st);
	//sb = -1;
	if ((st->a)[st->lena - 1] > (st->a)[st->lena - 2])
	{
		if ((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
		{

			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
			if (sb > 1)
				do_gen_dbl_ops(st, tr);
			else
				do_gen_ops(st, tr);
			do_op(st, tr, "sa");
		}
		else if ((st->a)[st->lena - 1] > (st->a)[st->lena - 3])
		{
			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
			if (sb > 1)
				do_gen_dbl_ops(st, tr);
			else
				do_gen_ops(st, tr);
		}
		else
		{
			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
		}
	}
	else if ((st->a)[st->lena - 3] > (st->a)[st->lena - 1] &&
			(st->a)[st->lena - 2] > (st->a)[st->lena - 3])
	{
		if (sb > 1)
			do_gen_dbl_ops(st, tr);
		else
			do_gen_ops(st, tr);
	}
	else if (((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
			&& ((st->a)[st->lena - 2] > (st->a)[st->lena - 1]))
	{
		if (sb > 1)
			do_gen_dbl_ops(st, tr);
		else
			do_gen_ops(st, tr);
		do_op(st, tr, "sa");
	}
	if (sb == 5)
		do_op(st, tr, "sb");
}

int		check_for_three(t_stack *st, t_avlt *tr, int ba)
{
	if ((st->lena - ba) == 3)
	{
		if (!ft_issorted(st->a, st->lena))
			basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int		check_for_two(t_stack *st, t_avlt *tr, int ba)
{
	if ((st->lena - ba) == 2)
	{
		if (!ft_issorted(st->a, st->lena))
		{
			if (st->lenb > 1 && (st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
		}
		return (1);
	}
	return (0);
}

int			create_check_med_a(t_stack *st, int ba, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->a[ba], st->lena - ba, &er);
	if (er < 0)
		return (-1);
	return (0);
}

int			find_ghost_med_a(t_stack *st, int ba, int med)
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

int			roll_b(t_stack *st, int bb, int gh_med)
{
	int cntr;

	cntr = 0;
	if (st->lenb - bb == 0)
		return (0);
	//ft_printf("med: %d\n", gh_med);
	//ft_printf("bb:  %d\n", bb);
	//ft_printf("st->lenb:  %d\n", st->lenb);
	if ((st->b)[st->lenb - 1] < gh_med)
		cntr++;
	return (cntr);
}

int			move_from_a(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		pbcntr;
	int		cntr;
	int		med;
	int 	hlen;
	int		len;

	int	gh_med = 0;
	int i = 0;
	
	cntr = 0;
	pbcntr = 0;
	len = st->lena - ba;
	hlen = (st->lena - ba) / 2 + 1;
	//ft_printf("ba:  %d\n", ba);
	//ft_printf("st->lena:  %d\n", st->lena);
	if (create_check_med_a(st, ba, &med) < 0)
		return (-1);
	gh_med = find_ghost_med_a(st, ba, med);
	while (len-- > 0 && (pbcntr < hlen))
	{
		if ((st->a)[st->lena - 1] <= med)
		{
			if (i)
				do_op(st, tr, "rb");
			pbcntr++;
			do_op(st, tr, "pb");
			if ((i = roll_b(st, bb, gh_med)) < 0)
				return (-1);
			st->min_bot_b += i;
		}
		else
		{
			ba > 0 ? cntr++ : 0;
			if (i)
			{
				do_op(st, tr, "rr");
				i = 0;
			}
			else
				do_op(st, tr, "ra");
		}
	}
	if (i)
	{
		ba > 0 ? cntr++ : 0;
		do_op(st, tr, "rr");
		i = 0;
	}
	//if (cntr > 1)
	//	ft_ps_print_stcks(st);
	while (cntr-- > 0)
		do_op(st, tr, "rra");
	return (0);
}

int					ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		min_bot;
	if (st->lena - ba == 0)
		return (0);
	if (st->lena - ba == 1)
		return (0);
	if (check_for_two(st, tr, ba))
		return (0);
	if (check_for_three(st, tr, ba))
		return (0);
	bb = st->lenb;
	//if (st->lena == 50)
	//{
	//	ft_ps_print_stcks(st);
	//	exit(0);
	//}
	//ft_ps_print_stcks(st);
	if (move_from_a(st, tr, ba, bb) < 0)
		return (-1);
	min_bot = st->min_bot_b;
	st->min_bot_b = 0;
	//ft_printf("hi!\n");
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	st->min_bot_b = min_bot;
	//ft_ps_print_stcks(st);
	ba = st->lena;
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
			return (-1);
	//ft_ps_print_stcks(st);
	return (0);
}