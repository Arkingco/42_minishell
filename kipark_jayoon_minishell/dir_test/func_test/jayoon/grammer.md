<pipeline>     ::= <cmd>
               |   <pipeline> '|' <cmd>
	ls
	ls | cat

<cmd>          ::= <simple_cmd> 
               |   <simple_cmd> <redirects>
	ls
	ls > a

<simple_cmd>   ::= <file_path>
               |   <argv>
	/bin/ls
	/bin/ls -al
	ls -a

<argv>         ::= <file_path> <args>
	/bin/ls -al

<redirects>    ::= <io_redirect>
                |  <redirects> <io_redirect>
	> a
	> a > b

<io_redirect>  ::= '<'   <filename>
                |  '<<'  <filename>
                |  '>'   <filename>
                |  '>>'  <filename>
	> a
	>> a
	< a
	<< a

<args>        ::= WORD 
                | <args> WORD
	ls ls
	ls word
	ls some_not_file

<filename>    ::= WORD
	ls	

<file_path>   ::= WORD
	/bin/ls



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
