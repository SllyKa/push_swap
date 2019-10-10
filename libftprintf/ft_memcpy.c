/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:19:40 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:40 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_arr;
	unsigned char	*src_arr;

	if (dest == src)
		return (dest);
	dest_arr = (unsigned char *)dest;
	src_arr = (unsigned char *)src;
	while (n--)
		*dest_arr++ = *src_arr++;
	return (dest);
}
