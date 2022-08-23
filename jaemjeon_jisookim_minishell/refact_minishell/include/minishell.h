/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:40:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/24 05:16:15 by jaemjeon         ###   ########.fr       */
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
# include "libft.h"
# include "env.h"
# include "cmd.h"
# include "token.h"
# include "utils.h"

# define TRUE			1
# define FALSE			0
# define INT_MAX	 	2147483647

// token_type
# define HEAD			0b10000000 00000000 00000000 00000000
# define PIPE			0b01000000 00000000 00000000 00000000
# define REDIRECT		0b00100000 00000000 00000000 00000000
# define WORD			0b00010000 00000000 00000000 00000000

// redirectio_type
# define READ			0b00000000 10000000 00000000 00000000
# define HEREDOC		0b00000000 01000000 00000000 00000000
# define WRITE			0b00000000 00100000 00000000 00000000
# define WRITE_APPEND	0b00000000 00010000 00000000 00000000

// word_type
# define PURE_WORD		0b00000000 00000000 10000000 00000000
# define EXPANDED		0b00000000 00000000 01000000 00000000
# define DQUOTE			0b00000000 00000000 00100000 00000000
# define SQUOTE			0b00000000 00000000 00010000 00000000

// linked_word_status
# define LEFT_IFS		0b00000000 00000000 00000000 10000000
# define RIGHT_IFS		0b00000000 00000000 00000000 01000000
# define LEFT_JOIN		0b00000000 00000000 00000000 00100000
# define RIGHT_JOIN		0b00000000 00000000 00000000 00010000


// folder_main

// main.c

// init.c
void	argument_error_check(int argc);
void	init_envp(char *envp[], t_envlst **env);

#endif
