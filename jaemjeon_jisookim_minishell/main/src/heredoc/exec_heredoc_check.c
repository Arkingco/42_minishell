/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:44:30 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/14 14:50:19 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 

cmd 받아와서 히어독이 있는지 체크. 
	1) 히어독이 있으면 몇개인지 체크 (heredoc->count)
		heredoc->delimiter_arr 를 herecof->count 만큼 동적할당
		링크드리스트를 순회하면서 히어독인 인자들만 차례대로 heredoc->delimiter_arr 안에 넣음
	2) 히어독이 없으면 return ;

while 루프를 돌면서 히어독 실행, 딜리미터로 넘겨주는 값은 heredoc->delimiter_arr[i] 의 값! 

*/


