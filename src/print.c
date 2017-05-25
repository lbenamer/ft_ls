#include "ft_ls.h"

size_t 		ft_nblen(long n)
{
	int ret;

	ret = 0;
	if(!n)
		return (1);
	n < 0 ? ++ret : 0;
	n < 0 ? n = -n : 0;
	while(n > 0 && ++ret)
		n /= 10;
	return (ret);
}


t_size 		ft_get_max(t_file *file, t_size size)
{

	ft_nblen(file->nlinks) > size.a ? size.a = ft_nblen(file->nlinks) : 0;
	ft_strlen_p(file->owner) > size.b ? size.b = ft_strlen_p(file->owner) : 0;
	ft_strlen_p(file->group) > size.c ? size.c = ft_strlen_p(file->group) : 0;
	ft_nblen(file->size) > size.d ? size.d = ft_nblen(file->size) : 0;
	ft_strlen_p(file->time) > size.e ? size.e = ft_strlen_p(file->time) : 0;
	return (size);
}

 t_size  	ft_get_size(t_file *file)
 {

 	t_size size;
 	t_file *tmp;
 	size = ft_init_size();
 	tmp = file;

 	while(tmp)
 	{
 		size = ft_get_max(tmp, size);
 		tmp = tmp->next;
 	}
 	return (size);
 }

 char 	*ft_make_str(t_size size)
{	
	char *print;
	char *a;
	char *b;
	char *c;
	char *d;
	char *e;

//	printf("start make str \n");
	a = ft_itoa(size.a);
	b = ft_itoa(size.b);
	c = ft_itoa(size.c);
	d = ft_itoa(size.d);
	e = ft_itoa(size.e);
//	printf("all itoa ok\n");
	print = ft_strjoinf("%c%s %" ,a, 2);
	print = ft_strjoinf(print, "ld %", 1);
	print = ft_strjoinf(print, b, 3);
	print = ft_strjoinf(print, "s  %", 1);
	print = ft_strjoinf(print, c, 3);
	print = ft_strjoinf(print, "s  %", 1);
	print = ft_strjoinf(print, d, 3);
	print = ft_strjoinf(print, "ld %", 1);
	print = ft_strjoinf(print, e, 3);
	print = ft_strjoinf(print, "s ", 1);
//	printf("print = %s\n", print);
	// ft_strdup("%c%s %2ld %s %6s %4ld %12s");
	//print = ft_joinstr("%c%s  %", 0, 10, a, "ld %", b, "s  %" , c, "s  %", d, "ld %", e, "s ");
	return (print);
}

 // int main(int argc, char const *argv[])
 // {
 // 	int n  = 134;
 // 	printf("%zu\n", ft_nblen(n));
 // 	return 0;
 // }