/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:22:41 by kipark            #+#    #+#             */
/*   Updated: 2022/10/10 10:44:18 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STATUS_H
# define EXIT_STATUS_H

typedef enum e_signal_exit
{
	SIGINT_EXIT = 130,
	SIGQUIT_EXIT = 131
}	t_signal_exit;

int	g_exit_status;

#endif
