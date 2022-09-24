
///////////////////////////////////
*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*
/*		[(PREFIX)]	MAIN	*/
*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*

- 00 check syntax quote
- 01 parsing
- 02 execute

///////////////////////////////////


====================================================================
*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*
/*		01	PARSING			*/
*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*

[PARSING]
	- 01 tokenize
	- 02 check syntax grammar
	- 03 expander
	- 04 remove trash token
	- 05 quote remove
	- 06 word split & word join
	- 07 combine redirect file name
	- 08 get token list to cmd structure (token -> cmd)

====================================================================

# 01 [TOKENIZE] (tokenize/split all component)
{
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
}
# 02 [main/check_syntax]
# 03 [EXPAND] (expander)
{
	check if it is...

	[1] HEREDOC & HEREDOC token
		heredoc delimiter token
		
	[2] WORD & SQUOTE
		- expand pidenv
		- expand env
			(0) 현재토큰에서 
			(1) 확장가능성 있는 문맥을 발견하면 ($발견)
			(2) cpy_ifs_string (ifs 체크) & cpy_ifs_strin & cpy_none_expander
			(3) 확장! (확장을 해야하는 것들을 만나면 확장을 쭉해줌.)
			(4) raise_buffer
				문자열덩어리, ifs덩어리, 확장된 덩어리들을 한 덩어리씩 모아서 계속 버퍼를 늘려주고 (strjoin을 계속하는 느낌) 해당 토큰을 확장된 문자열로 업데이트
}
# 04 [remove trash token]
# 05 [quote remove]
# 06 [WORD_SPLIT] & [WORD_JOIN]
{
	[1] WORD_SPLIT

		(0) is to word split
			check if is WORD && QUOTE
		(1) word split 
			split된 연결리스트 반환
		(2) insert token
			현재다음으로 연결해주고,
			만약에 현재가 맨처음것이라면
			head_token을 다음것으로 바꿔줌.
		(3) delete token
			이미 split해서 반영했으므로 현재것은 지워줌.

	[2] WORD_JOIN
		type가 
		(RIGHT_JOIN && LEFT_JOIN) 이면 join.
		(ft_strjoin)

}
# 07 [combine redirect file name]
# 08 [get token list to cmd structure (token -> cmd)]

====================================================================

*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*
/*		02	EXECUTE			*/
*:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*

[EXECUTE]

check redirect -> 
get command type (check if it is built in or not) ->
built in / not built in ->
store redirect fd


[HEREDOC]







