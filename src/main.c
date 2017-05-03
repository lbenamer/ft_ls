#include "ft_ls.h"

void disp(t_file *file)
{
	while(file)
	{
		ft_printf("file name = %s\n", file->name);
		file = file->next;
	}

}
void 	ft_disp_block(t_file *file)
{
	size_t total;

	total = 0;
	while(file)
	{
		total += file->block;
		file = file->next;
	}
	ft_printf("total %lu\n", total);
}

int	ft_print_color(t_file *file, int ops)
{
	if(file->type == 'd')
	{
		ft_printf(CYAN"%s\n"STOP, file->name);
		return (1);
	}
	else if(file->type == 'l')
	{
		ft_printf(MAGENTA"%s"STOP, file->name);
		if(CHECK_OPS(ops , L))
			ft_printf(" -> %s", file->link);
		ft_printf("\n");
		return (1);
	}
	else if(ft_strchr(file->right, 'x'))
	{
		ft_printf(RED"%s\n"STOP, file->name);
		return (1);
	}
	else
		ft_printf("%s\n", file->name);
	return (1);
}

void	ft_disp_file(t_file *file, int ops)
{
	t_size size;
	char *print;

	size = ft_get_size(file);
	print = ft_make_str(size);

	if(file->name && CHECK_OPS(ops, L))
		ft_disp_block(file);
	if(CHECK_OPS(ops, R))
		while(file->next)
			file = file->next;
	while(file)
	{
		if(CHECK_OPS(ops, L))
			ft_printf(print ,file->type, file->right, file->nlinks, file->owner, 
				file->group, file->size, file->time);
			// ft_printf("%c%s %2ld %s %6s %4ld %12s ",file->type, file->right, file->nlinks, file->owner, 
			// 	file->group, file->size, file->time);
		ft_print_color(file, ops);
		if(!CHECK_OPS(ops, R))
			file = file->next;
		else
			file = file->prev;
	}
}

int main(int ac, char **av)
{
	t_parse parse;
	int 	i;
	int 	size; 

	i = -1;
	if(ac == 1)
		parse = ft_no_parse();
	else
		parse = ft_parse(av, ac);
	size = ft_size_tab(parse.path);
	if(!CHECK_OPS(parse.ops, R))
		while(parse.path[++i])
		{
			if(size > 1)
				ft_printf("%s :\n", parse.path[i]);
			ft_lsdir(parse.path[i], parse.ops);
			if(size > 1 && i != size - 1)
				ft_printf("\n");
		}
	else
	{
		i = ft_size_tab(parse.path);
		while(parse.path[--i])
		{
			if(size > 1)
				ft_printf("%s :\n", parse.path[i]);
			ft_lsdir(parse.path[i], parse.ops);
			if(size > 1 && i != 0)
				ft_printf("\n");
		}
	}
	
	return 1;
}
