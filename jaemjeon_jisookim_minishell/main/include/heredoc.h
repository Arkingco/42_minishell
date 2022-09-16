/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:50 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 18:01:25 by jisookim         ###   ########.fr       */
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
	int			hdoc_flag;
	char		**limiters;		//calloc
	int			*limeter_fds;	//calloc
	pid_t		*hdoc_pids;
	char		*file_name;
}	t_hdoc;


// heredoc_check
void	check_heredoc(t_exec *exec, t_hdoc *hdoc);

//heredoc
int		heredoc(t_exec *exec);
void	open_heredoc_file(t_exec *exec, t_hdoc *hdoc, char *limiter, int i);
void	do_heredoc(t_exec *exec, char *limiter, int fd);
void	get_info_hdoc_struct(t_exec *exec, t_hdoc *hdoc);

// heredoc_init
void	make_heredoc_lilmiter_array(t_exec *exec, t_hdoc *hdoc);

#endif
