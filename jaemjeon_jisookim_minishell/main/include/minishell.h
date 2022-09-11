/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:40:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/11 17:13:11 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include "../libft/libft.h"
# include "env.h"
# include "cmd.h"
# include "token.h"
# include "utils.h"
# include "expand.h"
# include "parse.h"
# include "execute.h"
# include "built_in.h"

# define TRUE			1
# define FALSE			0
# define OPEN_FAIL		-1
# define INPUT_REDI		2
# define OUTPUT_REDI	3
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

// main.c

// init.c
void	argument_error_check(int argc);
void	init_envp(char *envp[], t_envlst **env);


// DEBUG

// print_lst_token.c
void	debug_print_lst_token(t_token *lst);
// print_lst_cmd.c
void	debug_print_lst_cmd(t_cmd *lst);

#endif
