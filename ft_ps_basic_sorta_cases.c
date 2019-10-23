/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_basic_sorta_cases.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:57:13 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 21:59:43 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

void		bsrt_case2(t_stack *st, t_avlt *tr, int sb)
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

void		bsrt_case4(t_stack *st, t_avlt *tr, int sb)
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

void		bsrt_case3(t_stack *st, t_avlt *tr, int sb)
{
	if (sb >= 1 && sb <= 3)
		do_op(st, tr, "ss");
	else
		do_op(st, tr, "sa");
}

void		bsrt_case5(t_stack *st, t_avlt *tr, int sb)
{
	if (sb > 1)
		do_gen_dbl_ops(st, tr);
	else
		do_gen_ops(st, tr);
}

void		bsrt_case1(t_stack *st, t_avlt *tr, int sb)
{
	if (sb > 1)
		do_gen_dbl_ops(st, tr);
	else
		do_gen_ops(st, tr);
	do_op(st, tr, "sa");
}
