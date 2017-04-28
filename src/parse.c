#include "ft_ls.h"

void	print_ops(int ops)
{
	if (CHECK_OPS(ops, L))
		ft_printf("l\n");
	if (CHECK_OPS(ops, A))
		ft_printf("a\n");
	if (CHECK_OPS(ops, R))
		ft_printf("r\n");
	if (CHECK_OPS(ops, T))
		ft_printf("t\n");
	if (CHECK_OPS(ops, RR))
		ft_printf("R\n");
}

t_parse  ft_init_parse(void)
{
	t_parse parse;

	parse.path = NULL;
	parse.ops = 0;
	return (parse);
}

t_parse ft_no_parse(void)
{
	t_parse parse;

	if(!(parse.path = (char**)ft_memalloc(sizeof(char*) * 2)))
		exit (0);
	parse.path[0] = ft_strdup("./");
	parse.ops = 0;
	return (parse);
}

int 	ft_isops(char c)
{
	if(ft_strchr("lrRat", c))
		return (1);
	else
		return (0);
}

int 	ft_check_options(char *arg)
{
	int i;

	i = 0;
	while(arg[++i])
		if(!ft_isops(arg[i]))
			return (0);
	return (1);
}

void	ft_disp_usage(char *arg)
{
	int i; 

	i = 1;
	while(ft_isops(arg[i]))
		++i;
	ft_printf("ft_ls : illegal option -- %c\nusage: ./ft_ls [-Ralrt] [file ...]\n", arg[i]);
}

int  ft_activ_ops(int ops, char *arg)
{
	int i;

	i = 0;
	while(arg[++i])
	{
		if(arg[i] == 'R')
			ops |= RR;
		else if(arg[i] == 'a')
			ops |= A;
		else if(arg[i] == 'r')
			ops |= R;
		else if(arg[i] == 'l')
			ops |= L;
		else if(arg[i] == 't')
			ops |= T;
	}
	return (ops);
}

char  	**ft_set_path(char **av, int ac, int i)
{
	char **path;
	int j;

	j = 0;
	if (!(path = (char**)ft_memalloc(sizeof(char*) * (ac - i + 1))))
		exit (0);
	if(i == ac)
	{
		path[0] = ft_strdup("./");
		return (path);
	}
	while(av[i])
		path[j++] = av[i++];
	path[j] = NULL;
	return (path);
}

t_parse   ft_parse(char **av, int ac)
{
	t_parse 	parse;
	int 		i;
	int 		j;

	i = 1;
	j = 0;
	parse = ft_init_parse();
	while(i < ac && (av[i][0] == '-'))
		++i;
	while(++j < i)
		if(!ft_check_options(av[j]))
		{
			ft_disp_usage(av[j]);
			exit (0);
		}
	j = 0;
	while(++j < i)
		parse.ops = ft_activ_ops(parse.ops, av[j]);
	parse.path = ft_set_path(av, ac, i);
	return (parse);
}

void disp_parse(t_parse parse)
{
	int i;

	i = -1;
	while(parse.path[++i] != NULL)
		ft_printf("path = %s\n", parse.path[i]);
//	printf("ok\n");
}

// int main(int ac, char  **av)
// {
// 	t_parse parse;
// 	if(ac == 1)
// 		parse = ft_no_parse();
// 	else
// 		parse = ft_parse(av, ac);
// 	print_ops(parse.ops);
// 	disp_parse(parse);
// 	return (0);
// }
