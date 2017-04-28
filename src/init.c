#include "ft_ls.h"

t_parse  ft_init_parse(void)
{
	t_parse parse;

	parse.path = NULL;
	parse.ops = 0;
	return (parse);
}

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