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

int	ft_get_info(char *file, t_stat *info)
{
	t_pwd *pswd;
	t_grp *gid;

	stat(file, info);
	pswd = getpwuid(info->st_uid);
	gid = getgrgid(info->st_gid);
	ft_printf("size = %ld octet\n", (long)info->st_size);
	ft_printf("Last mod:  %s", ctime(&info->st_mtime));
	ft_printf("proprio = %s\n", pswd->pw_name);
	ft_printf("group = %s \n", gid->gr_name);
	ft_printf("Nb liens = %ld\n", (long) info->st_nlink);
	if(S_ISREG(info->st_mode))
		ft_printf("type : fichier\n");
	if(S_ISDIR(info->st_mode))
		ft_printf("type : repertoir\n");
	ft_printf("Mode : %lo (octal)\n} \n", (unsigned long)info->st_mode);

	return (1);
}


int	main(int ac, char **av)
{
	DIR *rep;
	t_dir *file;
	char *error;
	t_stat info;

	if(av[1] == NULL)
		av[1] = ".";
	rep = opendir(av[1]);
	error = ft_joinstr("ls: ",0, 1,av[1]);
	if(!rep)
	{
		perror(error);
		(exit(-1));
	}
	file = readdir(rep);
	while(file)
	{
		if(file->d_name[0] != '.')
		{

			ft_printf("name  = %s\n{\n", file->d_name);
			ft_get_info(file->d_name, &info);
	//		ft_printf("Propriétaires : UID=%ld   GID=%ld\n", (long) info.st_uid, (long) info.st_gid);
		}
		file = readdir(rep);
	}
	//ft_printf("\n");
	if(closedir(rep) == -1)
		perror("");
	return 0;
}