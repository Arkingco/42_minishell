/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:04:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/09/23 03:15:56 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ft_printf.c
int	printf_fd(int fd, const char *format, ...);

// error_exit.c
void	ft_error_exit(int exit_status, char *message);

// ifs.c
int	ft_has_ifs(char *string);
int	ft_is_ifs(const char *letter);
int	ft_skip_ifs1(char **string_pointer);
void	ft_skip_ifs2(char *line, int *index);

// signal.c
void	set_signal(int mode);

// terminal.c
void	set_termios(int mode);

//setting.c
void	sigtermset(int mode);
void	process_errno(int errno_num, char *string, int type);

#endif
