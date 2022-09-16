/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:51:03 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/16 22:15:16 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_info(t_working_info *info, t_envlst *env)
{
	info->env = env;
	info->cur_path = getcwd(NULL, 0);
	if (info->cur_path == NULL)
		perror("initiating minishell.. error in getcwd..");
	else
		ft_setenv(env, "PWD", info->cur_path, TRUE);
	info->dp = opendir(info->cur_path);
	if (info->dp == NULL)
		perror("initiating minishell.. error in opendir..");
	ft_delenv(&env, "OLDPWD");
}

void	argument_error_check(int argc)
{
	if (argc != 1)
		ft_error_exit(1, "too many arguments");
}

void sigint_handler(int signo)
{
	signo++;
	write(1, "\n", 1);
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_signal_action(void)
{
	struct sigaction	sigint_action;
	struct sigaction	sigquit_action;
	struct termios		term_setting;

	sigint_action.sa_flags = SA_SIGINFO;
	sigint_action.sa_handler = sigint_handler;
	sigquit_action.sa_flags = SA_SIGINFO;
	sigquit_action.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sigint_action, NULL);
	sigaction(SIGQUIT, &sigquit_action, NULL);
	tcgetattr(1, &term_setting);
	term_setting.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term_setting);
}

void	init_inner_env(t_envlst **env)
{
	// t_envlst	*my_env;

	// getcwd()

	// my_env = ft_getenv_lst(*env, "PWD");
	// if ()
}

void	update_shlvl(t_envlst **env)
{
	t_envlst	*env_shlvl;
	int			shlvl_value_int;
	char		*shlvl_value_string;

	env_shlvl = ft_getenv_lst(*env, "SHLVL");
	if (env_shlvl == NULL)
		ft_addenv_str(env, "SHLVL=1");
	else
	{
		shlvl_value_int = ft_atoi(env_shlvl->value);
		shlvl_value_int++;
		shlvl_value_string = ft_itoa(shlvl_value_int);
		ft_setenv(*env, "SHLVL", shlvl_value_string, TRUE);
		free(shlvl_value_string);
	}
}

void	init_envp(char *envp[], t_envlst **env)
{
	while (*envp != NULL)
	{
		ft_addenv_str(env, *envp);
		envp++;
	}
	update_shlvl(env);
	init_inner_env(env);
}
