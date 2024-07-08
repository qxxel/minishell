/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 16:46:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	debug_print_argv(char **argv)
{
	size_t	i;

	if (!argv)
	{
		printf("\t.argv = NULL,\n");
		return ;
	}
	printf("\t.argv = {");
	i = 0;
	while (argv[i])
	{
		if (i)
			printf(", ");
		printf("\"%s\"", argv[i++]);
	}
	printf(", NULL},\n");
}

static void	debug_print_redirects(t_cmd cmd)
{
	size_t	i;

	printf("\t.n_redirects = %zu,\n", cmd.n_redirects);
	if (!cmd.redirects)
	{
		printf("\t.redirects = NULL\n");
		return ;
	}
	printf("\t.redirects = {\n");
	i = 0;
	while (i < cmd.n_redirects)
	{
		if (i)
			printf(",\n");
		printf("\t\t{\n\t\t\t.expand = %d,\n\t\t\t.option = %d,\
\n\t\t\t.out = %d,\n\t\t\t.path = \"%s\"\n\t\t}", cmd.redirects[i].expand,
			cmd.redirects[i].option, cmd.redirects[i].out,
			cmd.redirects[i].path);
		i++;
	}
	printf("\n\t}\n");
}

static void	debug_print_cmds(t_msh msh)
{
	size_t	i;

	i = 0;
	while (i < msh.n_cmds)
	{
		printf("msh.cmds[%zu] = {\n", i);
		debug_print_argv(msh.cmds[i].argv);
		debug_print_redirects(msh.cmds[i]);
		printf("}\n\n");
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_msh	msh;

	if (init_msh(envp, &msh))
		return (EXIT_FAILURE);
	if (argc > 1)
	{
		str = ft_strdup(argv[1]);
		printf("%s\n", str);
	}
	else
		str = readline("> ");
	printf("\n");
	parse_cmds(str, &msh);
	debug_print_cmds(msh);
	destroy_msh(msh);
	return (EXIT_SUCCESS);
}
