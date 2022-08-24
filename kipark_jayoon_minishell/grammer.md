// nkim statement
/*
*	{} 는 0번 이상 반복
*	[] 는 option 으로 0번 또는 1번 반복
*	| 는 또는으로 | 으로 연결 되어 있는 것으로 변경 가능
*/

<program>        -> { <pipe_line> }
<pipe_line>      -> <command> { '|' <pipe_line> }
<command>        -> [ <simple_command> ][  <redirects> ]
<simple_command> -> <exec_path> { <argv> }
<redirects>      -> <io_redirect> { <redirects> }
<io_redirect>    -> <redirect_op> <file_path>

<redirect_op>    -> '>' | '>>' | '<' | '<<'
<exec_path>      -> word | "word" | 'word'
<file_path>      -> word | "word" | 'word'
<argv>           -> word | "word" | 'word'








// 기존 statement
<pipeline>		::= <cmd>
				|	<pipeline> '|' <cmd>

<cmd>			::= <simple_cmd> 
				|	<simple_cmd> <redirects>

<simple_cmd>	::= <exec_path>
				|	<argv>

<argv>			::= <file_path> <args>

<redirects>		::= <io_redirect>
				|	<redirects> <io_redirect>

<io_redirect>	::= '<'   <filename>
				|	'<<'  <filename>
				|	'>'   <filename>
				|	'>>'  <filename>

<args>			::=	WORD 
				|	<args> WORD

<filename>		::= WORD

<exec_path>		::= WORD

<file_path>		::= WORD
