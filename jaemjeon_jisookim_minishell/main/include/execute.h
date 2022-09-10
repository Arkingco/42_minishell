/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:35 by jisookim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/10 17:23:46 by jaemjeon         ###   ########.fr       */
=======
/*   Updated: 2022/09/10 16:16:49 by jisookim         ###   ########.fr       */
>>>>>>> 120fb0b0ddeb1c2e1f9ee057da8c57642357d51f
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



// todo: single, multi 나눈거
// 실행하면서 환경변수를 바꿔야 하는데
// 실행할때 envlist 넘겨주는 쪽이?


typedef struct s_exec
{
	//util
	t_cmd		*cmds;
	void		*cmd_head;
	int			*token_cnt;				// fin, no malloc
	int			process_cnt;	 		// fin, len of cmd_cnt array

	// for exec - env
	t_envlst	*env;				//fin
	char		**env_lst;
	void		*env_head;
	int			count_key;
	
	// for exec - path
	char		**path_lst;			// malloced, fin
	char		*final_path;

	// for exec - cmd
	char		**final_cmd_str;	//fin

	// for exec - pipe
	int			pipe_fd[3];

	// for redirection
	int		redirect[2];
	
}	t_exec;


/*
	INITIALIZING
*/

//init_double_env
int		count_key_value(t_exec *exec);
void	make_env_double_ptr(t_exec *exec);

//exec_init_get_cmd
void	get_token_count(t_exec *exec);
int		get_simple_cmd_count(t_exec *exec, int i);

//init_struct
void	set_exec_struct_final_cmd_loop(t_exec *exec, char *cmd_str, int i);
void	set_exec_process_number_init(t_exec *exec, char *cmd_str, int j);
void	set_exec_struct_final_cmd_str(t_exec *exec, int j);
char	*set_final_path_str(t_exec *exec);
int		init_exec_struct(t_exec *exec, int j);

//init
void	tools_move_cmd(t_exec *exec, int i);
int		count_process(t_exec *exec);
void	make_path_list(t_exec *exec);
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env, char *envp[]);


/*
	MAIN PART
*/

//check_built_in
int		check_built_in(t_exec *exec);
void	exec_go_built_in(t_exec *exec);

//main
int		exec_single_cmd(t_exec *exec);
int		exec_multi_cmd(t_exec *exec);
int		execute(t_cmd *cmd, t_envlst *env, char **envp);

//multi_cmd
pid_t	exec_multi_first(t_exec *exec, int i, pid_t *pid);
pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid);
pid_t	exec_multi_last(t_exec *exec, int i, pid_t *pid);

void	init_pipe_before_exec(t_exec *exec, int i);
int		multi_process_exceve(t_exec *exec);

//exec_redirection
void	handle_redirect_input(t_exec *exec, int process_number);
void	handle_redirect_output(t_exec *exec, int process_number);
void	handle_redirection(t_exec *exec, int process_number);
void	check_redirection(t_exec *exec);
void	exec_handle_redirection(t_exec *exec, int process_number);

//exec_redi_parse
void	redi_open_before_exec_file(t_exec *exec, t_token *redi);
char	*exec_find_redi_file(t_exec *exec, t_token *redi, int *more_redi_flag);
char	*get_redi_execute_file(t_exec *exec, t_token *redi, int i);

//exec_tools_file
int		ft_open(const char *filename, int flags, int num);
int		ft_close(int fd);

//exec_tools
pid_t	ft_fork(void);
int		ft_dup2(int fd1, int fd2);
pid_t	ft_wait(t_exec *exec, pid_t *child_pids);
int		*ft_pipe(int *pipe_fd);
void	exec_executing(t_exec *exec, int process_number, int stat);

#endif
