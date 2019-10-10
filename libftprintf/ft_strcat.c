/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:08:38 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:39:47 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcat(char *destination, const char *append)
{
	size_t	i;
	char	*res;

	i = ft_strlen((char *)append);
	res = destination;
	while (*destination)
		destination++;
	while (i--)
		*destination++ = *append++;
	*destination = '\0';
	return (res);
}
