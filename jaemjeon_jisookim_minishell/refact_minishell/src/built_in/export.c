/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:21:19 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:14 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// # include <unistd.h>
// # include <stdio.h>
// # include <stdlib.h>

// typedef struct s_cmd
// {
// 	t_token			*simple_cmd;
// 	t_token			*redirect_input;
// 	t_token			*redirect_output;
// 	struct s_cmd	*next;
// }	t_cmd;

// typedef struct s_token
// {
// 	unsigned int	type;
// 	char			*string_value;
// 	struct s_token	*next;
// 	struct s_token	*prev;
// }	t_token;

// t_cmd의 simple_cmd문자가 export인걸 확인하고 해당 함수 안으로 들어옴
void	export(t_cmd *cmdline)
{
	//뒤따라오는 연결리스트 노드의 simple_cmd의 형식이 key=value인걸 확인
		//check : 단어사이에 공백이 있으면 안됨(key=value)
		
	//만약 정상적으로 예상한 값이 들어왔다면, 해당 key와 value를 '='을 기준으로 나눈 뒤에
	//key값과 value값에 하나씩 할당 한 뒤에, 업데이트
	//해당 함수에서 malloc 한게 있으면 동적할당 해제(free())하기

}