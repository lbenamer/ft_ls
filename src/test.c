#include "ft_ls.h"

char	*ft_get_right(size_t n)
{
	char *s;

	if(!(s = ft_strnew(10)))
		exit (0);

	s[0] = (S_IRUSR & n) ? 'r' : '-';
	s[1] = (S_IWUSR & n) ? 'w' : '-';
	s[2] = (S_IXUSR & n) ? 'x' : '-';
	s[3] = (S_IRGRP & n) ? 'r' : '-';
	s[4] = (S_IWGRP & n) ? 'w' : '-';
	s[5] = (S_IXGRP & n) ? 'x' : '-';
	s[6] = (S_IROTH & n) ? 'r' : '-';
	s[7] = (S_IWOTH & n) ? 'w' : '-';
	s[8] = (S_IXOTH & n) ? 'x' : '-';
	return (s);
}

char	*ft_mod_time(char *time)
{
	char **tab;
	char *ret;

	tab = ft_strsplit(time, ' ');
	tab[3][5] = '\0';
	ret = ft_joinstr(tab[2], 0, 4," ", tab[1], " ", tab[3]);
	return(ret);
}

void	ft_disp_file(t_file *file)
{
	if(file->name)
		while(file)
		{
			ft_printf("%s %4ld %s %s %8ld %s %s\n", file->right, file->nlinks, file->owner, file->group, file->size, file->time, file->name);
			file = file->next;
		}
		ft_printf("\n");
}
t_file		*ft_get_file(t_file *file)
{
	t_file 	*tmp;
	t_stat 	info;
	char 	*path_nm;
	t_pwd 	*pswd;
	t_grp 	*gid;

	tmp = file;
	while(tmp)
	{
		path_nm = ft_strjoin(tmp->path, tmp->name);

	//	printf("path_nm = %s\n", path_nm);
		if(stat(path_nm, &info) < 0)
		{
			perror("stat error ");
			tmp = tmp->next;
		//	return (NULL);
		}
		else
		{
		//	ft_printf("0\n");
			if(!(pswd = getpwuid(info.st_uid)))
				tmp->owner = "204";
			else
				tmp->owner = pswd->pw_name;
			gid = getgrgid(info.st_gid);
			// ft_printf("2\n");
			tmp->nlinks = info.st_nlink;
			// ft_printf("3\n");
			tmp->size = info.st_size;
			// ft_printf("5\n");
			tmp->group = gid->gr_name;
			// ft_printf("6\n");
			tmp->right = ft_get_right(info.st_mode);
			// ft_printf("7\n");
			tmp->time = ctime(&info.st_mtime);
			// ft_printf("8\n");
			tmp->time = ft_mod_time(tmp->time);
			// ft_printf("9\n");
			if(S_ISREG(info.st_mode))
				tmp->right = ft_strjoinf("-", tmp->right, 2);
			if(S_ISDIR(info.st_mode))
			{
				tmp->right = ft_strjoinf("d", tmp->right, 2);
				tmp->d = 1;
			}
			tmp = tmp->next;
		}
	}
	return (file);
}


void 	disp_file(t_file *file)
{
	while(file)
	{
		printf("file name = %s || file path =  %s\n", file->name, file->path);
		file = file->next;
	}
}

void	disp_dir(t_dir *dir)
{
	while(dir)
	{
		printf("dir name = %s || dir path =  %s\n", dir->name, dir->path);
		dir = dir->next;
	}
}


t_lsr 	*ft_new_lsr(char *name, char *path, int open)
{
	t_lsr *lsr;

	if(!(lsr = (t_lsr*)malloc(sizeof(t_lsr))))
		return (NULL);
	lsr->name = ft_strdup(name);
	lsr->path = ft_strdup(path);
	lsr->next = NULL;
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
	}
	return (lstdir);
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

void 	disp_lst(t_lsr *lst)
{
	while(lst)
	{
		printf("lstdir name = %s\n", lst->name);
		lst = lst->next;
	}

}

// int main(int ac, char **av)
// {
// 	DIR 		*rep;
// 	t_lsr 		*tmpdir;
// 	t_dir 		*dir;
// 	t_dirent 	*dirent;
// 	t_file		*tmpfile;

// 	dir = ft_init_dir();
// 	dir->lstdir = ft_new_lsr(NULL, NULL, 0);	// dir->file = ft_init_file();
// 	tmpfile = dir->file;
// 	ac = 1;
// 	if(av[1] == NULL)
// 		dir->name = "./";
// 	else
// 		dir->name = ft_strdup(av[1]);
// 	while(dir)
// 	{
// 		// printf("******\ndebut de boucle\n dir name = %s\n", dir->name);
// 		// printf("open->dir = %d\n", dir->open);
// 		//dir->lstdir = ft_init_dir();
// 		if(!dir->open)
// 		{
// 			//printf("open->dir = 0\n");
// 			printf("%s :\n", dir->name);
// 			dir->lstdir = ft_new_lsr(NULL, NULL, 0);
// 			if(!(rep = opendir(dir->name)))
// 			{
// 				perror("opendir :");
// 				dir = dir->next;
// 				//exit(-1);
// 			}
// 			else
// 			{
// 				dir->open = 1;
// 				if(!(dirent = readdir(rep)))
// 				{
// 					perror("readdir :");
// 					return(0);
// 				}
// 				while(dirent)
// 				{
// 					//printf("d_name = %s\n", dirent->d_name);
// 					//if(dirent->d_name[0] != '.')
// 						dir->file = ft_add_file(dir->file, dirent->d_name, dir->name);
// 				//	printf("2\n");
// 					// if(!(dir->file = ft_get_file(dir->file)))
// 					// 	return(0);
// 					dirent = readdir(rep);
// 				}
// 				if(dir->file)
// 					if(!(dir->file = ft_get_file(dir->file)))
// 					{		
// 						disp_file(dir->file);
// 						return(0);
// 					}
// 				ft_disp_file(dir->file);
// 				dir->lstdir = ft_lst_dir(dir->lstdir, dir);
// 				//disp_lst(dir->lstdir);
// 			}
// 			if(closedir(rep) == -1)
// 		 	perror("closedir ");
// 		} 
// 		//disp_lst(dir->lstdir);
// 		tmpdir = dir->lstdir;
// 		// printf("ok\n");
// 		while(tmpdir)
// 		{
// 			// printf("while\n");
// 			if(!tmpdir->open && tmpdir->name)
// 			{
// 			//	printf("dir->next = %s\n", tmpdir->name);
// 				//tmpdir->prev = dir;
// 				dir->next = ft_new_dir(tmpdir->name, tmpdir->path, tmpdir->open);
// 				dir->next->prev = dir;
// 				++tmpdir->open;
// 				break;
// 			}
// 			tmpdir = tmpdir->next;
// 			// printf("fin\n");
// 		}
// 		// printf("ok\n");
// 		if(!tmpdir)
// 		{
// 		 	// printf("prev\n");
// 			dir = dir->prev;
// 		}
// 		else
// 		{
// 			// printf("next\n");
// 			dir = dir->next;
// 		}
// 		// printf("Fin de boucle \n ********\n");
// 	}
// 	return 0;
// }

t_dirent 	*ft_get_dirent(DIR *rep)
{
	t_dirent 	*dirent;

	if(!(dirent = readdir(rep)))
	{
		//perror("readdir :");
		return(NULL);
	}
	return (dirent);
}


DIR 	*ft_get_dir(char *name)
{
	DIR *rep;

	if(!(rep = opendir(name)))
	{
		perror("opendir");
		return (NULL);
	}
	return (rep);
}

int 	ft_ls(t_dir **dir)
{
	DIR *rep;
	t_dirent *dirent;
	t_dir *dir2;

	dir2 = *dir;

	dir2->lstdir = ft_new_lsr(NULL, NULL, 0);
	if(!(rep = ft_get_dir(dir2->name)))
		return (0);
	while((dirent = ft_get_dirent(rep)) != NULL)
		dir2->file = ft_add_file(dir2->file, dirent->d_name, dir2->name);
	if(dir2->file)
		dir2->file = ft_get_file(dir2->file);
	ft_printf("%s :\n", dir2->name);
	ft_disp_file(dir2->file);
	dir2->lstdir = ft_lst_dir(dir2->lstdir, dir2);
	if(closedir(rep) == -1)
	{
		perror("closedir ");
			return (0);
	}
	dir2->open = 1;
	return (1);
}

void ft_free_dir(t_dir **dir)
{
	//ft_strdel(&(*dir)->name);
	//ft_strdel(&(*dir)->path);
	free(*dir);
}

int main(int ac, char **av)
{
	t_dir *dir;
	t_lsr *tmp;
	t_parse parse;

	dir = ft_init_dir();
	tmp = NULL;

	if(ac == 1)
		parse = ft_no_parse();
	else
		parse = ft_parse(av, ac);
	print_ops(parse.ops);
	disp_parse(parse);
	dir->name = ft_strdup(parse.path[0]);
	while(dir)
	{
		//printf("dir name = %s\n", dir->name);
		if (!dir->open)
			ft_ls(&dir);
		if((CHECK_OPS(parse.ops, RR)) && dir)
		{
	//		printf("r\n");
			tmp = dir->lstdir;
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
		}
	//	printf("heu\n");
		if(!tmp)
		{	
	//		printf("prev\n");
		//	printf("dir prev = %s\n", dir->prev->name);
			
			//ft_free_dir(&dir);
			dir = dir->prev;
		}
		else
		{
			//ft_printf("%s :\n", dir->next->name);
			dir = dir->next;
		}
	}
	return 0;
}
