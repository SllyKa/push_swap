/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:00:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/24 17:44:48 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "get_next_line.h"
#include "ft_ps_checker.h"
#include "avlt.h"

int				ft_ps_instruct_check(t_list **lst, t_avlt **tr)
{
	char	*instruct;
	int		e_code;
	t_list	*newl;

	*lst = NULL;
	if (!(*tr = init_ps_avlt()))
		return (-1);
	while ((e_code = get_next_line(0, &instruct)) > 0)
	{
		if (!(newl = ft_lstnew(NULL, 0)))
			return (-2);
		if (!(newl->content = srch_avlt(*tr, instruct)))
		{
			free(instruct);
			free(newl);
			return (-3);
		}
		ft_lstaddback(lst, newl);
		free(instruct);
	}
	if (e_code == -1)
		return (-4);
	return (0);
}

int				ft_ps_exec_ops(t_stack *s, t_list *lst)
{
	void		(*op)(t_stack *);
	int			i;

	i = 0;
	if (!s)
		return (-1);
	while (lst)
	{
		op = lst->content;
		lst = lst->next;
		op(s);
	}
	if (s->lenb == 0)
		while (i < s->lena - 1)
		{
			if ((s->a)[i] <= (s->a)[i + 1])
				return (0);
			i++;
		}
	else
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		*st;
	t_list		*lst;
	t_avlt		*tr;
	int			flags;
	char		*fname;

	fname = NULL;
	lst = NULL;
	tr = NULL;
	if ((flags = check_flags(argc, argv, &fname)) > 0)
		set_argv_argc(&argc, &argv, &flags, fname);
	if (!(st = ft_ps_arg_check(argc, argv)))
		write(2, "Error\n", 6);
	else if (ft_ps_instruct_check(&lst, &tr) < 0)
		write(2, "Error\n", 6);
	else
		ft_ps_exec_ops(st, lst) <= 0 ? ft_printf("KO\n") : ft_printf("OK\n");
	if ((flags & 4) == 4)
		free(argv[1]);
	free_stack(&st);
	free_avlt(tr);
	free_ft_list(lst);
	return (0);
}
