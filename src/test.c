#include "ft_ls.h"

char	*ft_conv_right(char c)
{
	char 	*right;
	int 	n;
	
	n = c - 48;
	if(n == 1)
		right = "--x";
	else if (n == 1 + 2)
		right = "-wx";
	else if(n == 1 + 2 + 4)
		right = "rwx";
	else if(n == 1 + 4)
		right = "r-x";
	else if(n == 2 + 4)
		right = "rw-";
	else if(n == 2)
		right = "-w-";
	else if(n == 4)
		right = "r--";
	return (right);
}

char	*ft_get_right(size_t n)
{
	char 	*tmp;
	char 	*tmp2;
	char 	*right;
	int		i;

	if(!(right = (char*)ft_memalloc(sizeof(char))))
		return (NULL);
	tmp = ft_utoa_base(n, 8);
	tmp = ft_strsub_f(tmp,ft_strlen_p(tmp) - 3, 3);
	i = -1;
	//ft_printf("right =  %s\n", right);
	while(tmp[++i])
	{
		tmp2 = ft_conv_right(tmp[i]);
		right = ft_strjoinf(right, tmp2, 1);
	}
	return (right);
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
		stat(path_nm, &info);
		pswd = getpwuid(info.st_uid);
		gid = getgrgid(info.st_gid);
		tmp->nlinks = info.st_nlink;
		tmp->size = info.st_size;
		tmp->owner = pswd->pw_name;
		tmp->group = gid->gr_name;
		tmp->right = ft_get_right(info.st_mode);
		tmp->time = ctime(&info.st_mtime);
		tmp->time = ft_mod_time(tmp->time);
		if(S_ISREG(info.st_mode))
			tmp->right = ft_strjoinf("-", tmp->right, 2);
		if(S_ISDIR(info.st_mode))
			tmp->right = ft_strjoinf("d", tmp->right, 2);
		tmp = tmp->next;
	}
	return (file);
}

int main(int ac, char const **av)
{	
	DIR 		*rep;
	t_dir 		*dir;
	t_dirent 	*dirent;
	char 		*path;

	dir = ft_init_dir();
	dir->file = ft_init_file();

	if(av[1] == NULL)
		dir->name = "./";
	else
		dir->name = ft_strdup(av[1]);
	while(dir)
	{
		if(!(rep = opendir(dir->name)))
		{
			perror("");
			exit(-1);
		}
		dirent = readdir(rep);
		while(dirent)
		{
			dir->file = ft_add_file(dir->file, dirent->d_name, dir->name);
			dirent = readdir(rep);
		}
		dir->file = ft_get_file(dir->file);
		ft_disp_file(dir->file);
		dir = dir->next;
	}
	return 0;
}



























