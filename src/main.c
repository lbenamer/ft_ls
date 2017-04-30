#include "ft_ls.h"

void 	ft_disp_block(t_file *file)
{
	//ne pas compter les block de liens// a faire // 
	size_t total;

	total = 0;
	while(file)
	{
		total += file->block;
		file = file->next;
	}
	ft_printf("total %lld\n", total);
}


void	ft_disp_file(t_file *file, int ops)
{
	if(file->name)
		ft_disp_block(file);
	if(!CHECK_OPS(ops, R))
	{
		if(file->name)
			while(file)
			{
				if(file->d)
				{
					ft_printf("%s %4ld %s %s %8ld %s ", file->right, file->nlinks, file->owner, 
					file->group, file->size, file->time);
					ft_printf(CYAN"%s\n"STOP, file->name);
				}
				else if(ft_strchr(file->right, 'x'))
				{
					ft_printf("%s %4ld %s %s %8ld %s ", file->right, file->nlinks, file->owner, 
					file->group, file->size, file->time);
					ft_printf(RED"%s\n"STOP, file->name);
				}
				else
				{
					ft_printf("%s %4ld %s %s %8ld %s %s\n", file->right, file->nlinks, file->owner,
					file->group, file->size, file->time, file->name);
				}
				//printf("block = %ld\n", file->block);
				file = file->next;
			}
	}
	else
	{
		if(file->name)
		{
			while(file->next)
				file = file->next;	
			while(file)
			{
				if(file->d)
				{
					ft_printf("%s %4ld %s %s %8ld %s ", file->right, file->nlinks, file->owner, 
					file->group, file->size, file->time);
					ft_printf(CYAN"%s\n"STOP, file->name);
				}
				else if(ft_strchr(file->right, 'x'))
				{
					ft_printf("%s %4ld %s %s %8ld %s ", file->right, file->nlinks, file->owner, 
					file->group, file->size, file->time);
					ft_printf(RED"%s\n"STOP, file->name);
				}
				else
				{
					ft_printf("%s %4ld %s %s %8ld %s %s\n", file->right, file->nlinks, file->owner,
					file->group, file->size, file->time, file->name);
				}
			//	ft_printf("stime = %lld\n", file->stime);
				file = file->prev;
			}
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
		}
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
	
	return 0;
}
