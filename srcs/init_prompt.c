#include "minishell.h"

static void handle_siginit(int sig)
{
    (void)sig;
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
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
        signal(SIGINT, handle_siginit);
        signal(SIGQUIT, handle_sigquit);
        shell->pipeline = readline(shell->prompt);
        if (!shell->pipeline)
            break ;
        if (ft_strncmp(shell->pipeline, "", 1))
            add_history(shell->pipeline);
    }
}

static void  get_pwd(t_shell *shell)
{
    char    *home;
    
    shell->prompt = "\n$";
    home = getenv("PWD");
    if (!home)
        print_error(1, shell);
    shell->prompt = ft_strjoin(home, shell->prompt);
}

void init_prompt(t_shell *shell)
{
    get_pwd(shell);
    main_loop(shell);
    free_strings(shell);
}