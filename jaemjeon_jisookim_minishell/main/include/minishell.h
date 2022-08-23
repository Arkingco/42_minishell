/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/23 20:45:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

# include "libft.h"
# include "parse.h"
# include "tokenize.h"
# include "env.h"
# include "util.h"

typedef struct s_global
{
	char		**envp;
	t_envlst	*lst_env;
	t_token		*lst_token;
	t_cmd		*lst_cmd;
}	t_global;

// main.c

//main_loop.c
void	loop_get_commandline(t_envlst *env);

// init.c
void	init(int argc, char *envp[], t_envlst *env);
void	init_env_lst(char *envp[], t_envlst *env);
void	update_shlvl(t_envlst *env);

// signal_action.c
void	set_signal_action(void);

// pwd.c
void	pwd(t_envlst *env);

#endif
