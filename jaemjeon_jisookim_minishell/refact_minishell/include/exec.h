/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:03:17 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/31 14:27:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <fcntl.h>


#define GOOD_EXIT	0
#define BAD_EXIT	1

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
	int		is_builtin;
	size_t	process_cnt;
	pid_t	process_id[2];
	int		pipe_fd[3];
	int		pre_read_fd;
	int		heredoc_flag;
	pid_t	*pid_lst;
	char	**argv;
	char	**envp;
	char	**cmds;
	char	*final_path;
}	t_exec;


//init_exec
int		check_heredoc(t_exec *exec, t_cmd *cmd);
size_t	count_process(t_cmd *cmd);
void	init_exec(t_exec *exec, t_cmd *cmd);

//pipe_and_fork <- 여기서 fork, child & parent 분기
void	pipe_and_fork(t_exec *exec, t_cmd *cmd);

//child_process
void	put_info_to_pipe(t_cmd *cmd, t_exec *exec);
void	child_process(t_exec *exec, int idx, t_cmd *cmd);

//execute
void	ft_error(void);
int		check_redirection(t_cmd *cmd);
void	execute(t_cmd *cmd);

//find_path 로 이름변경
char	*add_path_with_cmd(t_exec *exec, char **raw_paths);
char	*get_path_lst(t_envlst *env, t_exec *exec);
void	do_execute(t_envlst *env, t_cmd *cmd,t_exec *exec, char *argv_cmd);


//tools_exec
int	ft_fork(void);
int	ft_open(const char *filename, int flags);
int	ft_close(int fd);
int	ft_dup2(int fd1, int fd2);
int	ft_pipe(int pipe_fd[2]);

#endif