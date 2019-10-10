/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:02:17 by lshanaha          #+#    #+#             */
/*   Updated: 2019/10/10 14:43:41 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdarg.h>

typedef struct		s_list {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree {
	char			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef enum	{
	BLACK,
	RED
}	t_node_color;

typedef struct		s_node {
	int				data;
	void			*text;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
	t_node_color	color;
}					t_rb_node;

/*
** t_fmt descritpion:
** flags 			contains 1 in bit if corresponding flag exists
** 			   			 0 - otherwise
** flags 			structure: 000(0)#(space)+-
**
** width 			contains width respectively)
** precision		contains .presicion respectively)
** size 			contains one of the next symbols zj(ll)l(hh)hL
**
** type			contains one of the next symbols: "sSpdDioOuUxXcCfFb" eEgGaAn???
** *data			current argument. Usually corresponding to type-field :)
*/
typedef struct		s_fmt {
	char			flags;
	int				width;
	int				precision;
	char			size;
	char			type;
	void			*data;
	void			*extra;
}					t_fmt;
typedef struct		s_cntrl {
	char			type;
	void			*data;
	size_t			data_size;
	char			neg;
}					t_cntrl;

# define EQ(a, b) ft_strcmp(a, b) == 0
# define DIFF(a, b) ft_strcmp(a, b) < 0
# define B_SET(byte, pos) (((byte) & (1 << (pos))) ? (1) : (0))
# define MS B_SET(fmts->flags, 0)
# define PS B_SET(fmts->flags, 1)
# define SPC B_SET(fmts->flags, 2)
# define HSH B_SET(fmts->flags, 3)
# define ZO B_SET(fmts->flags, 4)
# define L B_SET(fmts->size, 0)
# define H1 B_SET(fmts->size, 1)
# define HH1 B_SET(fmts->size, 2)
# define L1 B_SET(fmts->size, 3)
# define LL1 B_SET(fmts->size, 4)
# define J1 B_SET(fmts->size, 5)
# define Z1 B_SET(fmts->size, 6)
# define DATA (fmts->data)
# define PREC (fmts->precision)
# define WIDTH (fmts->width)
# define TYPE (fmts->type)
# define NEG (((t_cntrl*)(fmts->extra))->neg)

# define TYPES "sSpdDioOuUxXcCfFbreEgG"
# define FLAGS "-+ #0"
# define SIZES "hlLjz"
# define OCTBASE "01234567"
# define HEXBASE "0123456789abcdef"
# define BIGHEXBASE "0123456789ABCDEF"
# define BINBASE "01"

# define ESCCLR		"eoc"
# define BLACKCLR	"black"
# define REDCLR		"red"
# define GREENCLR	"green"
# define YELLOWCLR	"yellow"
# define BLUECLR	"blue"
# define MAGENTACLR	"magenta"
# define CYANCLR	"cyan"
# define WHITECLR	"white"

# define ABS(a) (a < 0) ? (a = -a) : a

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy (void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strrev(char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_float_result(t_fmt *a, int b, unsigned long long c,\
int *d);
void				ft_print_help(char *str, int *i);
size_t				ft_strlen(const char *str);
size_t				ft_char_in_str(void *s, char c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_intlen(long long n);
int					ft_uintlen(unsigned long long n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat (char *destination, const char *append);
char				*ft_strncat (char *destination, const char *append,\
size_t n);
size_t				ft_strlcat (char *dst, const char *src, size_t n);
char				*ft_strchr (const char *str, int ch);
char				*ft_strrchr (const char *str, int ch);
char				*ft_strstr(const char *strb, const char *stra);
char				*ft_strnstr(const char *hay, const char *needle,\
size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_strrev_bin(char **str);
char				*ft_base_convert(char *base_str, unsigned long long nbr);
unsigned char		*ft_strrev_num(unsigned char *s, int len);
char				*ft_str_addition(char *first, char *second);
char				*ft_str_mult(char *first, char *second);
char				*ft_power2(int power);
char				*ft_power5(int power);

/*
** char				*ft_add_zeroes(char *str, int n, int len_first);
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstclear(t_list *lst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_prefix(t_btree *root,\
void (*applyf)(void *));
void				ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				ft_btree_apply_suffix(t_btree *root,\
void (*applyf)(void *));
void				ft_btree_insert(t_btree **r, void *item,\
int (*cmpf)(void *, void *));
void				*ft_btree_search(t_btree *root, void *data_ref);

void				ft_insert_case1(t_rb_node *n);
void				ft_insert_case2(t_rb_node *n);
void				ft_insert_case3(t_rb_node *n);
void				ft_insert_case4(t_rb_node *n);
void				ft_insert_case5(t_rb_node *n);
void				ft_freemem(t_rb_node *tree, t_rb_node *stop);
void				ft_treeprint(t_rb_node *p);
void				ft_rotate_left(t_rb_node *n);
void				ft_rotate_right(t_rb_node *n);
t_rb_node			*ft_findnode_text(t_rb_node *root, char *data);
t_rb_node			*ft_findnode_data(t_rb_node *root, int data);
t_rb_node			*ft_find_root(t_rb_node *node);
t_rb_node			*ft_add_in_tree(t_rb_node **root, int data, char *text);
t_rb_node			*ft_grandparent(t_rb_node *n);
t_rb_node			*ft_uncle(t_rb_node *n);
int					ft_printf(const char *a, ...);
int					ft_sprintf(char *a, const char *b, ...);
int					ft_fprintf(int a, const char *b, ...);
void				select_type_group(t_fmt *a, va_list b, int *c);
void				select_fstrings(t_fmt *a, va_list b, int *c);
void				select_fsig_dec(t_fmt *a, va_list b, int *c);
void				select_funsig_dec(t_fmt *a, va_list b, int *c);
void				select_hexoct(t_fmt *a, va_list b, int *c);
void				select_fdoubles(t_fmt *a, va_list b, int *c);
void				select_fextras(t_fmt *a, va_list b, int *c);
void				select_fexpos(t_fmt *a, va_list b, int *c);
void				select_fgs(t_fmt *fmts, va_list ap, int *ch_cntr);
int					read_format_item(const char **a, va_list b, t_fmt *c);
int					fmt_varg_len_set(int *a, va_list b);
int					fmt_type_set(char *a, const char b);
int					fmt_size_set(char *a, const char **b);
const char			*fmt_read_numbers(int *a, const char *b);
int					fmt_flag_set(char *a, const char b);
t_fmt				*fmt_init(char a, void *b);
void				fmt_clear(t_fmt *a);
char				set_bit(char a, char b);
char				s_a_c(char a, char b, char c);
void				ft_printf_putstr(t_fmt *a, int *b);
void				ft_printf_putstr_s(t_fmt *a, int *b);
void				ft_printf_widestr(t_fmt *a, int *b);
void				ft_printf_widechar(unsigned int a, t_fmt *b, int *c, int k);
void				ft_printf_putchar(int a, int *b, int c, t_fmt *d);
int					write_st(int a, const void *b, size_t c, t_cntrl *d);
void				ft_printf_putd(t_fmt *a, int *b);
void				ft_printf_putld(t_fmt *a, int *b);
void				ft_printf_putlld(t_fmt *a, int *b);
void				ft_printf_putu(t_fmt *a, int *b);
void				ft_printf_putlu(t_fmt *a, int *b);
void				ft_printf_putllu(t_fmt *a, int *b);
void				ft_printf_pointers(t_fmt *a, int *b);
void				ft_printf_putbase(t_fmt *a, int *b, char *c, int d);
void				ft_printf_putdbl(t_fmt *a, int *b);
void				ft_printf_putldbl(t_fmt *a, int *b);
void				ft_printf_putexp(t_fmt *a, int *b);
void				ft_printf_putlexp(t_fmt *a, int *b);
void				ft_printf_putg(t_fmt *fmts, int *i);
void				ft_printf_putlg(t_fmt *fmts, int *i);
void				ft_printf_clr_chk(const char **a);

void				ft_show_result(t_fmt *a, char *b, char *c, int *d);
void				ft_show_exp_result(t_fmt *a, char *b, char *c, int *d);
void				ft_show_exp(t_fmt *fmts, char *front, char *tale, int *i);
char				*ft_add_zeroes(char *str, int n, int len_first);
int					ft_width_solver(t_fmt *fmts, char *tale, int g_exp);
void				ft_mad_printer(t_fmt *a, char *b, char *c, int *d);
char				*ft_round_round(t_fmt *a, char *b, char *c);

void				print_fmt_s(t_fmt *a);
void				print_fmt_ls(t_fmt *a);
void				print_fmt_c(t_fmt *a);
void				print_fmt_lc(t_fmt *a);
void				print_fmt_d(t_fmt *a);
void				print_fmt_ld(t_fmt *a);
void				print_fmt_lld(t_fmt *a);
void				print_fmt_u(t_fmt *a);
void				print_fmt_lu(t_fmt *a);
void				print_fmt_llu(t_fmt *a);
void				print_fmt_o(t_fmt *a);
void				print_fmt_lo(t_fmt *a);
void				print_fmt_llo(t_fmt *a);
void				print_fmt_x(t_fmt *a);
void				print_fmt_lx(t_fmt *a);
void				print_fmt_llx(t_fmt *a);
void				print_fmt_f(t_fmt *a);
void				print_fmt_lf(t_fmt *a);
void				print_fmt_p(t_fmt *a);

long long			ft_power(long x, long y);
double				ft_power_float(long x, long y);
int					ft_satoi(const char *str, int *er_code);

#endif
