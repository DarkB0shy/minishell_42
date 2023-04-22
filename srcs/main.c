#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
    t_shell shell;
    int     i;

    (void)argc;
    (void)argv;
    (void)env;
    i = -1;
    shell.pipeline = readline("minishell$");
    shell.pipe_words = ft_split(shell.pipeline, ' ');
    while (shell.pipe_words[++i])
        printf("%s\n", shell.pipe_words[i]);
    free(shell.pipeline);
    return (0);
}
