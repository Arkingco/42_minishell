/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/02 15:38:36 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "token.h"
# include "env.h"
# include "cmd.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open, close
#include <sys/wait.h> // wait
#include <sys/types.h> // pid_t

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

typedef struct s_exec
{
	t_cmd	*cmds;
	t_cmd	*cmd_head;
	size_t	process_cnt;
	

	int		pipe_fd[3];
	//int		pre_read_fd;
	//pid_t	*pid_lst;
	//char	*final_path;
}	t_exec;


//built_in

//fork

//init
t_exec	*init_exec(t_exec *exec, t_cmd *cmd);
size_t	count_process(t_exec *exec, t_cmd *cmd);


//main
int	execute(t_cmd *cmd);
int	exec_multi_cmd(t_exec *exec);
int	exec_single_cmd(t_exec *exec);

//multi_cmd

//pipe

//single_cmd


//exec_tools_file
int		ft_open(const char *filename, int flags);
int		ft_close(int fd);

//exec_tools
int		*ft_pipe(int *pipe_fd);
int		ft_dup2(int fd1, int fd2);
int		ft_fork(void);
int		ft_exceve(const char *filename, char *const argv[], char *const envp[]);
pid_t	ft_wait(int *statloc);


#endif