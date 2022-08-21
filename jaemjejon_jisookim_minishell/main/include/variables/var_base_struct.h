/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_base_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:02:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/21 19:04:10 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_BASE_STRUCT_H
 # define VAR_BASE_STRUCT_H

# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

# include "../libft/libft.h"

typedef struct s_token // to do : value 초기화, redirect_type = 0
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
}	t_token;

typedef struct s_redirect
{
	t_token		*redirect_input[2]; // [0] -> REDIRECT_TOKEN [1] -> FILENAME_TOKEN
	t_token		*redirect_output[2];
}	t_redirect;

typedef struct s_simple_command
{
	t_token						cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_cmd
{
	t_simple_command	simple_command;
	t_redirect			redirect;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

typedef struct s_global
{
	char		**envp;
	t_envlst	*lst_env;
	t_token		*lst_token;
	t_cmd		*lst_cmd;
}	t_global;


#endif