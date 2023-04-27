# ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_shell
{
	char	*prompt;
	char	*pipeline;
	char	**pipe_words;
}	t_shell;

// Errori
void    print_error(int error, t_shell *shell);
void free_strings(t_shell *shell);

// Libft
int		ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);

// Readline
extern	void	rl_replace_line(const char *text, int clear_undo);

// Init
void init_prompt(t_shell *shell);

# endif