/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_general.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:18:04 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/17 20:07:38 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PS_GENERAL_H
# define FT_PS_GENERAL_H
#include "libftprintf.h"
#include "avlt.h"

typedef struct			s_stack
{
	int		*a;
	int		lena;
	int		*b;
	int		lenb;
	t_list	*op_lst;
}						t_stack;

typedef struct			s_opfunc
{
	char	*line;
	void	*func;
}						t_opfunc;

void			push(int *stk, int *s_len, int num);
int				pop(int *stk, int *s_len);
void			ps_sa(t_stack *s);
void			ps_sb(t_stack *s);
void			ps_ss(t_stack *s);
void			ps_pa(t_stack *s);
void			ps_pb(t_stack *s);
void			ps_ra(t_stack *s);
void			ps_rb(t_stack *s);
void			ps_rr(t_stack *s);
void			ps_rra(t_stack *s);
void			ps_rrb(t_stack *s);
void			ps_rrr(t_stack *s);
t_stack			*ft_ps_arg_check(int argc, char **argv);
void			free_tab(char **tab);
void			free_stack(t_stack **s);
void			free_ft_liststckalone(t_list **lst);
void			*t_ins(void *item);
void			t_del(void *item);
int				t_char_cmp(void *a, void *b);
t_avlt			*init_ps_avlt(void);
void			*srch_avlt(t_avlt *rt, char *it);
void			free_avlt(t_avlt *tr);
void			ft_ps_print_stcks(t_stack *st);
void			print_lst(t_list *lst);

#endif