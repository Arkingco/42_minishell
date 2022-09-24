/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:02:53 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/24 15:00:32 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "structs/t_working_dir.h"

//heredoc_do.c
char	*heredoc_expand(t_working_info *info, char *line);
void	get_input_heredoc(t_working_info *info, t_token *redirec_token, int fd);

// heredoc_util.c
int		has_heredoc(t_working_info *info);
char	*make_tmp_filename(void *p1_8byte, void *p2_8byte);
void	rename_string_value(t_working_info *info);

// heredoc.c
int		heredoc(t_working_info *info);

#endif
