/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:02:53 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/19 19:04:19 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "working_dir.h"

// heredoc.c
int	heredoc(t_working_info *info);

// heredoc_util.c
int	has_heredoc(t_working_info *info);

#endif