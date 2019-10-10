#include "avlt.h"
#include "extra.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int 	main(void)
{
    t_avlt  *tr;
    int		a[12];
	int		b[10];
    int     f;
	int		num;

	a[0] = 34;
	a[1] = 234;
	a[2] = 35;
	a[3] = 36;
	a[4] = 33;
	a[5] = 0;
	a[6] = -1;
	a[7] = -100;
	a[8] = 5;
	a[9] = 10;
	a[10] = 2;
	a[11] = 1;

	b[0] = 100;
	b[1] = -10;
	b[2] = 40;
	b[3] = 159;
	b[4] = 13;
	b[5] = 70;
	b[6] = 71;
	b[7] = 65;
	b[8] = 90;
	b[9] = 178;
	b[10] = 89;
	b[11] = 91;
	b[12] = 85;
	b[13] = 84;
	b[14] = 83;
	b[15] = 200;
	b[16] = 201;
	b[17] = 82;
	b[18] = 81;
 
	if ((f = open("graph.gv", O_TRUNC | O_CREAT | O_WRONLY, 00700)) < 0)
    {
        printf("%d\n", f);
		return (-1);
    }
	//tr = add_ar_to_tree(a, 12);
	if (!(tr = add_ar_to_tree(b, 19)))
		return (-1);
	num = 90;
	//remove_n(&tr, &num, tr_cmp);
	//num = 178;
	//remove_n(&tr, &num, tr_cmp);
    gfz_write_init(f);
	pre_order_gfz(tr, appt, f);
    gfz_write_end(f);
    close(f);
	return (0);	
}
