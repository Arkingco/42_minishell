/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:43:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/16 18:26:14 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_built_in(t_cmd *cmd, int cmd_type, t_working_info *info)
{
	void	(*built_in_func)(t_cmd*, t_working_info*);
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
	if (ft_strlen(cmd_string) < 2)
		return (FALSE);
	if (ft_strncmp("./", cmd_string, 2) == 0 || \
		ft_strncmp("~/", cmd_string, 2) == 0 || \
		ft_strncmp("/", cmd_string, 1) == 0)
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
	{
		expand_homepath(&cmd_string, info);
		return (is_valid_cmd_path(cmd_string));
	}
	else
	{
		return (set_absolute_path(cmd, info));
	}
}

int	process_not_built_in(t_cmd *cmd, t_working_info *info)
{
	pid_t	pid;
	char	**exec_argv;
	char	**exec_env;
	int		exit_status;

	if (set_exec_path(cmd, info) == FALSE)
	{
		perror("not cmd found");
		return (1);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			exec_argv = get_exec_argv(cmd);
			exec_env = ft_envlst_to_envp(info->env);
			execve(cmd->simple_cmd->string_value, exec_argv, exec_env);
			free(exec_argv);
			free(exec_env);
		}
		else
			waitpid(0, &exit_status, 0);
	}
	return (exit_status);
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
		perror("open error");
	while (redircet_token->next != NULL)
	{
		redircet_token = redircet_token->next;
		close(infile_fd);
		infile_fd = open(redircet_token->string_value, O_RDONLY);
		if (infile_fd == OPEN_FAIL)
			perror("open error");
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

int	process_redirect(t_cmd *cmd, int *io_fd)
{
	ft_bzero(io_fd, sizeof(int) * 4);
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

void	process_single_cmd(t_cmd *cmd, t_working_info *info)
{
	int	cmd_type;
	int	io_fd[4];

	if (process_redirect(cmd, io_fd) == OPEN_FAIL)
		return ;
	if (cmd->simple_cmd)
	{
		cmd_type = get_cmd_type(cmd);
		if (cmd_type == NOT_BUILT_IN)
			process_not_built_in(cmd, info);
		else
			process_built_in(cmd, cmd_type, info);
	}
	restore_redirect_fd(cmd, io_fd);
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

void	run_program_in_multi_process(t_cmd *cmd, t_envlst *env)
{

}

void	process_redirect_in_multi(t_cmd *cmd, int *io_fd)
{

}

void	restore_redirect_fd_in_multi(t_cmd *cmd, int *io_fd)
{

}

int	first_cmd(t_cmd *cmd, t_envlst *env)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		io_fd[4];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		process_redirect_in_multi(cmd, io_fd);
		run_program_in_multi_process(cmd, env);
		restore_redirect_fd_in_multi(cmd, io_fd);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(STDIN_FILENO, pipe_fd[0]);
	}
}

int	middle_cmd(t_cmd *cmd, t_envlst *env)
{

}

int	last_cmd(t_cmd *cmd, t_envlst *env)
{
	pid_t	pid;
	int		io_fd[4];

	pid = fork();
	if (pid == 0)
	{
		process_redirect(cmd, io_fd);
		run_program_in_multi_process(cmd, env);
		restore_redirect_fd(cmd, io_fd);
	}
	else
	{
	}
}

int	process_multi_cmd(t_cmd *cmd, t_envlst *env)
{
	int		cmd_index;
	int		cmd_count;
	pid_t	*child_pids;


	cmd_index = 0;
	cmd_count = ft_cmdlst_size(cmd);
	// 여여기기서  히히어어독  처처리리
	// 존재하는 명령어 들인지 확인
	child_pids = ft_calloc(cmd_count, sizeof(pid_t));

	while (cmd_index < cmd_count)
	{
		if (cmd_index == 0)
			child_pids[cmd_index] = first_cmd(cmd, env);
		else if (cmd_index == cmd_count - 1)
			child_pids[cmd_index] = last_cmd(cmd, env);
		else
			child_pids[cmd_index] = middle_cmd(cmd, env);
		cmd = cmd->next;
		cmd_index++;
	}
	return (ft_wait_childs(child_pids, cmd_count));
}

void	execute(t_cmd *cmd, t_working_info *info)
{
	int	cmd_count;

	cmd_count = ft_cmdlst_size(cmd);
	if (cmd_count == 1)
		process_single_cmd(cmd, info);
	else
		process_multi_cmd(cmd, info->env);
}
