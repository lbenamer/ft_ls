#include "ft_ls.h"

t_dir  *ft_init_dir(void)
{
	t_dir *dir;

	if(!(dir = (t_dir*)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	dir->name = NULL;
	dir->path = NULL;
	dir->file = ft_init_file();
	dir->next = NULL;
	dir->prev = NULL;
	dir->lstdir = NULL;
	dir->open = 0;
	return (dir);
}


t_file *ft_init_file(void)
{
	t_file *file;

	if(!(file = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->name = NULL;
	file->path = NULL;
	file->group = NULL;
	file->owner = NULL;
	file->time = NULL;
	file->right = NULL;
	file->size = 0;
	file->nlinks = 0;
	file->d = 0;
	file->prev = NULL;
	file->next = NULL;
	return (file);
}

t_file *ft_new_file(char *name, char *path)
{
	t_file *file;

	if(!(file = ft_init_file()))
		return(NULL);
	file->name = ft_strdup(name);
	file->path = ft_strdup(path);
	return (file);
}

t_file *ft_add_file(t_file *file, char *name, char *path)
{
	t_file *tmp;

	tmp = file;
	if(!file->name)
	{
		file->name = ft_strdup(name);
		file->path = ft_strdup(path);
		return(file);
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_file(name, path);
	}
	return (file);
}

t_dir	*ft_new_dir(char *name, char *path)
{
	t_dir *dir;

	if(!(dir = ft_init_dir()))
		return (NULL);
	dir->name = ft_strdup(name);
	dir->path = ft_strdup(path);
	return (dir);
}

t_dir	*ft_add_dir(t_dir *dir, char *name, char *path)
{
	t_dir *tmp;

	tmp = dir;
	//printf("hey 1\n");
	if(!dir->name)
	{
		dir->name = ft_strdup(name);
		dir->path = ft_strdup(path);
	//	printf("hey 3\n");
		return (dir);
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_dir(name, path);
		tmp->next->prev = tmp;
	}
	return (dir);
}