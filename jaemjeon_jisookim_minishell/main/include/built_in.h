/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:53:02 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/07 18:15:33 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "token.h"
# include "env.h"
# include "cmd.h"
# include "execute.h"

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h> // open, close
// #include <sys/wait.h> // wait
// #include <sys/types.h> // pid_t

#define BAD_EXIT	1

#define STDIN_FD	0
#define STDOUT_FD	1

// typedef struct s_cmd
// {
// 	t_token			*simple_cmd;
// 	t_token			*redirect_input;
// 	t_token			*redirect_output;
// 	struct s_cmd	*next;
// }	t_cmd;

// typedef struct s_token
// {
// 	unsigned int	type;
// 	char			*string_value;
// 	struct s_token	*next;
// 	struct s_token	*prev;
// }	t_token;



//cd
int	ft_cd(t_exec *exec);

//echo
int	ft_echo(t_exec *exec);

//env
int	ft_env(t_exec *exec);

//exit
int	ft_exit(t_exec *exec);

//export
int	ft_export(t_exec *exec);

//pwd
int	ft_pwd(t_exec *exec);

//unset
int	ft_unset(t_exec *exec);

#endif
