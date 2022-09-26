/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:33:48 by kipark            #+#    #+#             */
/*   Updated: 2022/09/26 15:23:31 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/exit_status.h"
int main()
{
    int pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        exit(258);
    }
    else 
    {
        wait(&status);
    }
    printf("%d ", WEXITSTATUS(status));
    g_exit_status = 10;
    printf("%d \n", g_exit_status);
}
