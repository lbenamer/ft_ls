#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include <stdio.h>

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
	int 			d;
	struct s_file 	*prev;
	struct s_file 	*next;
}						t_file;

typedef	struct			s_dir
{
	char 			*name;
	char 			*path;
	int 			open;
	t_file 			*file;
	struct s_dir 	*next;
	struct s_dir 	*prev;
	struct s_dir	*lstdir;
}						t_dir;

typedef struct 			s_parse
{
	char 	**path;
	int 	l;
	int  	a;
	int  	R;
	int  	r;
	int  	t;
}						t_parse;

void perror(const char* str);
t_file *ft_init_file(void);
t_dir  *ft_init_dir(void);
t_file *ft_new_file(char *name, char *path);
t_file *ft_add_file(t_file *file, char *name, char *path);
t_dir	*ft_add_dir(t_dir *dir, char *name, char *path);
t_dir	*ft_new_dir(char *name, char *path);


#endif