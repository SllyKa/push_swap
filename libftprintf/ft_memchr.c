/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:25:11 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:34 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	var;

	a = (unsigned char *)s;
	var = (unsigned char)c;
	while (n--)
	{
		if (*a == var)
			return ((void *)(a));
		a++;
	}
	return (NULL);
}
