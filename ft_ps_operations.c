/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:19:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/08 22:54:48 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ps_checker.h"

void	ps_sa(t_stack *s)
{
	int s_1;
	int	s_2;

	if (s->lena < 2)
		return ;
	s_1 = pop(s->a, &(s->lena));
	s_2 = pop(s->a, &(s->lena));
	push(s->a, &(s->lena), s_1);
	push(s->a, &(s->lena), s_2);
}

void	ps_sb(t_stack *s)
{
	int s_1;
	int	s_2;

	if (s->lenb < 2)
		return ;
	s_1 = pop(s->b, &(s->lenb));
	s_2 = pop(s->b, &(s->lenb));
	push(s->b, &(s->lenb), s_1);
	push(s->b, &(s->lenb), s_2);
}

void	ps_ss(t_stack *s)
{
	ps_sa(s);
	ps_sb(s);
}

void	ps_pa(t_stack *s)
{
	int		s_b;

	if (s->lenb == 0)
		return ;
	s_b = pop(s->b, &(s->lenb));
	push(s->a, &(s->lena), s_b);
}

void	ps_pb(t_stack *s)
{
	int		s_a;

	if (s->lena == 0)
		return ;
	s_a = pop(s->a, &(s->lena));
	push(s->b, &(s->lenb), s_a);
}
