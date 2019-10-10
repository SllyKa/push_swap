/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:08:47 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 13:56:00 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	char	b1;
	char	b2;

	if (c >= 0)
	{
		if (write(fd, &c, 1) < 0)
			return ;
	}
	else
	{
		b1 = 195 & (c >> 6);
		b2 = 191 & c;
		if (write(fd, &b1, 1) < 0)
			return ;
		write(fd, &b2, 1);
	}
}
