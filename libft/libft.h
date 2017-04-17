/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:44 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 00:27:23 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_flags
{
	int		plus;
	int		less;
	int		space;
	int		hstg;
	int		zero;
}					t_flags;

typedef	struct		s_ops
{
	char	*flags;
	char	*modif;
	int		chp;
	int		precis;
	char	conv;
}					t_ops;

typedef struct		s_print
{
	char	*ops;
	char	*argst;
	void	*arg;
	int		start;
	int		i;
	int		ret;
	int		nl;
}					t_print;

typedef struct		s_mod
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	j;
	int	z;
}					t_mod;

typedef	struct		s_uni
{
	char	*bnr;
	char	*tmp;
	char	*mask;
}					t_uni;

int					get_next_line(int fd, char **line);
void				ft_print_int_tab(int **tab, size_t size, size_t len);
void				ft_printstab(char **tab);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char*));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_swap(int *a, int *b);
void				ft_swap_c(char *a, char *b);

int					ft_putstr(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					**ft_malloctab(size_t size, size_t len);

size_t				ft_strlen(const char *s);
size_t				ft_strlen_p(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_size_tab(char **tab);

char				*ft_realloc(char *tab, size_t size);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *s, char c);
char				*ft_strtrim(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strsub(const char *s1, unsigned int start, size_t len);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
char				*ft_strjoinf(char *s1, char *s2, int f);
char				*ft_strrev(char *str);
char				*ft_litoa(long n);
char				*ft_utoa_hexmin(size_t n);
char				*ft_utoa(size_t n);
char				*ft_utoa_oct(size_t n);
char				*ft_utoa_x(size_t n);
char				*ft_strsub_f(char *s1, size_t start, size_t len);

char				*ft_make_print(t_print p, char *fmt, int i, int *start);
char				*ft_joinstr(char *str, int free, int nb, ...);
int					ft_printf(char *fmt, ...);
char				*ft_sv_flags(char *ops);
char				*ft_fixops(void *arg, t_flags f, t_ops sv, t_mod mod);
t_ops				ft_disp_ops(char *ops);
char				*ft_sv_ops(char *fmt);
char				*ft_sv_modif(char *ops);
int					ft_isconv(int c);
int					ft_isflag(char c);
int					ft_sv_chp(char *ops);
int					ft_sv_precis(char *ops);
int					ft_ismodif(char c);
char				ft_sv_conv(char *ops);
char				*ft_make_argst(char *ops, void *arg);
char				*ft_conv(t_ops sv, void *arg, t_mod mod);
t_flags				ft_check_flags(char *flags);
char				*ft_unsgd_fgchp(char *agst, t_flags fg, int chp, int pr);
char				*ft_strset(char c, size_t len);
char				*ft_unsgd_precis(char *argst, int precis);
char				*ft_sgd_fgchp(char *argst, t_flags f, int chp, int precis);
char				*ft_sgd_precis(char *args, int precis);
t_mod				ft_check_modif(char *modif);
char				*ft_oct_fgchp(char *argst, t_flags fg, int chp, int precis);
char				*ft_x_fgchp(char *argst, t_flags fg, int chp, int precis);
char				*ft_fixops_oct(char *argst, t_flags fg, t_ops sv);
char				*ft_fixops_d(char *argst, t_flags fg, t_ops sv, void *arg);
char				*ft_fixops_x(char *arst, t_flags fg, t_ops sv);
char				*ft_s_precis(char *argst, int precis);
char				*ft_s_fgchp(char *argst, t_flags fg, int chp);
char				*ft_fixops_s(char *argst, t_flags fg, t_ops sv);
char				*ft_conv_pc(t_mod mod, void *arg);
char				*ft_strupper(char *str);
int					ft_putprint(char *fmt, t_print p, int i, int *start);
int					ft_bnrdeci(char *bnr);
char				*ft_utoa_base(size_t n, size_t base);
char				*ft_chosemask(char *bnr);
char				*ft_apmask(char *mask, char *bnr);
char				*ft_getwchar(int c);
char				*ft_getwstr(int *ws);
char				*ft_conv_s(t_mod mod, void *arg);
char				*ft_conv_x(t_mod mod, void *arg);
char				*ft_conv_u(t_mod mod, void *arg);
char				*ft_conv_o(t_mod mod, void *arg);
char				*ft_conv_p(t_mod mod, void *arg);
char				*ft_conv_c(t_mod mod, void *arg);
char				*ft_conv_pc(t_mod mod, void *arg);
char				*ft_conv(t_ops sv, void *arg, t_mod mod);
char				*ft_conv_d(t_mod mod, void *arg);
int					ft_adjustprecis(int precis, char *argst);

#endif
