/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stackb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:19:37 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/17 22:17:42 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int		check_for_three_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb) == 3)
	{
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		if (!ft_issorted(st->a, st->lena))
			basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int				check_for_two_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb) == 2)
	{
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		if (!ft_issorted(st->a, st->lena))
		{
			//ft_printf("lenb: %d\n", st->lenb);
			//ft_ps_print_stcks(st);
			//if (st->lenb > 1 && ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2]))
			//	do_op(st, tr, "ss");
			//else
				do_op(st, tr, "sa");
			//ft_ps_print_stcks(st);
		}
		return (1);
	}
	return (0);
}

static int			create_check_med_b(t_stack *st, int bb, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->b[bb], st->lenb - bb, &er);
	if (er < 0)
		return (-1);
	return (0);
}

int			move_from_b(t_stack *st, t_avlt *tr, int bb)
{
	int		pbcntr;
	int		cntr;
	int		med;
	int 	hlen;
	int		len;

	cntr = 0;
	pbcntr = 0;
	len = st->lenb - bb;
	hlen = (st->lenb - bb) / 2 + 1;
	if (create_check_med_b(st, bb, &med) < 0)
		return (-1);
	while (len-- > 0 && (pbcntr < hlen))
	{
		if ((st->b)[st->lenb - 1] >= med)
		{
			do_op(st, tr, "pa");			
			pbcntr++;
		}
		else
		{
			do_op(st, tr, "rb");
			cntr++;
		}
	}
	while (cntr-- > 0)
		do_op(st, tr, "rrb");
	return (0);
}

int				ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb)
{
	if (st->lenb - bb == 1)
	{
		do_op(st, tr, "pa");
		return (0);
	}
	if (check_for_two_b(st, tr, bb))
		return (0);
	if (check_for_three_b(st, tr, bb))
		return (0);
	//ft_printf("--->bb: %d\n", bb);
	//ft_printf("--->lenb: %d\n", st->lenb);
	ba = st->lena;
	ft_ps_print_stcks(st);
	if (move_from_b(st, tr, bb) < 0)
		return (-1);

	//ft_printf("----->in_b\n");
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	ft_ps_print_stcks(st);	
	//ft_printf("<-----out_b\n");
	//bb = st->lenb;
	//ft_printf("----->in_b\n");
	ft_ps_print_stcks(st);	
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
		return (-1);
	ft_ps_print_stcks(st);	
	//ft_printf("<-----out_b\n");	
	return (0);
}