#include "ft_ls.h"

size_t 		ft_nblen(long n)
{
	int ret;

	ret = 0;
	n < 0 ? ++ret : 0;
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

 	size = ft_init_size();
 	while(file)
 	{
 		size = ft_get_max(file, size);
 		file = file->next;
 	}
 	return (size);
 }

 char 	*ft_make_str(t_size size)
{	
	char *print;

	print = ft_joinstr("%c%s  %", 0, 10, ft_itoa(size.a), "ld %", ft_itoa(size.b), "s  %" ,ft_itoa(size.c), "s  %", ft_itoa(size.d), "ld %", ft_itoa(size.e), "s ");
	return (print);
}

 // int main(int argc, char const *argv[])
 // {
 // 	int n  = 134;
 // 	printf("%zu\n", ft_nblen(n));
 // 	return 0;
 // }