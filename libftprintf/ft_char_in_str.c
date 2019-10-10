/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:10:11 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:37:35 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_char_in_str(void *s, char c)
{
	unsigned char	*str;
	size_t			i;

	if (s == NULL)
		return (0);
	str = (unsigned char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
