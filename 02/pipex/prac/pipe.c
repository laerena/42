#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int		pfd[2];
	pid_t	pid;
	char	buffer[100];
	int		n;
	/*
	char	*ls_args[] = {"/bin/ls", NULL};
	char	*wc_args[] = {"/usr/bin/wc", "-l", NULL};
	*/
	pipe(pfd);
	pid = fork();

	if (pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		//when the process writes to stdout, it now writes into the pipe
		write(1, "abc123\n", 7);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);

		n = read(pfd[0], buffer, 99);
		buffer[n] = '\0';
		printf("Parent read: %s\n", buffer);
		wait(NULL);
	}
	return (0);
}