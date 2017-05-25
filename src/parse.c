#include "ft_ls.h"
void disp_parse(t_parse parse);

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


t_parse ft_no_parse(void)
{
	t_parse parse;

	if(!(parse.path = (char**)ft_memalloc(sizeof(char*) * 2)))
		exit (0);
	parse.path[0] = ft_strdup("./");
	parse.ops = 0;
	return (parse);
}

void	ft_disp_usage(char *arg)
{
	int i; 

	i = 1;
	while(ft_isops(arg[i]))
		++i;
	ft_printf("ft_ls : illegal option -- %c\nusage: ./ft_ls [-1GRaflrt] [file ...]\n", arg[i]);
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
		else if(arg[i] == 'f')
			ops |= F;
		else if(arg[i] == 'G')
			ops |= G;
	}
	return (ops);
}

char  	**ft_set_path(char **av, int ac, int i)
{
	char **path;
	int j;
	int len;

	j = 0;
	if(i == ac)
	{	
		if (!(path = (char**)ft_memalloc(sizeof(char*) * (2))))
			exit (0);
		path[0] = ft_strdup("./"); 
		return (path);
	}
	if (!(path = (char**)ft_memalloc(sizeof(char*) * (ac - i + 1))))
		exit (0);
	while(i < ac)
	{
		len = ft_strlen_p(av[i]) - 1;
		if(av[i][len] != '/')
			av[i] = ft_strjoin(av[i], "/");
		path[j++] = ft_strdup(av[i++]);
	}
	return (path);
}

t_parse   ft_parse(char **av, int ac)
{
	t_parse 	parse;
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	parse = ft_init_parse();
	while(++i < ac && (av[i][0] == '-')) 
	{
		if(!ft_check_options(av[i]))
		{
			ft_disp_usage(av[i]);
			exit (0);
		}
		else if(ft_check_options(av[i]) == -1)
			break ;
	}
	while(++j < i)
		parse.ops = ft_activ_ops(parse.ops, av[j]);
	parse.path = ft_set_path(av, ac, i);
	if(CHECK_OPS(parse.ops, F))
	{
		parse.ops |= A;
		CHECK_OPS(parse.ops, G) ? parse.ops -= G : 0;
		CHECK_OPS(parse.ops, R) ? parse.ops -= R : 0;
		CHECK_OPS(parse.ops, T) ? parse.ops -= T : 0;

	}
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