/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:50 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/16 15:40:29 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

// heredoc
typedef struct s_hdoc
{
	char		*limiters;
	int			count;
	int			*limeter_fds;
}	t_hdoc;

//heredoc
int		exec_check_heredoc(t_exec *exec);
void	do_heredoc(t_exec *exec, char *limiter, int fd);
int		open_heredoc_file(t_exec *exec, char *limiter, int i);
void	make_delimiter_array(t_cmd *cmd, t_hdoc *hdoc);


#endif
