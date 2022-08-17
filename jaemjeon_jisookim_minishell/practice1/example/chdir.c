#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*dir;
	int		return_val;

	dir = getcwd(NULL, 0); // buffer에 NULL을 넣었으므로 새롭게 할당되어 반환됨.
	printf("%s\n", dir);   // "/Users/jaemjeon/projects/minishell" 출력
	free(dir);


	return_val = chdir("something_folder"); // 상대경로 가능함
	printf("%d\n", return_val); // 0 출력
	// something_folder라는 폴더가 있으면 0반환후 dir변경.
	// 없으면 -1반환후 현재 dir유지.


	dir = getcwd(NULL, 0);
	printf("%s\n", dir);   // "/Users/jaemjeon/projects/minishell/something_folder" 출력
	free(dir);


	chdir("/"); // 절대 경로도 가능함.
	dir = getcwd(NULL, 0);
	printf("%s\n", dir);   // "/" 출력
	free(dir);
}
