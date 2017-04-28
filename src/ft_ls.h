#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include <stdio.h>

# define CHECK_OPS(var, pos)	(var & pos)
# define L	1
# define A	2
# define R	4
# define T	8
# define RR	16


typedef struct dirent 	t_dirent;
typedef struct stat 	t_stat;
typedef struct passwd 	t_pwd;
typedef struct group 	t_grp;

typedef struct			s_file
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

typedef struct			s_lsr
{
	char			*name;
	char 			*path;
	int 			open;
	struct s_lsr 	*next;
} 						t_lsr;

typedef	struct			s_dir
{
	char 			*name;
	char 			*path;
	int 			open;
	t_file 			*file;
	struct s_dir 	*next;
	struct s_dir 	*prev;
	t_lsr 			*lstdir;
}						t_dir;

typedef struct 			s_parse
{
	char 	**path;
	int 	ops;
}						t_parse;

void perror(const char* str);
t_file *ft_init_file(void);
t_dir  *ft_init_dir(void);
t_file *ft_new_file(char *name, char *path);
t_file *ft_add_file(t_file *file, char *name, char *path);
t_dir	*ft_add_dir(t_dir *dir, char *name, char *path, int open);
t_dir	*ft_new_dir(char *name, char *path, int open);

//parse//

void disp_parse(t_parse parse);
t_parse   ft_parse(char **av, int ac);
char  	**ft_set_path(char **av, int ac, int i);
int  ft_activ_ops(int ops, char *arg);
void	ft_disp_usage(char *arg);
int 	ft_check_options(char *arg);
int 	ft_isops(char c);
t_parse  ft_init_parse(void);
void	print_ops(int ops);
t_parse ft_no_parse(void);


#endif
