/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:35:35 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 12:39:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include "libftprintf.h"

static int		rec(int n)
{
	int		cntr;

	cntr = 0;
	if (n / 10 == 0)
	{
		cntr++;
	}
	else
	{
		cntr += rec(n / 10);
		cntr++;
	}
	return (cntr);
}

static int		ft_cntnbr(int n)
{
	int		cntr;

	cntr = 0;
	if (n == -2147483648)
	{
		cntr++;
		cntr += rec(n / -10);
		cntr++;
	}
	else
	{
		if (n < 0)
		{
			cntr++;
			n *= -1;
		}
		cntr += rec(n);
	}
	return (cntr);
}

static int		fsize(int	*ar, size_t s)
{
	int		max;
	int		min;
	size_t	i;

	if (!ar)
		return (1);
	i = 1;
	max = ar[0];
	min = ar[0];
	while (i < s)
	{
		max = (max < ar[i] ? ar[i] : max);
		min = (min > ar[i] ? ar[i] : min);
		i++;
	}
	if (ft_cntnbr(min) > ft_cntnbr(max))
		return (ft_cntnbr(min));
	else
		return (ft_cntnbr(max));
}

static void		just_print(t_stack *st, int fa, int fb, int i)
{
	int		cura;
	int		curb;

	cura = st->lena - i - 1;
	curb = st->lenb - i - 1;
	if (cura >= 0)
	{
		ft_printf("|%*d|", fa, (st->a)[cura]);
		cura--;
	}
	else
		ft_printf("|%*c|", fa, ' ');
	if (curb >= 0)
	{
		ft_printf("%*d|", fb, (st->b)[curb]);
		curb--;
	}
	else
		ft_printf("%*c|", fb, ' ');
	ft_printf("\n");
}

void			ft_ps_print_stcks(t_stack *st)
{
	int		i;
	int		max;
	int		f_sizea;
	int		f_sizeb;

	if (!st)
		return ;
	f_sizea = fsize(st->a, st->lena);
	f_sizeb = fsize(st->b, st->lenb);
	i = 0;
	ft_printf("|");
	while (i < f_sizea)
	{
		ft_printf("%c", '-');
		i++;
	}
	ft_printf("|");
	i = 0;
	while (i < f_sizeb)
	{
		ft_printf("%c", '-');
		i++;
	}
	ft_printf("|\n");
	max = ((st->lena > st->lenb) ? st->lena : st->lenb);
	i = 0;
	while (i < max)
	{
		just_print(st, f_sizea, f_sizeb, i);
		i++;
	}
}
