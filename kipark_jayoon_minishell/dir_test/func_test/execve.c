#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char	*cmd = "";
	char	**args = {"", NULL};

	execve(cmd, args, envp);
	return (0);
}
