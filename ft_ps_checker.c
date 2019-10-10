/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:00:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/10 17:38:45 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "get_next_line.h"
#include "ft_ps_checker.h"
#include "avlt.h"

static t_stack		*ps_chk_arg_init(int *i, int *er_code, int argc)
{
	t_stack *stack;

	if (argc <= 1)
		return (NULL);
	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		exit(-1);
	if (!(stack->a = (int*)malloc(sizeof(int) * argc)))
		exit(-1);
	if (!(stack->b = (int*)malloc(sizeof(int) * argc)))
		exit(-1);
	*i = 0;
	stack->lena = 0;
	stack->lenb = 0;
	*er_code = 0;
	return (stack);
}

t_stack				*ft_ps_arg_check(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	int			er_code;

	if (!(stack = ps_chk_arg_init(&i, &er_code, argc)))
		return (NULL);
	while (i < argc - 1)
	{
		(stack->a)[i] = ft_satoi(argv[argc - i - 1], &er_code);
		if (echk_atoi(er_code, stack) < 0)
			return (NULL);
		i++;
	}
	if (echk_duplicate(stack, i) < 0)
		return (NULL);
	stack->lena = i;
	return (stack);
}

t_list				*ft_ps_instruct_check(t_list *lst)
{
	char	*instruct;
	int		e_code;
	t_avlt	*tr;
	t_list	*newl;

	lst = NULL;
	if (!(tr = init_ps_avlt()))
		// free tree?
		return (NULL);
	while ((e_code = get_next_line(0, &instruct)) > 0)
	{
		newl = ft_lstnew(NULL, 0);
		if (!(newl->content = srch_avlt(tr, instruct)))
			return (NULL);
		ft_lstaddback(&lst, newl);
	}
	if (e_code == -1)
		return (NULL);
	return (lst);
}

int				ft_ps_exec_ops(t_stack *s, t_list *lst)
{
	void		(*op)(t_stack *);
	int			i;

	i = 0;
	if (!lst || !s)
		return (-1);
	while(lst)
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

	lst = NULL;
	if (!(st = ft_ps_arg_check(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!(lst = ft_ps_instruct_check(lst)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_ps_exec_ops(st, lst) <= 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	//somwhere free stack tree list
	return (0);
}