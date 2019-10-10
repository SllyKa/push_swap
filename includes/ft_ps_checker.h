/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:55:35 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/10 15:01:36 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PS_CHECKER_H
# define FT_PS_CHECKER_H
# include "avlt.h"
#include "libftprintf.h"

typedef struct			s_stack
{
	int		*a;
	int		lena;
	int		*b;
	int		lenb;
}						t_stack;

typedef struct			s_opfunc
{
	char	*line;
	void	*func;
}						t_opfunc;

enum					e_operations
{
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
};

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
void			free_stack(t_stack **s);
int				echk_atoi(int er_code, t_stack *stack);
int				echk_duplicate(t_stack *stack, int size);
t_stack			*ft_ps_arg_check(int argc, char **argv);
t_list			*ft_ps_instruct_check(t_list *stack);
int				ft_ps_exec_ops(t_stack *s, t_list *lst);
void			*t_ins(void *item);
void			t_del(void *item);
int				t_char_cmp(void *a, void *b);
t_avlt			*init_ps_avlt(void);
void			*srch_avlt(t_avlt *rt, char *it);

# endif