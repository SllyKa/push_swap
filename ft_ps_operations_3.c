/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:12:13 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:14:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ps_checker.h"

void	ps_ra(t_stack *s)
{
	int		la;
	int		i;

	i = s->lena - 1;
	la = (s->a)[s->lena - 1];
	while (i > 0)
	{
		(s->a)[i] = (s->a)[i - 1];
		i--;
	}
	(s->a)[i] = la;
}

void	ps_rb(t_stack *s)
{
	int		lb;
	int		i;

	i = s->lenb - 1;
	lb = (s->b)[s->lenb - 1];
	while (i > 0)
	{
		(s->b)[i] = (s->b)[i - 1];
		i--;
	}
	(s->b)[i] = lb;
}

void	ps_rr(t_stack *s)
{
	ps_ra(s);
	ps_rb(s);
}
