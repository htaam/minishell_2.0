#include "minishell.h"

int	check_shell_lvl(void)
{
	int		i;
	int		new_int;

	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], "SHLVL", 5) == 0)
		{
			new_int = ft_atoi(&g_shell.env[i][6]);
			return (new_int);
		}
		i++;
	}
	return (0);
}

void sig_handler(int signal)
{

	if (signal == SIGINT)
	{
		printf("Prompt minishell$ \n");
	}
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}


void setting_signal()
{
    signal(SIGINT, sig_handler);  // CTRL + C
    signal(SIGQUIT, SIG_IGN); // CTRL + /
}

char	*rl_w_history(char *prompt, char *line_read)
{
	if (line_read)
	{
		free (line_read);
		line_read = (char *) NULL;
	}

	setting_signal();
	line_read = readline (prompt);
	if (!line_read)
	{
		printf("\033[1A");
		printf("\033[10C");
		printf("\t$ exit\n");
		exit(-1);
	}
	else
		add_history (line_read);
	return (line_read);
}
