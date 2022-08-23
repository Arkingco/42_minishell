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
