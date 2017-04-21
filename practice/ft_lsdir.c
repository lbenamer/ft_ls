#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void perror(const char* str);
typedef struct dirent t_dir;
typedef struct stat t_stat;
typedef struct passwd 	t_pwd;
typedef struct group t_grp;



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

int	ft_get_info(char *file, t_stat *info)
{
	t_pwd *pswd;
	t_grp *gid;
	size_t oct;
	char *right;
	char *time;

	stat(file, info);
	pswd = getpwuid(info->st_uid);
	gid = getgrgid(info->st_gid);
	time = ctime(&info->st_mtime);
	time = ft_mod_time(time);
	right = ft_get_right(info->st_mode);
	if(S_ISREG(info->st_mode))
	{
		right = ft_strjoinf("-", right, 2);
	//	ft_printf("type : fichier\n");
	}
	if(S_ISDIR(info->st_mode))
	{
		right = ft_strjoinf("d", right, 2);
	//	ft_printf("type : repertoir\n");
	}
	// ft_printf("size = %ld octet\n", (long)info->st_size);
	// ft_printf("Last mod:  %s\n", time);
	// ft_printf("proprio = %s\n", pswd->pw_name);
	// ft_printf("group = %s \n", gid->gr_name);
	// ft_printf("Nb liens = %ld\n", (long) info->st_nlink);
	// ft_printf("Mode : %ld (deci)\n", (unsigned long)info->st_mode);
	// ft_printf("right = %s\n} \n", right);

	ft_printf("%s %4ld %s %s %8ld %s %s\n", right, info->st_nlink, pswd->pw_name, gid->gr_name, info->st_size, time, file);
	return (1);
}


int	main(int ac, char **av)
{
	DIR *rep;
	t_dir *file;
	char *error;
	t_stat info;
	char *name;

	if(av[1] == NULL)
		av[1] = "./";
	rep = opendir(av[1]);
	error = ft_joinstr("ls: ",0, 1,av[1]);
	if(!rep)
	{
		perror(error);
		(exit(-1));
	}
	file = readdir(rep);
	ft_printf("@\n");
	while(file)
	{
		//if(file->d_name[0] != '.')
		//{
			name = ft_strjoin(av[1], file->d_name);
			//ft_printf("name  = %s\n{\n", name);
			ft_get_info(name, &info);
	//		ft_printf("Propriétaires : UID=%ld   GID=%ld\n", (long) info.st_uid, (long) info.st_gid);
		//}
		file = readdir(rep);
	}
	//ft_printf("\n");
	if(closedir(rep) == -1)
		perror("");
	return 0;
}