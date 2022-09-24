--------------------------------------
* todo : exit code

* [expand.c] expand_exit_status; // todo expand exit status
--------------------------------------

==================================
## MAIN ##
==================================
- check syntax quote
- parsing
	# tokenize
		- split all component
		- 
	# check_syntax_grammar
	# expander
	# (remove trash token) & (quote remove)
	# word split
	# word join
	# combine redirect filename
	# token -> cmd

- execute


==================================
# 01 [TOKENIZE]
==================================
# tokenize/split all component
skip ifs ->
{
	[1] read in quote
		(1) check if it is QUOTE or DEQUOTE 
		(2) move index to pair quote 
		(3) get quote string value 
		(4) set join flag 
		(5) if there is $ -> set EXPANDER
	[2] read in redirect

	[3] read in pipe

	[4] read in pure word
}


==================================
# 02 [main/check_syntax]
==================================
# check syntax grammar


==================================
# 03 [EXPAND]
==================================
# expander
check if it is...

[1] HEREDOC & HEREDOC token
	heredoc delimiter token
	
[2] WORD & SQUOTE
	- expand pidenv
	- expand env
		현재토큰에서 확장을 해야하는 것들을 만나면 확장을 쭉해줌. 문자열덩어리, ifs덩어리, 확장된 덩어리들을
		한 덩어리씩 모아서 계속 버퍼를 늘려주고 strlcat을 하여 늘려주고(strjoin을 계속하는 느낌) 해당 토큰을 확장된 문자열로 업데이트



==================================
[EXECUTE]
==================================
* todo : remake int get_cmd_type(t_cmd *cmd) function

check redirect -> 
get command type (check if it is built in or not) ->
built in / not built in ->
store redirect fd



==================================
[HEREDOC]
==================================





==================================
[PARSE]
==================================


