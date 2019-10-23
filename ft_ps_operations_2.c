/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:58:16 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:13:58 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ps_checker.h"

void	ps_rra(t_stack *s)
{
	int		fa;
	int		i;

	i = 0;
	fa = (s->a)[0];
	while (i < s->lena - 1)
	{
		(s->a)[i] = (s->a)[i + 1];
		i++;
	}
	(s->a)[s->lena - 1] = fa;
}

void	ps_rrb(t_stack *s)
{
	int		fb;
	int		i;

	i = 0;
	fb = (s->b)[0];
	while (i < s->lenb - 1)
	{
		(s->b)[i] = (s->b)[i + 1];
		i++;
	}
	(s->b)[s->lenb - 1] = fb;
}

void	ps_rrr(t_stack *s)
{
	ps_rra(s);
	ps_rrb(s);
}
