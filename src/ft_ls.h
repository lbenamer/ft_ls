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
# define F  32
# define G 	64

# define STOP		"\033[00m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32;01m"
# define YELLOW		"\033[33;01m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36;01m"
# define WHITE		"\033[37m"

typedef	struct	dirent	t_dirent;
typedef	struct	stat	t_stat;
typedef	struct	passwd	t_pwd;
typedef	struct	group	t_grp;

typedef struct			s_file
{
	char			*name;
	char			*path;
	char			*group;
	char			*owner;
	char			*time;
	char			*right;
	char 			*link;
	char 			type;
	size_t			size;
	size_t 			slink;
	size_t			nlinks;
	size_t 			stime;
	size_t			block;
	struct s_file	*prev;
	struct s_file	*next;
}						t_file;

typedef struct			s_lsr
{
	char			*name;
	char			*path;
	int				open;
	struct s_lsr	*next;
	struct s_lsr 	*prev;
} 						t_lsr;

typedef	struct			s_dir
{
	char			*name;
	char			*path;
	int				open;
	t_file			*file;
	struct s_dir	*next;
	struct s_dir	*prev;
	t_lsr			*lstdir;
}						t_dir;

typedef struct			s_parse
{
	char	**path;
	int		ops;
}						t_parse;

typedef struct 			s_size
{
	size_t a;
	size_t b;
	size_t c;
	size_t d;
	size_t e;
}						t_size;

// sort_list.c
t_file					*ft_sort_lst(t_file *file, int ops);
t_file					*ft_sort_ascii(t_file *file);
void					ft_swap_lst(t_file **a, t_file **b);
t_file					*ft_is_sort(t_file *file);
// ft_ls.c :
int						ft_lsdir(char *name, int ops);
int						ft_ls(t_dir **dir, int ops);
t_lsr					*ft_lst_dir(t_lsr *lstdir, t_dir *dir);
// parse.c :
t_parse					ft_parse(char **av, int ac);
char					**ft_set_path(char **av, int ac, int i);
int 					ft_activ_ops(int ops, char *arg);
void					ft_disp_usage(char *arg);
t_parse					ft_no_parse(void);

// manlst.c :
t_file					*ft_new_file(char *name, char *path, char type);
t_file					*ft_add_file(t_file *file, char *name, char *path, char type);
t_dir					*ft_new_dir(char *name, char *path, int open);
t_dir					*ft_add_dir(t_dir *dir, char *name, char *path, int open);
t_lsr					*ft_new_lsr(char *name, char *path, int open);
t_lsr					*ft_add_lsr(t_lsr *lstdir, char *name, char *path);

// get.c :
char					*ft_get_right(size_t n);
t_file					*ft_get_file(t_file *file, int ops);
t_dirent				*ft_get_dirent(DIR *rep);
DIR						*ft_get_dir(char *name);
char					*ft_mod_time(char *time);
char 					ft_get_type(t_stat info);

// init.c :
t_parse					ft_init_parse(void);
t_dir					*ft_init_dir(void);
t_file					*ft_init_file(void);
int						ft_check_options(char *arg);
int						ft_isops(char c);
t_size 					ft_init_size(void);

// print.c :
 t_size  	ft_get_size(t_file *file);
t_size 		ft_get_max(t_file *file, t_size size);
size_t 		ft_nblen(long n);
 char 	*ft_make_str(t_size size);

// main.c :
void disp(t_file *file);
void					ft_disp_name(t_file *file, int ops);
void					ft_disp_file(t_file *file, int ops);
#endif
