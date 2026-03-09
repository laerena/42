#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int		pfd[2];
	pid_t	pid;
	char	buffer[100];
	int		n;

	pipe(pfd);
	pid = fork();

	if (pid == 0)
	{
		//child
		close(pid[0]); //child won't read
	}
}