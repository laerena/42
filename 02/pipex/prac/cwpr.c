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
		close(pfd[0]); //child won't read
		write (pfd[1], "message from child", 18);
		close(pfd[1]);
	}
	else
	{
		//parent
		close(pfd[1]); //parent won't write
		n = read(pfd[0], buffer, 99);
		buffer[n] = '\0';
		printf("Parent read: %s\n", buffer);
		close(pfd[0]);
		wait(NULL); //wait for child to finish
	}
	return (0);
}
