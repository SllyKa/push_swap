/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:25:51 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/24 15:39:05 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include "libftprintf.h"

void		print_lst(t_list *lst, int i, t_stack *st)
{
	if (!lst)
		return ;
	i++;
	print_lst(lst->next, i, st);
	if ((st->flags & 2) == 2)
	{
		if (i % 2 == 0)
			ft_printf("%{green}%s%{eoc}\n", (char*)(lst->content));
		else
			ft_printf("%{yellow}%s%{eoc}\n", (char*)(lst->content));
	}
	else
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

static int	set_flags(char c, int *flags)
{
	if (c == 'v')
		*flags = *flags | 1;
	else if (c == 'c')
		*flags = *flags | 2;
	else if (c == 'f')
		*flags = *flags | 4;
	else
		return (-1);
	return (0);
}

void		set_argv_argc(int *argc, char ***argv, int *flags, char *fname)
{
	if ((*flags <= 7 && *flags >= 4) && fname)
	{
		*argc = 2;
		if (((*argv)[1] = read_from_file(fname)) == NULL)
			*argc = 1;
	}
	else if (*flags == 3)
	{
		*argc -= 2;
		*argv = &(*argv)[2];
	}
	else if (*flags == 2 || *flags == 1)
	{
		*argc -= 1;
		*argv = &(*argv)[1];
	}
	else
		*flags = 0;
}

int			check_flags(int argc, char **argv, char **fname)
{
	int		flags;
	int		i;

	flags = 0;
	i = 1;
	if (argc < 2)
		return (-1);
	while (argc-- > 1)
	{
		if (ft_strlen(argv[i]) == 2 && argv[i][0] == '-')
		{
			if ((set_flags(argv[i][1], &flags) < 0))
				return (flags);
			if ((flags & 4) == 4)
			{
				if (argc > 1)
					*fname = strdup(argv[i + 1]);
				return (flags);
			}
		}
		else
			return (flags);
		i++;
	}
	return (flags);
}
