/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:25:51 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 22:51:50 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include "libftprintf.h"

void		print_lst(t_list *lst)
{
	if (!lst)
		return ;
	print_lst(lst->next);
	ft_printf("%s\n", (char*)(lst->content));
}

void		free_ft_list_from_stck(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = temp;
	}
}
