#include "ft_ls.h"


t_parse  ft_init_parse(void)
{
	t_parse parse;

	parse.a = 0;
	parse.l = 0;
	parse.r = 0;
	parse.R = 0;
	parse.t = 0;
	parse.path = NULL;
	return (parse);
}

t_parse   ft_parse(char **av)
{
	t_parse parse;

	parse = ft_init_parse();
	if(!ft_strcmp(av[1], "-a"))
		parse.a = 1;
	return (parse);
}



int main(int ac, char  **av)
{
	t_parse parse;

	ac = 6;
	parse =	ft_parse(av);
	printf("parse a = %d\n", parse.a);
	return 0;
}