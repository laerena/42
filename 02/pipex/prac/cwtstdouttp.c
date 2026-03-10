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
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);

		write(STDOUT_FILENO, "hello through stdout\n", 21);
	}
	else
	{
		close(pfd[1]);
		n = read(pfd[0], buffer, 99);
		buffer[n] = '\0';
		printf("Parent read: %s\n", buffer);
		close(pfd[0]);
		wait(NULL);
	}
	return (0);
}
