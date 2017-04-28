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

		if(stat(path_nm, &info) < 0)
		{
			perror("stat error ");
			tmp = tmp->next;
		}
		else
		{
			if(!(pswd = getpwuid(info.st_uid)))
				tmp->owner = "204";
			else
				tmp->owner = pswd->pw_name;
			gid = getgrgid(info.st_gid);
			tmp->nlinks = info.st_nlink;
			tmp->size = info.st_size;
			tmp->group = gid->gr_name;
			tmp->right = ft_get_right(info.st_mode);
			tmp->time = ctime(&info.st_mtime);
			tmp->time = ft_mod_time(tmp->time);
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

char	*ft_mod_time(char *time)
{
	char **tab;
	char *ret;

	tab = ft_strsplit(time, ' ');
	tab[3][5] = '\0';
	ret = ft_joinstr(tab[2], 0, 4," ", tab[1], " ", tab[3]);
	return(ret);
}
