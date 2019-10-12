/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:49:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 16:15:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int			sort_big(t_stack *st, t_avlt *tr)
{
	int		len;
	int		med;
	int		er;

	len = st->lena;
	med = ft_quicksel_medi(st, &er);
		return (-1);
	while(len > 0)
	{
		if ((st->a)[st->lena - 1] < med)
			do_op(st, tr, "pb");
		else
			do_op(st, tr, "ra");
		len--;
	}
	while (st->lena > 3)
	{
			do_op(st, tr, "pb");		
	}
	check_for_two(st, tr);
	check_for_three(st, tr);
	while(!ft_issorted(st->a, st->lena) && ((st->b)[st->lenb - 1] > med))
	{

	}
}