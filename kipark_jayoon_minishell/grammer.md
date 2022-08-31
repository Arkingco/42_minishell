/*
* 	EBNF 문법 내용
*	{} 는 0번 이상 반복
*	[] 는 option 으로 0번 또는 1번 반복
*	| 는 또는으로 | 으로 연결 되어 있는 것들과 동급('|' 와 다르다.)
*/

<program>			-> { <pipe_line> }
<pipe_line>			-> <command> { '|' <command> }
<command>			-> [ <simple_command> ][ <redir_iter> ]
<simple_command>	-> <exec_path> { <argv> }
<redir_iter>		-> <redir_chunk> { <redir_chunk> }
<redir_chunk>		-> <redirection> <file_path>

<redirection>		-> '<' | '<<' | '>' | '>>'
<exec_path>			-> word
<file_path>			-> word
<argv>				-> word
