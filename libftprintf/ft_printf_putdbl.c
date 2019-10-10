/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:52:54 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/02 18:53:56 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void		ft_float_result(t_fmt *fmts, int ex, unsigned long long mant,\
int *i)
{
	char	*tale;
	char	*frnt;
	int		power;

	(!(tale = ft_strdup("000000")) ? (exit(1)) : 0);
	(!(frnt = ft_strdup("0"))) ? (exit(1)) : 0;
	power = -(-52 + ex);
	while (ex - 52 < 0 && mant > 0)
	{
		if (mant & 1)
			tale = ft_str_addition(tale, ft_add_zeroes(\
			ft_power5(-(ex - 52)), -(ex - 52), power));
		mant = mant >> 1;
		ex++;
	}
	while (mant > 0)
	{
		if (mant & 1)
			frnt = ft_str_addition(frnt, ft_power2(ex - 52));
		mant = mant >> 1;
		ex++;
	}
	ft_show_result(fmts, frnt, tale, i);
}

static int	ft_check_vals(t_fmt *fmts, int e, unsigned long long m, int *i)
{
	if (e != 1024)
		return (1);
	fmts->flags = fmts->flags & ((m == 0x10000000000000) ? 7 : 1);
	PREC = 0;
	if (m == 0x10000000000000)
		ft_show_result(fmts, ft_strdup((TYPE == 'E' || TYPE == 'G')\
		? ("INF") : ("inf")), ft_strnew(0), i);
	else if (e == 1024)
		ft_show_result(fmts, ft_strdup((TYPE == 'E' || TYPE == 'G') ?\
		("NAN") : ("nan")), ft_strnew(0), i);
	return (0);
}

void		ft_printf_putdbl(t_fmt *fmts, int *i)
{
	unsigned long long	res;
	unsigned long long	mant;
	long long			ex;
	unsigned char		b[8];

	mant = 0;
	res = 0;
	ft_memcpy(b, ((double *)DATA), sizeof(double));
	ft_strrev_num(b, sizeof(double));
	while (mant < 8)
		res = (res << 8) + (b[mant++] % 256);
	NEG = (res & 0x8000000000000000) >> 63;
	res = res & 0x7FFFFFFFFFFFFFFF;
	ex = ((res & 0x7FF0000000000000) >> 52) - 1023;
	mant = (res & 0xfffffffffffff) | 0x10000000000000;
	PREC = (PREC < 0) ? (6) : PREC;
	(ft_check_vals(fmts, ex, mant, i)) ? ft_float_result(fmts, ex, mant, i) : 0;
}
