/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:49:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/17 21:20:30 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

/*mb someday...

int			srchbetterway(t_stack *st, int med, int *er)
{
	int		i;
	int		sch_up;
	int		sch_down;

	sch_up = 0;
	sch_down = 0;
	i = 0;
	while (i < st->lena)
	{
		if (st->a[st->lena - i - 1] <= med)
		{
			sch_up = i;
			break;
		}
		i++;
		sch_up = -1;
	}
	i = 0;
	while (i < st->lena)
	{
		if (st->a[i] <= med)
		{
			sch_down = -i - 1;
			break;
		}
		i++;
		sch_down = 1;
	}
	if (sch_up < 0 || sch_down > 0)
	{
		*er = -1;
		return (0);
	}
	if (sch_up <= sch_down * -1)
		return (sch_up);
	else
		return (sch_down);
}

	if (ba == 0)
		{
			if((srchbetterway(st, med, &er) < 0) && (er > -1))
				cmdmv = "rra";
			else
				cmdmv = "ra";
		}
*/
/// rev_1

/*static void		basic_sort(t_stack *st, t_avlt *tr)
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
	er = 0;
	med = ft_quicksel_medi(st, &er);
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
	//if (len == 16)
	//{
	//ft_ps_print_stcks(st);
	//	exit (-1);
	//}
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
}*/


/// rev_2


/*
int				ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb)
{
	int		len;
	int		med;
	int		er;
	int		hlen;

	int		i;
	int		cntr;
	int		pbcntr;

	if (st->lena - ba == 1)
		return (0);
	if (check_for_two(st, tr, ba))
		return (0);
	if (check_for_three(st, tr, ba))
		return (0);
	len = st->lena - ba;
	er = 0;
	med = ft_quicksel_medi(&st->a[ba], st->lena - ba, &er);
	if (er < 0)
		return (-1);
	hlen = len;
	bb = st->lenb;
	cntr = 0;
	pbcntr = 0;
	while (len > 0 && pbcntr < ((hlen % 2 == 0) ? (hlen / 2) : (hlen / 2 + 1)))
	{
		if ((st->a)[st->lena - 1] <= med)
		{
			pbcntr++;
			do_op(st, tr, "pb");			
		}
		else
		{
			ba > 0 ? cntr++ : 0;
			do_op(st, tr, "ra");
		}
		len--;
	}
	while (cntr > 0)
	{
		cntr--;
		do_op(st, tr, "rra");
	}
	len = hlen;
	ft_printf("------>in: %d|\n", bb);
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	ft_printf("------>out: %d|\n", bb);	
	ba = st->lena;
	len = ((len % 2 == 0) ? (len / 2) : (len / 2 + 1));
	i = 0;
	//if (len == 16)
	//{
	//ft_ps_print_stcks(st);
	//	exit (-1);
	//}
	if (len < 4)
	{
		while (i < len)
		{
			do_op(st, tr, "pa");
			i++;
		}
		if (len == 2)
		{
			if (!ft_issorted(st->a, st->lena))
				do_op(st, tr, "sa");
		}
		else if (len == 3)
			if (!ft_issorted(st->a, st->lena))
				basic_sort(st, tr);
	}
	else
	{
		while (st->lena < hlen)
		{
			ft_ps_print_stcks(st);
			ft_printf("--->ba: %d|\n", ba);
			ft_printf("--->bb: %d|\n", bb);
			ft_ps_sort_stackb(st, tr, bb);
			ft_printf("------>in: %d|\n", bb);
			ft_ps_sort_stacka(st, tr, ba, bb);
			ft_printf("------>out: %d|\n", bb);
			ba = st->lena;
		}
		//ft_printf("--->out|\n");
	}
	
	return (0);
}

int				ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int border)
{
	int		len;
	int		klen;
	int		med;
	int		er;
	int		cntr;
	int		pacntr;

	len = st->lenb - border;
	cntr = 0;
	er = 0;
	med = ft_quicksel_medi(&st->b[border], st->lenb - border, &er);
	if (er < 0)
		return (-1);
	pacntr = 0;
	klen = ((len % 2 == 0) ? (len / 2) : (len / 2 + 1));
	while (len > 0 && pacntr < klen)
	{
		if ((st->b)[st->lenb - 1] > med)
		{
			do_op(st, tr, "pa");
			pacntr++;
		}
		else
		{
			do_op(st, tr, "rb");
			cntr++;
		}
		len--;
	}
	while (cntr > 0)
	{
		do_op(st, tr, "rrb");
		cntr--;
	}
	return (0);
}
*/