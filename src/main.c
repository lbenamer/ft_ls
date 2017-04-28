#include "ft_ls.h"

void	ft_disp_file(t_file *file, int ops)
{
	if(!CHECK_OPS(ops, R))
	{
		if(file->name)
			while(file)
			{
				ft_printf("%s %4ld %s %s %8ld %s %s\n", file->right, file->nlinks, file->owner, file->group, file->size, file->time, file->name);
				file = file->next;
			}
		ft_printf("\n");
	}
	else
	{
		if(file->name)
		{
			while(file->next)
				file = file->next;	
			while(file)
			{
				ft_printf("%s %4ld %s %s %8ld %s %s\n", file->right, file->nlinks, file->owner, file->group, file->size, file->time, file->name);
				file = file->prev;
			}
		ft_printf("\n");
		}
	}
}

void	ft_disp_name(t_file *file, int ops)
{
	if(!CHECK_OPS(ops, R))
	{
		if(file->name)
			while(file)
			{
				ft_printf("%s\n", file->name);
				file = file->next;
			}
		ft_printf("\n");
	}
	else
	{
		if(file->name)
		{
			while(file->next)
				file = file->next;	
			while(file)
			{
				ft_printf("%s\n", file->name);
				file = file->prev;
			}
		ft_printf("\n");
		}
	}
}


int main(int ac, char **av)
{
	t_parse parse;
	int 	i; 

	i = -1;
	if(ac == 1)
		parse = ft_no_parse();
	else
		parse = ft_parse(av, ac);
	if(!CHECK_OPS(parse.ops, R))
		while(parse.path[++i])
			ft_lsdir(parse.path[i], parse.ops);
	else
	{
		i = ft_size_tab(parse.path);
		while(parse.path[--i])
			ft_lsdir(parse.path[i], parse.ops);
	}
	
	return 0;
}
