/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:27:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/13 22:50:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <signal.h>
# include "./libft/libft.h"
# include "env.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define P_SUCCESS NULL
# define P_FAIL ((void *)-1)
# define ERROR 1
# define GET 0
# define SET 1

enum e_info_type{
	e_login_name,
	e_prompt,
	e_envlst,
	e_envp,
	e_pathp
};

typedef struct s_info
{
	char		*login_name;
	char		*prompt;
	t_envlst	*envlst;
	char		**envp;
	char		**pathp;
}	t_info;

// main.c

//init_parsing.c
void	init_parsing(int argc, char *argv[], char *envp[]);
void	get_envp(char *envp[]);
char	*strtok_in_envp(char *envp);

//global.c
void	*getset_info(int getset, int type, void *p_value);

//util_1.c
void	ft_error(char *error_message);
void	ft_free(void **p_pointer);

//command_parsing.c
void	command_processing(char *command_line);

//run_command.c
void	run_command_in_path(char **command, char *argv);

//env.c
void	command_env(void);

//signal_action.c
void	set_signal_action(void);
#endif
