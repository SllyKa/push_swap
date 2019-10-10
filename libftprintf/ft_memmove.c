/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:39:56 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:45 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
		while (n--)
			*(d + n) = *(s + n);
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
