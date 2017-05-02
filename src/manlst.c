#include "ft_ls.h"

t_file *ft_new_file(char *name, char *path, char type)
{
	t_file *file;

	if(!(file = ft_init_file()))
		return(NULL);
	file->name = ft_strdup(name);
	file->path = ft_strdup(path);
	file->type = type;
	return (file);
}

t_file *ft_add_file(t_file *file, char *name, char *path, char type)
{
	t_file *tmp;

	tmp = file;
	if(!file->name)
	{
		file->name = ft_strdup(name);
		file->path = ft_strdup(path);
		file->type = type;
		return(file);
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_file(name, path, type);
		tmp->next->prev = tmp;
	}
	return (file);
}

t_dir	*ft_new_dir(char *name, char *path, int open)
{
	t_dir *dir;

	if(!(dir = ft_init_dir()))
		return (NULL);
	dir->name = ft_strdup(name);
	dir->path = ft_strdup(path);
	dir->open = open;
	return (dir);
}

t_dir	*ft_add_dir(t_dir *dir, char *name, char *path, int open)
{
	t_dir *tmp;

	tmp = dir;
	//printf("hey 1\n");
	if(!dir->name)
	{
		dir->name = ft_strdup(name);
		dir->path = ft_strdup(path);
		dir->open = open;
	//	printf("hey 3\n");
		return (dir);
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_dir(name, path, open);
		tmp->next->prev = tmp;
	}
	return (dir);
}

t_lsr 	*ft_new_lsr(char *name, char *path, int open)
{
	t_lsr *lsr;

	if(!(lsr = (t_lsr*)malloc(sizeof(t_lsr))))
		return (NULL);
	lsr->name = ft_strdup(name);
	lsr->path = ft_strdup(path);
	lsr->next = NULL;
	lsr->prev = NULL;
	lsr->open = open;
	return (lsr);
}

t_lsr 	*ft_add_lsr(t_lsr *lstdir, char *name, char *path)
{

	t_lsr *tmp;

	tmp = lstdir;
	if(!lstdir->name)
	{
		lstdir->name = ft_strdup(name);
		lstdir->path = ft_strdup(path);
		return (lstdir);
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_lsr(name, path, 0);
		tmp->next->prev = tmp;
	}
	return (lstdir);
}