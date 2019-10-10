#ifndef EXTRA_H
# define EXTRA_H
#include "avlt.h"
#include <unistd.h>

void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			appt(void *);
int				tr_int_cmp(void *, void *);
t_avlt			*add_ar_to_tree(int *, size_t);

#endif