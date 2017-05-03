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

char 	ft_get_type(unsigned char type)
{
	if (type == DT_BLK)
		return('b');
	else if (type == DT_CHR)
		return('c');
	else if (type == DT_DIR)
		return('d');
	else if (type == DT_FIFO)
		return('p');
	else if (type == DT_LNK)
		return('l');
	else if (type == DT_REG)
		return('-');
	else if (type == DT_SOCK)
		return('s');
	else if (type == DT_UNKNOWN)
		return('-');
	else
		return ('-');
}

char 	*ft_get_link(size_t size, char *path)
{
	char *buf;

	buf = ft_strnew(size);
	readlink(path, buf, size);
	return (buf);
}

t_file 		*ft_get_info(t_file *file, t_stat info, int ops)
{
	t_pwd *pswd;
	t_grp *gid;

	if(CHECK_OPS(ops, L))
	{
		if(!(pswd = getpwuid(info.st_uid)))
			file->owner = "204";
		else
			file->owner = pswd->pw_name;
		gid = getgrgid(info.st_gid);
		file->nlinks = info.st_nlink;
		file->size = info.st_size;
		file->group = gid->gr_name;
		file->right = ft_get_right(info.st_mode);
		file->stime = info.st_mtime;
		file->block = info.st_blocks;
		file->time = ctime(&info.st_mtime);
		file->time = ft_mod_time(file->time);
	}
	if(CHECK_OPS(ops, T))
		file->stime = info.st_mtime;
	return (file);
}


t_file		*ft_get_file(t_file *file, int ops)
{
	t_file 	*tmp;
	t_stat 	info;
	char 	*path_nm;

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
			if(tmp->type == 'l')
			{
				lstat(path_nm, &info);
				tmp->link = ft_get_link(info.st_size, path_nm);
			}
			tmp = ft_get_info(tmp, info, ops);
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
