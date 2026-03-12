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
		close (pfd[1]);
		n = read(pfd[0], buffer, 99);
		buffer[n] = '\0';
		printf("Child read: %s\n", buffer);
		close(pfd[0]);
	}
	else
	{
		//parent
		close(pfd[0]);
		write(pfd[1], "message from parent", 19);
		close(pfd[1]);
		wait(NULL);
	}
	return (0);
}