#include "ft_ls.h"

void 	ft_free_lsr(t_lsr **lsr)
{
	if((*lsr)->name)
		while((*lsr))
		{
			ft_strdel(&(*lsr)->name);
			ft_strdel(&(*lsr)->path);
			*lsr = (*lsr)->next;
		}
	free(*lsr);
}

void 	ft_free_file(t_file **file)
{
	if((*file)->name)
		while((*file))
		{
			ft_strdel(&(*file)->name);
			ft_strdel(&(*file)->path);
			ft_strdel(&(*file)->time);
			ft_strdel(&(*file)->right);
			*file = (*file)->next;
		}
	free(*file);
}

void 	ft_freezer(t_dir **dir)
{
	ft_strdel(&(*dir)->name);
	ft_strdel(&(*dir)->path);
	(*dir)->file ? ft_free_file(&((*dir)->file)) : 0;
	(*dir)->lstdir ? ft_free_lsr(&(*dir)->lstdir) : 0;
	free(*dir);
}

t_lsr 	*ft_lst_dir(t_lsr *lstdir, t_dir *dir)
{
	char *tmp;

	tmp = NULL;
	while(dir->file)
	{
		if(ft_strcmp(dir->file->name, ".") && dir->file->d == 1 && ft_strcmp(dir->file->name, ".."))
		{
			tmp = ft_strjoin(dir->name, dir->file->name);
			tmp = ft_strjoin(tmp, "/");
			lstdir = ft_add_lsr(lstdir, tmp, dir->name);
		}
		dir->file = dir->file->next;
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
		//printf("dir name = %s\n", dir->name);
		ls = 1;
		if (!dir->open)
			ls = ft_ls(&dir, ops);
		if((CHECK_OPS(ops, RR)) && dir && ls)
		{
			tmp = dir->lstdir;
			if(!CHECK_OPS(ops, R))
				while(tmp)
				{
					if(!tmp->open && tmp->name)
					{	
						dir->next = ft_new_dir(tmp->name, tmp->path, tmp->open);
						dir->next->prev = dir;
						++tmp->open;
						break ;
					}
					else 
						tmp = tmp->next;
				}
			else
			{
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
					else 
						tmp = tmp->prev;
				}
			}
		}
		if(!tmp || !ls)
		{
			 ft_freezer(&dir);   //dir->prev ? printf("prev = %s\n", dir->prev->name) : printf("NULL\n");
			dir = dir->prev;
		}
		else
		{
		//	dir->next ?	ft_printf("next = %s\n", dir->next->name) : printf("NULL\n");
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
	//printf("open file\n");
	dir2->lstdir = ft_new_lsr(NULL, NULL, 0);
	if(!(rep = ft_get_dir(dir2->name)))
		return (0);
	while((dirent = ft_get_dirent(rep)) != NULL)
	{
		if(CHECK_OPS(ops, A))
			dir2->file = ft_add_file(dir2->file, dirent->d_name, dir2->name);
		else
			if(dirent->d_name[0] != '.')
				dir2->file = ft_add_file(dir2->file, dirent->d_name, dir2->name);
	}
	if(!dir2->file->name)
	{
		closedir(rep);
		return (0);
	}
	if(CHECK_OPS(ops, L) || CHECK_OPS(ops, RR) || CHECK_OPS(ops, T))
		if(dir2->file)
			dir2->file = ft_get_file(dir2->file);
	dir2->file = ft_sort_lst(dir2->file, ops);
	if(dir2->prev)
		ft_printf("%s :\n", dir2->name);
	if(CHECK_OPS(ops, L))
		ft_disp_file(dir2->file, ops);
	else
		ft_disp_name(dir2->file, ops);
	CHECK_OPS(ops, RR) ? dir2->lstdir = ft_lst_dir(dir2->lstdir, dir2) : 0;
	// if(closedir(rep) == -1)
	// {
	// 	perror("closedir ");
	// 		return (0);
	// }
	closedir(rep);
	dir2->open = 1;
	return (1);
}
