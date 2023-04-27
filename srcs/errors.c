#include "minishell.h"

void free_strings(t_shell *shell)
{
    free(shell->pipeline);
    free(shell->prompt);
}

static void write_std_error(char *error)
{
    int i;

    i = -1;
    write(2, "Error: ", 7);
    while (error[++i])
        write(2, &error[i], 1);
}

void    print_error(int error, t_shell *shell)
{
    if (error == 1)
        write_std_error("could not get PWD\n");
    free_strings(shell);
    exit (error);
}