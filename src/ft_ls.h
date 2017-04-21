#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct dirent 	t_dirent;
typedef struct stat 	t_stat;
typedef struct passwd 	t_pwd;
typedef struct group 	t_grp;

typedef struct 			s_file
{
	char 			*name;
	char 			*path;
	char 			*group;
	char			*owner;
	char 			*time;
	char 			*right;
	size_t 			size;
	size_t 			nlinks;
	struct s_file 	*prev;
	struct s_file 	*next;
}						t_file;

typedef	struct			s_dir
{
	char 			*name;
	char 			*path;
	t_file 			*file;
	struct s_dir 	*next;
}						t_dir;


void perror(const char* str);
t_file *ft_init_file(void);
t_dir  *ft_init_dir(void);
t_file *ft_new_file(char *name, char *path);
t_file *ft_add_file(t_file *file, char *name, char *path);


#endif