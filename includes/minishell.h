# ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>

typedef struct s_shell
{
	char	*prompt;
	char	*pipeline;
}	t_shell;

// Errori
void			print_error(int error);

// Libft
int				ft_strlen(const char *str);
char			**ft_split(const char *s, char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

// Readline
extern	void	rl_replace_line(const char *text, int clear_undo);

// Reader
void 			init_prompt(t_shell *shell);
int 			check_syntax(char *str);
int				check_redirs(char *str);

# endif