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
	char	**pipe_words;
}	t_shell;

// Libft
int		ft_strlen(const char *str);
char	**ft_split(const char *s, char c);

# endif