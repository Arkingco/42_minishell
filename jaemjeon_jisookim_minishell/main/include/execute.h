/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/08 09:53:05 by jisookim         ###   ########.fr       */
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

#define BAD_EXIT	1

#define STDIN_FD	0
#define STDOUT_FD	1

// divide single & multi cmd
#define SINGLE_CMD	0
#define MULTI_CMD	1

// pipe control - pipe type
#define SINGLE_PIPE		0
#define ADDITIONAL_PIPE	1

// pipe type
// PIPE_OUT matches with STDIN_FD
// PIPE_IN matches with STDOUT_FD
#define PIPE_OUT	0
#define PIPE_IN		1

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

	// for exec
	t_envlst	*env;				//fin
	char		**env_lst;
	void		*env_head;
	int			count_key;
	
	char		**path_lst;			// malloced, fin
	char		*final_path;

	char		**final_cmd_str;	//fin

	//pipe
	int			pipe_fd[3];
	//int		pre_read_fd;
	//pid_t		*pid_lst;
	
}	t_exec;


/*
	INITIALIZING
*/

//init_double_env
int		count_key_value(t_exec *exec);
void	make_env_double_ptr(t_exec *exec);

/*
//init_final_path
char	*get_paths_from_env(t_exec *exec, char *path_list);
char	**ft_split_paths(t_exec *exec, char *path_list, char **temp_path_lists);
char	*get_final_path(t_exec *exec, char **temp_path_lists);
void	main_get_final_paths(t_exec *exec);
*/

//exec_init_get_cmd
void	get_token_count(t_exec *exec);
int		get_simple_cmd_count(t_exec *exec, int i);
void	make_ptr_execve_cmds(t_exec *exec);
char	**init_execve_cmds(t_exec *exec);

//init
int		count_process(t_exec *exec);
void	make_path_list(t_exec *exec);
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env, char *envp[]);

void	set_exec_process_number_init(t_exec *exec, char *cmd_str, int j);
void	set_exec_struct_final_cmd_loop(t_exec *exec, char *cmd_str, int i);
void	set_exec_struct_final_cmd_str(t_exec *exec, int j);
char	*set_final_path_str(t_exec *exec);
int		init_exec_struct(t_exec *exec, int j);

/*
	MAIN PART
*/

//check_built_in
int		check_built_in(t_exec *exec);
void	exec_go_built_in(t_exec *exec);

//fork


//dup2
int		single_pipe_dup2(t_exec *exec);
int		multi_pipe_dup2(t_exec *exec);

//main
void	exec_executing(t_exec *exec, int process_number, int stat, pid_t pid);
int		exec_single_cmd(t_exec *exec);
int		exec_multi_cmd(t_exec *exec);
int		execute(t_cmd *cmd, t_envlst *env, char **envp);

//multi_cmd

pid_t	exec_multi_first(t_exec *exec, pid_t *pid);
pid_t	exec_multi_middle(t_exec *exec, int i, pid_t *pid);
pid_t	exec_multi_last(t_exec *exec, pid_t *pid);

int		multi_process_exceve(t_exec *exec, int i, pid_t *pid);
int		exec_multi_child_process(t_exec *exec);

//pipe
int		exec_pipe_control(t_exec *exec);

//single_cmd

//exec_tools_file
int		ft_open(const char *filename, int flags);
int		ft_close(int fd);

//exec_tools
void	ft_double_free(char **list);
int		*ft_pipe(int *pipe_fd);
int		ft_dup2(int fd1, int fd2);
pid_t	ft_fork(void);
int		ft_exceve(const char *filename, char *const argv[], char *const envp[]);
pid_t	ft_wait(int *statloc);


#endif
