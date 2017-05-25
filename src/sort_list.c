#include "ft_ls.h"

t_file 	*ft_is_sort(t_file *file)
{
	while(file->next)
	{
		if(ft_strcmp(file->name, file->next->name) < 0)
			file = file->next;
		else
			return (file);
	}
	return (NULL);
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
	new->type = file->type;
	new->block = file->block;
	new->link = file->link;                         
}

void		ft_swap_lst(t_file **a, t_file **b)
{
	t_file *tmp;

	tmp = ft_init_file();
	ft_cpy_data(&tmp, *a);
	ft_cpy_data(a, *b);
	ft_cpy_data(b,tmp);	
	free(tmp);
}

t_file 		*ft_is_sort_t(t_file *file)
{
	while(file->next)
	{
		if(file->stime >= file->next->stime)
			file = file->next;
		else 
			return (file);
	}
	return (NULL);
}

t_file 	 	*ft_sort_time(t_file *file)
{
	t_file *start;

	start = file;
	while((file = ft_is_sort_t(start)) != NULL)
	{
		while(file->next)
		{
			if(file->stime < file->next->stime)
				ft_swap_lst(&file, &file->next);
			file = file->next;
		}
	}	
	return (start);
}

t_file 		*ft_sort_ascii(t_file *file)
{
	t_file *start;

	start = file; 
	while((file = ft_is_sort(start)) != NULL)
	{
		while(file->next)
		{
			if(ft_strcmp(file->name, file->next->name) > 0)
 				ft_swap_lst(&file, &file->next);
 			file = file->next;
		}
	}
	return (start);
}

t_file 		*ft_sort_lst(t_file *file, int ops)
{
	if(CHECK_OPS(ops, F))
		return (file);
	else if(!CHECK_OPS(ops, T))
		file = ft_sort_ascii(file);
	else
	 	file = ft_sort_time(file);
	return (file);
}