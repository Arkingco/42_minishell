/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/05 14:56:38 by jisookim         ###   ########.fr       */
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
	t_cmd	*cmds;
	void	*cmd_head;
	int		process_cnt;

	// for exec
	char		**execve_cmds;
	char		*final_path;
	char		**env_lst;
	t_envlst	*env;

	//pipe
	int			pipe_fd[3];
	//int		pre_read_fd;
	//pid_t		*pid_lst;
	
}	t_exec;

// typedef struct s_stat
// {
// 	dev_t	st_dev;			/*ID of device containing file */
// 	ino_t	st_ino;			/*inode number*/
// 	mode_t	st_mode;		/*protection*/
// 	nlink_t	st_nlink;		/*number of hard links*/
// 	uid_t	st_uid;			/*user ID of owner*/
// 	gid_t	st_gid;			/*group ID of owner*/
// 	dev_t	st_rdev;		/*device ID (if special file)*/
// 	off_t	st_size;		/*total size, in byte*/
// 	blksize_t	st_blksize;	/*blocksize for file system I/O*/
// 	blkcnt_t	st_blocks;	/*number of 512B blocks allocated*/
// 	// time_t	st_atime;		/*time of last access*/
// 	// time_t	st_mtime;		/*time of last modification*/
// 	// time_t	st_xtime;		/*time of last status change*/
	
// }	t_stat;


/*
	INITIALIZING
*/

//init_double_env
int		count_key_value(t_envlst *env);
void	make_env_double_ptr(t_exec *exec, t_envlst *env);

//init_final_path
char	*get_paths_from_env(t_exec *exec, char *path_list);
char	**ft_split_paths(t_exec *exec, char *path_list, char **temp_path_lists);
char	*get_final_path(t_exec *exec, char **temp_path_lists);
void	main_get_final_paths(t_exec *exec);

//exec_init_get_cmd
void	make_double_ptr_execve_cmds(t_exec *exec, int cmd_count);
int		get_cmd_count(t_exec *exec);
char	**get_execve_cmds(t_exec *exec);

//init
int		count_process(t_exec *exec);
t_exec	*main_init_exec(t_exec *exec, t_cmd *cmd, t_envlst *env);


/*
	MAIN PART
*/

//fork
int	exec_single_fork(t_exec *exec);
int	exec_multi_fork(t_exec *exec);

//dup2
int	single_pipe_dup2(t_exec *exec);
int	multi_pipe_dup2(t_exec *exec);

//main
int	exec_single_cmd(t_exec *exec, t_envlst *env);
int	exec_multi_cmd(t_exec *exec, t_envlst *env, int *wait_ret);
int	execute(t_cmd *cmd, t_envlst *env);

//multi_cmd
int		exec_multi_check_built_in(t_exec *exec);
int		exec_multi_first(t_exec *exec);
int		exec_multi_last(t_exec *exec);
int		exec_multi_middle(t_exec *exec);

//pipe
int	exec_pipe_control(t_exec *exec);

//single_cmd
void	exec_single_check_built_in(t_exec *exec);

//exec_tools_file
int		ft_open(const char *filename, int flags);
int		ft_close(int fd);

//exec_tools
void	ft_double_free(char **list);
int		ft_stat(const char *path);
int		*ft_pipe(int *pipe_fd);
int		ft_dup2(int fd1, int fd2);
pid_t	ft_fork(void);
int		ft_exceve(const char *filename, char *const argv[], char *const envp[]);
pid_t	ft_wait(int *statloc);


#endif