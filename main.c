#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (line == NULL)
		{
			line = get_next_line(fd);
			printf("%s", line);
			break ;
		}
	}
	close(fd);
}

/*
int main()
{
	char	*s1;
	char	*s2;
	int 	eof = 1;

	s1 = ft_strndup("12345", 5);
	s2 = ft_strndup("12345\n12345", 11);
	ft_trim(&s1, eof);
	ft_trim(&s2, eof);
	printf("%p", s1);
	printf("\n");
	printf("%s", s2);
	free(s1);
	free(s2);	

}
*/
