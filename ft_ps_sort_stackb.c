/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stackb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:19:37 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 13:08:11 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int		check_for_three_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb - st->min_bot_b) == 3)
	{
		/*if (st->min_bot_b == 1)
		{
			do_op(st, tr, "pa");
			do_op(st, tr, "pa");
			do_op(st, tr, "rrb");
			do_op(st, tr, "pa");
		}
		else if (st->min_bot_b == 2)
		{
			do_op(st, tr, "pa");
			do_op(st, tr, "rrb");
			do_op(st, tr, "rrb");
			do_op(st, tr, "pa");
			do_op(st, tr, "pa");
		}
		else if (st->min_bot_b == 3)
		{
			do_op(st, tr, "rrb");
			do_op(st, tr, "rrb");
			do_op(st, tr, "rrb");
			do_op(st, tr, "pa");
			do_op(st, tr, "pa");
			do_op(st, tr, "pa");
		}
		*/
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		//if (!ft_issorted(st->a, st->lena))
		//	basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int				check_for_two_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb - st->min_bot_b) == 2)
	{
		do_op(st, tr, "pa");
		//if (st->min_bot_b == 1)
		//	do_op(st, tr, "rrb");
		do_op(st, tr, "pa");
		/*if (!ft_issorted(st->a, st->lena))
		{
			//ft_printf("lenb: %d\n", st->lenb);
			//ft_ps_print_stcks(st);
			//if (st->lenb > 1 && ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2]))
			//	do_op(st, tr, "ss");
			//else
				do_op(st, tr, "sa");
			//ft_ps_print_stcks(st);
		}*/
		return (1);
	}
	return (0);
}

int			create_check_med_b(t_stack *st, int bb, int *med) // why do i need it?
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->b[bb], st->lenb - bb, &er);
	if (er < 0)
		return (-1);
	return (0);
}

int			find_ghost_med_b(t_stack *st, int bb, int med)
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

int			roll_a(t_stack *st, int ba, int gh_med)
{
	int cntr;

	cntr = 0;
	if (st->lena - ba == 0)
		return (0);
	//ft_printf("med: %d\n", gh_med);
	//ft_printf("ba:  %d\n", ba);
	//ft_printf("st->lena:  %d\n", st->lena);
	if ((st->a)[st->lena - 1] < gh_med)
		cntr++;
	return (cntr);
}

int			move_from_b_med(t_stack *st, t_avlt *tr, int ba, int bb)
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
	bb = (bb > 0 ? (bb + st->min_bot_b) : st->min_bot_b);
	len = st->lenb - bb;
	hlen = (st->lenb - bb) / 2 + 1;
	//ft_printf("bb:  %d\n", bb);//
	//ft_printf("min_bot_b:  %d\n", st->min_bot_b);//
	//ft_printf("lenb: %d\n", st->lenb);
	if (create_check_med_b(st, bb, &med) < 0)
		return (-1);
	gh_med = find_ghost_med_b(st, bb, med);
	while (len-- > 0 && (pbcntr < hlen))
	{
		if ((st->b)[st->lenb - 1] >= med)
		{
			if (i)
				do_op(st, tr, "ra");
			pbcntr++;
			//ft_printf("-->med: %d\n", med);
			//ft_printf("-->gh_med: %d\n", gh_med);
			do_op(st, tr, "pa");
			if ((i = roll_a(st, ba, gh_med)) < 0)
				return (-1);
			st->min_bot_a += i;
		}
		else
		{
			bb > 0 ? cntr++ : 0;
			if (i)
			{
				do_op(st, tr, "rr");
				i = 0;
			}
			else
				do_op(st, tr, "rb");
		}
	}
	if (i)
	{
		do_op(st, tr, "ra");
		i = 0;
	}
	//if (cntr > 1)
	//	ft_ps_print_stcks(st);
	while (cntr-- > 0)
		do_op(st, tr, "rrb");
	return (0);
}

int			move_from_b(t_stack *st, t_avlt *tr, int bb)
{
	int		pbcntr;
	//int		cntr;
	//int		med;
	//int 	hlen;
	int		len;

	//cntr = 0;
	pbcntr = 0;
	len = st->lenb - bb;
	//hlen = (st->lenb - bb) / 2 + 1;
	//if (create_check_med_b(st, bb, &med) < 0) who do i need it?
	//	return (-1);
	//while (len > 0 && (pbcntr < hlen))
	//ft_printf("-->len: %d\n", len);
	//ft_printf("-->min_bot: %d\n", st->min_bot_b);

	if (len > st->min_bot_b)
	{
		while (len > st->min_bot_b)
		{
			do_op(st, tr, "pa");
			pbcntr++;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			do_op(st, tr, "rrb");
			do_op(st, tr, "pa");
			pbcntr++;
			len--;
			//cntr++;
		}
	}
	//while (cntr-- > 0)
	//	do_op(st, tr, "rrb");
	return (0);
}

void			return_bot_b(t_stack *st, t_avlt *tr)
{
	while(st->min_bot_b > 0)
	{
		do_op(st, tr, "rrb");
		(st->min_bot_b)--;
	}
	// modificate it?
}

int				ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		min_bot_a;
	int		min_bot_b;

	//ft_printf("st->lenb: %d\n", st->lenb);//
	//ft_printf("ba: %d\n", ba);//
	//ft_printf("bb: %d\n", bb);//
	//ft_printf("st->min_bot_b: %d\n", st->min_bot_b);//
	
	ba = st->lena; //- st->min_bot_a;
	if (st->min_bot_b > 0 && st->lenb - bb == st->min_bot_b)
			return_bot_b(st, tr);
	//ft_printf("--->min_bot_b: %d\n", st->min_bot_b);
	//ft_printf("--->lenb: %d\n", st->lenb);
	//ft_printf("--->min_bot_a: %d\n", st->min_bot_a);
	if (st->lenb - bb == 0)
		return (0);
	else if (st->lenb - bb - st->min_bot_b == 1)
		do_op(st, tr, "pa");
	else if (check_for_two_b(st, tr, bb))
		;
	else if (check_for_three_b(st, tr, bb))
		;//ft_printf("hi!!\n");//
	else
	{
		//if (st->lena < st->lenb)
		//{
		//	if (move_from_b(st, tr, bb) < 0)
		//		return (-1);
		//}
		//else
		//{

		//else
			move_from_b_med(st, tr, ba, bb);
		//}
	}
	//ft_printf("----->in_ab\n");//
	min_bot_b = st->min_bot_b;
	st->min_bot_b = 0;
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	st->min_bot_b = min_bot_b;
	//ft_printf("----->out_ab\n");//
	min_bot_a = st->min_bot_a;
	st->min_bot_a = 0;
	//ft_printf("----->in_bb\n");//
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
		return (-1);
	//ft_printf("min_bot_ab: %d", st->min_bot_a);
	//ft_printf("----->out_bb\n");//
	st->min_bot_a = min_bot_a;
	if (st->min_bot_a > 0)
	{
		min_bot_b = st->min_bot_b;
		st->min_bot_b = 0;
		//ft_printf("--->in_ab_bot\n");//
		if (ft_ps_sort_stacka(st, tr, st->lena - st->min_bot_a, bb) < 0)
			return (-1);
		//ft_printf("--->out_ab_bot\n");//
		st->min_bot_b = min_bot_b;

		st->min_bot_a = 0;
	}
	return (0);
}