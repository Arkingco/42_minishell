/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 21:05:31 by jisookim         ###   ########.fr       */
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
#include <sys/stat.h> // stat
#include <errno.h>

#include <string.h> //for debug

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
	
	t_cmd		*cmds;
	int			*token_cnt;			// no malloc
	int			process_cnt;	 	// len of cmd_cnt array

	t_envlst	*env;				// [env]
	char		**env_lst;			// [env] for execve
	void		*env_head;
	int			count_key;
	
	char		**path_lst;			// [path] malloced
	char		*final_path;		// [path] for execve

	char		**final_cmd_str;	// [cmd] for execve

	int			pipe_fd[2];			// [pipe]

}	t_exec;

typedef struct s_fd
{
	int			pipe_input_fd;		// pipe's input fd
	int			pipe_output_fd;		// pipe's output fd
	int			before_input_fd;	// file's input fd

}	t_fd;


/*
	INITIALIZING
*/

//init_double_env
void	count_key_value(t_exec *exec, t_envlst *env);
void	make_env_double_ptr(t_exec *exec);

//exec_init_get_cmd
void	get_token_count(t_exec *exec);
int		fill_token_count_array(t_cmd *cmd);

//init_struct
void	set_exec_struct_final_cmd_loop(t_exec *exec, t_cmd *cmd, int i);
void	set_exec_struct_final_cmd_str(t_exec *exec, int j);
void	set_final_path_str(t_exec *exec);
int		init_exec_struct(t_exec *exec, int j);

//init
t_cmd	*get_cmd_for_index(t_exec *exec, int index);
t_token	*reset_redi_input(t_cmd *cmd);
int		count_process(t_exec *exec);
void	make_path_list(t_exec *exec);

//exit
void	ft_exit_if(t_exec *exec, int condition);

/*
	MAIN PART
*/

//check_built_in
int		check_built_in(t_exec *exec);
void	exec_go_built_in(t_exec *exec);

//main
pid_t	exec_single_cmd(t_exec *exec, pid_t ret_pid);
pid_t	exec_multi_cmd(t_exec *exec, pid_t ret_pid);


//multi_cmd
void	exec_multi(t_exec *exec, int i, t_fd *fd);
void	init_pipe_before_exec(t_exec *exec, int i, t_fd *fd);
int		multi_process_exceve(t_exec *exec, t_fd *fd);

//exec_redirection
void	check_infile_redi_valid(t_cmd *cmd, int *infile_fd);
void	check_outfile_redi_valid(t_cmd *cmd, int type, int *outfile_fd);
int		handle_redireict_input(t_exec *exec, t_cmd *cmd);
int		handle_redirect_output(t_exec *exec, t_cmd *cmd);
void	exec_handle_redirection(t_exec *exec, t_cmd *cmd, int i);

//exec_redi_parse
void	redi_open_before_exec_file(t_exec *exec, t_token *redi);
char	*exec_find_redi_file(t_exec *exec, t_token *redi, int *flag, int *type);
char	*get_redi_execute_file(t_exec *exec, t_token *redi, int *type);

//exec_tools_file
int		ft_open(const char *filename, int flags);
int		ft_close(int fd);
void	close_all_fds(t_exec *exec, t_fd *fd);

//exec_tools
pid_t	ft_fork(void);
int		ft_dup2(int fd1, int fd2);
pid_t	ft_wait(int count, pid_t *child_pids);
int		ft_pipe(int *pipe_fd);
void	exec_executing(t_exec *exec, int process_number);

#endif
