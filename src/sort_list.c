#include "ft_ls.h"


int 		ft_is_sort(t_file *file)
{
	while(file->next)
	{
		if(ft_strcmp(file->name, file->next->name) < 0)
			file = file->next;
		else
			return (0);
	}
	return (1);
}

void	 	ft_cpy_data(t_file **tmp, t_file *file)
{
	t_file *new;

	new = *tmp;
	new->name = file->name;
	new->path = file->path;
	new->group = file->group;
	new->owner = file->owner;
	new->time = file->time;
	new->right = file->right;
	new->size = file->size;
	new->nlinks = file->nlinks;
	new->stime = file->stime;
	new->d = file->d;
	new->block = file->block;                         
}

void		ft_swap_lst(t_file **a, t_file **b)
{
	t_file *tmp;

	tmp = ft_init_file();
	ft_cpy_data(&tmp, *a);
	ft_cpy_data(a, *b);
	ft_cpy_data(b,tmp);	
}

int 		ft_is_sort_t(t_file *file)
{
	while(file->next)
	{
		if(file->stime >= file->next->stime)
			file = file->next;
		else 
			return (0);
	}
	return (1);
}

t_file  *ft_sort_rev(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while(tmp->prev)
	{
		if(ft_strcmp(tmp->prev->name, tmp->name) > 0)
			ft_swap_lst(&tmp->prev, &tmp);
		tmp = tmp->prev;
	}
	return (file);
}

t_file 	 	*ft_sort_time(t_file *file)
{
	t_file *start;

	start = file;
	while(!ft_is_sort_t(start))
	{
		while(file->next)
		{
			if(file->stime < file->next->stime)
				ft_swap_lst(&file, &file->next);
			file = file->next;
		}
		file = start;
	}	
	return (file);

}

t_file 		*ft_sort_ascii(t_file *file)
{
	t_file *start;

	start = file;

	while(!ft_is_sort(start))
	{
		while(file->next)
		{
			if(ft_strcmp(file->name, file->next->name) > 0)
				ft_swap_lst(&file, &file->next);
			file = ft_sort_rev(file);
			file = file->next;
		}
		file = start;
	}	
	return (file);
}

t_file 		*ft_sort_lst(t_file *file, int ops)
{
	if(!CHECK_OPS(ops, T))
		file = ft_sort_ascii(file);
	else
	 	file = ft_sort_time(file);
	return (file);
}