/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:57:16 by gbrandon          #+#    #+#             */
/*   Updated: 2019/09/24 23:22:58 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

static void		rec(int n, int fd)
{
	if (n / 10 == 0)
	{
		ft_putchar_fd(n + 48, fd);
	}
	else
	{
		rec(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		rec(n / -10, fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		rec(n, fd);
	}
}
