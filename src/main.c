t_dirent 	*ft_get_dirent(DIR *rep)
{
	t_dirent 	*dirent;

	if(!(dirent = readdir(rep)))
	{
		perror("readdir :");
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

t_dir 	*ft_ls(t_dir *dir)
{
	DIR *rep;
	t_dirent *dirent;

	dir->lstdir = ft_new_lsr(NULL, NULL, 0);
	if(!rep = ft_get_dir(dir->name))
		return (NULL);
	while(dirent = ft_get_dirent(rep))
		dir->file = ft_add_file(dir->file, dirent->d_name, dir->name);
	if(dir->file)
		dir->file = ft_get_file(dir->file);
	ft_dispfile(dir->file);
	dir->lstdir = ft_lst_dir(dir->lstdir, dir);
	if(closedir(rep) == -1)
	{
		perror("closedir ");
			return (NULL);
	}
	dir->open = 1;
	return (dir);
}

int main(int ac, char **av)
{
	t_dir *dir;
	t_lsr *tmp;
	int r = 0;

	dir = ft_init_dir();
	ac = 1;
	tmp = NULL;
	if(av[1] == NULL)
		dir->name = "./";
	else
		dir->name = ft_strdup(av[1]);
	while(dir)
	{
		if (dir->open)
			dir = ft_ls(dir);
		if(r)
		{
			tmp = dir->lstdir;
			while(tmp)
			{
				if(!tmp->open && tmp->name)
				{	
					dir->next = ft_new_dir(tmp->name, tmp->path, tmp->open);
					dir->next->prev = dir;
					++tmpdir->open;
					break ;
				}
				else 
					tmp = tmp->next;
			}
		}
		if(!tmp)
			dir = dir->prev;
		else
			dir = dir->next;
	}
	return 0;
}