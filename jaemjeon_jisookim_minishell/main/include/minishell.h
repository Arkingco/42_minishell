/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:40:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 01:35:30 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <dirent.h>
# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include "env.h"
# include "cmd.h"
# include "token.h"
# include "utils.h"
# include "expand.h"
# include "parse.h"
# include "execute.h"
# include "built_in.h"
# include "working_dir.h"
# include "heredoc.h"
# include "structs/t_cmd.h"
# include "structs/t_env.h"
# include "structs/t_token.h"
# include "structs/t_working_dir.h"
// # include "sigset.h"

# define TRUE			1
# define FALSE			0
# define FAIL			-1
# define OPEN_FAIL		FAIL
# define NONE			FALSE
# define INT_MAX	 	2147483647

// token_type
# define EXPANDER		0b10000000000000000000000000000000
# define PIPE			0b01000000000000000000000000000000
# define REDIRECT		0b00100000000000000000000000000000
# define WORD			0b00010000000000000000000000000000

// redirectio_type
# define READ			0b00000000100000000000000000000000
# define HEREDOC		0b00000000010000000000000000000000
# define WRITE			0b00000000001000000000000000000000
# define WRITE_APPEND	0b00000000000100000000000000000000

// word_type
# define PURE_WORD		0b00000000000000001000000000000000
# define EXPANDED		0b00000000000000000100000000000000
# define DQUOTE			0b00000000000000000010000000000000
# define SQUOTE			0b00000000000000000001000000000000
# define QUOTE			0b00000000000000000011000000000000

// linked_word_status
# define LEFT_IFS		0b00000000000000000000000010000000
# define RIGHT_IFS		0b00000000000000000000000001000000
# define LEFT_JOIN		0b00000000000000000000000000100000
# define RIGHT_JOIN		0b00000000000000000000000000010000
# define WORD_JOIN		0b00000000000000000000000000110000

enum e_process_mode
{
	MINISHELL_NO_CHILD,
	MINISHELL_HAS_CHILD,
	EXECUTE_CHILD,
	HEREDOC_CHILD,
	HEREDOC_PARENT
};

enum e_error
{
	IDENTIFIER_ERR,
	MANY_ARG_ERR,
	CMD_NOT_FOUND_ERR,
	NOT_NUM_ARG_ERR
};

// main.c

// init.c
void	argument_error_check(int argc);
void	init_envp(t_working_info *info, char *envp[]);
void	init_cur_path(t_working_info *info);
// void	set_signal_action(void);
void 	rl_replace_line(const char *, int);


// DEBUG

// print_lst_token.c
void	debug_print_lst_token(t_token *lst);
// print_lst_cmd.c
void	debug_print_lst_cmd(t_cmd *lst);

#endif
