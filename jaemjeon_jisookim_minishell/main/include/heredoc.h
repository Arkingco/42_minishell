/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:50 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/17 19:00:24 by jisookim         ###   ########.fr       */
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


// heredoc_check

//heredoc
int		heredoc(t_exec *exec, pid_t ret_pid);
void	make_and_open_hdoc(t_exec *exec, t_hdoc *hdoc, char *limiter, int i);
void	do_heredoc(t_exec *exec, char *limiter, int fd);
void	close_and_reopen_hdoc(t_exec *exec, t_hdoc *hdoc, int i);

// heredoc_init
void	count_hdoc(t_exec *exec, t_hdoc *hdoc);
int		init_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc);
void	make_heredoc_lilmiter_array(t_exec *exec, t_hdoc *hdoc);

#endif
