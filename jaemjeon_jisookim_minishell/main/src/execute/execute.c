/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/20 04:39:22 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_errno;

void	process_built_in(t_cmd *cmd, t_working_info *info, int cmd_type)
{
	void	(*built_in_func)(t_cmd *cmd, t_working_info*);
	static void (*built_in_func_board[BUILT_IN_COUNT])(t_cmd*, t_working_info*)\
	= {
		[T_ECHO] = ft_echo,
		[T_CD] = ft_cd,
		[T_PWD] = ft_pwd,
		[T_EXPORT] = ft_export,
		[T_UNSET] = ft_unset,
		[T_ENV] = ft_env,
		[T_EXIT] = ft_exit
	};

	built_in_func = built_in_func_board[cmd_type];
	built_in_func(cmd, info);
}

int	is_already_exec_path(char *cmd_string)
{
	if (ft_strchr(cmd_string, '/') != NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	expand_homepath(char **cmd_string, t_working_info *info)
{
	char	*new_cmd_string;
	char	*homepath;

	homepath = ft_getenv(info->env, "HOME");
	if (homepath == NULL)
		return ;
	if (**cmd_string == '~')
	{
		new_cmd_string = ft_strjoin(homepath, *cmd_string + 1);
		free(*cmd_string);
		*cmd_string = new_cmd_string;
	}
}

int	is_valid_cmd_path(char *cmd_string)
{
	struct stat	file_stat;

	if (stat(cmd_string, &file_stat) == 0)
		return (TRUE);
	return (FALSE);
}

int	expand_homepath_and_check_is_there(t_cmd *cmd, t_working_info *info)
{
	struct stat	file_stat;

	expand_homepath(&cmd->simple_cmd->string_value, info);
	if (stat(cmd->simple_cmd->string_value, &file_stat) == 0)
		return (TRUE);
	return (FALSE);
}

void	ft_free_double(char **board)
{
	char	**tmp_board;
	char	*to_free;

	tmp_board = board;
	while (*tmp_board != NULL)
	{
		free(*tmp_board);
		tmp_board++;
	}
	free(board);
}

int	set_absolute_path(t_cmd *cmd, t_working_info *info)
{
	const char	**path_board = (const char **)get_path_board(info->env);
	int		index;
	char	*exec_path;
	struct stat	file_stat;

	if (path_board == NULL)
		return (FALSE);
	index = 0;
	while (path_board[index] != NULL)
	{
		exec_path = ft_strjoin_triple((char *)path_board[index], "/",
									cmd->simple_cmd->string_value);
		if (stat(exec_path, &file_stat) == 0)
		{
			free(cmd->simple_cmd->string_value);
			cmd->simple_cmd->string_value = exec_path;
			ft_free_double((char **)path_board);
			return (TRUE);
		}
		free(exec_path);
		index++;
	}
	ft_free_double((char **)path_board);
	return (FALSE);
}

int	set_exec_path(t_cmd *cmd, t_working_info *info)
{
	char		*execv_path;
	char		*cmd_string;

	cmd_string = cmd->simple_cmd->string_value;
	if (is_already_exec_path(cmd_string) == TRUE)
		return (is_valid_cmd_path(cmd_string));
	else
	{
		return (set_absolute_path(cmd, info));
	}
}

void	single_cmd_child_process(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;
	struct stat	stat_info;

	exec_argv = get_exec_argv(info->cmd);
	exec_env = ft_envlst_to_envp(info->env);
	if (exec_argv == NULL || exec_env == NULL)
		exit(errno);
	execve(info->cmd->simple_cmd->string_value, exec_argv, exec_env);
	exit(errno);
}

void	exec_executing(t_working_info *info)
{
	char		**exec_argv;
	char		**exec_env;
	int			errno_tmp;
	struct stat	stat_info;

	if (set_exec_path(info->cmd, info) == FALSE)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	exec_argv = get_exec_argv(info->cmd);
	exec_env = ft_envlst_to_envp(info->env);
	if (exec_argv == NULL || exec_env == NULL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
	if (execve(info->cmd->simple_cmd->string_value, exec_argv, exec_env) \
		== FAIL)
	{
		errno_tmp = errno;
		ft_putendl_fd(strerror(errno_tmp), 2);
		exit(errno_tmp);
	}
}

void	process_not_built_in(t_working_info *info)
{
	pid_t	pid;
	int		exit_status;

	sigtermset(MINISHELL_HAS_CHILD);
	pid = fork();
	if (pid == 0)
	{
		sigtermset(EXECUTE_CHILD);
		exec_executing(info);
	}
	else
	{
		waitpid(0, &exit_status, 0);
		sigtermset(MINISHELL_NO_CHILD);
		if (WIFEXITED(exit_status))
			g_errno = WEXITSTATUS(exit_status);
		else
			g_errno = WCOREFLAG + WTERMSIG(exit_status);
	}
}

int	open_infile(t_cmd *cmd)
{
	t_token *redircet_token;
	int	infile_fd;

	redircet_token = cmd->redirect_input;
	if (redircet_token == NULL)
		return (STDIN_FILENO);
	infile_fd = open(redircet_token->string_value, O_RDONLY);
	if (infile_fd == OPEN_FAIL)
	{
		perror("open error");
		return (OPEN_FAIL);
	}
	while (redircet_token->next != NULL)
	{
		redircet_token = redircet_token->next;
		close(infile_fd);
		infile_fd = open(redircet_token->string_value, O_RDONLY);
		if (infile_fd == OPEN_FAIL)
		{
			perror("open error");
			return (OPEN_FAIL);
		}
	}
	return (infile_fd);
}

int	open_outfile(t_cmd *cmd)
{
	t_token *redircet_token;
	int		open_option;
	int		outfile_fd;

	redircet_token = cmd->redirect_output;
	if (redircet_token == NULL)
		return (STDOUT_FILENO);
	if (redircet_token->type & WRITE_APPEND)
		open_option = O_WRONLY | O_CREAT | O_APPEND;
	else
		open_option = O_WRONLY | O_CREAT;
	outfile_fd = open(redircet_token->string_value, open_option, 0644);
	if (outfile_fd == OPEN_FAIL)
		perror("open error");
	while (redircet_token->next != NULL)
	{
		redircet_token = redircet_token->next;
		close(outfile_fd);
		outfile_fd = open(redircet_token->string_value, open_option, 0644);
		if (outfile_fd == OPEN_FAIL)
			perror("open error");
	}
	return (outfile_fd);
}

void	restore_redirect_fd(t_cmd *cmd, int *io_fd)
{
	if (cmd->redirect_input != NULL)
	{
		dup2(io_fd[STDIN_FILENO], STDIN_FILENO);
		close(io_fd[STDIN_FILENO]);
	}
	if (cmd->redirect_output != NULL)
	{
		dup2(io_fd[STDOUT_FILENO], STDOUT_FILENO);
		close(io_fd[STDOUT_FILENO]);
	}
}

int	process_redirect(t_cmd *cmd, int *io_fd)
{
	ft_memset(io_fd, 0, sizeof(int) * 4);
	if (cmd->redirect_input != NULL)
		io_fd[INPUT_REDI] = open_infile(cmd);
	if (cmd->redirect_output != NULL)
		io_fd[OUTPUT_REDI] = open_outfile(cmd);
	if (io_fd[INPUT_REDI] == OPEN_FAIL || io_fd[OUTPUT_REDI == OPEN_FAIL])
	{
		if (io_fd[INPUT_REDI] != OPEN_FAIL)
			close(io_fd[INPUT_REDI]);
		if (io_fd[OUTPUT_REDI] != OPEN_FAIL)
			close(io_fd[OUTPUT_REDI]);
		return (OPEN_FAIL);
	}
	if (io_fd[INPUT_REDI] != 0)
	{
		io_fd[STDIN_FILENO] = dup(STDIN_FILENO);
		dup2(io_fd[INPUT_REDI], STDIN_FILENO);
		close(io_fd[INPUT_REDI]);
	}
	if (io_fd[OUTPUT_REDI] != 0)
	{
		io_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
		dup2(io_fd[OUTPUT_REDI], STDOUT_FILENO);
		close(io_fd[OUTPUT_REDI]);
	}
	return (FALSE);
}

void	process_single_cmd(t_working_info *info)
{
	int	cmd_type;
	int	io_fd[4];

	if (info->cmd->simple_cmd)
	{
		process_redirect(info->cmd, io_fd);
		cmd_type = get_cmd_type(info->cmd);
		if (cmd_type == NOT_BUILT_IN)
			process_not_built_in(info);
		else
			process_built_in(info->cmd, info, cmd_type);
	}
	restore_redirect_fd(info->cmd, io_fd);
}

int	ft_wait_childs(pid_t *child_pids, int cmd_count)
{
	int	index;
	int	exit_status;

	index = 0;
	while (index < cmd_count)
	{
		waitpid(child_pids[index], &exit_status, 0);
		index++;
	}
	return (exit_status);
}

void	init_pipe_before_next_cmd(t_cmd *cur_cmd, int *fd)
{
	if (fd[BEFORE_INPUT_FD] != -1)
		ft_close(fd[BEFORE_INPUT_FD]);
	fd[BEFORE_INPUT_FD] = fd[MULTI_PIPE_OUTPUT];
	if (fd[MULTI_PIPE_INPUT] != -1)
		ft_close(fd[MULTI_PIPE_INPUT]);
	fd[MULTI_PIPE_INPUT] = -1;
	fd[MULTI_PIPE_OUTPUT] = -1;
	return ;
}

int	check_and_get_infile(t_token *input)
{
	int	infile_fd;

	while (input)
	{
		infile_fd = open(input->string_value, O_RDONLY);
		if (infile_fd == -1)
		{
			ft_putstr_fd(input->string_value, 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		if (input->next != NULL)
			close(infile_fd);
		input = input->next;
	}
	return (infile_fd);
}

int	check_and_get_outfile(t_token *output)
{
	int	outfile_fd;

	while (output)
	{
		if (output->type & WRITE)
			outfile_fd = open(output->string_value, \
										O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (output->type & WRITE_APPEND)
			outfile_fd = open(output->string_value, \
										O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (outfile_fd == -1)
		{
			ft_putstr_fd(output->string_value, 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		if (output->next != NULL)
			close(outfile_fd);
		output = output->next;
	}
	return (outfile_fd);
}

void	handle_redirect_input(t_token *input_redirection)
{
	int		infile_fd;
	
	infile_fd = check_and_get_infile(input_redirection);
	ft_dup2(infile_fd, 0);
	ft_close(infile_fd);
}

void	handle_redirect_output(t_token *output_redirection)
{
	int		outfile_fd;
	int		type;

	outfile_fd = check_and_get_outfile(output_redirection);
	ft_dup2(outfile_fd, 1);
	ft_close(outfile_fd);
}

void	handle_redirection_multi_cmd(t_cmd *cmd)
{
	if (cmd->redirect_input)
		handle_redirect_input(cmd->redirect_input);
	if (cmd->redirect_output)
		handle_redirect_output(cmd->redirect_output);
}

void	close_useless_fds(int *fd)
{
	if (fd[0] != -1)
		ft_close(fd[0]);
	if (fd[1] != -1)
		ft_close(fd[1]);
	if (fd[2] != -1)
		ft_close(fd[2]);
}

void	execute_multicmd_child(t_working_info *info, t_cmd *my_cmd, int *fd)
{
	if (my_cmd->redirect_input || my_cmd->redirect_output)
		handle_redirection_multi_cmd(my_cmd);
	if (fd[BEFORE_INPUT_FD] != -1 && my_cmd->redirect_input == NULL)
	{
		ft_dup2(fd[BEFORE_INPUT_FD], 0);
	}
	if (fd[MULTI_PIPE_OUTPUT] != -1 && my_cmd->redirect_output == NULL)
	{
		ft_dup2(fd[MULTI_PIPE_INPUT], 1);
	}
	close_useless_fds(fd);
	info->cmd = my_cmd;
	exec_executing(info);
	exit(0);
}

pid_t	process_multi_cmd(t_working_info *info)
{
	pid_t	pid;
	int		fd[3];
	pid_t	*child_pids;
	int		index;
	t_cmd	*cur_cmd;

	ft_memset(fd, -1, sizeof(int) * 3);
	child_pids = ft_calloc(ft_cmdlst_size(info->cmd), sizeof(pid_t));
	// ft_calloc 널가드 -> 널가드를 포함하여 에러출력하고 종료하는 함수가 필요
	cur_cmd = info->cmd;
	index = 0;
	while (cur_cmd != NULL)
	{
		if (cur_cmd->next != NULL)
			ft_pipe(fd);
		sigtermset(MINISHELL_HAS_CHILD);
		pid = ft_fork();
		if (pid == 0)
		{
			sigtermset(EXECUTE_CHILD);
			execute_multicmd_child(info, cur_cmd, fd);
		}
		child_pids[index] = pid;
		ft_wait_childs(child_pids, ft_cmdlst_size(info->cmd));
		init_pipe_before_next_cmd(cur_cmd, fd);
		index++;
		cur_cmd = cur_cmd->next;
	}
}

void	execute(t_working_info *info)
{
	int	cmd_count;
	int	status;

	cmd_count = ft_cmdlst_size(info->cmd);
	if (has_heredoc(info))
		status = heredoc(info);
	else
		status = TRUE;
	if (status == TRUE)
	{
		if (cmd_count == 1)
			process_single_cmd(info);
		else
			process_multi_cmd(info);
	}
}
