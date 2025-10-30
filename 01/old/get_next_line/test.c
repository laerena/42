
#include <fcntl.h>
#include <stdio.h>
# include "get_next_line.h"

int	main(void)
{
	int	fd = open("1char.txt", O_RDONLY);
	char	*line;
	int		i;

	i = 0;
	line = (char *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		//free(line);
		//line = NULL;
		i++;
	}
	if (line)
		free(line);

	close(fd);
}