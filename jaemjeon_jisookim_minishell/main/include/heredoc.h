/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:50 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/18 01:56:57 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "token.h"
# include "env.h"
# include "cmd.h"
# include "execute.h"

// heredoc
typedef struct s_hdoc
{
	int			count;
	char		**limiters;		//calloc
	int			*limiter_fds;	//calloc
	pid_t		*hdoc_pids;
	char		**file_name;
}	t_hdoc;

//heredoc_tools
void	doing_heredoc_sigint_process(int signo);
void	heredoc_process_sigint_process(int signo);
char	*make_tmp_filename(void *p1_8byte, void *p2_8byte);
void	rename_string_value(t_exec *exec);

//heredoc
int		make_heredoc_file(t_exec *exec, t_cmd *cur_cmd, \
												t_token *cur_redirect_token);
int		heredoc(t_exec *exec, pid_t ret_pid);
void	do_heredoc(t_exec *exec, char *limiter, int fd);

// heredoc_init
void	count_hdoc(t_exec *exec, t_hdoc *hdoc);
void	make_heredoc_lilmiter_array(t_exec *exec, t_hdoc *hdoc);
int		init_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc);

#endif
