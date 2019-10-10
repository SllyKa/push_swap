#include "avlt.h"
#include "extra.h"
#include <unistd.h>

static void write_to_file(t_avlt *root, int gfz_f)
{
    if (root->left)
    {
        ft_putnbr_fd(*(int*)(root->item), gfz_f);
        write(gfz_f, " -> ", 4);
		ft_putnbr_fd(*(int*)(root->left->item), gfz_f);
		write(gfz_f, ";\n", 2);
    }
	if (root->right)
    {
        ft_putnbr_fd(*(int*)(root->item), gfz_f);
        write(gfz_f, " -> ", 4);
		ft_putnbr_fd(*(int*)(root->right->item), gfz_f);
		write(gfz_f, ";\n", 2);
    }
}

void	pre_order_gfz(t_avlt *root, void (*appt)(void *), int gfz_f)
{
    if (gfz_f < 0)
        return ;
    if (!root)
        return ;
    appt(root->item);
	write_to_file(root, gfz_f);
    pre_order_gfz(root->left, appt, gfz_f);
    pre_order_gfz(root->right, appt, gfz_f);
}

void	gfz_write_init(int gfz_f)
{
	if (gfz_f < 0)
		return ;
	write(gfz_f, "digraph G {\n", 12);
}

void	gfz_write_end(int gfz_f)
{
	if (gfz_f < 0)
		return ;
	write(gfz_f, "}", 1);
}
