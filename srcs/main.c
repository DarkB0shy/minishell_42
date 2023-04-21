#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
    t_shell shell;

    (void)argc;
    (void)argv;
    (void)env;
    shell.pipeline = readline("minishell$");
    printf("%s\n", shell.pipeline);
    return (0);
}
