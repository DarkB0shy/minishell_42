#include "minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}

static void main_loop(t_shell *shell)
{
    while (1)
    {
        signal(SIGINT, handle_sigint);
        signal(SIGQUIT, handle_sigquit);
        shell->pipeline = readline(shell->prompt);
        if (!shell->pipeline)
            break ;
        if (ft_strncmp(shell->pipeline, "", 1))
        {
            add_history(shell->pipeline);
            if (!check_syntax(shell->pipeline))
                printf("ok\n");
        }        
        free(shell->pipeline);
    }
}

static void  get_pwd(t_shell *shell)
{
    char    *home;
    char    *temp;

    shell->prompt = "\n$";
    home = getenv("PWD");
    if (!home)
        print_error(1);
    temp = getenv("USER");
    if (!temp)
        temp = "guest";
    temp = ft_strjoin(temp, "@minishell-");
    temp = ft_strjoin(temp, home);
    shell->prompt = ft_strjoin(temp, shell->prompt);
    free(temp);
}

void init_prompt(t_shell *shell)
{
    get_pwd(shell);
    main_loop(shell);
    free(shell->prompt);
}