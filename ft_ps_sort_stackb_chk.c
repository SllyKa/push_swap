/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stackb_chk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:59:35 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 21:37:44 by gbrandon         ###   ########.fr       */
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
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		return (1);
	}
	return (0);
}

int		check_for_two_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb - st->min_bot_b) == 2)
	{
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		return (1);
	}
	return (0);
}

int		create_check_med_b(t_stack *st, int bb, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->b[bb], st->lenb - bb, &er);
	if (er < 0)
		return (-1);
	return (0);
}
