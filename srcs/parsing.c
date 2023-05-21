#include "minishell.h"

static int add_space(char *tmp, int i, char *line, int j)
{
	if (tmp[i] == 124)
	{	
		line[j] = 32;
		j++;
    	line[j] = tmp[i];
	}
    if (tmp[i - 1] != 60 && tmp[i - 1] != 62)
    {
        line[j] = 32;
        j++;
    }
    line[j] = tmp[i];
    if (tmp[i + 1] != 60 && tmp[i + 1] != 62)
    {
        j++;
        line[j] = 32;
    }
    return j;
}

int		count_in_out(char *str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			k++;
		i++;
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 124)
			j++;
		i++;
	}
	return (k + j);
}

// Aggiunge gli spazi per poter usare ft_split con ' '

static char	*parsing(t_shell *shell)
{
	char	*str;
	int		i;
	int		j;
	int		space;

	i = 0;
	j = 0;
	space = 0;
	space = count_in_out(shell->pipeline);
	str = malloc(sizeof(char) * (ft_strlen(shell->pipeline) + space + 1));
	if (!str)
		return (NULL);
	while (shell->pipeline[i])
	{
		if (shell->pipeline[i] == 60 || shell->pipeline[i] == 62 || shell->pipeline[i] == 124)
			j = add_space(shell->pipeline, i, str, j);
		else
			str[j] = shell->pipeline[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

// static void	tokenizing(t_node *node)
// {
// 	t_node	*temp;

// 	temp = node;
// 	while (temp->next)
// 	{
// 		printf("%s\n", temp->command);
// 		// if ((int)temp->command == 62)
// 		// 	printf("got it");
// 		temp = temp->next;
// 	}
// 	printf("%s\n", temp->command);
// 	printf("Current token: %s\n", node->command);
// }

void	get_first_command_path(t_shell *shell)
{
	shell->line_to_split = parsing(shell);
	shell->splitted_pipe = ft_split(shell->line_to_split, ' ');
	free(shell->line_to_split);
	shell->first_cmd_path = get_path(shell->splitted_pipe[0]);
	if (shell->first_cmd_path)
		create_instruction_list(shell);
	else	
		free(shell->splitted_pipe);
	// tokenizing(shell->token);
	// shell->first_cmd_path = get_path(shell->token->command);
}
