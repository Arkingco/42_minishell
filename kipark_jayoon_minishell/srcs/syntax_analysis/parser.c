/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:02:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/31 19:00:56 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	typedef enum e_token_type
	{
		T_NULL,
		T_WORD,
		T_DOUBLE_QUOTE,
		T_SINGLE_QUOTE,
		T_INPUT_REDIR,
		T_HERE_DOC,
		T_OUTPUT_REDIR,
		T_APPEND_REDIR,
		T_PIPE
	}	t_token_type;

	typedef struct s_token
	{
		t_token_type	type;
		char			*str;
		struct s_token	*next;
	}	t_token;

문법 검사
	토큰 타입과 문자열을 가지고 있는 dummy linked list 를 하나씩 탐색하며 검사함
	(처음 노드인 T_NULL 은 뛰어 넘어야 함)
		처음에 올 수 있는 타입은
			T_WORD
			T_INPUT_REDIR
			T_HERE_DOC
			T_OUTPUT_REDIR
			T_APPEND_REDIR
		올 수 없는 타입은
			T_PIPE
	
*/
/*
parser 가 해야 할 일은 
토큰화 된 데이터를 분석하여 문법이 맞는지 검사하며,
확인 된 노드들을 parsing linked list 에 넣는다.
parsing linked list 는 이후에 command program 을 실행하기 위해 사용하게 된다.
*/

#include "lexer.h"
#include "parser.h"
#include <stdlib.h>

void	parser(t_token	*l_token, t_parsing_list *l_parsing)
{
	init_parsing_list(l_parsing);
}
