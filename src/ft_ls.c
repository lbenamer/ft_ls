#include "ft_ls.h"

void 	ft_free_lsr(t_lsr **lsr)
{
	if((*lsr)->name)
		while((*lsr))
		{
			ft_strdel(&(*lsr)->name);
			ft_strdel(&(*lsr)->path);
			free(*lsr);
			*lsr = (*lsr)->next;
		}
}

void 	ft_free_file(t_file **file)
{
		while((*file))
		{
			if((*file)->name)
			{	
				// printf("file name del = %s\n", (*file)->name);
				ft_strdel(&(*file)->name);
			 	ft_strdel(&(*file)->path);
				ft_strdel(&(*file)->time);
				ft_strdel(&(*file)->right);
				free(*file);
			}
			*file = (*file)->next;
		}
}

void 	ft_freezer(t_dir **dir)
 {
	ft_free_file(&(*dir)->file);
 	ft_free_lsr(&(*dir)->lstdir);
	 // ft_free_file(&(*dir)->file);
	 // ft_free_lsr(&(*dir)->lstdir);
	ft_strdel(&(*dir)->name);
	ft_strdel(&(*dir)->path);
	free(*dir);
}

t_lsr 	*ft_lst_dir(t_lsr *lstdir, t_dir *dir)
{
	char *tmp;
	t_file *file;

	tmp = NULL;
	file = dir->file;
	while(file)
	{
		if(ft_strcmp(file->name, ".") && file->type == 'd' && ft_strcmp(file->name, ".."))
		{
			tmp = ft_strjoin(dir->name, file->name);
			tmp = ft_strjoinf(tmp, "/", 1);
			lstdir = ft_add_lsr(lstdir, tmp, dir->name);
			ft_strdel(&tmp);
		}
		file = file->next;
	}
	return (lstdir);
}

int		ft_lsdir(char *name, int ops)
{	
	t_dir 	*dir;
	t_lsr 	*tmp;
	int 	ls;

	dir = ft_init_dir();
	tmp = NULL;
	dir->name = name;
	while(dir)
	{
		ls = 1;
		if (!dir->open)
			ls = ft_ls(&dir, ops);
		if((CHECK_OPS(ops, RR)) && dir && ls)
		{
			tmp = dir->lstdir;
			if(CHECK_OPS(ops, R))
				while(tmp->next)
					tmp = tmp->next;
			while(tmp)
			{
				if(!tmp->open && tmp->name)
				{	
					dir->next = ft_new_dir(tmp->name, tmp->path, tmp->open);
					dir->next->prev = dir;
					++tmp->open;
					break ;
				}
				if(CHECK_OPS(ops, R))
					tmp = tmp->prev;
				else
					tmp = tmp->next;
			}
		}
		if(!tmp || !ls)
		{
			ft_freezer(&dir);
			//ft_printf("dir del = %s\n", dir->name);
			dir = dir->prev;
		}
		else
		{
			dir->next ? ft_printf("\n") : 0;
			dir = dir->next;
		}
	}
	return (1);
}

int 	ft_ls(t_dir **dir, int ops)
{
	DIR *rep;
	t_dirent *dirent;
	t_dir *dir2;

	dir2 = *dir;
	//char type;
	dir2->lstdir = ft_new_lsr(NULL, NULL, 0);
	if(!(rep = ft_get_dir(dir2->name)))
		return (0);
	while((dirent = ft_get_dirent(rep)) != NULL)
	{
		//type = ft_get_type(dirent->d_type);
		if(CHECK_OPS(ops, A))
			dir2->file = ft_add_file(dir2->file, dirent->d_name, dir2->name, 0);
		else
			if(dirent->d_name[0] != '.')
				dir2->file = ft_add_file(dir2->file, dirent->d_name, dir2->name, 0);
	}
	if(!dir2->file->name)
	{
		closedir(rep);
		return (0);
	}
	if(CHECK_OPS(ops, L) || CHECK_OPS(ops, T) || CHECK_OPS(ops, G) || CHECK_OPS(ops, RR))	
		dir2->file ? dir2->file = ft_get_file(dir2->file, ops) : 0;
	dir2->file = ft_sort_lst(dir2->file, ops);
	dir2->prev ? ft_printf("%s :\n", dir2->name) : 0;
	ft_disp_file(dir2->file, ops);
	CHECK_OPS(ops, RR) ? dir2->lstdir = ft_lst_dir(dir2->lstdir, dir2) : 0;
	//ft_disp_file(dir2->file, ops);
	closedir(rep);
	dir2->open = 1;
	free(dirent);
	return (1);
}
