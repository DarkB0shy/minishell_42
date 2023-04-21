# ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_shell
{
	char	**env;
	char	*pipeline;
}	t_shell;

# endif